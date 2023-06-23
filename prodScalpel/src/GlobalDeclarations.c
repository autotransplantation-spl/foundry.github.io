#include "GlobalDeclarations.h"
#include "ListOfString.h"
#include "ListOfFunctionSourceFile.h"
#include "GenTrans.h"
#include "folderContent.h"
#include "DependencyList.h"
#include "DeclarationSymbolTable.h"
#include "FunctionCallDependency.h"
#include "IndividualInstantiator.h"
#include "GlobalDependenceGraph.h"
#include "FunctionExtractor.h"
#include <stdlib.h>
#include <stdio.h>
//#include <malloc.h>
#include <string.h>

#define NORMAL_DECLARATION_MARKER "NORMAL_DECLARATION\n"
#define STRUCT_UNION_MARKER "STRUCT_DECLARATION\n"
#define TYPEDEF_MARKER "TYPEDEF_DECLARATION\n"
#define STRUCT_DECL_BEGINNING_MARKER "/* STRUCT_DECL_"
#define GLOBAL_DECL_BEGINNING_MARKER "/* GLOBAL_DECL_"
#define TYPEDEF_DECL_BEGINNING_MARKER "/* TYPEDEF_DECL_"
#define ENUM_DECL_BEGINNING_MARKER "/* ENUM_DECL"
#define ENUM_DECL_BEGINNING_MARKER_ "/* ENUM_DECL_"

#define DECLARED_TYPES_MARKER "DECLARED_TYPES"
#define DECLARED_GLOBALS_MARKER "DECLARED_GLOBALS"
#define GLOBAL_END_MARKER "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

#define DEPENDENCIES_FOR_GLOBALS_MARKER "DEPENDENCIES_FOR_GLOBAL"

#include "Utils.h"
#include "GlobalDeclarations.h"
void addFunctionDeclarationAsExtern( char * extractSourceFile, char * extractSourceFileFuncDeclaration, ListOfString * ListOfDeclFromVainFile) {
    ListOfString *auxListOfDeclFromVainFile = copyCompleteListOfString(ListOfDeclFromVainFile);
    ListOfString *ListOfDeclarationWithoutStatic = NULL;
    char *formattedLine = (char *) malloc(500 * sizeof(char));
    char *currentLine = (char *) malloc(500 * sizeof(char));
    char *tempOutputFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempOutputFile, "%stempOutputFile.out", TXLTemporaryFolderMainThread);

    //Change static function declaration to extern and insert it into the interfaceHeader file
    while (auxListOfDeclFromVainFile->next != NULL) {
        fflush(stdout);
        strcpy(currentLine, auxListOfDeclFromVainFile->el);
        if (strstr(currentLine, "static"))
            addNewString(&ListOfDeclarationWithoutStatic,replace_str(auxListOfDeclFromVainFile->el, "static", ""));
        auxListOfDeclFromVainFile = auxListOfDeclFromVainFile->next;
    }
    printAListOfStrings(ListOfDeclarationWithoutStatic,tempOutputFile );
    //add declaration into currentSourceFile
    addLocsFromSourceToDestination(extractSourceFile, tempOutputFile, TXLToolsPath);
    removeAFileFromADirectory(tempOutputFile);
    while (ListOfDeclarationWithoutStatic->next != NULL) {
        sprintf(currentLine, "extern %s", ListOfDeclarationWithoutStatic->el);
        addAStringsInTheEndFile(currentLine, tempOutputFile);
        ListOfDeclarationWithoutStatic = ListOfDeclarationWithoutStatic->next;
    }
    //addFunctionDeclaration without static
    char * NeededFunctionsHeader = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
    sprintf(NeededFunctionsHeader, "%s%s", TXLTemporaryFolderMainThread, "NeededFunctionsHeader.h");
    addLocsFromSourceToDestination(NeededFunctionsHeader, tempOutputFile, TXLToolsPath);
    removeAFileFromADirectory(tempOutputFile);
    freeListOfStrings(&ListOfDeclarationWithoutStatic);
}

/* Move functions declaration from .cDEC to .c */
void moveExtractedFunctionDeclarationMultiFile(char * tempAllSourceFilesTargetPath){

    ListOfString * ListOfSourceFilesExtracted = readListOfStringFromFileAsWords(tempAllSourceFilesTargetPath);
    char *extractSourceFile = (char *) malloc(100 * sizeof(char));
    char *extractSourceFileFuncDeclaration = (char *) malloc(100 * sizeof(char));
    ListOfString * ListOfDeclFromVainFile = NULL;
    while (ListOfSourceFilesExtracted) {
        sprintf(extractSourceFile, "%s%s", TXLTemporaryMultiFileFolder, ListOfSourceFilesExtracted->el);
        sprintf(extractSourceFileFuncDeclaration, "%s%sDEC", TXLTemporaryMultiFileFolder, ListOfSourceFilesExtracted->el);
        ListOfDeclFromVainFile = readListOfStringFromFile(extractSourceFileFuncDeclaration);
        if (ListOfDeclFromVainFile && !strcmp(ListOfSourceFilesExtracted->el, donorEntryFile)) {
            addFunctionDeclarationAsExtern( extractSourceFile, extractSourceFileFuncDeclaration, ListOfDeclFromVainFile);
        }else
            if(ListOfDeclFromVainFile)
                addLocsFromSourceToDestination(extractSourceFile, extractSourceFileFuncDeclaration, TXLToolsPath);

        removeAFileFromADirectory(extractSourceFileFuncDeclaration);

        ListOfSourceFilesExtracted = ListOfSourceFilesExtracted->next;
    }
    free(extractSourceFile);
    free(extractSourceFileFuncDeclaration);
}
void freeListOfListOfDefinedTypesAndVars(ListOfDefinedTypesAndVars ** head) {
    ListOfDefinedTypesAndVars * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfStrings(&aux->definedTypes);
        freeListOfStrings(&aux->definedVar);
        free(aux->lineMarker);
        aux->definedTypes = NULL;
        aux->definedVar = NULL;
        aux->lineMarker = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewListOfDefinedTypesAndVars(ListOfDefinedTypesAndVars ** head, char * lineMarker,
        ListOfString * definedTypes, ListOfString * definedVars, char * currentTypeDef) {
    ListOfDefinedTypesAndVars * newEl = (ListOfDefinedTypesAndVars *) malloc(1 * sizeof (ListOfDefinedTypesAndVars));
    newEl->definedTypes = NULL;
    newEl->definedVar = NULL;
    newEl->lineMarker = (char *) malloc((strlen(lineMarker) + 1) * sizeof (char));
    strcpy(newEl->lineMarker, lineMarker);

    newEl->declType = (char *) malloc((strlen(currentTypeDef) + 1) * sizeof (char));
    strcpy(newEl->declType, currentTypeDef);

    newEl->definedTypes = copyCompleteListOfString(definedTypes);
    newEl->definedVar = copyCompleteListOfString(definedVars);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfDefinedTypesAndVars * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewListOfDependencies(ListOfStructMark ** head, char * newStatment,  char * oldStatment) {
    ListOfStructMark * newEl = (ListOfStructMark *) malloc(1 * sizeof (ListOfStructMark));
    newEl->newStatment = NULL;
    newEl->oldStatment = NULL;

    newEl->oldStatment = (char *) malloc((strlen(oldStatment) + 1) * sizeof (char));
    newEl->newStatment = (char *) malloc((strlen(newStatment) + 1) * sizeof (char));

    strcpy(newEl->oldStatment , oldStatment);
    strcpy(newEl->newStatment , newStatment);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfStructMark * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewDefinedTypesAndVars(ListOfDefinedTypesAndVars ** head, char * lineMarker,
                                     char * definedTypes, ListOfString * definedVars ){
    ListOfDefinedTypesAndVarsDecl * newEl = (ListOfDefinedTypesAndVarsDecl *) malloc(1 * sizeof (ListOfDefinedTypesAndVarsDecl));
    newEl->definedTypes = (char *) malloc((strlen(definedTypes) + 1) * sizeof (char));
    newEl->definedVar = NULL;
    newEl->lineMarker = (char *) malloc((strlen(lineMarker) + 1) * sizeof (char));
    strcpy(newEl->lineMarker, lineMarker);
    strcpy(newEl->definedTypes, definedTypes);
    newEl->definedVar = copyCompleteListOfString(definedVars);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfDefinedTypesAndVarsDecl * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }

}



ListOfDefinedTypesAndVars * readListOfDefinedTypesAndVarsFromFile(char * inputFile) {
    ListOfDefinedTypesAndVars * result = NULL;

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(1000 * sizeof (char));
    char * currentLine;
    currentLine = (char *) malloc(1000 * sizeof (char));

    while (fgets(line, 999, fin)) {

        while (!strstr(line, DECLARED_TYPES_MARKER) && !strstr(line, DECLARED_GLOBALS_MARKER)) {
            fgets(line, 999, fin);
            strtok(line, "\n");
            if(feof(fin)){
                fclose(fin);
                return result;
            }
        }
        strtok(line, "\n");
        strcpy(currentLine, line);
        fgets(line, 999, fin);
        strtok(line, "\n");
        char * currentTypeDef = NULL;
        currentTypeDef = (char *) malloc((strlen(line) + 1) * sizeof (char));
        strcpy(currentTypeDef,line);
        fgets(line, 999, fin);
        ListOfString * declaredTypesList = NULL;
        ListOfString * declaredGlobalsList = NULL;

        while (!strstr(line, GLOBAL_END_MARKER) && !strstr(line, DECLARED_GLOBALS_MARKER)) {
            addNewString(&declaredTypesList, line);
            fgets(line, 999, fin);
        }
        if (!strstr(line, GLOBAL_END_MARKER)) {
            fgets(line, 999, fin);
            while (!strstr(line, GLOBAL_END_MARKER)) {
                addNewString(&declaredGlobalsList, line);
                fgets(line, 999, fin);
            }
        }
        addNewListOfDefinedTypesAndVars(&result, currentLine, declaredTypesList, declaredGlobalsList,currentTypeDef);
    }
    fclose(fin);
    return result;
}

ListOfDefinedTypesAndVars * readCompletListOfDefinedTypesAndVarsFromFile(char * inputFile) {
    ListOfDefinedTypesAndVarsDecl * result = NULL;

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(4000 * sizeof (char));
    char * currentLine;
    currentLine = (char *) malloc(4000 * sizeof (char));

    char * defTypes;
    defTypes = (char *) malloc(40 * sizeof (char));

    ListOfString * defVar = NULL;

    while (fgets(line, 3999, fin)) {
        strtok(line, "\n");
        if (strstr(line, DECLARED_TYPES_MARKER)) {
            strcpy(currentLine, line);
            fgets(line, 3999, fin);
            strtok(line, "\n");
            strcpy(defTypes, line);
            fgets(line, 3999, fin);

            while (!strstr(line, GLOBAL_END_MARKER)) {
                strtok(line, "\n");
                addNewString(&defVar, line);
                fgets(line, 3999, fin);
            }
            addNewDefinedTypesAndVars(&result, currentLine, defTypes, defVar);
        }
    }
        fclose(fin);
        return result;
}

//list of structs definitions

void freeListOfStructDefinitions(ListOfStructDefinitions ** head) {
    ListOfStructDefinitions * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfStrings(&aux->structDef);
        free(aux->headerDefinition);
        aux->headerDefinition = NULL;
        aux->structDef = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void freeGlobalDeclaration(GlobalDeclarations * head){

    freeListOfStructDefinitions(&((*head).structUnionDeclarations));
    freeListOfStructDefinitions(&((*head).typedefDeclarations));
    freeListOfStructDefinitions(&((*head).normalDeclarations));
    head = NULL;
}

void addNewStructDefinitionAtBeggining(ListOfStructDefinitions ** head, ListOfString * structLOCs,
        char * headerDefinition, char *file) {
    ListOfStructDefinitions * newEl = (ListOfStructDefinitions *) malloc(1 * sizeof (ListOfStructDefinitions));
    newEl->structDef = NULL;

    newEl->structDef = copyCompleteListOfString(structLOCs);

    newEl->headerDefinition = NULL;

    newEl->file = file;

    if (headerDefinition) {
        newEl->headerDefinition = (char *) malloc((strlen(headerDefinition) + 1) * sizeof (char));
        strcpy(newEl->headerDefinition, headerDefinition);
    }

    newEl->next = (*head);
    (*head) = newEl;
}

void addNewStructDefinition(ListOfStructDefinitions ** head, ListOfString * structLOCs,
        char * headerDefinition, char * file, long int line) {
    ListOfStructDefinitions * newEl = (ListOfStructDefinitions *) malloc(1 * sizeof (ListOfStructDefinitions));
    newEl->structDef = NULL;

    newEl->structDef = copyCompleteListOfString(structLOCs);

    newEl->headerDefinition = NULL;
    newEl->occurrenceLine = line;
    newEl->file = file;

    if (headerDefinition) {
        newEl->headerDefinition = (char *) malloc((strlen(headerDefinition) + 1) * sizeof (char));
        strcpy(newEl->headerDefinition, headerDefinition);
    }
    if (file) {
        newEl->file = (char *) malloc((strlen(file) + 1) * sizeof (char));
        strcpy(newEl->file, file);
    }

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfStructDefinitions * p = NULL;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

//search just by looking at the first line, since it should be unique (the name of the struct)

int searchStructInAListOfStruct(ListOfStructDefinitions * head, ListOfString * searchedStruct) {
    ListOfStructDefinitions * aux = head;

    while (aux) {
        if (!strcmp(aux->structDef->el, searchedStruct->el)) {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void addNewListOfStructToAnExistingOne(ListOfStructDefinitions ** destination, ListOfStructDefinitions * source) {
    ListOfStructDefinitions * aux = source;

    while (aux) {
        if (!searchStructInAListOfStruct((*destination), aux->structDef)) {
            addNewStructDefinition(&(*destination), aux->structDef, aux->headerDefinition, aux->file, aux->occurrenceLine);
        }
        aux = aux->next;
    }
}

void addNewListOfStructToAnExistingOneWithNewDefinitionID(ListOfStructDefinitions ** destination, ListOfStructDefinitions * source, int * definitionID, ListOfStructMark **ListOfDeclarationMark) {
    ListOfStructDefinitions * aux = source;

    while (aux) {
        char *formattedNewStructDefinition = (char *) malloc(99999 * sizeof (char));

        fflush(stdout);
        /*keep old Mark */
        char *oldMark = NULL;
        oldMark =  (char *) malloc((strlen(aux->structDef->el) + 10) * sizeof(char *));
        strcpy(oldMark,readSubstring("/* ", aux->structDef->el, " */"));

        /*keep new Mark */
        char * formattedNewMark = NULL;
        formattedNewMark = (char *) malloc(100 * sizeof (char *));

        /*keep old Mark */
        char * formattedOldMark = NULL;
        formattedOldMark = (char *) malloc(100 * sizeof (char *));
        sprintf(formattedOldMark, "/* %s */", oldMark);
        fflush(stdout);
        ListOfString * structDef = NULL;

        if(strstr(aux->structDef->el, GLOBAL_DECL_BEGINNING_MARKER)) {
            sprintf(formattedNewStructDefinition, "%s%d */ %s\n", GLOBAL_DECL_BEGINNING_MARKER, (*definitionID), readSubstring("*/ ", aux->structDef->el, "\n"));
         ///   printf("--> %s\n",formattedNewStructDefinition);
         ///   printf("\n#####> %s\n", aux->structDef->el);
           /// structDef = copyCompleteListOfString(aux->structDef);
            addNewString(&structDef, formattedNewStructDefinition);
          ///  printf("\n%s\n", formattedNewStructDefinition);
            while(aux->structDef->next) {
                aux->structDef = aux->structDef->next;
                addNewString(&structDef, aux->structDef->el);
                aux->structDef->next;
            }
            sprintf(formattedNewMark, "%s%d */", GLOBAL_DECL_BEGINNING_MARKER, (*definitionID));
        }

        if(strstr(aux->structDef->el, ENUM_DECL_BEGINNING_MARKER)) {
            sprintf(formattedNewStructDefinition, "%s_%d */ %s\n", ENUM_DECL_BEGINNING_MARKER, (*definitionID), readSubstring("*/ ", aux->structDef->el, "\n"));
            addNewString(&structDef, formattedNewStructDefinition);
            while(aux->structDef->next) {
                aux->structDef = aux->structDef->next;
                addNewString(&structDef, aux->structDef->el);
                aux->structDef->next;
            }
            sprintf(formattedNewMark, "%s_%d */", ENUM_DECL_BEGINNING_MARKER, (*definitionID));
        }

        if(strstr(aux->structDef->el, STRUCT_DECL_BEGINNING_MARKER)) {
            sprintf(formattedNewStructDefinition, "%s%d */ %s\n", STRUCT_DECL_BEGINNING_MARKER, (*definitionID),
                    readSubstring("*/ ", aux->structDef->el, "\n"));
            addNewString(&structDef, formattedNewStructDefinition);
            while(aux->structDef->next) {
                aux->structDef = aux->structDef->next;
                addNewString(&structDef, aux->structDef->el);
            }
            sprintf(formattedNewMark, "%s%d */", STRUCT_DECL_BEGINNING_MARKER, (*definitionID));
        }

        if(strstr(aux->structDef->el, TYPEDEF_DECL_BEGINNING_MARKER)) {
            sprintf(formattedNewStructDefinition, "%s%d */ %s\n", TYPEDEF_DECL_BEGINNING_MARKER, (*definitionID),
                    readSubstring("*/ ", aux->structDef->el, "\n"));
            addNewString(&structDef, formattedNewStructDefinition);
            while(aux->structDef->next) {
                aux->structDef = aux->structDef->next;
                addNewString(&structDef, aux->structDef->el);
                aux->structDef->next;
            }
            sprintf(formattedNewMark, "%s%d */", TYPEDEF_DECL_BEGINNING_MARKER, (*definitionID));
        }

        addNewStructDefinition(&(*destination), structDef, aux->headerDefinition, aux->file, aux->occurrenceLine);
        addNewStatmentMark(ListOfDeclarationMark, formattedOldMark, formattedNewMark);

        (*definitionID)++;
        freeListOfStrings(&structDef);
        aux = aux->next;
    }
}


//global declarations functions

#define HEADER_DECLARATION_MARKER "HEADER_DECL"
#define FILE_NAME "FILE:"
#define FINISHER "-----------------------------------------"
#define TYPEDEF_STRUCT_MARKER "typedef struct"
#define STRUCT_STATIC "static struct"
#define STRUCT_TYPE "struct"
#define GLOBAL_DECLARATION_MARKER "/* GLOBAL_DECL_"
#define ENUM_DECLARATION_MARKER "/* ENUM_DECL_"

GlobalDeclarations readGlobalDeclarationFromFile(char * inputFile) {
    GlobalDeclarations listOfDecl;

    listOfDecl.normalDeclarations = NULL;
    listOfDecl.structUnionDeclarations = NULL;
    listOfDecl.typedefDeclarations = NULL;

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(100000 * sizeof (char));

    //first for normal marker
    fgets(line, 99999, fin);
    fgets(line, 99999, fin);

    while (strcmp(line, STRUCT_UNION_MARKER)) {

        ListOfString * newStructDef = NULL;
        addNewString(&newStructDef, line);
        fgets(line, 99999, fin);

        char * newHeaderDecl = NULL;
        while (strcmp(line, STRUCT_UNION_MARKER) && !strstr(line, GLOBAL_DECL_BEGINNING_MARKER)
                && !strstr(line, HEADER_DECLARATION_MARKER) && !strstr(line, ENUM_DECL_BEGINNING_MARKER)) {

            addNewString(&newStructDef, line);
            fgets(line, 99999, fin);
          //  if (feof(fin)) break;
        }

        if (strstr(line, HEADER_DECLARATION_MARKER)) {
            fgets(line, 99999, fin);
            if (!strstr(line, GLOBAL_DECL_BEGINNING_MARKER) && !strstr(line, ENUM_DECL_BEGINNING_MARKER)
                    && strcmp(line, STRUCT_UNION_MARKER)) {
                newHeaderDecl = (char *) malloc(99999 * sizeof (char));
                strcpy(newHeaderDecl, line);
                fgets(line, 99999, fin);
            }
        }

        if(strstr(newStructDef->el, ENUM_DECL_BEGINNING_MARKER)){
            char * newHeaderDelNoExtern = NULL;
            newHeaderDelNoExtern = (char *) malloc(400 * sizeof (char));
            strcpy(newHeaderDelNoExtern, readSubstring("*/ ", newStructDef->el, "{"));
            newHeaderDecl = (char *) malloc(99999 * sizeof (char));
            sprintf(newHeaderDecl, "extern %s;\n", newHeaderDelNoExtern);
        }



        addNewStructDefinition(&listOfDecl.normalDeclarations, newStructDef, newHeaderDecl, NULL, 0);


        /*
        char * globalDecl;
                globalDecl = (char *) malloc(20000 * sizeof (char));
                strcpy(globalDecl, line);
                //addNewString(&listOfDecl.normalDeclarations, line);
                fgets(line, 29999, fin);
                fgets(line, 29999, fin);
                char * newHeaderDecl = NULL;
                if (!strstr(line, GLOBAL_DECLARATION_MARKER) && !strstr(line, ENUM_DECLARATION_MARKER) && strcmp(line, STRUCT_UNION_MARKER)) {
                    newHeaderDecl = (char *) malloc(10000 * sizeof (char));
                    strcpy(newHeaderDecl, line);
                    fgets(line, 29999, fin);
                }
                addNewDeclarationWithHeaderDefinition(&listOfDecl.normalDeclarations, globalDecl, newHeaderDecl);
         */
      //  if (feof(fin)) break;
        if (!strcmp(line, TYPEDEF_MARKER))break;
    }

    fgets(line, 99999, fin);
    int structTypeDef = 0;
    while (strcmp(line, TYPEDEF_MARKER)) {
        structTypeDef = 0;
        ListOfString * newStructDef = NULL;
        addNewString(&newStructDef, line);
        char * newHeaderDecl = NULL;

        if(strstr(newStructDef->el,STRUCT_STATIC)){
            printf("STRUCT_STATIC\n");
        }
        if( strstr(newStructDef->el, TYPEDEF_STRUCT_MARKER) || strstr(newStructDef->el, STRUCT_STATIC)) {
            structTypeDef = 1;
        }
        fgets(line, 99999, fin);

        while (strcmp(line, TYPEDEF_MARKER) && !strstr(line, STRUCT_DECL_BEGINNING_MARKER)
                && !strstr(line, HEADER_DECLARATION_MARKER)) {

            addNewString(&newStructDef, line);
            fgets(line, 99999, fin);
            if (feof(fin))
                break;
        }
        if (strstr(line, HEADER_DECLARATION_MARKER)) {
            if (!strstr(line, STRUCT_DECL_BEGINNING_MARKER) && strcmp(line, TYPEDEF_MARKER)) {
                newHeaderDecl = (char *) malloc(99999 * sizeof (char));
                if(structTypeDef == 1){
                    char * lastElementInStruct = returnLastElementInListString(newStructDef);
                    strcpy(newHeaderDecl, readSubstring("} ", lastElementInStruct, "\n"));
                    strcat(newHeaderDecl, ";\n");
                }else {
                   if( strstr(line, HEADER_DECLARATION_MARKER))
                    fgets(line, 99999, fin);

                    if(!strstr(line, STRUCT_DECL_BEGINNING_MARKER) && strcmp(line, TYPEDEF_MARKER)){
                        strcpy(newHeaderDecl, line);
                    } else {
                        strcpy(newHeaderDecl, readSubstring("*/ ", newStructDef->el, " {"));
                        strcat(newHeaderDecl, ";\n");
                    }
                }

            }
        }


        addNewStructDefinition(&listOfDecl.structUnionDeclarations, newStructDef, newHeaderDecl, NULL,0);
        //addNewString(&listOfDecl.structUnionDeclarations, line);
        //fgets(line, 2999, fin);
        if(!strstr(line, STRUCT_DECL_BEGINNING_MARKER) && !strstr(line, TYPEDEF_DECL_BEGINNING_MARKER) && strcmp(line, TYPEDEF_MARKER))
            fgets(line, 99999, fin);

        if (feof(fin)) break;
    }


    char * testEOF = fgets(line, 99999, fin);

    while (testEOF != NULL) {
        ListOfString * newStructDef = NULL;
        addNewString(&newStructDef, line);
        //fgets(line, 2999, fin);
        while ((testEOF = fgets(line, 99999, fin)) && !strstr(line, TYPEDEF_DECL_BEGINNING_MARKER)) {
            addNewString(&newStructDef, line);
            //fgets(line, 2999, fin);
        }
        char * newHeaderDecl = NULL;
        newHeaderDecl = (char *) malloc(99999 * sizeof (char));
        strcpy(newHeaderDecl, readSubstring("*/ ", line, "\n"));
        addNewStructDefinition(&listOfDecl.typedefDeclarations, newStructDef, newHeaderDecl, NULL,0);
        /*
        addNewString(&listOfDecl.typedefDeclarations, line);
         */
        if (feof(fin)) break;
    }

    free(line);

    fclose(fin);
    return listOfDecl;
}


GlobalDeclarations readGlobalDeclarationFromFileWithFile(char * inputFile) {
    GlobalDeclarations listOfDecl;

    listOfDecl.normalDeclarations = NULL;
    listOfDecl.structUnionDeclarations = NULL;
    listOfDecl.typedefDeclarations = NULL;

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(100000 * sizeof (char));

    //first for normal marker
    fgets(line, 99999, fin);
    fgets(line, 99999, fin);


    char * fileName = NULL;
    char * fileMarker = NULL;
    fileName = (char *) malloc(99 * sizeof (char));
    fileMarker = (char *) malloc(99 * sizeof (char));

    while (strcmp(line, STRUCT_UNION_MARKER)) {

        ListOfString *newStructDef = NULL;
        char *newHeaderDecl = NULL;
        if(strcmp(line, STRUCT_UNION_MARKER) && strstr(line, GLOBAL_DECL_BEGINNING_MARKER)
           && !strstr(line, HEADER_DECLARATION_MARKER) && !strstr(line, ENUM_DECL_BEGINNING_MARKER)) {

            addNewString(&newStructDef, line);
            fgets(line, 99999, fin);
            while (strcmp(line, STRUCT_UNION_MARKER) && !strstr(line, GLOBAL_DECL_BEGINNING_MARKER)
                   && !strstr(line, HEADER_DECLARATION_MARKER) && !strstr(line, ENUM_DECL_BEGINNING_MARKER)) {
                addNewString(&newStructDef, line);
                fgets(line, 99999, fin);
            }
        }
        if (strstr(line, ENUM_DECL_BEGINNING_MARKER)) {
            newHeaderDecl = (char *) malloc(99999 * sizeof(char));
            addNewString(&newStructDef, line);
            strcpy(newHeaderDecl, readSubstring("*/ ", newStructDef->el, "{"));
            fgets(line, 99999, fin);
            fgets(line, 99999, fin);
        }

        if (strstr(line, HEADER_DECLARATION_MARKER)) {
            fgets(line, 99999, fin);
            if (!strstr(line, GLOBAL_DECL_BEGINNING_MARKER) && !strstr(line, ENUM_DECL_BEGINNING_MARKER)
                && strcmp(line, STRUCT_UNION_MARKER)) {
                newHeaderDecl = (char *) malloc(99999 * sizeof(char));
                strcpy(newHeaderDecl, line);
                fgets(line, 99999, fin);
            }
        }

        if (strstr(line, FILE_NAME)) {
            sscanf(line, "%s %s", fileMarker, fileName);
        }

        if(newStructDef != NULL && newHeaderDecl != NULL && strcmp(fileName,""))
            addNewStructDefinition(&listOfDecl.normalDeclarations, newStructDef, newHeaderDecl, fileName, 0);

        while (fgets(line, 99999, fin) != NULL && !strstr( line, FINISHER)){
        }
        fgets(line, 99999, fin);
    }

    fgets(line, 99999, fin);
    while (strcmp(line, TYPEDEF_MARKER)) {
        ListOfString *newStructDef = NULL;

        char *newHeaderDecl = NULL;
        if (strstr(line, STRUCT_DECL_BEGINNING_MARKER) && strcmp(line, TYPEDEF_MARKER)) {
            //addNewString(&newStructDef, line);
            while (strcmp(line, TYPEDEF_MARKER) && !strstr(line, HEADER_DECLARATION_MARKER)) {
                addNewString(&newStructDef, line);
                fgets(line, 99999, fin);
            }
        }

        if (strstr(line, HEADER_DECLARATION_MARKER)) {
            fgets(line, 99999, fin);
            newHeaderDecl = (char *) malloc(99999 * sizeof (char));
            strcpy(newHeaderDecl, line);
            if (!strstr(line, STRUCT_DECL_BEGINNING_MARKER) && strcmp(line, TYPEDEF_MARKER)) {
                newHeaderDecl = (char *) malloc(99999 * sizeof (char));
                strcpy(newHeaderDecl, line);
                fgets(line, 99999, fin);
            }
        }

        if(strstr(line, FILE_NAME)){
            sscanf(line, "%s %s", fileMarker, fileName);
        }

        if(newStructDef != NULL && newHeaderDecl != NULL && strcmp(fileName,""))
            addNewStructDefinition(&listOfDecl.structUnionDeclarations, newStructDef, newHeaderDecl, fileName,0);

        while (fgets(line, 99999, fin) != NULL && !strstr( line, FINISHER)){
        }
        fgets(line, 99999, fin);
        if (feof(fin)) break;
    }


   // char * testEOF = fgets(line, 99999, fin);

    while (fgets(line, 99999, fin)) {
        ListOfString * newStructDef = NULL;
        if (strstr(line, TYPEDEF_DECL_BEGINNING_MARKER)) {
            addNewString(&newStructDef, line);
            while (fgets(line, 99999, fin) != NULL && !strstr(line, FILE_NAME)) {
                addNewString(&newStructDef, line);
            }
        }
        char * newHeaderDecl = NULL;
       // newHeaderDecl = (char *) malloc(99999 * sizeof (char));
       // strcpy(newHeaderDecl, readSubstring("*/ ", line, "\n"));
       // fgets(line, 99999, fin);
        if(strstr(line, FILE_NAME)){
            sscanf(line, "%s %s", fileMarker, fileName);
        }

        if(newStructDef!= NULL && newHeaderDecl!= NULL && strcmp(fileName,""))
            addNewStructDefinition(&listOfDecl.typedefDeclarations, newStructDef, newHeaderDecl, fileName,0);

        while (fgets(line, 99999, fin) != NULL && !strstr( line, FINISHER)){}
    }

    free(line);

    fclose(fin);
    return listOfDecl;
}

//Return the line of occorence of a string in a file
int searchOccurrenceOfStringInAFileLine(char *filePath, char searchedEl){

    ListOfString * sourceInList = readListOfStringFromFile(filePath);
    int line = 0;
    while (sourceInList) {
        if (strstr(sourceInList->el, searchedEl)){
            return line+1;
        }
            line++;
            sourceInList = sourceInList->next;
    }
}

//Return the line of occorence of a string in a file
ListOfString *  readListOccurrenceOfStringInAFileLine(char *filePath, char searchedEl){

    ListOfString * sourceInList = readListOfStringFromFile(filePath);
    int line = 0;
    while (sourceInList) {
        if (strstr(sourceInList->el, searchedEl)){
            return line+1;
        }
            line++;
            sourceInList = sourceInList->next;
    }
}

void addFileNameInGlobalDeclarations( ListOfStructDefinitions * destination, char * inputFileName) {
    ListOfStructDefinitions * aux = destination;
    while (aux) {
        aux->file = (char *) malloc((strlen(inputFileName) + 1) * sizeof(char));
        strcpy(aux->file, inputFileName);

        aux = aux->next;
    }
}


int isSubstring(char * s1, char * s2)
{
    int lenM = strlen(s1);
    int lenN = strlen(s2);

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= lenN - lenM; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < lenM; j++)
            if (s2[i + j] != s1[j])
                if (s2[i + j] != '\n' && s2[i + j] != '{'  && s2[i + j] != ' ' && s1[j] != '\n' && s1[j] != '{' && s1[j] != ' ' )
                    break;

        if (j == lenM)
            return i;
    }

    return -1;
}

void addOccurrenceLineInGlobalDeclarations( ListOfStructDefinitions * destination, char * inputFileName) {

    ListOfString *occurrenceList = readListOfStringFromFile(readSubstring("\"", inputFileName, "\""));
    ListOfString *auxOccurenceList = occurrenceList;
    ListOfString *occurenceListWithoutSpace = NULL;

    while(auxOccurenceList) {
        char * str = removeSpaceInString(auxOccurenceList->el);
        addNewString(&occurenceListWithoutSpace, str);
        auxOccurenceList = auxOccurenceList->next;
    }

    ListOfStructDefinitions *globalDeclarations = destination;

    ListOfString *auxOccurrenceListWithoutSpac = NULL;

    int signal = 0;
    while (globalDeclarations) {
        auxOccurrenceListWithoutSpac = occurenceListWithoutSpace;
        long int line = 0;
        char *globalDecl = NULL;
        //TODO LOS Improve
        if (strstr(globalDeclarations->structDef->el, TYPEDEF_STRUCT_MARKER)) {
            ListOfString * ListTypedefStructDeclaration = globalDeclarations->structDef;

            while (ListTypedefStructDeclaration->next)
                ListTypedefStructDeclaration = ListTypedefStructDeclaration->next;

            fflush(stdout);
            globalDecl = (char *) malloc((strlen(ListTypedefStructDeclaration->el) + 1) * sizeof(char));
            strcpy(globalDecl, ListTypedefStructDeclaration->el);
        }else {
            globalDecl = (char *) malloc((strlen(globalDeclarations->structDef->el) + 1) * sizeof(char));
            strcpy(globalDecl, readSubstring("*/ ", globalDeclarations->structDef->el, "\n"));
        }

        while (auxOccurrenceListWithoutSpac && signal == 0) {
            fflush(stdout);
            char * sourceLine = NULL;
                    sourceLine = (char *) malloc((strlen(auxOccurrenceListWithoutSpac->el) + 1) * sizeof(char));
            strcpy(sourceLine, auxOccurrenceListWithoutSpac->el);
           // printf("%s",sourceLine);
            strtok(globalDecl, "\n");
            strtok(globalDecl, "{");

          //  sourceLine = strtok(sourceLine, "\n");
         //   sourceLine = strtok(sourceLine, "{");
          //  sourceLine = strtok(sourceLine, " ");

            // if (!strncmp(globalDecl,sourceLine,5) || !strncmp(sourceLine,globalDecl,5)) {
            if (strstr(globalDecl,sourceLine) || strstr(sourceLine,globalDecl)) {
            //if(isSubstring(globalDecl, sourceLine) != -1 || isSubstring(sourceLine, globalDecl) != -1){
                line++;
                globalDeclarations->occurrenceLine = line;
                signal = 1;
            }
            line++;
            auxOccurrenceListWithoutSpac = auxOccurrenceListWithoutSpac->next;
        }
        signal = 0;
        globalDeclarations = globalDeclarations->next;
    }

}

void addOccurrenceLine( ListOfStructDefinitions * destination, char * inputFileName) {
    ListOfStructDefinitions * aux = destination;
    while (aux) {
        aux->file = (char *) malloc((strlen(inputFileName) + 1) * sizeof(char));
        strcpy(aux->file, inputFileName);

        aux = aux->next;
    }
}

void addFileNameInListOfFinalGlobalDeclarations(char * directory, GlobalDeclarations * destination, char * inputFile) {

    /* Keep only fine name*/
    char *inputFileName = (char *) malloc((strlen(inputFile) + 1) * sizeof(char));
    if(strstr(inputFile,".h")){
        strcpy(inputFileName, readSubstring(directory, inputFile, ".h"));
        strcat(inputFileName,".h");
    }
    else
    if(strstr(inputFile,".c")){
        strcpy(inputFileName, readSubstring(directory, inputFile, ".c"));
        strcat(inputFileName,".c");
    }
    else {
        printf("ERRO: File type does not expected!!\n");
        return;
    }
    fflush(stdout);

    /* LOS Insert file name into normalDeclarations from ListOfFinalGlobalDeclarations */
    ListOfStructDefinitions * listOfNormalDeclarations = destination->normalDeclarations;
    addFileNameInGlobalDeclarations(listOfNormalDeclarations, inputFileName);
    //addOccurrenceLine( listOfNormalDeclarations, inputFile);
    addOccurrenceLineInGlobalDeclarations( listOfNormalDeclarations, inputFile);

    /* LOS Insert file name into structUnionDeclarations from ListOfFinalGlobalDeclarations */
    ListOfStructDefinitions * listOfStructUnionDeclarations = destination->structUnionDeclarations;
    addFileNameInGlobalDeclarations(listOfStructUnionDeclarations, inputFileName);
    addOccurrenceLineInGlobalDeclarations( listOfNormalDeclarations, inputFile);

    /* LOS Insert file name into typedefDeclarations from ListOfFinalGlobalDeclarations */
    ListOfStructDefinitions * listOfTypedefDeclarations = destination->typedefDeclarations;
    addFileNameInGlobalDeclarations(listOfTypedefDeclarations, inputFileName);
    addOccurrenceLineInGlobalDeclarations( listOfNormalDeclarations, inputFile);

}


void addFileNameInListOfFinalGlobalDeclarations1(GlobalDeclarations * destination, char * inputFile) {

    /* LOS Insert file name into normalDeclarations from ListOfFinalGlobalDeclarations */
    ListOfStructDefinitions * listOfNormalDeclarations = destination->normalDeclarations;
    addFileNameInGlobalDeclarations(listOfNormalDeclarations, inputFile);

    /* LOS Insert file name into structUnionDeclarations from ListOfFinalGlobalDeclarations */
    ListOfStructDefinitions * listOfStructUnionDeclarations = destination->structUnionDeclarations;
    addFileNameInGlobalDeclarations(listOfStructUnionDeclarations, inputFile);

    /* LOS Insert file name into typedefDeclarations from ListOfFinalGlobalDeclarations */
    ListOfStructDefinitions * listOfTypedefDeclarations = destination->typedefDeclarations;
    addFileNameInGlobalDeclarations(listOfTypedefDeclarations, inputFile);

    fflush(stdout);

}


#ifdef MULTIFILE_VAR_EXTRACTION


void insertFileNameIntoListOfFinalGlobalDeclarations1( ListOfStructDefinitions * head, char * inputFile) {


    char *inputHeaderFileName = (char *) malloc((strlen(inputFile) + 1) * sizeof(char));
    if(strstr(inputFile,".h")){
        strcpy(inputHeaderFileName, readSubstring(donorSourceFileFolder, inputFile, ".h"));
        strcat(inputHeaderFileName,".h");
    }
    else
    if(strstr(inputFile,".c")){
        strcpy(inputHeaderFileName, readSubstring(donorSourceFileFolder, inputFile, ".c"));
        strcat(inputHeaderFileName,".c");
    }
    else {
        printf("ERRO: File type does not expected!!\n");
        return;
    }
    fflush(stdout);

    /* LOS Insert file name into normalDeclarations from ListOfFinalGlobalDeclarations */
    while (head) {
        strcpy(head->file, inputHeaderFileName);
        head = head->next;
    }



}

void insertFileNameIntoListOfFinalGlobalDeclarations( ListOfStructDefinitions * source, ListOfStructDefinitions * destination, char * inputFile) {


    char *inputHeaderFileName = (char *) malloc((strlen(inputFile) + 1) * sizeof(char));
    if(strstr(inputFile,".h")){
        strcpy(inputHeaderFileName, readSubstring(donorSourceFileFolder, inputFile, ".h"));
        strcat(inputHeaderFileName,".h");
    }
    else
        if(strstr(inputFile,".c")){
            strcpy(inputHeaderFileName, readSubstring(donorSourceFileFolder, inputFile, ".c"));
            strcat(inputHeaderFileName,".c");
    }
    else {
            printf("ERRO: File type does not expected!!\n");
            return;
        }
    fflush(stdout);

    ListOfStructDefinitions * sourceVar;
    ListOfStructDefinitions * listOfVarDestiantion;
    listOfVarDestiantion  = destination;
    /* LOS Insert file name into normalDeclarations from ListOfFinalGlobalDeclarations */
    while (listOfVarDestiantion) {
        int equal = 0;
     //   printf("destinationVar %s, (*destination) %s\n", destinationVar->structDef, (**destination) );
        char *currentDeclaration = NULL;
        currentDeclaration = (char *) malloc((strlen(listOfVarDestiantion->structDef->el) + 1) * sizeof(char));

        strcpy(currentDeclaration, listOfVarDestiantion->structDef->el);

        char * formattedFinalDeclaration = (char *) malloc(
                (strlen(listOfVarDestiantion->structDef->el) + 1) * sizeof(char));

        strcpy(formattedFinalDeclaration,readSubstring( "*/ ",currentDeclaration,"\n"));


        sourceVar = source;
    /*    ListOfString *listOfVarSource = NULL;
        if(sourceVar->structDef != NULL) {
            listOfVarSource = sourceVar->structDef;
        }*/

        while (sourceVar) {
            fflush(stdout);
            char * formattedCurrentDeclaration = (char *) malloc(
                    (strlen(sourceVar->structDef->el) + 1) * sizeof(char));

            strcpy(formattedCurrentDeclaration, readSubstring( "*/ ",sourceVar->structDef->el,"\n"));

            if (!strcmp(formattedCurrentDeclaration, formattedFinalDeclaration)) {
                equal = 1;
                ListOfString * structDefVarDest = listOfVarDestiantion->structDef;
                ListOfString * structDefVarSource = sourceVar->structDef;
                structDefVarDest = structDefVarDest->next;
                structDefVarSource = structDefVarSource->next;

                while(structDefVarDest && structDefVarDest && equal == 1){

                    if(strcmp(structDefVarDest->el,structDefVarSource->el ))
                        equal = 0;

                    structDefVarDest = structDefVarDest->next;
                    structDefVarSource = structDefVarSource->next;

                    if(!structDefVarDest || !structDefVarDest)
                        equal = 0;

                }
                if(equal == 1) {
                    listOfVarDestiantion->file = (char *) malloc((strlen(inputHeaderFileName) + 1) * sizeof(char));
                    strcpy(listOfVarDestiantion->file, inputHeaderFileName);
                }
            }
            sourceVar = sourceVar->next;

        }

        listOfVarDestiantion = listOfVarDestiantion->next;
    }


/*
    /* LOS Insert file name into structUnionDeclarations from ListOfFinalGlobalDeclarations
    while (ListOfFinalGlobalDeclarations->typedefDeclarations) {
        char *currentDeclaration = NULL;
        currentDeclaration = (char *) malloc(
                (strlen(ListOfFinalGlobalDeclarations->typedefDeclarations->structDef->el) + 1) * sizeof(char));

        strcpy(currentDeclaration, ListOfFinalGlobalDeclarations->typedefDeclarations->structDef->el);

        char * formattedFinalDeclaration = (char *) malloc(
                (strlen(ListOfFinalGlobalDeclarations->typedefDeclarations->structDef->el) + 1) * sizeof(char));
*/
 //       strcpy(formattedFinalDeclaration,readSubstring( "*/ ",currentDeclaration,"\n"));
/*
        ListOfString *listOfTypedefDeclarations = NULL;
        if(ListOfCurrentGlobalDeclarations.typedefDeclarations != NULL) {
            ListOfString *listOfTypedefDeclarations = ListOfCurrentGlobalDeclarations.typedefDeclarations->structDef;
        }

        while (listOfTypedefDeclarations) {
            fflush(stdout);
            char * formattedCurrentDeclaration = (char *) malloc(
                    (strlen(listOfTypedefDeclarations->el) + 1) * sizeof(char));
*/
//            strcpy(formattedCurrentDeclaration, readSubstring( "*/ ",listOfTypedefDeclarations->el,"\n"));
/*
            if (!strcmp(formattedCurrentDeclaration, formattedFinalDeclaration)) {

                ListOfFinalGlobalDeclarations->typedefDeclarations->file = (char *) malloc(100 * sizeof(char));
                strcpy(ListOfFinalGlobalDeclarations->typedefDeclarations->file, inputFile);
            }
            listOfTypedefDeclarations = listOfTypedefDeclarations->next;
        }

        ListOfFinalGlobalDeclarations->typedefDeclarations = ListOfFinalGlobalDeclarations->typedefDeclarations->next;
    }

    /* LOS Insert file name into normalDeclarations from ListOfFinalGlobalDeclarations
    while (ListOfFinalGlobalDeclarations->structUnionDeclarations) {
        char *currentDeclaration = NULL;
        currentDeclaration = (char *) malloc(
                (strlen(ListOfFinalGlobalDeclarations->structUnionDeclarations->structDef->el) + 1) * sizeof(char));

        strcpy(currentDeclaration, ListOfFinalGlobalDeclarations->structUnionDeclarations->structDef->el);

        char * formattedFinalDeclaration = (char *) malloc(
                (strlen(ListOfFinalGlobalDeclarations->structUnionDeclarations->structDef->el) + 1) * sizeof(char));
*/
//        strcpy(formattedFinalDeclaration,readSubstring( "*/ ",currentDeclaration,"\n"));
/*
        ListOfString *listOfStructUnionDeclarations = ListOfCurrentGlobalDeclarations.structUnionDeclarations->structDef;

        while (listOfStructUnionDeclarations) {
            fflush(stdout);
            char * formattedCurrentDeclaration = (char *) malloc(
                    (strlen(listOfStructUnionDeclarations->el) + 1) * sizeof(char));
*/
   //         strcpy(formattedCurrentDeclaration, readSubstring( "*/ ",listOfStructUnionDeclarations->el,"\n"));

      //      if (!strcmp(formattedCurrentDeclaration, formattedFinalDeclaration)) {

      /*          ListOfFinalGlobalDeclarations->structUnionDeclarations->file = (char *) malloc(100 * sizeof(char));
                strcpy(ListOfFinalGlobalDeclarations->structUnionDeclarations->file, inputFile);
            }
            listOfStructUnionDeclarations = listOfStructUnionDeclarations->next;
        }

        ListOfFinalGlobalDeclarations->structUnionDeclarations = ListOfFinalGlobalDeclarations->structUnionDeclarations->next;
    }
*/
}
#endif


void extractAllGlobalDeclStructAndTypedefDefinitionsToInterface(char * sourceAndHeaderFileNames,
                                                     char * outputFile, char * tempGlobalDependencies, char * tempGlobalTypeVarDeclaration,
                                                     char * ifdefFile, char * TXLProgsPath, char * tempDefinesFile, char * tempIncludeLibFile,
                                                     char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput) {
/*
    char * line;
    line = (char *) malloc(400 * sizeof(char));
    char * currentFile;
    currentFile = (char *) malloc(2000 * sizeof(char));

    FILE * fin = fopen(sourceAndHeaderFileNames, "r");

    char * tempSourceHeaderFileIntDonor;
    tempSourceHeaderFileIntDonor = (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceHeaderFileIntDonor, "%stemp_source_header_file_int_donor.out", TXLTemporaryMultiFileFolder);

    while (fgets(line, 400, fin) != NULL) {
        FILE *fout = fopen(tempSourceHeaderFileIntDonor, "w");
        fprintf(fout, "%s", line);
        fclose(fout);
*/
    fflush(stdout);
    char * commandTXL;
    commandTXL = (char *) malloc(3000 * sizeof (char));
    printf("[TXL] ExtractGlobalDefinitionStructDeclarations.x >> Extract global definition struct declarations\n");
    sprintf(commandTXL, "%sExtractGlobalDefinitionStructDeclarations.x %s %s %s %s %s %s %s %s %s %s", TXLProgsPath, sourceAndHeaderFileNames,
            outputFile, tempGlobalDependencies, tempGlobalTypeVarDeclaration, ifdefFile, tempDefinesFile,
            tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, ConsoleStderrOutput);
    int status = system(commandTXL);

    if (status != 0) {
        printf("ERROR! ExtractGlobalDefinitionStructDeclarations.x\n");
        printf("\t Command: %s\n",commandTXL);
        exit(1);
    }
    /*  else {
          addLinesFromTempIntoDestinationFile(tempGlobalDependencies,
                                              "Transplant-mytar/Temp/2temp_global_dependencies.out");
          addLinesFromTempIntoDestinationFile(tempGlobalTypeVarDeclaration,
                                              "Transplant-mytar/Temp/2temp_global_type_var_declarations.out");
          addLinesFromTempIntoDestinationFile(tempDefinesFile,
                                              "Transplant-mytar/Temp/2temp_define_file.out");
          addLinesFromTempIntoDestinationFile(tempIncludeLibFile,
                                              "Transplant-mytar/Temp/2temp_include_lib_file.out");
          addLinesFromTempIntoDestinationFile(GlobalFctDependOutput,
                                              "Transplant-mytar/Temp/2temp_needed_functions_for_global_declarations.out");
      }*/
    free(commandTXL);
    // }

}


void extractAllGlobalDeclStructAndTypedefDefinitions(char * sourceAndHeaderFileNames,
                                                     char * outputFile, char * tempGlobalDependencies, char * tempGlobalTypeVarDeclaration,
                                                     char * ifdefFile, char * TXLProgsPath, char * tempDefinesFile, char * tempIncludeLibFile,
                                                     char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput) {
    printf("\tExtract Global Definition Struct Declarations\n");
    char *commandTXL;
    commandTXL = (char *) malloc(3000 * sizeof(char));
    sprintf(commandTXL,
            "%sExtractGlobalDefinitionStructDeclarations.x %s %s %s %s %s %s %s %s %s > /dev/null 2> ErrorFile.out",
            TXLProgsPath, sourceAndHeaderFileNames,
            outputFile, tempGlobalDependencies, tempGlobalTypeVarDeclaration, ifdefFile, tempDefinesFile,
            tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, ConsoleNullOutput);
    printf("\t\t[TXL] ExtractGlobalDefinitionStructDeclarations.x\n");
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! ExtractGlobalDefinitionStructDeclarations.x\n");
        system("open ErrorFile.out");
        exit(1);
    }
#ifdef DEBUGING
    else{
        printf("\t\t|>> temp_include_lib_file.out\n");
        printf("\t\t|>> temp_define_file.out\n");
        printf("\t\t|>> temp_global_type_var_declarations.out\n");
        printf("\t\t|>> temp_global_dependencies.out\n");
        printf("\t\t|>> temp_needed_functions_for_global_declarations.out\n");
        printf("\t\t|>> temp_global_defs_output.out\n");
    }
#endif


    free(commandTXL);
}

void extractAllLocalIncludesDefinitions(char * sourceAndHeaderFileNames, char * TXLProgsPath, char * tempIncludeLibFile,
                                                              char * AllDefinedFunctionsInDonor) {

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(1000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

/*LOSTXL included to generate list of local includes necessary to multiheader files implementation */
    fflush(stdout);
    char * commandTXLExtractLocalIncludes;
    commandTXLExtractLocalIncludes = (char *) malloc(3000 * sizeof (char));
    printf("--------------------------------------\n[TXL] ExtractLocalIncludes.x >> Extract local includes declarations\n");
    sprintf(commandTXLExtractLocalIncludes, "%sExtractLocalIncludes.x %s %s %s %s %s", TXLProgsPath, sourceAndHeaderFileNames,
            txlIfDefProg,
            tempIncludeLibFile, AllDefinedFunctionsInDonor, ConsoleStderrOutput);
    int statusCommandTXLExtractLocalIncludes = system(commandTXLExtractLocalIncludes);
    if (statusCommandTXLExtractLocalIncludes != 0) {
        printf("ERROR! ExtractLocalIncludes.x\n");
        printf("\t Command: %s\n",commandTXLExtractLocalIncludes);
        //exit(1);
    }
    free(commandTXLExtractLocalIncludes);

}

void extractAllGlobalDeclStructAndTypedefDefinitionsFromOrgan(char * sourceAndHeaderFileNames,
        char * outputFile, char * tempGlobalDependencies, char * tempGlobalTypeVarDeclaration,
        char * ifdefFile, char * TXLProgsPath, char * tempDefinesFile, char * tempIncludeLibFile,
        char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput) {

    char * commandTXL;
    commandTXL = (char *) malloc(2000 * sizeof (char));
#ifdef DEBUGING
    printf("\t\t[TXL] ExtractGlobalDefinitionStructDeclarationsFromOrgan.x >> Extract global definition struct declarations\n");
#endif
    sprintf(commandTXL, " ulimit -s 65353 && %sExtractGlobalDefinitionStructDeclarations.x %s %s %s %s %s %s %s %s %s %s", TXLProgsPath, sourceAndHeaderFileNames,
            outputFile, tempGlobalDependencies, tempGlobalTypeVarDeclaration, ifdefFile, tempDefinesFile,
            tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! ExtractGlobalDefinitionStructDeclarations.x\n");
        printf("\t Command: %s\n",commandTXL);
        exit(1);
    }

    free(commandTXL);
}
/*
void extractAllGlobalDeclStructAndTypedefDefinitions(char * sourceAndHeaderFileNames,
                                                     char * outputFile, char * tempGlobalDependencies, char * tempGlobalTypeVarDeclaration,
                                                     char * ifdefFile, char * TXLProgsPath, char * tempDefinesFile, char * tempIncludeLibFile,
                                                     char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput) {
/*
    char * line;
    line = (char *) malloc(400 * sizeof(char));
    char * currentFile;
    currentFile = (char *) malloc(2000 * sizeof(char));

    FILE * fin = fopen(sourceAndHeaderFileNames, "r");

    char * tempSourceHeaderFileIntDonor;
    tempSourceHeaderFileIntDonor = (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceHeaderFileIntDonor, "%stemp_source_header_file_int_donor.out", TXLTemporaryMultiFileFolder);

    while (fgets(line, 400, fin) != NULL) {
        FILE *fout = fopen(tempSourceHeaderFileIntDonor, "w");
        fprintf(fout, "%s", line);
        fclose(fout);

    fflush(stdout);
    char * commandTXL;
    commandTXL = (char *) malloc(3000 * sizeof (char));
    printf("[TXL] ExtractGlobalDefinitionStructDeclarations.x >> Extract global definition struct declarations\n");
    sprintf(commandTXL, "%sExtractGlobalDefinitionStructDeclarations.x %s %s %s %s %s %s %s %s %s %s", TXLProgsPath, sourceAndHeaderFileNames,
            outputFile, tempGlobalDependencies, tempGlobalTypeVarDeclaration, ifdefFile, tempDefinesFile,
            tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, ConsoleStderrOutput);
    int status = system(commandTXL);

    if (status != 0) {
        printf("ERROR! ExtractGlobalDefinitionStructDeclarations.x\n");
        printf("\t Command: %s\n",commandTXL);
        exit(1);
    }
    /*  else {
          addLinesFromTempIntoDestinationFile(tempGlobalDependencies,
                                              "Transplant-mytar/Temp/2temp_global_dependencies.out");
          addLinesFromTempIntoDestinationFile(tempGlobalTypeVarDeclaration,
                                              "Transplant-mytar/Temp/2temp_global_type_var_declarations.out");
          addLinesFromTempIntoDestinationFile(tempDefinesFile,
                                              "Transplant-mytar/Temp/2temp_define_file.out");
          addLinesFromTempIntoDestinationFile(tempIncludeLibFile,
                                              "Transplant-mytar/Temp/2temp_include_lib_file.out");
          addLinesFromTempIntoDestinationFile(GlobalFctDependOutput,
                                              "Transplant-mytar/Temp/2temp_needed_functions_for_global_declarations.out");
      }
    free(commandTXL);
    // }

}*/



#if 0  /* MULTIFILES */
void extractAllGlobalDeclStructAndTypedefDefinitionsMultiFiles(char * sourceAndHeaderFileTargetNames,
                                                               char * outputFile, char * tempGlobalDependencies, char * tempGlobalTypeVarDeclaration,
                                                                 char * ifdefFile, char * TXLProgsPath, char * tempDefinesFile, char * tempIncludeLibFile,
                                                                 char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput){


    /* LOS: temporary source output file */
  /*  char * tempSourceHeaderOutputFile;
    tempSourceHeaderOutputFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceHeaderOutputFile, "%stemp_source_and_header_file_target.out", TXLTemporaryMultiFileFolder);

    char * currentFct;
    currentFct = (char *) malloc(400 * sizeof(char));
    char * line;
    line = (char *) malloc(400 * sizeof(char));

    /* LOS: read temp list of source and header files */
  //  FILE * fin = fopen(sourceAndHeaderFileTargetNames, "r");

    char * commandTXL;
    commandTXL = (char *) malloc(3000 * sizeof (char));

/*    while (fgets(line, 400, fin) != NULL) {
        sscanf(line, "%s", currentFct);

        /* LOS: write source file and header by file in tempSourceFile */
/*        FILE *fout = fopen(tempSourceHeaderOutputFile, "w");
        fprintf(fout, "%s", currentFct);
        fclose(fout);
*/
        sprintf(commandTXL, "%sExtractGlobalDefinitionStructDeclarations.x %s %s %s %s %s %s %s %s %s %s", TXLProgsPath, sourceAndHeaderFileTargetNames,
                outputFile, tempGlobalDependencies, tempGlobalTypeVarDeclaration, ifdefFile, tempDefinesFile,
                tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, ConsoleNullOutput);
        int status = system(commandTXL);
        if (status != 0) {
            printf("ERROR during the extractraction of all global declaration structure and typedef definitions by source file! commandTXL to run ExtractGlobalDefinitionStructDeclarations.x\n");
        }

    //}

   // fclose(fin);

    free(commandTXL);
}
#endif



#ifdef SEARCH_VAR_UNION



GlobalDeclarations extractNeededGlobalDeclarationsDependencies(ListOfString * SelectedMarkers,
                                                              GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                              DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals) {

    //Mapped declarations are globals which are mapped to the values in the host
    //these are not used for the moment
    ListOfString * MappedDeclarations = NULL;
    ListOfString * GlobalMarkersForTransplant = NULL;
    DependencyList * AllGlobalDependencies = NULL;
    //addDependencyListToAnExistingOne(&AllGlobalDependencies, SkeletonDependenciesOnGlobals);
    //addDependencyListToAnExistingOne(&AllGlobalDependencies, GlobalDependencyList);
    addDependencyListToAnExistingOne(&AllGlobalDependencies, SkeletonDependenciesOnGlobals);
    addDependencyListToAnExistingOne(&AllGlobalDependencies, GlobalDependencyList);

    //first create the initial list of needed global markers, by the list of all
    //needed markers from the selected LOCs of the Skeleton
    ListOfString * auxSelectedMarkers = SelectedMarkers;
    while (auxSelectedMarkers) {
        ListOfString * neededDepsForCurrent = NULL;
        if(auxSelectedMarkers->el)
            neededDepsForCurrent = returnDependencyForAMarkerNewPointers(AllGlobalDependencies, auxSelectedMarkers->el);

        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            while (auxListString) {
                if (!searchStringInListOfStrings(MappedDeclarations, auxListString->el) &&
                    !searchStringInListOfStrings(GlobalMarkersForTransplant, auxListString->el)) {
                    addNewString(&GlobalMarkersForTransplant, auxListString->el);
                }
                auxListString = auxListString->next;
            }
            freeListOfStrings(&neededDepsForCurrent);
        }
        fflush(stdout);
        auxSelectedMarkers = auxSelectedMarkers->next;
    }
    ListOfString * auxNeededMarkers = GlobalMarkersForTransplant;
    //for all added line markers, add the one from dependency, if they are not mapped
    while (auxNeededMarkers) {
        //memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
        ListOfString * neededDepsForCurrent = returnDependencyForAMarkerNewPointers(AllGlobalDependencies,
                                                                                    auxNeededMarkers->el);
        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            while (auxListString) {
                if (!searchStringInListOfStrings(GlobalMarkersForTransplant, auxListString->el)) {
                    addNewString(&GlobalMarkersForTransplant, auxListString->el);
                }
                auxListString = auxListString->next;
            }
            //LOSCHANGE
            // freeListOfStrings(&neededDepsForCurrent);
        }
        auxNeededMarkers = auxNeededMarkers->next;
    }

    //temporary add all the global declarations!!!

    // TODO: CHECK HERE
    GlobalDeclarations NeededGlobalDeclarations = returnMarkerGlobalDeclaration(ListOfFinalGlobalDeclarations,
                                                                                GlobalMarkersForTransplant);

    //printListOfGlobalDeclarations(NeededGlobalDeclarations, "/home/---/workspace/testGLOBALSnewSource.out",
    // "/home/---/workspace/testGLOBALSnewHeader.out");


    return NeededGlobalDeclarations;

}

// TODO rewrite this funcition to MULTIFILE
void extractNeededGlobalDeclarations(
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList,
        DependencyList * DependencyListGlobalCoreFunctions,
        ListOfString * ListOfSelectedFunctionNames,
        char * tempSourceCodeGlobalsContent) {


    GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
            extractNeededGlobalDeclarationsDependencies(
                    ListOfSelectedFunctionNames, ListOfFinalGlobalDeclarations,
                    GlobalDependencyList, DependencyListGlobalCoreFunctions);

    GlobalDeclarations GlobalNeededCoreAndSkeleton;
    GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
    GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
    GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;

    addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
                                          AllGlobalNeededDeclarationsCoreFunctions);

   /* printListOfGlobalDeclarations2(GlobalNeededCoreAndSkeleton,
                                   tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);*/


    char * tempListOfVarsExtracted;
    tempListOfVarsExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfVarsExtracted, "%stemp_list_of_vars_extracted.out",
            TempVeinDirectory);

    printAllListOfGlobalDeclarationsExtracted(GlobalNeededCoreAndSkeleton,
                                              tempListOfVarsExtracted);

    addLocsFromSourceToDestination(tempSourceCodeGlobalsContent, tempListOfVarsExtracted, TXLToolsPath);


}

ListOfString * extractDependenciesMarkers(DependencyList * GlobalDependencies ){

    DependencyList * AuxGlobalDependencies = GlobalDependencies;

    ListOfString * ListOfDeclarationsDependencies = NULL;
    char * currentStatement;
    currentStatement = (char*) malloc(10000 * sizeof (char));
    while (AuxGlobalDependencies) {
        strcpy(currentStatement, AuxGlobalDependencies->Statement);
        addNewString(&ListOfDeclarationsDependencies, currentStatement);

        AuxGlobalDependencies = AuxGlobalDependencies->next;
    }
    free(currentStatement);
    return ListOfDeclarationsDependencies;
}






void printListOfGlobalDependencies(GlobalDeclarations ListOfFinalGlobalDeclarations, char * listOfAllGlobalExtracted, char * definedGlobalTypesAndVariablesFile, char * tempGlobalDependencies){

    ListOfDefinedTypesAndVars * GlobalTypeAndVarDependencyList = readDependencyListFromFile(definedGlobalTypesAndVariablesFile);

    DependencyList * GlobalDependencies = readDependencyListFromFile(
            tempGlobalDependencies);

    ListOfString * FinalListOfTransplantedGlobalVarAsMarkers = extractDependenciesMarkers(GlobalDependencies );

    ListOfString * globalTypeAndVariable = readListOfStringFromFile(definedGlobalTypesAndVariablesFile);

/* TODO HOJE   extractNeededGlobalDeclarations(
            ListOfFinalGlobalDeclarations, GlobalTypeAndVarDependencyList,
            GlobalDependencies,
            FinalListOfTransplantedGlobalVarAsMarkers,
            listOfAllGlobalExtracted, listOfAllGlobalExtracted);*/
}

#endif


void extractDefinitionsToInterfaceHeader( char * currentSourceFile, char * sourceFileTargetNames, char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                   char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder) {

    /* temp global dependencies: temp_global_dependencies.out */
    char * tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryMultiFileFolder);

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(1000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput;
    tempGlobalDefsOutput = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryMultiFileFolder);

    /* temp global type variable declarations: temp_global_type_var_declarations.out */
    char *definedGlobalTypesAndVariablesFile;
    definedGlobalTypesAndVariablesFile = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryMultiFileFolder);

    sprintf(GlobalFctDependOutput, "%stemp_needed_functions_for_global_declarations.out",
            TXLTemporaryMultiFileFolder);

    fflush(stdout);

    extractAllGlobalDeclStructAndTypedefDefinitions(sourceFileTargetNames, tempGlobalDefsOutput,
                                                    tempGlobalDependencies, definedGlobalTypesAndVariablesFile, txlIfDefProg, TXLToolsPath,
                                                    tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput);

    /* LOS add definitions */
    char *tempDefineInHeaderFile;
    tempDefineInHeaderFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempDefineInHeaderFile, "%stemp_define_file.out",
            TXLTemporaryMultiFileFolder);

    /* Insert defines into InterfaceHeader file */
    char * localSkeletonCoreFeatureHeader = (char *) malloc (1000 * sizeof(char));
    sprintf(localSkeletonCoreFeatureHeader, "%sNeededFunctionsHeader.h", TXLTemporaryFolderMainThread);
    //LOSNOTES Keep it commanted to not add includes into InterfaceHeader.h
    //TESTANDO
    addLocsFromSourceToDestination(localSkeletonCoreFeatureHeader,tempDefineInHeaderFile, TXLToolsPath);
    addLocsFromSourceToDestination(localSkeletonCoreFeatureHeader,tempIncludeLibFile, TXLToolsPath);
}

void extractDefinitionsAndIncludes(ListOfString ** ListOfNeededLocalHeaderForInterface, char * currentSourceFile, char * sourceFileTargetNames, char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                                               char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder) {

    /* temp global dependencies: temp_global_dependencies.out */
    char * tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryMultiFileFolder);

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(1000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput;
    tempGlobalDefsOutput = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryMultiFileFolder);

    /* temp global type variable declarations: temp_global_type_var_declarations.out */
    char *definedGlobalTypesAndVariablesFile;
    definedGlobalTypesAndVariablesFile = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryMultiFileFolder);

    sprintf(GlobalFctDependOutput, "%stemp_needed_functions_for_global_declarations.out",
            TXLTemporaryMultiFileFolder);

    fflush(stdout);

    extractAllGlobalDeclStructAndTypedefDefinitions(sourceFileTargetNames, tempGlobalDefsOutput,
                                                             tempGlobalDependencies, definedGlobalTypesAndVariablesFile, txlIfDefProg, TXLToolsPath,
                                                             tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput);


    char *formattedCurrentFileDestinationPath = (char *) malloc(500 * sizeof(char));
    sprintf(formattedCurrentFileDestinationPath, "%s%s", TXLTemporaryMultiFileFolder,
            currentSourceFile);

    /* LOS add definitions */
    char *tempDefineInHeaderFile;
    tempDefineInHeaderFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempDefineInHeaderFile, "%stemp_define_file.out",
            TXLTemporaryMultiFileFolder);
    addLocsFromSourceToDestination(formattedCurrentFileDestinationPath,tempDefineInHeaderFile, TXLToolsPath);

    /* LOS Add includes */
    char *tempIncludeLibInHeaderFile;
    tempIncludeLibInHeaderFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempIncludeLibInHeaderFile, "%stemp_include_lib_file.out",
            TXLTemporaryMultiFileFolder);
    addLocsFromSourceToDestination(formattedCurrentFileDestinationPath, tempIncludeLibInHeaderFile,
                                               TXLToolsPath);


    /* LOS add local includes */
    char * tempIncludeLocalLibFile;
    tempIncludeLocalLibFile = (char *) malloc(500 * sizeof (char));
    sprintf(tempIncludeLocalLibFile, "%stemp_include_local_lib_file.out", TXLTemporaryMultiFileFolder);
    extractAllLocalIncludesDefinitions(sourceFileTargetNames, TXLToolsPath, tempIncludeLocalLibFile,
                                       AllDefinedFunctionsInDonor);

    /* LOS add local includes */
    /*char * tempIncludeLocalLibFileInHost;
    tempIncludeLocalLibFileInHost = (char *) malloc(500 * sizeof (char));
    sprintf(tempIncludeLocalLibFileInHost, "%stemp_include_local_lib_file_in_host.out", TXLTemporaryMultiFileFolder);
    extractAllLocalIncludesDefinitions(sourceFileTargetNames, TXLToolsPath, tempIncludeLocalLibFile,
                                       AllDefinedFunctionsInDonor);*/

    ListOfString * listOfLocalIncludes = readListOfStringFromFileAsWords(tempIncludeLocalLibFile);
    /* LOS add local includes */
    char * tempIncludeLocal;
    tempIncludeLocal = (char *) malloc(500 * sizeof (char));
    sprintf(tempIncludeLocal, "%stemp_include_local_lib.out", TXLTemporaryMultiFileFolder);

    createFile(tempIncludeLocal);

    if (fileExists(tempIncludeLocalLibFile))
        removeAFileFromADirectory(tempIncludeLocalLibFile);

    while(listOfLocalIncludes) {

        char *currentLocalIncludeName = (char *) malloc(
                (strlen(listOfLocalIncludes->el) + 1) * sizeof(char));
        strcpy(currentLocalIncludeName, listOfLocalIncludes->el);

        if(strstr(currentLocalIncludeName,".h")) {

             //  strcpy(currentLocalIncludeName,listOfLocalIncludes->el);
            strcpy(currentLocalIncludeName, readSubstring("\"", currentLocalIncludeName, "\""));

            /* LOS formatte curreentLocalIncludeName to check if it is part of the over organ */
            char *formattedCurrentLocalIncludeNamePath = (char *) malloc(500 * sizeof(char));
            sprintf(formattedCurrentLocalIncludeNamePath, "%s%s", TXLTemporaryMultiFileFolder,
                    currentLocalIncludeName);

            if (!file_exists(formattedCurrentLocalIncludeNamePath)) {

                char * formattedIncludeName = (char *) malloc(500 * sizeof(char));
                sprintf(formattedIncludeName, "#include \"%s\"\n\n", currentLocalIncludeName);
                addAStringsInTheEndFile(formattedIncludeName, tempIncludeLocal);
              //  strcat(currentLocalIncludeName,"\n");
                if(strstr(currentSourceFile,".h")) {
                    /*LOS Remove header file from list of header files to insert into interfaceCorefunctionality */
                    removeString(ListOfNeededLocalHeaderForInterface, currentLocalIncludeName);
                }
            }
         }
        listOfLocalIncludes = listOfLocalIncludes->next;
    }
    if(!strcmp(currentSourceFile, donorEntryFile)) {
        // LOS  create new file with include: #include "InterfaceHeader.h" in order to be add in all files
        char * includeCoreFeatureHeader;
        includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
        sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
                InterfaceHeaderFileName);
        addAStringsInTheEndFile(includeCoreFeatureHeader, tempIncludeLocal);
    }
    addLocsFromSourceToDestination(formattedCurrentFileDestinationPath,
                                   tempIncludeLocal, TXLToolsPath);
}

void insertNeededHeaderFileIncludeIntoInterfaceCFAndMainFile(ListOfString * ListOfNeededLocalHeaderForInterface){

    /* LOS add all header files inclued into InterfaceCoreFunctionality.c */
    ListOfString * listOfAllHeaderFilesFormated = NULL;

    while(ListOfNeededLocalHeaderForInterface) {

        char *formatIncludeHeader = NULL;
        formatIncludeHeader = (char *) malloc(100 * sizeof(char));
        sprintf(formatIncludeHeader, "#include \"%s\"\n", strtok(ListOfNeededLocalHeaderForInterface->el,"\n"));

        addNewString(&listOfAllHeaderFilesFormated, formatIncludeHeader);
        ListOfNeededLocalHeaderForInterface = ListOfNeededLocalHeaderForInterface->next;
        fflush(stdout);
        free(formatIncludeHeader);
    }

    char *tempHeaderFilePath;
    tempHeaderFilePath = (char *) malloc(150 * sizeof(char));
    sprintf(tempHeaderFilePath, "%stemp_formated_include.out", TXLTemporaryMultiFileFolder);

    printAListOfStringsNL(listOfAllHeaderFilesFormated, tempHeaderFilePath);

    char * localSkeletonCoreFeatureHeader = (char *) malloc(
            1000 * sizeof(char));
    sprintf(localSkeletonCoreFeatureHeader, "%sInterfaceCoreFunctionality.c",
            TXLTemporaryFolderMainThread);
    /*LOS Insert all include_header into InterfaceCoreFunctionality*/
    addLocsFromSourceToDestination(localSkeletonCoreFeatureHeader,
                                   tempHeaderFilePath, TXLToolsPath);

    /*LOS Insert all include_header into main*/
    char * outputMainPath = (char *) malloc((strlen(TransplantResultLocation) + strlen("test_suite.c") + 1) * sizeof(char));
    /* TODO LOSIMPROVING Chang InsertAllSourceCodeFromInputAtTheBegginingOfOutput to doesn´t duplicate includes with "".*/
    sprintf(outputMainPath, "%stest_suite.c",
            TransplantResultLocation);

    addLocsFromSourceToDestination(outputMainPath,
                                   tempHeaderFilePath, TXLToolsPath);
}

#if 1  /* MULTIFILES */

    #if 1 //LOSMULTIFILESIMPLEMENTATION


GlobalDeclarations constructListOfGlobalDeclarationsForSGD(DependencyList ** globalDependencyList,
                                                               char * AllDefinedFunctionsInDonor,
                                                               char * TXLTemporaryMultiFileFolder) {

    char *tempIncludeLibFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out", TXLTemporaryMultiFileFolder);

    char *tempDefinesFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempDefinesFile, "%stemp_define_file.out", TXLTemporaryMultiFileFolder);

    char * sourceFileTargetNames = (char *) malloc(100 * sizeof (char));
    sprintf(sourceFileTargetNames, "%stemp_source_header_files_target.out", TXLTemporaryMultiFileFolder);

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg = (char *) malloc(100 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput = (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryMultiFileFolder);

    /* temp global type variable declarations: temp_global_type_var_declarations.out */
    char *definedGlobalTypesAndVariablesFile = (char *) malloc(100 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryMultiFileFolder);

    char * tempGlobalFctDependOutputMultiFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalFctDependOutputMultiFile, "%stemp_needed_functions_for_global_declarations.out",
            TXLTemporaryMultiFileFolder);
    fflush(stdout);

    char * tempGlobalDependencies = (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryMultiFileFolder);

    extractAllGlobalDeclStructAndTypedefDefinitionsFromOrgan(sourceFileTargetNames, tempGlobalDefsOutput,
                                                             tempGlobalDependencies, definedGlobalTypesAndVariablesFile, txlIfDefProg, TXLToolsPath,
                                                             tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, tempGlobalFctDependOutputMultiFile);

    GlobalDeclarations finalGlobalDecl = readGlobalDeclarationFromFile(tempGlobalDefsOutput);
    * globalDependencyList = readDependencyListFromFile(tempGlobalDependencies);

   /* removeAFileFromADirectory(tempIncludeLibFile);
    removeAFileFromADirectory(tempDefinesFile);
    removeAFileFromADirectory(definedGlobalTypesAndVariablesFile);
    removeAFileFromADirectory(tempGlobalDefsOutput);
    removeAFileFromADirectory(tempGlobalFctDependOutputMultiFile);
    removeAFileFromADirectory(tempGlobalDependencies);*/

    free(tempIncludeLibFile);
    free(tempDefinesFile);
    free(tempGlobalDependencies);
    free(sourceFileTargetNames);
    free(txlIfDefProg);
    free(tempGlobalDefsOutput);
    free(definedGlobalTypesAndVariablesFile);
    free(tempGlobalFctDependOutputMultiFile);

    fflush(stdout);

    return finalGlobalDecl;
}

GlobalDeclarations constructListOfGlobalDeclarationsMultiFiles(ListOfDefinedTypesAndVars **GlobalListOfDefinedTypeVar, CallDependency **ListOfNeededFunctionsForGlobals, char * tempGlobalDefsOutput, char * tempGlobalTypeVarDeclaration,
                                                               char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                                               char * GlobalFctDependOutput, char * TXLTemporaryFolder, char * sourceFileTargetNames, char * TXLTemporaryMultiFileFolder, char * tempGlobalDependencies) {

    char * txlIfDefProg = (char *) malloc(100 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);
    fflush(stdout);

    extractAllGlobalDeclStructAndTypedefDefinitionsFromOrgan(sourceFileTargetNames, tempGlobalDefsOutput,
                                                    tempGlobalDependencies, tempGlobalTypeVarDeclaration, txlIfDefProg, TXLToolsPath,
                                                    tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput);

    GlobalDeclarations finalGlobalDecl = readGlobalDeclarationFromFile(tempGlobalDefsOutput);
    /*PRINT FINAL GLOBAL DEFS: temp_global_defs_output.out */
   /* char *tempGlobalDefFile = (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDefFile, "%s222temp_global_defs_output.out", TXLTemporaryFolderMainThread);
    printListOfGlobalDeclarationsinDefsOutput(finalGlobalDecl, tempGlobalDefFile);*/

    *GlobalListOfDefinedTypeVar = readListOfDefinedTypesAndVarsFromFile( tempGlobalTypeVarDeclaration);
    *ListOfNeededFunctionsForGlobals = readListOfNeededFunctionsDeclaration( GlobalFctDependOutput);

    char * fileNamePath = readAStringFromFileAsWords(sourceFileTargetNames);
    addFileNameInListOfFinalGlobalDeclarations(donorSourceFileFolder,&finalGlobalDecl, fileNamePath);
  /*  sprintf(tempGlobalDefFile, "%s333temp_global_defs_output.out", TXLTemporaryFolderMainThread);
    printListOfGlobalDeclarationsinDefsOutput(finalGlobalDecl, tempGlobalDefFile);*/
    return finalGlobalDecl;
}

GlobalDeclarations constructListOfGlobalDeclarations1(char * sourceFile, ListOfDefinedTypesAndVars ** globalListOfDefinedTypeVar, char * tempGlobalDefsOutput, char * tempGlobalTypeVarDeclaration,
                                                               char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                                               char * GlobalFctDependOutput, char * TXLTemporaryFolder, char * sourceFileTargetNames, char * TXLTemporaryMultiFileFolder, char * tempGlobalDependencies) {

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(1000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

    extractAllGlobalDeclStructAndTypedefDefinitions(sourceFileTargetNames, tempGlobalDefsOutput,
                                                             tempGlobalDependencies, tempGlobalTypeVarDeclaration, txlIfDefProg, TXLToolsPath,
                                                             tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput);

    GlobalDeclarations finalGlobalDecl = readGlobalDeclarationFromFile(tempGlobalDefsOutput);

    addFileNameInListOfFinalGlobalDeclarations1(&finalGlobalDecl, sourceFile);

    * globalListOfDefinedTypeVar = readListOfDefinedTypesAndVarsFromFile(
            tempGlobalTypeVarDeclaration);

    return finalGlobalDecl;
}
#else
GlobalDeclarations constructListOfGlobalDeclarationsMultiFiles(DependencyList ** globalDependencyList,
            ListOfDefinedTypesAndVars ** globalListOfDefinedTypeVar, char * tempGlobalTypeVarDeclaration,
    char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
    char * GlobalFctDependOutput, char * TXLTemporaryFolder, char * TXLTemporaryMultiFileFolder) {

    /* temp global dependencies: temp_global_dependencies.out */
    char * tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryMultiFileFolder);

    char * sourceFileTargetNames;
    sourceFileTargetNames = (char *) malloc(500 * sizeof (char));
    sprintf(sourceFileTargetNames, "%ssourceContentFilesTarget.out", TXLTemporaryMultiFileFolder);

    /* create file with list of source files target */
    char * sourceFileNameInDonor;
    sourceFileNameInDonor = (char *) malloc(500 * sizeof (char));

    sprintf(sourceFileNameInDonor, "%stemp_list_of_source_files_in_donor.out", TXLTemporaryFolder);

    FILE * sourceFile = fopen(sourceFileNameInDonor, "w");
    readFilesFromDir(donorSourceFileFolder, sourceFile, 'c');
    fclose(sourceFile);

    /*
    char * headFileTargetNames;
    headFileTargetNames = (char *) malloc(500 * sizeof (char));
    sprintf(headFileTargetNames, "%sheadContentFilesTarget.out", TXLTemporaryMultiFileFolder);

    FILE * headerFile = fopen(sourceFileTargetNames, "w");
    readFilesFromDir(donorSourceFileFolder, headFileTargetNames, 'h');
    fclose(headerFile);
    */

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(1000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput;
    tempGlobalDefsOutput = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryMultiFileFolder);

    /* temp global type variable declarations: temp_global_type_var_declarations.out */
    char *definedGlobalTypesAndVariablesFile;
    definedGlobalTypesAndVariablesFile = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryMultiFileFolder);


    /* rewrite temp defines file to temporaryMultiFilesFoles stemp_include_lib_file.out */
    sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out",
            TXLTemporaryMultiFileFolder);

    /* rewrite temp defines file to temporaryMultiFilesFoles */
    sprintf(AllDefinedFunctionsInDonor, "%stemp_all_defined_functions_in_donor.out",
               TXLTemporaryFolderMainThread);

       //the output file of needed functions to be extracted for globals!
       /* rewrite temp defines file to temporaryMultiFilesFoles
        * the output file of needed functions to be extracted for globals!
        * */
       sprintf(GlobalFctDependOutput, "%stemp_needed_functions_for_global_declarations.out",
               TXLTemporaryMultiFileFolder);

       DependencyList * GlobalDependencyList;

       fflush(stdout);

       // TODO chegar a necessidade desta variavel
       //not used for the moment
       ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

      // strcpy(tempGlobalDefsOutput, "%sTransplat-mytar/Donor/append.c");

    /* LOS: insert includes into each source file */
/*

    char * listOfSourceFileTargetPath = NULL;
    listOfSourceFileTargetPath = (char *) malloc(500 * sizeof(char));
    sprintf(listOfSourceFileTargetPath, "%stempSourceFileTarget.out", TXLTemporaryMultiFileFolder);



        extractAllGlobalDeclStructAndTypedefDefinitions(listOfSourceFileTargetPath, tempGlobalDefsOutput,
                                                        tempGlobalDependencies, definedGlobalTypesAndVariablesFile,
                                                        txlIfDefProg, TXLToolsPath,
                                                        tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor,
                                                        GlobalFctDependOutput);

*/

    extractAllGlobalDeclStructAndTypedefDefinitions(sourceFileTargetNames, tempGlobalDefsOutput,
                                                    tempGlobalDependencies, definedGlobalTypesAndVariablesFile, txlIfDefProg, TXLToolsPath,
                                                    tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput);


    GlobalDeclarations finalGlobalDecl = readGlobalDeclarationFromFile(tempGlobalDefsOutput);

        * globalDependencyList = readDependencyListFromFile(tempGlobalDependencies);

        * globalListOfDefinedTypeVar = readListOfDefinedTypesAndVarsFromFile(
            tempGlobalTypeVarDeclaration);

        return finalGlobalDecl;
   }
    #endif
#endif

GlobalDeclarations constructListOfGlobalDeclarations(DependencyList ** globalDependencyList,
           ListOfDefinedTypesAndVars ** globalListOfDefinedTypeVar, char * tempGlobalTypeVarDeclaration,
           char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
           char * GlobalFctDependOutput, char * TXLTemporaryFolder) {

        //sprintf(AllDefinedFunctionsInDonor = "%stemp_list_of_source_header_files.out", TXLTemporaryFolder);
       char * tempGlobalDependencies;
       tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
       sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryFolder);

       /* Create list of all source file names from the Donor -------------------*/
       printf("\tCreate list of all source file names from the Donor\n");
       char * sourceHeaderFileName;
       sourceHeaderFileName = (char *) malloc(500 * sizeof (char));
       sprintf(sourceHeaderFileName, "%stemp_list_of_source_header_files.out", TXLTemporaryFolder);
       FILE * sourceHeaderFile = fopen(sourceHeaderFileName, "w");
       readFilesFromDir(donorSourceFileFolder, sourceHeaderFile, 'c');
       readFilesFromDir(donorSourceFileFolder, sourceHeaderFile, 'h');
       fclose(sourceHeaderFile);
#ifdef DEBUGING
       printf("\t\t|>> temp_list_of_source_header_files.out\n");
#endif
       char * txlIfDefProg;
       txlIfDefProg = (char *) malloc(1000 * sizeof (char));
       sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

       char * tempGlobalDefsOutput;
       tempGlobalDefsOutput = (char *) malloc(500 * sizeof (char));
       sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryFolder);

       extractAllGlobalDeclStructAndTypedefDefinitions(sourceHeaderFileName, tempGlobalDefsOutput,
                                                       tempGlobalDependencies, tempGlobalTypeVarDeclaration, txlIfDefProg, TXLToolsPath,
                                                       tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput);

       /* Read global declaration from temp_global_defs_output.out */
       GlobalDeclarations finalGlobalDecl = readGlobalDeclarationFromFile(tempGlobalDefsOutput);

       /* Read dependency from temp_global_dependencies.out */
       * globalDependencyList = readDependencyListFromFile(tempGlobalDependencies);

       /* Fix dependency inconsistence *///LOSCHANGE23
     //  checkDependecyFromDeclaration(globalDependencyList,finalGlobalDecl );

       /* Replace initial dependency list extracted */
       printADependencyList(*globalDependencyList, tempGlobalDependencies);

       /* Read list of defined type var temp_global_type_var_declarations.out */
       * globalListOfDefinedTypeVar = readListOfDefinedTypesAndVarsFromFile(
               tempGlobalTypeVarDeclaration);

       return finalGlobalDecl;
}

void callInterfaceGlobalDependencySolver(char * tempSkeletonFile, char * tempGlobalDeclarations, char * tempGlobalTypeVarDecl,
           char * TXLProgsPath, char * temporaryOutputFile) {
    char * commandTXL;
    commandTXL = (char *) malloc(1000 * sizeof (char));
    sprintf(commandTXL, "%sGlobalVarTypesDeclDependencyINTERFACE.x %s %s %s %s %s", TXLProgsPath, tempSkeletonFile,
               tempGlobalDeclarations, tempGlobalTypeVarDecl, temporaryOutputFile, ConsoleStderrOutput);
    printf("\t\t[TXL] GlobalVarTypesDeclDependencyINTERFACE.x >> Global Variable Types Declaration Dependency INTERFACE\n");
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! GlobalVarTypesDeclDependencyINTERFACE");
        printf("\t%s\n", commandTXL);
        system("open ErrorFile.out");
        exit(1);
    } else {
#ifdef DEBUGING
        printf("\t\t|>> temp_skeleton_dependency_file.out\n");
#endif
    }
    free(commandTXL);
}

void printListOfStructDefinition(ListOfStructDefinitions * auxDeclHeader,  char * tempGlobalDeclarations){
    FILE * fileTempGlobalDecl = fopen(tempGlobalDeclarations, "w");
    printf("\t>> temp_global_variable_declarations.out\n");
    /*Create temp_global_variable_declarations.out */
    while (auxDeclHeader) {
        ListOfString * auxMultiLineDecl = auxDeclHeader->structDef;
        while (auxMultiLineDecl) {
            fprintf(fileTempGlobalDecl, "%s ", auxMultiLineDecl->el);
            auxMultiLineDecl = auxMultiLineDecl->next;
        }
        auxDeclHeader = auxDeclHeader->next;
    }
    fclose(fileTempGlobalDecl);
}

DependencyList * generateGlobalDependencyListForSkeleton(ListOfString * FinalSkeletonSourceCode,
           char * definedGlobalTypesAndVariablesFile, GlobalDeclarations ListOfFinalGlobalDeclarations,
           char * tempGlobalDeclarations, char * TXLTemporaryFolder) {
    printf("\n\tGenerating global dependency list for skeleton\n");

    char * tempSkeletonSourceCode = (char *) malloc(100 * sizeof (char));
    sprintf(tempSkeletonSourceCode, "%stemp_skeleton_for_global_depend.out", TXLTemporaryFolderMainThread);
    printAListOfStrings(FinalSkeletonSourceCode, tempSkeletonSourceCode);

    ListOfStructDefinitions * auxDeclHeader = ListOfFinalGlobalDeclarations.normalDeclarations;
    printListOfStructDefinition(auxDeclHeader, tempGlobalDeclarations);

    /* Call interface global dependency solver */
    char * tempDependOutput = (char *) malloc(100 * sizeof (char));
    sprintf(tempDependOutput, "%stemp_skeleton_dependency_file.out", TXLTemporaryFolder);
    //LOSCHANGE23
#if !defined(FAST_RUNNING)
    callInterfaceGlobalDependencySolver(tempSkeletonSourceCode, tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
               TXLToolsPath, tempDependOutput);
#endif
    DependencyList * skeletonGlobalDependencies = readDependencyListFromFile(tempDependOutput);

    free(tempSkeletonSourceCode);
    free(tempDependOutput);

    return skeletonGlobalDependencies;
}

GlobalDeclarations fixGlobalDeclarationsForSkeleton(ListOfString * FinalSkeletonSourceCode, DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
           char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile, char * tempDefinesFile,
           char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
           char * TXLTemporaryFolder) {
    printf("[AUTOSCALPEL] Fix global declaration for Skeleton\n");
    //not used for the moment
    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

    /* Construct list of global declaration for skeleton */
    GlobalDeclarations ListOfFinalGlobalDeclarations = constructListOfGlobalDeclarations(&(*GlobalDependencyList),
               &GlobalListOfDefinedTypeVar, definedGlobalTypesAndVariablesFile,
               tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, TXLTemporaryFolder);
    fflush(stdout);

    /* Generate global dependency list for skeleton */
    * SkeletonDependenciesOnGlobals = generateGlobalDependencyListForSkeleton(FinalSkeletonSourceCode,
               definedGlobalTypesAndVariablesFile, ListOfFinalGlobalDeclarations, tempGlobalDeclarations, TXLTemporaryFolder);
    fflush(stdout);

    return ListOfFinalGlobalDeclarations;
}
   #if 0 /* MULTIFILES Using in mulitple header file*/


GlobalDeclarations fixGlobalDeclarationsForSkeletonInterface(ListOfString * FinalSkeletonSourceCode,
                                                    DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
                                                    char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile, char * tempDefinesFile,
                                                    char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
                                                    char * TXLTemporaryFolder) {
    //not used for the moment
    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

    GlobalDeclarations ListOfFinalGlobalDeclarations = constructListOfGlobalDeclarations(&(*GlobalDependencyList),
                                                                                         &GlobalListOfDefinedTypeVar, definedGlobalTypesAndVariablesFile,
                                                                                         tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, TXLTemporaryFolder);

    fflush(stdout);

    * SkeletonDependenciesOnGlobals = generateGlobalDependencyListForSkeleton(FinalSkeletonSourceCode,
                                                                              definedGlobalTypesAndVariablesFile, ListOfFinalGlobalDeclarations, tempGlobalDeclarations, TXLTemporaryFolder);

    fflush(stdout);

    return ListOfFinalGlobalDeclarations;
}

GlobalDeclarations fixGlobalDeclarationsForSkeletonMultiFiles(ListOfString * FinalSkeletonSourceCode,
                                                              DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
                                                              char * tempGlobalDeclarations, char * tempDefinesFile,
                                                              char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
                                                              char * TXLTemporaryFolder, ListOfFunctionSourceFile * listOfFunctionSourceFileExtracted,
                                                              CallDependency * ListOfNeededFunctionsForAllLOCs, char * listOfSourceFilesTargetPath, DependencyList * GlobalDependencyListMultiFiles ) {
    //not used for the moment
    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;
    GlobalDeclarations ListOfFinalGlobalDeclarations;

    char * listOfHeadFilesTargetPath;
    listOfHeadFilesTargetPath = (char *) malloc(500 * sizeof(char));
    sprintf(listOfHeadFilesTargetPath, "%slistOfSourceFilesExtractedPath.out", TXLTemporaryMultiFileFolder);

    char * tempSourceFileTarget = NULL;
    tempSourceFileTarget = (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceFileTarget, "%stempSourceFileTarget.out", TXLTemporaryMultiFileFolder);

    char *definedGlobalTypesAndVariablesFile;
    definedGlobalTypesAndVariablesFile = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile,
            "%stemp_global_type_var_declarations.out",
            TXLTemporaryMultiFileFolder);

    char * currentFct;
    currentFct = (char *) malloc(2000 * sizeof(char));
    char * line;
    line = (char *) malloc(2000 * sizeof(char));
    FILE * fin = fopen(listOfHeadFilesTargetPath, "r");

    while (fgets(line, 2000, fin) != NULL) {

        sscanf(line, "%s", currentFct);
        FILE *fout = fopen(tempSourceFileTarget, "w");
        fprintf(fout, "%s", currentFct);
        fclose(fout);


        ListOfFinalGlobalDeclarations = constructListOfGlobalDeclarationsMultiFiles(&(*GlobalDependencyList),
                                                                                         &GlobalListOfDefinedTypeVar, definedGlobalTypesAndVariablesFile,
                                                                                         tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, TXLTemporaryFolder, TXLTemporaryMultiFileFolder, listOfFunctionSourceFileExtracted);

        fflush(stdout);


        /* rewrite definedGlobalTypesAndVariablesFile to temporaryMultiFilesFoles */
        * SkeletonDependenciesOnGlobals = generateGlobalDependencyListForSkeleton(FinalSkeletonSourceCode,
                                                                              definedGlobalTypesAndVariablesFile, ListOfFinalGlobalDeclarations, tempGlobalDeclarations, TXLTemporaryMultiFileFolder);

        fflush(stdout);

        extractNeededFunctionsAndGlobalDeclarations(FinalSkeletonSourceCode,
                                                   ListOfNeededFunctionsForAllLOCs,
                                                   SkeletonDependenciesOnGlobals,
                                                   GraftFunctionName,
                                                   GlobalFctDependOutput,
                                                   listOfSourceFilesTargetPath,
                                                    ListOfFinalGlobalDeclarations,
                                                   GlobalDependencyListMultiFiles);
    }

    return ListOfFinalGlobalDeclarations;
}
#endif

#if 1 /* MULTIFILES without multiple header files*/


GlobalDeclarations fixGlobalDeclarationsForSkeletonInterface(ListOfString * FinalSkeletonSourceCode,
                                                             DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
                                                             char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile, char * tempDefinesFile,
                                                             char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
                                                             char * TXLTemporaryFolder) {
    //not used for the moment
    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

    GlobalDeclarations ListOfFinalGlobalDeclarations = constructListOfGlobalDeclarations(&(*GlobalDependencyList),
                                                                                         &GlobalListOfDefinedTypeVar, definedGlobalTypesAndVariablesFile,
                                                                                         tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput, TXLTemporaryFolder);

    fflush(stdout);

    * SkeletonDependenciesOnGlobals = generateGlobalDependencyListForSkeleton(FinalSkeletonSourceCode,
                                                                              definedGlobalTypesAndVariablesFile, ListOfFinalGlobalDeclarations, tempGlobalDeclarations, TXLTemporaryFolder);

    fflush(stdout);

    return ListOfFinalGlobalDeclarations;
}

GlobalDeclarations fixGlobalDeclarationsForSkeletonMultiFiles( char * definedGlobalTypesAndVariablesFile, char * tempGlobalDefsOutput, char * tempDefinesFile,
                                                              char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput, char * sourceFileTargetNames,
                                                              char * TXLTemporaryFolder, char *tempGlobalDependencies) {

    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;
    CallDependency *ListOfNeededFunctionsForGlobals;
    GlobalDeclarations ListOfFinalGlobalDeclarations = constructListOfGlobalDeclarationsMultiFiles( GlobalListOfDefinedTypeVar, ListOfNeededFunctionsForGlobals, tempGlobalDefsOutput, definedGlobalTypesAndVariablesFile,
                                                                                                   tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, GlobalFctDependOutput,
                                                                                                    TXLTemporaryFolder, sourceFileTargetNames, TXLTemporaryMultiFileFolder, tempGlobalDependencies);

#ifdef SEARCH_VAR_UNION
    char *listOfAllGlobalExtracted = (char *) malloc(100 * sizeof(char));
    sprintf(listOfAllGlobalExtracted, "%sAllGlobalDependencies.h", TempVeinDirectory);
  ///  printListOfGlobalDependencies(ListOfFinalGlobalDeclarations, listOfAllGlob---tracted, definedGlobalTypesAndVariablesFile,tempGlobalDependencies);

#endif

    fflush(stdout);
    return ListOfFinalGlobalDeclarations;
}

GlobalDeclarations fixGlobalDeclarations(char * tempDir, char * sourceFile,
                                                              char * AllDefinedFunctions, char * tempSourceHeaderFilesTargetPath,
                                                              char * TXLTemporaryFolder) {
    char *listOfAllGlobalExtracted;
    listOfAllGlobalExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(listOfAllGlobalExtracted, "%sAllGlobalDependencies.h",
            tempDir);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput;
    tempGlobalDefsOutput = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", tempDir);

    char *tempGlobalDeclarationsPath;
    tempGlobalDeclarationsPath = (char *) malloc(500 * sizeof(char));
    sprintf(tempGlobalDeclarationsPath, "%stemp_global_variable_declarations",
            tempDir);
    createFile(tempGlobalDeclarationsPath);

    char *definedGlobalTypesAndVariables;
    definedGlobalTypesAndVariables = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariables, "%stemp_global_type_var_declarations.out",
            tempDir);

    char *tempDefinesFile;
    tempDefinesFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempDefinesFile, "%stemp_define_file.out",
            tempDir);

    char *tempIncludeLibFile;
    tempIncludeLibFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out",
            tempDir);

    char *tempGlobalFctDependOutputPath;
    tempGlobalFctDependOutputPath = (char *) malloc(1000 * sizeof(char));
    sprintf(tempGlobalFctDependOutputPath, "%stemp_needed_functions_for_global_declarations.out",
            tempDir);

    char * tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", tempDir);

    //not used for the moment
    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

    GlobalDeclarations ListOfFinalGlobalDeclarations = constructListOfGlobalDeclarations1( sourceFile, &GlobalListOfDefinedTypeVar, tempGlobalDefsOutput, definedGlobalTypesAndVariables,
                                                                                                    tempDefinesFile, tempIncludeLibFile, AllDefinedFunctions, tempGlobalFctDependOutputPath,
                                                                                                    TXLTemporaryFolder, tempSourceHeaderFilesTargetPath, TXLTemporaryMultiFileFolder, tempGlobalDependencies);

    fflush(stdout);

    return ListOfFinalGlobalDeclarations;
}
#endif




GlobalDeclarations returnMarkerGlobalDeclarationFromMarkersList(GlobalDeclarations currentGlobal, ListOfString * markers) {
    ListOfString * auxMarkers = markers;

    GlobalDeclarations neededGlobals;
    neededGlobals.normalDeclarations = NULL;
    neededGlobals.structUnionDeclarations = NULL;
    neededGlobals.typedefDeclarations = NULL;

    while (auxMarkers) {
        ListOfStructDefinitions * auxNormalDecl = currentGlobal.normalDeclarations;
        ListOfStructDefinitions * auxStructDecl = currentGlobal.structUnionDeclarations;
        ListOfStructDefinitions * auxTypedefDecl = currentGlobal.typedefDeclarations;

        while (auxNormalDecl) {
            if(strstr(auxNormalDecl->structDef->el, auxMarkers->el))
                addNewStructDefinition(&neededGlobals.normalDeclarations, auxNormalDecl->structDef,
                                   auxNormalDecl->headerDefinition, auxNormalDecl->file,auxNormalDecl->occurrenceLine);

            auxNormalDecl = auxNormalDecl->next;
        }

        while (auxStructDecl) {
            if(strstr(auxStructDecl->structDef->el, auxMarkers->el))
                addNewStructDefinition(&neededGlobals.structUnionDeclarations, auxStructDecl->structDef,
                                   auxStructDecl->headerDefinition, auxStructDecl->file, auxStructDecl->occurrenceLine);

            auxStructDecl = auxStructDecl->next;
        }

        while (auxTypedefDecl) {
            if(strstr(auxTypedefDecl->structDef->el, auxMarkers->el))
                addNewStructDefinition(&neededGlobals.typedefDeclarations, auxTypedefDecl->structDef,
                                   auxTypedefDecl->headerDefinition, auxTypedefDecl->file, auxTypedefDecl->occurrenceLine);

            auxTypedefDecl = auxTypedefDecl->next;
        }

        auxMarkers = auxMarkers->next;
    }

    return neededGlobals;
}

GlobalDeclarations returnMarkerGlobalDeclarationALL(GlobalDeclarations currentGlobal, ListOfString * markers) {
    ListOfString * auxMarkers = markers;

    GlobalDeclarations neededGlobals;
    neededGlobals.normalDeclarations = NULL;
    neededGlobals.structUnionDeclarations = NULL;
    neededGlobals.typedefDeclarations = NULL;

    while (auxMarkers) {
        ListOfStructDefinitions * auxNormalDecl = currentGlobal.normalDeclarations;
        ListOfStructDefinitions * auxStructDecl = currentGlobal.structUnionDeclarations;
        ListOfStructDefinitions * auxTypedefDecl = currentGlobal.typedefDeclarations;

        while (auxNormalDecl) {

                addNewStructDefinition(&neededGlobals.normalDeclarations, auxNormalDecl->structDef,
                        auxNormalDecl->headerDefinition, auxNormalDecl->file,auxNormalDecl->occurrenceLine);
            auxNormalDecl = auxNormalDecl->next;


            /*
            if (strstr(auxNormalDecl->declaration, auxMarkers->el)) {
                addNewDeclarationWithHeaderDefinition(&neededGlobals.normalDeclarations, auxNormalDecl->declaration,
                        auxNormalDecl->headerDefinition);
            }
            auxNormalDecl = auxNormalDecl->next;
             */
        }

        while (auxStructDecl) {
                addNewStructDefinition(&neededGlobals.structUnionDeclarations, auxStructDecl->structDef,
                        auxStructDecl->headerDefinition, auxStructDecl->file, auxStructDecl->occurrenceLine);
            auxStructDecl = auxStructDecl->next;
        }

        while (auxTypedefDecl) {

                addNewStructDefinition(&neededGlobals.typedefDeclarations, auxTypedefDecl->structDef,
                        auxTypedefDecl->headerDefinition, auxTypedefDecl->file, auxTypedefDecl->occurrenceLine);
            auxTypedefDecl = auxTypedefDecl->next;

            /*
            if (strstr(auxTypedefDecl->el, auxMarkers->el)) {
                addNewString(&neededGlobals.typedefDeclarations, auxTypedefDecl->el);
            }
            auxTypedefDecl = auxTypedefDecl->next;
             */
        }

        auxMarkers = auxMarkers->next;
    }

    return neededGlobals;
}







GlobalDeclarations returnMarkerGlobalDeclaration(GlobalDeclarations currentGlobal, ListOfString * markers) {
    ListOfString * auxMarkers = markers;

    GlobalDeclarations neededGlobals;
    neededGlobals.normalDeclarations = NULL;
    neededGlobals.structUnionDeclarations = NULL;
    neededGlobals.typedefDeclarations = NULL;

    while (auxMarkers) {
        ListOfStructDefinitions * auxNormalDecl = currentGlobal.normalDeclarations;
        ListOfStructDefinitions * auxStructDecl = currentGlobal.structUnionDeclarations;
        ListOfStructDefinitions * auxTypedefDecl = currentGlobal.typedefDeclarations;

        while (auxNormalDecl) {

            if (strstr(auxNormalDecl->structDef->el, auxMarkers->el)) {
                addNewStructDefinition(&neededGlobals.normalDeclarations, auxNormalDecl->structDef,
                        auxNormalDecl->headerDefinition, auxNormalDecl->file, auxNormalDecl->occurrenceLine);
            }
            auxNormalDecl = auxNormalDecl->next;


            /*
            if (strstr(auxNormalDecl->declaration, auxMarkers->el)) {
                addNewDeclarationWithHeaderDefinition(&neededGlobals.normalDeclarations, auxNormalDecl->declaration,
                        auxNormalDecl->headerDefinition);
            }
            auxNormalDecl = auxNormalDecl->next;
             */
        }

        while (auxStructDecl) {
            if (strstr(auxStructDecl->structDef->el, auxMarkers->el)) {
                addNewStructDefinition(&neededGlobals.structUnionDeclarations, auxStructDecl->structDef,
                        auxStructDecl->headerDefinition, auxStructDecl->file, auxStructDecl->occurrenceLine);
            }
            auxStructDecl = auxStructDecl->next;
        }

        while (auxTypedefDecl) {

            if (strstr(auxTypedefDecl->structDef->el, auxMarkers->el)) {
                addNewStructDefinition(&neededGlobals.typedefDeclarations, auxTypedefDecl->structDef,
                        auxTypedefDecl->headerDefinition, auxTypedefDecl->file, auxTypedefDecl->occurrenceLine);
            }
            auxTypedefDecl = auxTypedefDecl->next;

            /*
            if (strstr(auxTypedefDecl->el, auxMarkers->el)) {
                addNewString(&neededGlobals.typedefDeclarations, auxTypedefDecl->el);
            }
            auxTypedefDecl = auxTypedefDecl->next;
             */
        }

        auxMarkers = auxMarkers->next;
    }

    return neededGlobals;
}

/*
void addNewGlobalForTransplant(ListOfGlobalForTransplant ** head, char * string, int visited) {
    ListOfGlobalForTransplant * newEl = (ListOfGlobalForTransplant *) malloc(1 * sizeof (ListOfGlobalForTransplant));
    newEl->marker = (char *) malloc((strlen(string) + 1) * sizeof (char *));
    newEl->visited = visited;
    strcpy(newEl, string);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfString * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }

}

ListOfGlobalForTransplant * newListOfGlobalForTransplant;

char * returnDependencyForAMarker(DependencyList * GlobalDependencyList, char * mark){

    ListOfString * currentStmDependList = returnDependencyForAMarkerNewPointers(GlobalDependencyList, mark);

    while(currentStmDependList){

        if(strstr(currentStmDependList->el,mark)) {
            char *marker = returnDependencyForAMarker(GlobalDependencyList, currentStmDependList->el);
            addNewGlobalForTransplant(&newListOfGlobalForTransplant, marker, 1);
        }
        currentStmDependList = currentStmDependList->next;
    }
    return mark;
}*/

void readListDeclarationByType(ListOfString ** head, ListOfString * listOfMarkers, int n, char * type) {

    ListOfString *auxListOfMarkers = listOfMarkers;

    ListOfString *auxMarkers = NULL;
    //for (int i = 0; i < n; i++) {
    int s = 1;
    while(auxListOfMarkers){
//        printf("[%d] %s\n", s, auxListOfMarkers->el);
        auxListOfMarkers = auxListOfMarkers->next;
        s++;
     }
   // printf("==============\n");

    auxListOfMarkers = listOfMarkers;
    while(auxListOfMarkers){
        if (strstr(auxListOfMarkers->el, type)) {
            char *finalGDMark = (char *) malloc((strlen(auxListOfMarkers->el) + 1) * sizeof(char));
            strcpy(finalGDMark, readSubstring(type, auxListOfMarkers->el, " */"));
            addNewString(&auxMarkers, finalGDMark);
        }
        auxListOfMarkers = auxListOfMarkers->next;
    }

    ListOfString * aux = auxMarkers;
    int c =1;
    while(aux){
    //    printf("[%d] %s\n", c, aux->el);
        aux = aux->next;
        c++;
    }

    int nMarkers = countElementsInListOfString(auxMarkers);
    char **str = NULL;
    str = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < nMarkers; i++) {
        str[i] = (char *) malloc(100 * sizeof(char));
    }

    //for (int i = 0; i < nMarkers; i++) {
    int z = 0;
    while(auxMarkers){
        strcpy(str[z], auxMarkers->el);
        auxMarkers = auxMarkers->next;
        z++;
    }


    for (int i = 0; i < nMarkers; i++) {
 //       printf("%d - %s\n", i,str[i]);

    }

    int i, j;
    char *temp;

    char minStr[100];
   /* for (i = 0; i < nMarkers-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy(minStr, str[i]);
        for (j = i + 1; j < nMarkers; j++)
        {
            // If min is greater than arr[j]
            if (strcmp(minStr, str[j]) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, str[j]);
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char temp[100];
            strcpy(temp, str[i]); //swap item[pos] and item[i]
            strcpy(str[i], str[min_idx]);
            strcpy(str[min_idx], temp);
        }
    }*/
    for (i = 1; i < nMarkers; i++)
        for (j = 0; j < nMarkers - i; j++) {
            int strCurrent = atoi(str[j]);
            int strPos = atoi(str[j+1]);
            if (strCurrent > strPos) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }


   /* for (int i = 0; i < nMarkers; i++) {
        printf("%s\n",str[i]);
    }*/

    for (int i = 0; i < nMarkers; i++) {
        char* temp1 = (char *) malloc((strlen(str[i]) + 10) * sizeof (char *));
        //strcpy(temp1, str[i]);
        sprintf(temp1, "%s%s */", type, str[i]);
        //if(str[i] == str[i+1])
            addNewString(head, temp1);
    }
    free(str);
}
ListOfString * orderListOfString(ListOfString * head) {
    ListOfString * newHead = NULL;
    int n = countElementsInListOfString(head);


    readListDeclarationByType(&newHead, head, n, GLOBAL_DECL_BEGINNING_MARKER);
    readListDeclarationByType(&newHead, head, n, ENUM_DECL_BEGINNING_MARKER_);
    readListDeclarationByType(&newHead, head, n, STRUCT_DECL_BEGINNING_MARKER);
    readListDeclarationByType(&newHead, head, n, TYPEDEF_DECL_BEGINNING_MARKER);

    return newHead;
}
/*
char * returnDependencyForAMarker(ListOfString **newGlobalMarkersForTransplant,  DependencyList *GlobalDependencyList, char * mark){

    ListOfString * currentStmDependList = returnDependencyForAMarkerNewPointers(GlobalDependencyList, mark);
    DependencyList * auxGlobalDependencyList = GlobalDependencyList;

    if(currentStmDependList == NULL  && !searchStringInListOfStrings((*newGlobalMarkersForTransplant), mark)){
        addNewString(newGlobalMarkersForTransplant , mark);
        char * recursiveGlobalForTransplant;
        recursiveGlobalForTransplant = (char *) malloc(500 * sizeof(char));
        sprintf(recursiveGlobalForTransplant, "%srecursive_global_for_transplant.out", TXLTemporaryFolderMainThread);
        printAListOfStringsNL((*newGlobalMarkersForTransplant) , recursiveGlobalForTransplant);
    }else
        setDependencyStatmentVisited(GlobalDependencyList, mark);

    while(currentStmDependList){
        int visited = getDependencyStatmentVisited(GlobalDependencyList, currentStmDependList->el);
        //check if the statement has already visited and if the node has been added
        if(visited != 1 && !searchStringInListOfStrings((*newGlobalMarkersForTransplant), currentStmDependList->el)) {
            char *marker = returnDependencyForAMarker(newGlobalMarkersForTransplant, GlobalDependencyList, currentStmDependList->el);
        }
        currentStmDependList = currentStmDependList->next;
        //    }
    }
    if(!searchStringInListOfStrings((*newGlobalMarkersForTransplant), mark)) {
        addNewString(newGlobalMarkersForTransplant, mark);
        char *recursiveGlobalForTransplant;
        recursiveGlobalForTransplant = (char *) malloc(500 * sizeof(char));
        sprintf(recursiveGlobalForTransplant, "%srecursive_global_for_transplant.out", TXLTemporaryFolderMainThread);
        printAListOfStringsNL((*newGlobalMarkersForTransplant), recursiveGlobalForTransplant);
    }
    return mark;
}*/


char * returnDependencyForAMarker(ListOfString **newGlobalMarkersForTransplant,  DependencyList *GlobalDependencyList, char * mark){

    ListOfString * currentStmDependList = returnDependencyForAMarkerNewPointers(GlobalDependencyList, mark);
    DependencyList * auxGlobalDependencyList = GlobalDependencyList;
    setDependencyStatmentVisited(GlobalDependencyList, mark);

    while(currentStmDependList){
        //if(strstr(currentStmDependList->el,mark)){
        int visited = getDependencyStatmentVisited(GlobalDependencyList, currentStmDependList->el);
        //check if the statement has already visited and if the node has been added
        if(visited != 1 && !searchStringInListOfStrings((*newGlobalMarkersForTransplant), currentStmDependList->el)) {
            char *marker = returnDependencyForAMarker(newGlobalMarkersForTransplant, GlobalDependencyList, currentStmDependList->el);
            addNewString(newGlobalMarkersForTransplant , marker);
            char * recursiveGlobalForTransplant;
            recursiveGlobalForTransplant = (char *) malloc(500 * sizeof(char));
            sprintf(recursiveGlobalForTransplant, "%srecursive_global_for_transplant.out", TXLTemporaryFolderMainThread);
            printAListOfStringsNL((*newGlobalMarkersForTransplant) , recursiveGlobalForTransplant);

        }
        currentStmDependList = currentStmDependList->next;
        //    }

    }
    //setDependencyStatmentVisited(GlobalDependencyList, mark);

    return mark;
}

GlobalDeclarations extractNeededGlobalDeclarationsForSkeleton(ListOfString * SelectedMarkers,
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals) {

    //Mapped declarations are globals which are mapped to the values in the host
    //these are not used for the moment
    ListOfString * MappedDeclarations = NULL;
    ListOfString * GlobalMarkersForTransplant = NULL;
    DependencyList * AllGlobalDependencies = NULL;
    addDependencyListToAnExistingOne(&AllGlobalDependencies, SkeletonDependenciesOnGlobals);
    addDependencyListToAnExistingOne(&AllGlobalDependencies, GlobalDependencyList);
    //first create the initial list of needed global markers, by the list of all
    //needed markers from the selected LOCs of the Skeleton
    ListOfString * auxSelectedMarkers = SelectedMarkers;
    while (auxSelectedMarkers) {
        ListOfString * neededDepsForCurrent = returnDependencyForAMarkerNewPointers(AllGlobalDependencies,
                auxSelectedMarkers->el);
        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            while (auxListString) {
                if (!searchStringInListOfStrings(MappedDeclarations, auxListString->el) &&
                        !searchStringInListOfStrings(GlobalMarkersForTransplant, auxListString->el)) {
                    addNewString(&GlobalMarkersForTransplant, auxListString->el);
                }
                auxListString = auxListString->next;
            }
            freeListOfStrings(&neededDepsForCurrent);
        }
        auxSelectedMarkers = auxSelectedMarkers->next;
    }
    ListOfString * auxNeededMarkers = GlobalMarkersForTransplant;



    //for all added line markers, add the one from dependency, if they are not mapped
   while (auxNeededMarkers) {
        //memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
        ListOfString * neededDepsForCurrent = returnDependencyForAMarkerNewPointers(AllGlobalDependencies,
                auxNeededMarkers->el);
        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            while (auxListString) {
                if (!searchStringInListOfStrings(GlobalMarkersForTransplant, auxListString->el)) {
                    addNewString(&GlobalMarkersForTransplant, auxListString->el);
                }
                auxListString = auxListString->next;
            }
            //LOSCHANGE
           // freeListOfStrings(&neededDepsForCurrent);
        }
        auxNeededMarkers = auxNeededMarkers->next;
    }

    //temporary add all the global declarations!!!
    ListOfString *  auxGlobalMarkersForTransplant = GlobalMarkersForTransplant;
   // ListOfString * GlobalMarkersWithDependenciesForTransplant;



    //ListOfString * newGlobalMarkersForTransplant1 = NULL;
    ListOfString * GlobalMarkers = NULL;
    ListOfString * newGlobalMarkersForTransplant = NULL;

    char * inicialGlobalForTransplant;
    inicialGlobalForTransplant = (char *) malloc(500 * sizeof (char));
    sprintf(inicialGlobalForTransplant, "%sinicial_global_for_transplant.out", TXLTemporaryFolderMainThread);

    printAListOfStringsNL(auxGlobalMarkersForTransplant , inicialGlobalForTransplant);

    // TODO Removed, check any collateral effect.
  //  ListOfStatmentMark * listOfStatmentMark = readListStatmentMark(ListOfFinalGlobalDeclarations);

   /* struct DependenceGraph * graph = generateDependenceGraph(GlobalDependencyList, listOfStatmentMark);
    while (auxGlobalMarkersForTransplant) {
        int idNode = searchDeclNodeId(listOfStatmentMark, auxGlobalMarkersForTransplant->el);
        readDeclDependenceForTransplant(graph, &newGlobalMarkersForTransplant, listOfStatmentMark, idNode);

        char * partialGlobalForTransplant;
        partialGlobalForTransplant = (char *) malloc(500 * sizeof(char));
        sprintf(partialGlobalForTransplant, "%spartial_global_for_transplant.out", TXLTemporaryFolderMainThread);
        printAListOfStringsNL(newGlobalMarkersForTransplant , partialGlobalForTransplant);

        auxGlobalMarkersForTransplant = auxGlobalMarkersForTransplant->next;
    }*/
     while (auxGlobalMarkersForTransplant) {

        int visited = getDependencyStatmentVisited(GlobalDependencyList, auxGlobalMarkersForTransplant->el);
        if(visited != 1 && !searchStringInListOfStrings(newGlobalMarkersForTransplant, auxGlobalMarkersForTransplant->el)) {
            char *marker = returnDependencyForAMarker(&newGlobalMarkersForTransplant, GlobalDependencyList,
                                                      auxGlobalMarkersForTransplant->el);
            addNewString(&newGlobalMarkersForTransplant, marker);
            // addNewString(&newGlobalMarkersForTransplant , marker);
        }
            char * partialGlobalForTransplant;
            partialGlobalForTransplant = (char *) malloc(500 * sizeof


                                                                       (char));
            sprintf(partialGlobalForTransplant, "%spartial_global_for_transplant.out", TXLTemporaryFolderMainThread);

            printAListOfStringsNL(newGlobalMarkersForTransplant , partialGlobalForTransplant);


     /*   while(newGlobalMarkersForTransplant){
            addNewString(&newGlobalMarkersForTransplant1,newGlobalMarkersForTransplant->el);
            newGlobalMarkersForTransplant = newGlobalMarkersForTransplant->next;
        }*/

       /* ListOfString * reverGlobalMarkersForTransplant = reverseListOfString(newGlobalMarkersForTransplant);

        printAListOfStringsNL(reverGlobalMarkersForTransplant , partialGlobalForTransplant);


        while(reverGlobalMarkersForTransplant){
            addNewString(&newGlobalMarkersForTransplant1,reverGlobalMarkersForTransplant->el);
            reverGlobalMarkersForTransplant = reverGlobalMarkersForTransplant->next;
        }*/

        auxGlobalMarkersForTransplant = auxGlobalMarkersForTransplant->next;
    }
  //  ListOfString * reverGlobalMarkersForTransplant = reverseListOfString(newGlobalMarkersForTransplant);

    ListOfString * orderGlobalMarkersForTransplant = orderListOfString(newGlobalMarkersForTransplant);
    ListOfString * reverGlobalMarkersForTransplant = reverseListOfString(orderGlobalMarkersForTransplant);
    char * tempGlobalForTransplant;
    tempGlobalForTransplant = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalForTransplant, "%stemp_global_for_transplant.out", TXLTemporaryFolderMainThread);
   // printAListOfStringsNL(reverGlobalMarkersForTransplant , tempGlobalForTransplant);
    printAListOfStringsNL(reverGlobalMarkersForTransplant , tempGlobalForTransplant);

    // TODO: CHECK HERE
    //GlobalDeclarations NeededGlobalDeclarations = returnMarkerGlobalDeclaration(ListOfFinalGlobalDeclarations, reverGlobalMarkersForTransplant);
    GlobalDeclarations NeededGlobalDeclarations = returnMarkerGlobalDeclaration(ListOfFinalGlobalDeclarations, reverGlobalMarkersForTransplant);
    //printListOfGlobalDeclarations(NeededGlobalDeclarations, "/home/---/workspace/testGLOBALSnewSource.out",
    // "/home/---/workspace/testGLOBALSnewHeader.out");


    return NeededGlobalDeclarations;

}

ListOfStructDefinitions * reverseListOfStructDefinitions(ListOfStructDefinitions * originalList) {
    ListOfStructDefinitions * newListOfStructDefinitions = NULL;
    while (originalList) {
        addNewStructDefinitionAtBeggining(& newListOfStructDefinitions, originalList->structDef, originalList->headerDefinition, originalList->file);
        originalList = originalList->next;
    }
    return newListOfStructDefinitions;
}



#define ENUM_MARKER "/* ENUM_DECL_"
//to be changhed!!!
#define TYPEDEF_MARKER_TEMP "typedef"


#define STRUCT_ARRAY_HEADER_DECLARATION "/* STRUCT_WITH_ARRAY */"

void printListOfGlobalDeclarationsCoreFunction(GlobalDeclarations ListOfDecl, char * outputFileSurce,
                                   char * outputFileHeader) {
    FILE * fout = fopen(outputFileSurce, "w");
    FILE * foutHeader = fopen(outputFileHeader, "w");


    //first time, print in the source file the struct declarations with marker, from the header!!!

    ListOfStructDefinitions * reversedNormalDecl = reverseListOfStructDefinitions(ListOfDecl.normalDeclarations);

    ListOfStructDefinitions * auxNormalDeclJustHeader = reversedNormalDecl;
    while (auxNormalDeclJustHeader) {
        ListOfString * auxNormalElements = auxNormalDeclJustHeader->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //nothing here, after structs!
        } else {
            while (auxNormalElements) {
              //  fprintf(foutHeader, "%s", auxNormalElements->el);
                fprintf(fout, "%s", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
        }

        ///ListOfString * auxNormalElementsForStructArray = auxNormalDeclJustHeader->headerDefinition;
        if (auxNormalDeclJustHeader->headerDefinition && strstr(auxNormalDeclJustHeader->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
            //fprintf(fout, "%s", auxNormalDeclJustHeader->headerDefinition);

        }


        auxNormalDeclJustHeader = auxNormalDeclJustHeader->next;
    }

    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDecl.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        ListOfString * auxStructElements = auxTypeDecl->structDef;
        while (auxStructElements) {
            //    fprintf(foutHeader, "%s", auxStructElements->el);
            fprintf(fout, "%s", auxStructElements->el);
            auxStructElements = auxStructElements->next;
        }

        //fprintf(foutHeader, "%s\n\n", auxTypeDecl->el);
        auxTypeDecl = auxTypeDecl->next;
    }



    ListOfStructDefinitions * reversedStructDecl = reverseListOfStructDefinitions(ListOfDecl.structUnionDeclarations);

    ListOfStructDefinitions * auxStructDecl = reversedStructDecl;
    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;


        if (!strstr(auxStructElements->el, TYPEDEF_MARKER_TEMP)) {
            while (auxStructElements) {
                fprintf(fout, "%s", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
            if (auxStructDecl->headerDefinition) {
               // fprintf(foutHeader, "%s\n\n", auxStructDecl->headerDefinition);

            }
        } else {
            while (auxStructElements) {
             //   fprintf(foutHeader, "%s", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
        }
        auxStructDecl = auxStructDecl->next;
    }








    ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //fprintf(fout, "%s\n\n", auxNormalElements->el);
            while (auxNormalElements) {
                fprintf(fout, "%s", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
            fprintf(fout, "\n\n");
            if (auxNormalDecl->headerDefinition && !strstr(auxNormalDecl->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
        //        fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
            }
        } else {
            //nothing here, it was added before the structs!
        }

        /*
        if (!strstr(auxNormalDecl->declaration, ENUM_MARKER)) {
            fprintf(fout, "%s\n\n", auxNormalDecl->declaration);
        } else {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->declaration);
        }
        if (auxNormalDecl->headerDefinition) {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
        }
         */
        auxNormalDecl = auxNormalDecl->next;
    }









    fclose(fout);
    fclose(foutHeader);
}

void printListOfGlobalDeclarations2(GlobalDeclarations ListOfDecl, char * outputFileSurce,
                                   char * outputFileHeader) {
    FILE * fout = fopen(outputFileSurce, "w");
    FILE * foutHeader = fopen(outputFileHeader, "w");


    //first time, print in the source file the struct declarations with marker, from the header!!!

    ListOfStructDefinitions * reversedNormalDecl = reverseListOfStructDefinitions(ListOfDecl.normalDeclarations);

    ListOfStructDefinitions * auxNormalDeclJustHeader = reversedNormalDecl;
    while (auxNormalDeclJustHeader) {
        ListOfString * auxNormalElements = auxNormalDeclJustHeader->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //nothing here, after structs!
        } else {
            while (auxNormalElements) {
                fprintf(foutHeader, "%s", auxNormalElements->el);
            //    printf("NormalElements: %s\n", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
        }

        ///ListOfString * auxNormalElementsForStructArray = auxNormalDeclJustHeader->headerDefinition;
        if (auxNormalDeclJustHeader->headerDefinition && strstr(auxNormalDeclJustHeader->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
            //fprintf(fout, "%s", auxNormalDeclJustHeader->headerDefinition);

        }


        auxNormalDeclJustHeader = auxNormalDeclJustHeader->next;
    }




    ListOfStructDefinitions * reversedStructDecl = reverseListOfStructDefinitions(ListOfDecl.structUnionDeclarations);

    ListOfStructDefinitions * auxStructDecl = reversedStructDecl;
    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;


        if (!strstr(auxStructElements->el, TYPEDEF_MARKER_TEMP)) {
            while (auxStructElements) {
                fprintf(fout, "%s", auxStructElements->el);
                printf("auxStructElements: %s\n", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
            if (auxStructDecl->headerDefinition) {
                fprintf(foutHeader, "%s\n\n", auxStructDecl->headerDefinition);
                printf("auxStructDecl: %s\n", auxStructDecl->headerDefinition);
            }
        } else {
            while (auxStructElements) {
                fprintf(foutHeader, "%s", auxStructElements->el);
                printf("auxStructElements: %s\n", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
        }
        auxStructDecl = auxStructDecl->next;
    }



    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDecl.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        ListOfString * auxStructElements = auxTypeDecl->structDef;
        while (auxStructElements) {
            fprintf(foutHeader, "%s", auxStructElements->el);
            printf("auxStructElements: %s\n", auxStructElements->el);
            auxStructElements = auxStructElements->next;
        }

        //fprintf(foutHeader, "%s\n\n", auxTypeDecl->el);
        auxTypeDecl = auxTypeDecl->next;
    }





    ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //fprintf(fout, "%s\n\n", auxNormalElements->el);
            while (auxNormalElements) {
                fprintf(fout, "%s", auxNormalElements->el);
               // printf("auxNormalElements: %s\n", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
            fprintf(fout, "\n\n");
            if (auxNormalDecl->headerDefinition && !strstr(auxNormalDecl->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
                fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
                printf("auxNormalDecl: %s\n", auxNormalDecl->headerDefinition);
            }
        } else {
            //nothing here, it was added before the structs!
        }

        /*
        if (!strstr(auxNormalDecl->declaration, ENUM_MARKER)) {
            fprintf(fout, "%s\n\n", auxNormalDecl->declaration);
        } else {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->declaration);
        }
        if (auxNormalDecl->headerDefinition) {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
        }
         */
        auxNormalDecl = auxNormalDecl->next;
    }









    fclose(fout);
    fclose(foutHeader);
}

void printListOfGlobalDeclarations(GlobalDeclarations ListOfDecl, char * outputFileSurce,
        char * outputFileHeader) {
    FILE * fout = fopen(outputFileSurce, "w");
    FILE * foutHeader = fopen(outputFileHeader, "w");


    //first time, print in the source file the struct declarations with marker, from the header!!!

    ListOfStructDefinitions * reversedNormalDecl = reverseListOfStructDefinitions(ListOfDecl.normalDeclarations);

    ListOfStructDefinitions * auxNormalDeclJustHeader = reversedNormalDecl;
    while (auxNormalDeclJustHeader) {
        ListOfString * auxNormalElements = auxNormalDeclJustHeader->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //nothing here, after structs!
        } else {
            while (auxNormalElements) {
                fprintf(foutHeader, "%s", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
        }

        ///ListOfString * auxNormalElementsForStructArray = auxNormalDeclJustHeader->headerDefinition;
        if (auxNormalDeclJustHeader->headerDefinition && strstr(auxNormalDeclJustHeader->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
            //fprintf(fout, "%s", auxNormalDeclJustHeader->headerDefinition);

        }


        auxNormalDeclJustHeader = auxNormalDeclJustHeader->next;
    }




    ListOfStructDefinitions * reversedStructDecl = reverseListOfStructDefinitions(ListOfDecl.structUnionDeclarations);

    ListOfStructDefinitions * auxStructDecl = reversedStructDecl;
    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;


        if (!strstr(auxStructElements->el, TYPEDEF_MARKER_TEMP)) {
            while (auxStructElements) {
                fprintf(fout, "%s", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
            if (auxStructDecl->headerDefinition) {
                fprintf(foutHeader, "%s\n\n", auxStructDecl->headerDefinition);

            }
        } else {
            while (auxStructElements) {
                fprintf(foutHeader, "%s", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
        }
        auxStructDecl = auxStructDecl->next;
    }



    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDecl.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        ListOfString * auxStructElements = auxTypeDecl->structDef;
        while (auxStructElements) {
            fprintf(foutHeader, "%s", auxStructElements->el);
            auxStructElements = auxStructElements->next;
        }

        //fprintf(foutHeader, "%s\n\n", auxTypeDecl->el);
        auxTypeDecl = auxTypeDecl->next;
    }





    ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //fprintf(fout, "%s\n\n", auxNormalElements->el);
            while (auxNormalElements) {
                fprintf(fout, "%s", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
            fprintf(fout, "\n\n");
            if (auxNormalDecl->headerDefinition && !strstr(auxNormalDecl->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
                fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
            }
        } else {
            //nothing here, it was added before the structs!
        }

        /*
        if (!strstr(auxNormalDecl->declaration, ENUM_MARKER)) {
            fprintf(fout, "%s\n\n", auxNormalDecl->declaration);
        } else {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->declaration);
        }
        if (auxNormalDecl->headerDefinition) {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
        }
         */
        auxNormalDecl = auxNormalDecl->next;
    }









    fclose(fout);
    fclose(foutHeader);
}

#ifdef MULTIFILE_VAR_EXTRACTION

void addVarDeclarationIntoVeinHeaderFilesAndInterface(ListOfStructDefinitions * varDeclHeader, char * outputFile){
    fflush(stdout);

    char *formattedFileOutputPath = NULL;
    formattedFileOutputPath = (char *) malloc(
            (strlen(varDeclHeader->file) + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof(char));
    sprintf(formattedFileOutputPath, "%s%s", TXLTemporaryMultiFileFolder, varDeclHeader->file);

    if(strstr(varDeclHeader->file,".c")){

        addLocsFromSourceToDestination(InterfaceCoreFunctionality,
                                       outputFile, TXLToolsPath);

    }else {
        if (file_exists(formattedFileOutputPath)) {
            createFile(formattedFileOutputPath);
            /*LOS Add new file in temp_all_header_files_target.out*/
            char *tempAllHeaderFilesTargetPath = NULL;
            tempAllHeaderFilesTargetPath = (char *) malloc(500 * sizeof(char));
            sprintf(tempAllHeaderFilesTargetPath, "%stemp_list_of_header_files_extracted.out", TXLTemporaryMultiFileFolder);

            ListOfString *listOfHeaderFilesExtracted = readListOfStringFromFile(tempAllHeaderFilesTargetPath);
            if (!searchStringInListOfStrings(listOfHeaderFilesExtracted, varDeclHeader->file)) {
                //Add new file name into temp_all_header_files_target.out
                addAStringsInTheEndFileLN(varDeclHeader->file, tempAllHeaderFilesTargetPath);
               /* addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,
                                               outputHeader, TXLToolsPath);*/
               // addNewString(&listOfHeaderFilesExtracted, varDeclHeader->file);
            }
        }

        addLocsFromSourceToDestination(formattedFileOutputPath,
                                       outputFile, TXLToolsPath);


    }

}

void addVarDeclarationIntoOrganSourceAndHeaderFiles(ListOfStructDefinitions * varDeclHeader, char * outputFile, char * outputHeader) {
    fflush(stdout);

    char *formattedFileOutputPath = (char *) malloc(500 * sizeof(char));
    sprintf(formattedFileOutputPath, "%s%s", TXLTemporaryMultiFileFolder, varDeclHeader->file);

  /*if (strstr(varDeclHeader->file, donorEntryFile)) {

            InterfaceCoreFunctionality = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof(char));
            sprintf(InterfaceCoreFunctionality, "%s%s", TXLTemporaryFolderMainThread, "InterfaceCoreFunctionality.c");

            /* SkeletonCoreFeatureHeader = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
             sprintf(SkeletonCoreFeatureHeader, "%s%s", TXLTemporaryFolderMainThread, "NeededFunctionsHeader.h");*/

           // addLocsFromSourceToDestination(InterfaceCoreFunctionality, outputFile, TXLToolsPath);
         /*   addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,outputHeader, TXLToolsPath);
        }*/
            //Create and add new file and add it in list temp_all_header_files_target.out
            /*LOS Add new file in temp_all_header_files_target.out*/
            char *tempAllHeaderFilesTargetPath = NULL;
            tempAllHeaderFilesTargetPath = (char *) malloc(500 * sizeof(char));
            sprintf(tempAllHeaderFilesTargetPath, "%stemp_list_of_header_files_extracted.out",
                    TXLTemporaryMultiFileFolder);

            char *tempAllSourceFilesTargetPath = NULL;
            tempAllSourceFilesTargetPath = (char *) malloc(500 * sizeof(char));
            sprintf(tempAllSourceFilesTargetPath, "%stemp_list_of_source_files_extracted.out",
                    TXLTemporaryMultiFileFolder);

            if (file_exists(formattedFileOutputPath))
                createFile(formattedFileOutputPath);

            /* Only copy header files */
            if (strstr(varDeclHeader->file, ".h")) {
                char *formattedFileOutputPath = NULL;
                formattedFileOutputPath = (char *) malloc(
                        (strlen(varDeclHeader->file) + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof(char));
                sprintf(formattedFileOutputPath, "%s%s", TXLTemporaryMultiFileFolder, varDeclHeader->file);

                char *hederTempDonorFolder = (char *) malloc(500 * sizeof(char));
                sprintf(hederTempDonorFolder, "%s%s", tempDonorSourceFileFolder, varDeclHeader->file);

                char *commandCopySourceFiles = (char *) malloc(5000 * sizeof(char));
                sprintf(commandCopySourceFiles, "cp %s %s", hederTempDonorFolder, formattedFileOutputPath);
                int statusCommand = system(commandCopySourceFiles);
                if (statusCommand != 0) {
                    printf("Erro: Trying copy header file: %s", hederTempDonorFolder);
                    exit(1);
                }
                ListOfString *ListOfHeaderFilesExtracted = readListOfStringFromFileAsWords(
                        tempAllHeaderFilesTargetPath);
                if (!searchStringInListOfStrings(ListOfHeaderFilesExtracted, varDeclHeader->file))
                    addAStringsInTheEndFileLN(varDeclHeader->file, tempAllHeaderFilesTargetPath);

                fflush(stdout);
            } else {
                /* Create header files */
                ListOfString *ListOfSourceFilesExtracted = readListOfStringFromFileAsWords(
                        tempAllSourceFilesTargetPath);
                if (!searchStringInListOfStrings(ListOfSourceFilesExtracted, varDeclHeader->file))
                    addAStringsInTheEndFileLN(varDeclHeader->file, tempAllSourceFilesTargetPath);

                addLocsFromSourceToDestination(formattedFileOutputPath, outputFile, TXLToolsPath);
            }

            //    addLocsFromSourceToDestination(formattedFileOutputPath,outputFile, TXLToolsPath);
            /*  addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,
                                            outputHeader, TXLToolsPath);
              addLocsFromSourceToDestination(formattedFileOutputPath,outputFile, TXLToolsPath); */
            ///printf("\t\tHeader: %s\n", varDeclHeader->file);

            /*  ListOfString *listOfHeaderFilesExtracted = readListOfStringFromFile(tempAllHeaderFilesTargetPath);
              if (!searchStringInListOfStrings(listOfHeaderFilesExtracted, varDeclHeader->file)) {
                  //Add new file name into temp_all_header_files_target.out
                  addAStringsInTheEndFileLN(varDeclHeader->file, tempAllHeaderFilesTargetPath);
                  addNewString(&listOfHeaderFilesExtracted, varDeclHeader->file);*/

        //}


       /* }*/

}
char * getMarkFromDeclaration(ListOfStructDefinitions * ListOfStructUnionDeclarations, char * declaration){

    while (ListOfStructUnionDeclarations){
        if(strstr(ListOfStructUnionDeclarations->structDef->el, declaration)) {
            char * declMark = (char *) malloc((strlen(ListOfStructUnionDeclarations->structDef->el) + 1) * sizeof(char));
            /*return the struct definition as words list*/
            strcpy(declMark,readSubstring("/* ", ListOfStructUnionDeclarations->structDef->el, " */"));
            return declMark;
        }
        ListOfStructUnionDeclarations = ListOfStructUnionDeclarations->next;
    }
    return NULL;
}

char * getMarkFromAnDeclaration(char * declaration){

            char * declMark = NULL;
            declMark = (char *) malloc((strlen(declaration) + 1) * sizeof(char));
            strcpy(declMark,readSubstring("/* ", declaration, " */"));
            return declMark;
}

ListOfStructDefinitions * getGlobalDeclarationFromMarker(GlobalDeclarations ListOfDecl, char *declarationMark) {

    ListOfStructDefinitions * auxNormalDecl = ListOfDecl.normalDeclarations;
   // char *currentDeclarationElement = (char *) malloc(500 * sizeof(char));
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
       // strcpy(currentDeclarationElement,auxNormalElements->el);
        if(strstr(auxNormalElements->el, declarationMark)) {
            return auxNormalDecl;
        }
        auxNormalDecl = auxNormalDecl->next;
    }
    ListOfStructDefinitions * auxStructDecl = ListOfDecl.structUnionDeclarations;
    while (auxStructDecl) {
        ListOfString *auxStructElements = auxStructDecl->structDef;
     //   strcpy(currentDeclarationElement,auxStructElements->el);
        if(strstr(auxStructElements->el, declarationMark)) {
            return auxStructDecl;
        }
        auxStructDecl = auxStructDecl->next;
    }
    ListOfStructDefinitions * auxTypedefDecl = ListOfDecl.typedefDeclarations;
    while (auxTypedefDecl) {
        ListOfString *auxTypeElements = auxTypedefDecl->structDef;
      //  strcpy(currentDeclarationElement,auxTypeElements->el);
        if(strstr(auxTypeElements->el, declarationMark)) {
            return auxTypedefDecl;
        }
        auxTypedefDecl = auxTypedefDecl->next;
    }
    return NULL;
}

void printStructDeclarationDependency(char *currentDeclElement, GlobalDeclarations ListOfAllDonorGlobalDeclarations,char * outputFileSource, char * outputFileHeader){
    char *tempGlobalDefsFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalDefsFile, "%stemp_global_defs_file_output.out", TXLTemporaryFolderMainThread);
    fflush(stdout);
    GlobalDeclarations ListOfAllGlobalDeclarations= readGlobalDeclarationFromFileWithFile(tempGlobalDefsFile);


    char * currentDeclStructMark = NULL;
    DependencyList * auxDestination = NULL;
    char *tempGlobalDependencies =  (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryFolderMainThread);

    DependencyList * dependencyList = readDependencyListFromFile(tempGlobalDependencies);
    char *formatedCurrentDeclStructMark = (char *) malloc(500 * sizeof(char));
   // ListOfStructDefinitions * auxNormalDecl = ListOfAllDonorGlobalDeclarations.normalDeclarations;
  //  ListOfString * auxNormalElements = auxNormalDecl->structDef;
  //  currentDeclStructMark = getMarkFromDeclaration(auxNormalDecl,currentDeclElement);
    currentDeclStructMark = getMarkFromAnDeclaration(currentDeclElement);
    sprintf(formatedCurrentDeclStructMark, "/* %s */", currentDeclStructMark);
    auxDestination = searchDependenciesForAnElement(dependencyList, formatedCurrentDeclStructMark);
    ListOfString * auxListOfDependencies = NULL;
    if(auxDestination)
       auxListOfDependencies = auxDestination->ListOfDependencies;

    while(auxListOfDependencies) {
        ListOfStructDefinitions *currentDependency = getGlobalDeclarationFromMarker(ListOfAllGlobalDeclarations, auxListOfDependencies->el);
        ListOfString * auxDependencyDecl = currentDependency->structDef;

        if (auxDependencyDecl) {
            FILE * fout = fopen(outputFileSource, "w");
            while (auxDependencyDecl) {
                fprintf(fout, "%s", auxDependencyDecl->el);
                auxDependencyDecl = auxDependencyDecl->next;
            }
            fprintf(fout, "\n\n");
            fclose(fout);
            addVarDeclarationIntoOrganSourceAndHeaderFiles(currentDependency, outputFileSource, outputFileHeader);
        }

        auxListOfDependencies = auxListOfDependencies->next;
    }
}
void printGlobalDeclElementForSourceFile(FILE * fout, char *outputFileSource, ListOfString * auxNormalElements){
    //fprintf(fout, "%s\n\n", auxNormalElements->el);
    fout = fopen(outputFileSource, "w");
    while (auxNormalElements) {
        fprintf(fout, "%s", auxNormalElements->el);
        auxNormalElements = auxNormalElements->next;
    }
    fprintf(fout, "\n\n");
    fclose(fout);
}

void printGlobalDeclElementForHeaderFile(FILE * foutHeader, char *outputFileHeader, char * headerDefinition){
    foutHeader = fopen(outputFileHeader, "w");
    fprintf(foutHeader, "%s\n\n", headerDefinition);
    fclose(foutHeader);
}
void printListOfGlobalDeclarationsForOrgan(GlobalDeclarations ListOfAllDonorGlobalDeclarations, GlobalDeclarations ListOfDecl, char * outputFileSource,
                                     char * outputFileHeader) {
    FILE * fout = NULL;
    FILE * foutHeader = NULL;
    char * definition = (char *) malloc(500 * sizeof (char));
    char * coreFunctionFile=(char *) malloc(500 * sizeof (char));
    /* Replace donor path to tempoDonorFiles path */
    strcpy(coreFunctionFile, replace_str(donorSourceFileFolder, "TempDonorFiles/","Donor/"));
    strcpy(coreFunctionFile, readSubstring(coreFunctionFile, inputFileGraft, ".c"));
    strcat(coreFunctionFile,".c");

    ListOfStructDefinitions * auxNormalDecl = ListOfDecl.normalDeclarations;
     while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        strcpy(definition, auxNormalDecl->headerDefinition);

         if(strstr(auxNormalElements->el, "struct regmatch_t"))
             printf("struct regmatch_t");
        if (strstr(auxNormalElements->el, STRUCT_TYPE)) {// if struct declaration
            printGlobalDeclElementForSourceFile(fout, outputFileSource, auxNormalElements);//print declaration into temp_source
            addVarDeclarationIntoOrganSourceAndHeaderFiles(auxNormalDecl, outputFileSource, outputFileHeader);//add declaration into source_file
            if (definition && !strstr(definition, STRUCT_ARRAY_HEADER_DECLARATION)) {//if struct array
                printGlobalDeclElementForHeaderFile(foutHeader, outputFileHeader, definition);
                addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,outputFileHeader, TXLToolsPath);
            }
            if (!strcmp(auxNormalDecl->file, donorEntryFile)){//if is the organ entry point file, insert it into the coreFunctionalityInterface file
                printGlobalDeclElementForHeaderFile(foutHeader, outputFileHeader, definition);//print struct array into temp_source file
               /// addLocsFromSourceToDestination(InterfaceCoreFunctionality,outputFileHeader, TXLToolsPath);//add it into coreFunctionalityInterface
            }else {
                auxNormalElements = auxNormalDecl->structDef;
                printStructDeclarationDependency(auxNormalElements->el, ListOfAllDonorGlobalDeclarations,
                                                 outputFileSource,
                                                 outputFileHeader);// Insert current declaration dependencies
            }
        }
        auxNormalDecl = auxNormalDecl->next;
    }

    ListOfStructDefinitions * auxStructDecl = ListOfDecl.structUnionDeclarations;
    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;
        strcpy(definition,auxStructDecl->headerDefinition);
        if(strstr(auxStructDecl->structDef, "struct regmatch_t"))
            printf("struct regmatch_t");
        if (!strstr(auxStructElements->el, TYPEDEF_MARKER_TEMP)) {
            printGlobalDeclElementForSourceFile(fout, outputFileSource, auxStructElements);
         //   addVarDeclarationIntoOrganSourceAndHeaderFiles(auxStructDecl, outputFileSource, outputFileHeader);
            printGlobalDeclElementForHeaderFile(foutHeader, outputFileHeader, definition);
            if (!strcmp(auxStructDecl->file, donorEntryFile))
                addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,outputFileSource, TXLToolsPath);//add struct definition into interface_heard
           else
             addVarDeclarationIntoOrganSourceAndHeaderFiles(auxStructDecl, outputFileSource, outputFileHeader); /* add var into its correspondent file *///delete colocando todas as declaraçoes de variaveis no Header.h

        } else {
            printGlobalDeclElementForSourceFile(fout, outputFileSource, auxStructElements);
            addAStringsInTheFile(definition, outputFileHeader);

            if (auxStructDecl->file!=NULL && !strcmp(auxStructDecl->file, coreFunctionFile))
                addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, outputFileHeader, TXLToolsPath);
        }
        auxStructDecl = auxStructDecl->next;
    }

    ///ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    auxNormalDecl = ListOfDecl.normalDeclarations;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        strcpy(definition,auxNormalDecl->headerDefinition);
        if(strstr(auxNormalElements->el, "struct regmatch_t"))
            printf("struct regmatch_t");
        if (!strstr(auxNormalElements->el, STRUCT_TYPE)) {
            printGlobalDeclElementForSourceFile(fout, outputFileSource, auxNormalElements);
            addVarDeclarationIntoOrganSourceAndHeaderFiles(auxNormalDecl, outputFileSource, outputFileHeader);

            if (definition && !strstr(definition, STRUCT_ARRAY_HEADER_DECLARATION))
                printGlobalDeclElementForHeaderFile(foutHeader, outputFileHeader, definition);

            if (!strcmp(auxNormalDecl->file, donorEntryFile))
                addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, outputFileHeader, TXLToolsPath);//add decl with extern into InterfaceHeader.h

            // Insert current declaration dependencies
            auxNormalElements = auxNormalDecl->structDef;
        //    printStructDeclarationDependency(auxNormalElements->el, ListOfAllDonorGlobalDeclarations,outputFileSource, outputFileHeader);

        }

        auxNormalDecl = auxNormalDecl->next;
    }

    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDecl.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        if(strstr(auxTypeDecl->structDef, "struct regmatch_t"))
            printf("struct regmatch_t");
        ListOfString * auxTypeStructElements = auxTypeDecl->structDef;
        strcpy(definition,auxTypeDecl->headerDefinition);
        printGlobalDeclElementForSourceFile(fout, outputFileSource, auxTypeStructElements);
        addAStringsInTheFile(definition, outputFileHeader);
        // addVarDeclarationIntoOrganSourceAndHeaderFiles(auxTypeDecl, outputFileSource, outputFileHeader);
        if (!strcmp(auxTypeDecl->file, donorEntryFile))
            addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, outputFileSource, TXLToolsPath);
        auxTypeDecl = auxTypeDecl->next;
    }

}

int removeGlobalDeclaration(ListOfStructDefinitions ** head, char * decl){
    fflush(stdout);
    ListOfStructDefinitions * p;
        p = *head;
        int s = 0;
        if (!strcmp(p->headerDefinition, decl)) {
            *head = p->next;
            free(p->headerDefinition);
            free(p->file);
            freeListOfStrings(&p->structDef);
            p->headerDefinition = NULL;
            p->file = NULL;
            p->structDef = NULL;
            free(p);
            p = NULL;
            s = 1;
        } else {
            while (p->next && s == 0) {
                if (!strcmp(p->next->headerDefinition, decl)) {
                    ListOfStructDefinitions * aux;
                    aux = p->next;
                    p -> next = p -> next -> next;
                    free(aux->headerDefinition);
                    free(aux->file);
                    freeListOfStrings(&aux->structDef);
                    aux->headerDefinition = NULL;
                    aux->file = NULL;
                    aux->structDef = NULL;
                    free(aux);
                    aux = NULL;
                    s = 1;
                } else {
                    p = p->next;
                }

            }
        }

        return s;
}



ListOfStructDefinitions * searchDeclarationInListOfDeclaration(ListOfStructDefinitions * head, char * decl) {
    ListOfStructDefinitions * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->headerDefinition, decl)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}




int addVarDeclarationIntoFile(int *newDeclarationImplanted, char * finalFileToImplantation, char * TempImplantationDirectory, ListOfStructDefinitions * varDeclHeaderInHost, ListOfStructDefinitions ** ListOfDeclarationInOrgan, char * outputHostFile ,
                               char * outputOrganFile) {

    /* Check if variables have the same signatur ----------------------------*/
    char * hostDeclAST = (char *) malloc((strlen(TempImplantationDirectory) + 30) * sizeof(char));
    char * organDeclAST = (char *) malloc((strlen(TempImplantationDirectory) + 30) * sizeof(char));

    char * hostCurrentHeaderDefinition = varDeclHeaderInHost->headerDefinition;
    ListOfStructDefinitions * foundDeclarationInOrgan = NULL;
    foundDeclarationInOrgan = searchDeclarationInListOfDeclaration((*ListOfDeclarationInOrgan), hostCurrentHeaderDefinition);

    if (foundDeclarationInOrgan != NULL) {
        ListOfString * currentDeclarationInOrgan = foundDeclarationInOrgan->structDef;

        printAListOfStrings(currentDeclarationInOrgan, outputOrganFile);

        sprintf(hostDeclAST, "%sHostAST.c", TempImplantationDirectory);
        createFile(hostDeclAST);
        addLocsFromSourceToDestinationWithDirectives(hostDeclAST, outputHostFile, TXLToolsPath);

        sprintf(organDeclAST, "%sOrgantAST.c", TempImplantationDirectory);
        createFile(organDeclAST);
        addLocsFromSourceToDestination(organDeclAST, outputOrganFile, TXLToolsPath);
        fflush(stdout);
            /* Check if ASTs are equals ----------------------------*/
        if (!ASTIsEqual(organDeclAST, hostDeclAST)) {
#if 0  /*Proposal to merge organ and host when the organ's declaration regect some host statement */
            /* Duplication does not detected. Merge organ and host declarations */
            char * mergeResultFile;
             mergeResultFile = (char *) malloc(500 * sizeof (char));
               sprintf(mergeResultFile, "%smergeResultFile.c", TempImplantationDirectory);

                //mergeElements(mergeResultFile, organDeclAST, hostDeclAST, "F_WRITE");
                addLocsFromSourceToDestinationWithDirectives(finalFileToImplantation, mergeResultFile, TXLToolsPath);
                removeGlobalDeclaration(varDeclHeaderInOrgan, (*varDeclHeaderInOrgan)->headerDefinition);
         }else{
#endif
            /* Duplication detected. Re-implant declaration from host ------------------------------ */
            printf("\t\t\tDuplication detected. Re-implant declaration from host.\n");
            addLocsFromSourceToDestination(finalFileToImplantation,
                                               outputHostFile, TXLToolsPath);
            removeGlobalDeclaration(ListOfDeclarationInOrgan, varDeclHeaderInHost->headerDefinition);
        }else{
            /* Code clone detected. Implanting current declaration from organ into the host  -----------*/
            addLocsFromSourceToDestination(finalFileToImplantation,
                                                            outputOrganFile, TXLToolsPath);
            removeGlobalDeclaration(ListOfDeclarationInOrgan, varDeclHeaderInHost->headerDefinition);
            (*newDeclarationImplanted) = 1;
        }

    }else{
        /* Declaration from host does not duplicated. Re-implant. ------------------------*/
        fflush(stdout);
        addLocsFromSourceToDestination(finalFileToImplantation,
                                                         outputHostFile, TXLToolsPath);
    }

}

/* PRINT DECLARATION TO IMPLANT ------------------------------------------------------------------------------*/
void printListOfGlobalDeclarations1(int *newDeclarationImplanted, char * currentFile, char * TempImplantationDirectory, GlobalDeclarations ListOfDeclInHost, GlobalDeclarations ListOfDeclInOrgan, char * outputHostFile ,
                                           char * outputOrganFile) {

    char *finalFileToImplantation = (char *) malloc(500 * sizeof(char));
    sprintf(finalFileToImplantation, "%s%s", TempImplantationDirectory, currentFile);

   /// ListOfStructDefinitions *auxStructDecl = ListOfDeclInHost.structUnionDeclarations;
    ListOfStructDefinitions * reversedStructDecl = reverseListOfStructDefinitions(ListOfDeclInHost.structUnionDeclarations);

    ListOfStructDefinitions * auxStructDecl = reversedStructDecl;
    /* Analyze and implant structs -----------------------------------------------*/
    printf("[AUTOSCALPEL] Implanting global declarations in file: %s...\n", currentFile);
    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;
        printAListOfStrings(auxStructElements, outputHostFile);
        /* add var into its correspondent file */
        addVarDeclarationIntoFile(&newDeclarationImplanted, finalFileToImplantation, TempImplantationDirectory, auxStructDecl,
                                      &ListOfDeclInOrgan.structUnionDeclarations,
                                      outputHostFile, outputOrganFile);
        auxStructDecl = auxStructDecl->next;
    }
    /* Implant new declaration from organ */
    ListOfStructDefinitions *remainingListOfDeclInOrgan = ListOfDeclInOrgan.structUnionDeclarations;
    while(remainingListOfDeclInOrgan){
        ListOfString * auxStructElements = remainingListOfDeclInOrgan->structDef;
        printAListOfStrings(auxStructElements, outputOrganFile);
        addLocsFromSourceToDestination(finalFileToImplantation,
                                       outputOrganFile, TXLToolsPath);
        remainingListOfDeclInOrgan = remainingListOfDeclInOrgan->next;
        (*newDeclarationImplanted) = 1;
    }

    /* Analyze and implant normal var and Enums -----------------------------------------------*/
    ListOfStructDefinitions * reversedNormalDecl = reverseListOfStructDefinitions(ListOfDeclInHost.normalDeclarations);
    ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        printAListOfStrings(auxNormalElements, outputHostFile);
        addVarDeclarationIntoFile(&newDeclarationImplanted, finalFileToImplantation, TempImplantationDirectory, auxNormalDecl, &ListOfDeclInOrgan.normalDeclarations,
                                      outputHostFile, outputOrganFile);
        auxNormalDecl = auxNormalDecl->next;
    }
    /* Implant new declaration from organ */
    ListOfStructDefinitions *remainingListOfNormalDeclInOrgan = ListOfDeclInOrgan.normalDeclarations;
    while(remainingListOfNormalDeclInOrgan){
        ListOfString * auxStructElements = remainingListOfNormalDeclInOrgan->structDef;
        printAListOfStrings(auxStructElements, outputOrganFile);
        addLocsFromSourceToDestination(finalFileToImplantation,
                                       outputOrganFile, TXLToolsPath);
        remainingListOfNormalDeclInOrgan = remainingListOfNormalDeclInOrgan->next;
        (*newDeclarationImplanted) = 1;
    }

    /* Analyze and implant typedefs -----------------------------------------------*/
    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDeclInHost.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        ListOfString * auxStructElements = auxTypeDecl->structDef;
        printAListOfStrings(auxStructElements, outputHostFile);
        addVarDeclarationIntoFile(&newDeclarationImplanted, finalFileToImplantation, TempImplantationDirectory, auxTypeDecl, &ListOfDeclInOrgan.typedefDeclarations,
                                  outputHostFile, outputOrganFile);
        auxTypeDecl = auxTypeDecl->next;
    }
    /* Implant new declaration from organ */
    ListOfStructDefinitions *remainingListOfTypedefDeclInOrgan = ListOfDeclInOrgan.typedefDeclarations;
    while(remainingListOfTypedefDeclInOrgan){
        ListOfString * auxStructElements = remainingListOfTypedefDeclInOrgan->structDef;
        printAListOfStrings(auxStructElements, outputOrganFile);
        addLocsFromSourceToDestination(finalFileToImplantation,
                                       outputOrganFile, TXLToolsPath);
        remainingListOfTypedefDeclInOrgan = remainingListOfTypedefDeclInOrgan->next;
        (*newDeclarationImplanted) = 1;
    }

}



void printListOfGlobalDeclarationsForSkeleton(GlobalDeclarations ListOfDecl,DependencyList * GlobalDependencyList, char * outputFileSource,
                                   char * outputFileHeader) {

    FILE *fout = NULL;
    FILE *foutHeader = NULL;

    //first time, print in the source file the struct declarations with marker, from the header!!!
    ListOfStructDefinitions *reversedNormalDecl = reverseListOfStructDefinitions(ListOfDecl.normalDeclarations);


    ListOfStructDefinitions *reversedStructDecl = reverseListOfStructDefinitions(ListOfDecl.structUnionDeclarations);

    ListOfStructDefinitions *auxStructDecl = ListOfDecl.structUnionDeclarations;
   /* ListOfStructDefinitions *newStructDecl;
    while (auxStructDecl) {
        addNewString(&newStructDecl, returnDependencyForAMarker(GlobalDependencyList, auxStructDecl->structDef->el,newStructDecl));
        auxStructDecl = auxStructDecl->next;
    }
    auxStructDecl = ListOfDecl.structUnionDeclarations;*/

    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;
        if (!strstr(auxStructElements->el, TYPEDEF_MARKER_TEMP)) {
            fout = fopen(outputFileSource, "w");
            while (auxStructElements) {
                fprintf(fout, "%s", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }
            fprintf(fout, "\n\n");
            fclose(fout);
            /* add var into its correspondent file */
            addVarDeclarationIntoVeinHeaderFilesAndInterface(auxStructDecl, outputFileSource);

            if (auxStructDecl->headerDefinition) {
                foutHeader = fopen(outputFileHeader, "w");
                fprintf(foutHeader, "%s\n\n", auxStructDecl->headerDefinition);
                fclose(foutHeader);

                /* add var into its correspondent file */
                char * NeededFunctionsHeader = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
                sprintf(NeededFunctionsHeader, "%s%s", TXLTemporaryFolderMainThread, "NeededFunctionsHeader.h");

                addLocsFromSourceToDestination(NeededFunctionsHeader,
                                               outputFileHeader, TXLToolsPath);

             //   addVarDeclarationIntoVeinHeaderFilesAndInterface(auxStructDecl, outputFileHeader);

            }
        } else {
            foutHeader = fopen(outputFileHeader, "w");
            while (auxStructElements) {
                fprintf(foutHeader, "%s", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }
            fprintf(foutHeader, "\n\n");
            fclose(foutHeader);

            /* add var into its correspondent file*/
            addVarDeclarationIntoVeinHeaderFilesAndInterface(auxStructDecl, outputFileHeader);


           /* FILE * fout = fopen(outputFileSource, "w");
            fprintf(fout, "\n\n");
            fclose(fout);*/

            /* add var into its correspondent file*/
           // addVarDeclarationIntoVeinHeaderFilesAndInterface(auxStructDecl, outputFileSource);
        }
        auxStructDecl = auxStructDecl->next;
    }

    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDecl.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        ListOfString * auxStructElements = auxTypeDecl->structDef;
        foutHeader = fopen(outputFileHeader, "w");
        while (auxStructElements) {
            fprintf(foutHeader, "%s", auxStructElements->el);
            auxStructElements = auxStructElements->next;
        }
        fprintf(foutHeader, "\n\n");
        fclose(foutHeader);
        /* add var into its correspondent file */
        addVarDeclarationIntoVeinHeaderFilesAndInterface(auxTypeDecl, outputFileHeader);
        //fprintf(foutHeader, "%s\n\n", auxTypeDecl->el);
        auxTypeDecl = auxTypeDecl->next;
    }

    ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //fprintf(fout, "%s\n\n", auxNormalElements->el);
            fout = fopen(outputFileSource, "w");
            while (auxNormalElements) {
                fprintf(fout, "%s", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
            fprintf(fout, "\n\n");
            fclose(fout);
            /* add var into its correspondent file */
            addVarDeclarationIntoVeinHeaderFilesAndInterface(auxNormalDecl, outputFileSource);

            fprintf(fout, "\n\n");
            if (auxNormalDecl->headerDefinition && !strstr(auxNormalDecl->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
                foutHeader = fopen(outputFileHeader, "w");
                fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
                fclose(foutHeader);
                /* add var into its correspondent file */

           //addVarDeclarationIntoVeinHeaderFilesAndInterface(auxNormalDecl, outputFileSource);
            }
        } else {
            //nothing here, it was added before the structs!
        }

        /*
        if (!strstr(auxNormalDecl->declaration, ENUM_MARKER)) {
            fprintf(fout, "%s\n\n", auxNormalDecl->declaration);
        } else {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->declaration);
        }
        if (auxNormalDecl->headerDefinition) {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
        }
         */
        auxNormalDecl = auxNormalDecl->next;
    }


    ListOfStructDefinitions * auxNormalDeclJustHeader = reversedNormalDecl;
    while (auxNormalDeclJustHeader) {
        ListOfString * auxNormalElements = auxNormalDeclJustHeader->structDef;


        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //nothing here, after structs!
        } else {
            while (auxNormalElements) {
                foutHeader = fopen(outputFileHeader, "w");
                fprintf(foutHeader, "%s", auxNormalElements->el);
                fclose(foutHeader);

                /* add var into its correspondent file*/
                addVarDeclarationIntoVeinHeaderFilesAndInterface(auxNormalDeclJustHeader, outputFileHeader);

                auxNormalElements = auxNormalElements->next;
            }
        }

        ///ListOfString * auxNormalElementsForStructArray = auxNormalDeclJustHeader->headerDefinition;
        if (auxNormalDeclJustHeader->headerDefinition && strstr(auxNormalDeclJustHeader->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
            //fprintf(fout, "%s", auxNormalDeclJustHeader->headerDefinition);

        }

        auxNormalDeclJustHeader = auxNormalDeclJustHeader->next;
    }



}
#endif
#ifdef SEARCH_VAR_UNION
/* LOSIMPLEMENTTATION list of global variables extracted to be used to variable union identification.*/


void printAllListOfGlobalDeclarationsExtracted(GlobalDeclarations ListOfDecl,
                                               char * outputVarExtracted) {
    FILE * fout = fopen(outputVarExtracted, "w");
   // printf("-------\nprintAllListOfGlobalDeclarationsExtracted\n-------\n");
    //first time, print in the source file the struct declarations with marker, from the header!!!

    ListOfStructDefinitions * reversedNormalDecl = reverseListOfStructDefinitions(ListOfDecl.normalDeclarations);

    ListOfStructDefinitions * auxNormalDeclJustHeader = reversedNormalDecl;
    while (auxNormalDeclJustHeader) {
        ListOfString * auxNormalElements = auxNormalDeclJustHeader->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //nothing here, after structs!
        } else {
            while (auxNormalElements) {
                fprintf(fout, "%s", auxNormalElements->el);
                //printf("NormalElements: %s\n", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
        }

        ///ListOfString * auxNormalElementsForStructArray = auxNormalDeclJustHeader->headerDefinition;
        if (auxNormalDeclJustHeader->headerDefinition && strstr(auxNormalDeclJustHeader->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
            //fprintf(fout, "%s", auxNormalDeclJustHeader->headerDefinition);

        }


        auxNormalDeclJustHeader = auxNormalDeclJustHeader->next;
    }




    ListOfStructDefinitions * reversedStructDecl = reverseListOfStructDefinitions(ListOfDecl.structUnionDeclarations);

    ListOfStructDefinitions * auxStructDecl = reversedStructDecl;
    while (auxStructDecl) {
        ListOfString * auxStructElements = auxStructDecl->structDef;


        if (!strstr(auxStructElements->el, TYPEDEF_MARKER_TEMP)) {
            while (auxStructElements->next->next) {
                auxStructElements = auxStructElements->next;
                fprintf(fout, "%s", auxStructElements->el);
               // printf("auxStructElements: %s\n", auxStructElements->el);

            }



            fprintf(fout, "\n\n");
          /*  if (auxStructDecl->headerDefinition) {
                fprintf(fout, "%s\n\n", auxStructDecl->headerDefinition);
                printf("auxStructDecl: %s\n", auxStructDecl->headerDefinition);
            }*/
        } else {
            while (auxStructElements) {
                fprintf(fout, "%s", auxStructElements->el);
             //   printf("auxStructElements: %s\n", auxStructElements->el);
                auxStructElements = auxStructElements->next;
            }



            fprintf(fout, "\n\n");
        }
        auxStructDecl = auxStructDecl->next;
    }



    ListOfStructDefinitions * reversedTypeDefDecl = reverseListOfStructDefinitions(ListOfDecl.typedefDeclarations);
    ListOfStructDefinitions * auxTypeDecl = reversedTypeDefDecl;
    while (auxTypeDecl) {
        ListOfString * auxStructElements = auxTypeDecl->structDef;
        while (auxStructElements) {
            fprintf(fout, "%s", auxStructElements->el);
           // printf("auxStructElements: %s\n", auxStructElements->el);
            auxStructElements = auxStructElements->next;
        }

        //fprintf(foutHeader, "%s\n\n", auxTypeDecl->el);
        auxTypeDecl = auxTypeDecl->next;
    }





    ListOfStructDefinitions * auxNormalDecl = reversedNormalDecl;
    while (auxNormalDecl) {
        ListOfString * auxNormalElements = auxNormalDecl->structDef;
        if (!strstr(auxNormalElements->el, ENUM_MARKER)) {
            //fprintf(fout, "%s\n\n", auxNormalElements->el);
            while (auxNormalElements) {
                fprintf(fout, "%s", auxNormalElements->el);
              //  printf("auxNormalElements: %s\n", auxNormalElements->el);
                auxNormalElements = auxNormalElements->next;
            }
            fprintf(fout, "\n\n");
            if (auxNormalDecl->headerDefinition && !strstr(auxNormalDecl->headerDefinition, STRUCT_ARRAY_HEADER_DECLARATION)) {
                fprintf(fout, "%s\n\n", auxNormalDecl->headerDefinition);
              //  printf("auxNormalDecl: %s\n", auxNormalDecl->headerDefinition);
            }
        } else {
            //nothing here, it was added before the structs!
        }

        /*
        if (!strstr(auxNormalDecl->declaration, ENUM_MARKER)) {
            fprintf(fout, "%s\n\n", auxNormalDecl->declaration);
        } else {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->declaration);
        }
        if (auxNormalDecl->headerDefinition) {
            fprintf(foutHeader, "%s\n\n", auxNormalDecl->headerDefinition);
        }
         */
        auxNormalDecl = auxNormalDecl->next;
    }



    fclose(fout);
}

#endif

void addGlobalDeclarationListToExistingOne(GlobalDeclarations * head, GlobalDeclarations toBeAdded) {
    addNewListOfStructToAnExistingOne(&((*head).normalDeclarations),
            toBeAdded.normalDeclarations);
    addNewListOfStructToAnExistingOne(&((*head).typedefDeclarations), toBeAdded.typedefDeclarations);
    addNewListOfStructToAnExistingOne(&((*head).structUnionDeclarations), toBeAdded.structUnionDeclarations);
}

void addGlobalDeclarationListToExistingOneWithNewDefinitionID(GlobalDeclarations * head, GlobalDeclarations toBeAdded,
                                                              int  * newNormalDeclarationsID, int * newStructUnionDeclarationsID, int * newTypedefDeclarationsID, ListOfStructMark **ListOfDeclarationMark ) {
    addNewListOfStructToAnExistingOneWithNewDefinitionID(&((*head).normalDeclarations),
                                      toBeAdded.normalDeclarations, newNormalDeclarationsID, ListOfDeclarationMark);
    addNewListOfStructToAnExistingOneWithNewDefinitionID(&((*head).typedefDeclarations), toBeAdded.typedefDeclarations, newTypedefDeclarationsID , ListOfDeclarationMark);
    addNewListOfStructToAnExistingOneWithNewDefinitionID(&((*head).structUnionDeclarations), toBeAdded.structUnionDeclarations,newStructUnionDeclarationsID ,ListOfDeclarationMark);
}

int searchForGlobalMarker(GlobalDeclarations ListOfGlobalDeclarations, char * marker) {
    ListOfStructDefinitions * auxNormalDecl = ListOfGlobalDeclarations.normalDeclarations;
    ListOfStructDefinitions * auxStructDecl = ListOfGlobalDeclarations.structUnionDeclarations;
    ListOfStructDefinitions * auxTypedefDecl = ListOfGlobalDeclarations.typedefDeclarations;
    while (auxNormalDecl) {
        if (strstr(auxNormalDecl->structDef->el, marker)) {
            return 1;
        }
        auxNormalDecl = auxNormalDecl->next;
    }
    while (auxStructDecl) {
        if (strstr(auxStructDecl->structDef->el, marker)) {
            return 1;
        }
        auxStructDecl = auxStructDecl->next;
    }
    while (auxTypedefDecl) {
        if (strstr(auxTypedefDecl->structDef->el, marker)) {
            return 1;
        }
        auxTypedefDecl = auxTypedefDecl->next;
    }
    return 0;
}
/*
int searchForGlobal(ListOfStructDefinitions ListOfGlobalDeclarationsHeader1, ListOfStructDefinitions ListOfGlobalDeclarationsHeader2) {
    ListOfStructDefinitions *auxDecl1 = ListOfGlobalDeclarationsHeader1.headerDefinition;
    ListOfStructDefinitions *auxDecl2 = ListOfGlobalDeclarationsHeader2.headerDefinition;
    while (auxDecl2) {
        while (auxDecl1) {
            if (strcmp(auxDecl1->structDef->el, auxDecl2->headerDefinition)) {
                return 1;
            }
            auxDecl1 = auxDecl1->next;
        }
        auxDecl2 = auxDecl2.
    }
    return 0;
}*/

ListOfString * extractNeededFunctionsForDeclaration(char * GlobalsDependenciesOnFunctFileName){
    ListOfString * ListOfNeededFunctionsDeclAsMarkers  = NULL;
    ListOfString * ListOfNeededFunctionsDeclDependency = NULL;

    ListOfNeededFunctionsDeclDependency = readListOfStringFromFile(GlobalsDependenciesOnFunctFileName);
    char * currentDeclaration = (char *) malloc(500 * sizeof(char));
    while(ListOfNeededFunctionsDeclDependency){
        if(strstr(ListOfNeededFunctionsDeclDependency->el, STRUCT_DECL_BEGINNING_MARKER) || strstr(ListOfNeededFunctionsDeclDependency->el,GLOBAL_DECL_BEGINNING_MARKER)
            || strstr(ListOfNeededFunctionsDeclDependency->el, TYPEDEF_DECL_BEGINNING_MARKER )) {
            strcpy(currentDeclaration, ListOfNeededFunctionsDeclDependency->el);
            strtok(currentDeclaration, "\n");
            addNewString(&ListOfNeededFunctionsDeclAsMarkers, currentDeclaration);
        }
        ListOfNeededFunctionsDeclDependency = ListOfNeededFunctionsDeclDependency->next;
    }

    return ListOfNeededFunctionsDeclAsMarkers;
}

void removeGlobalDeclarationFromAnotheOne(GlobalDeclarations *head, GlobalDeclarations toGlovaDeclToBeRemoved){

    ListOfStructDefinitions * auxNormalDecl = toGlovaDeclToBeRemoved.normalDeclarations;

   while (auxNormalDecl) {
        if (searchStructInAListOfStruct(auxNormalDecl, auxNormalDecl->structDef))
            removeGlobalDeclaration(&((*head).normalDeclarations), auxNormalDecl->headerDefinition);

        auxNormalDecl = auxNormalDecl->next;
    }

    ListOfStructDefinitions * auxStructDecl = toGlovaDeclToBeRemoved.structUnionDeclarations;
    while (auxStructDecl) {
        if (searchStructInAListOfStruct(auxStructDecl, auxStructDecl->structDef))
            removeGlobalDeclaration(&((*head).structUnionDeclarations), auxStructDecl->headerDefinition);
        auxStructDecl = auxStructDecl->next;
    }

    ListOfStructDefinitions * auxTypedefDecl = toGlovaDeclToBeRemoved.typedefDeclarations;
    while (auxTypedefDecl) {
        if (searchStructInAListOfStruct(auxTypedefDecl, auxTypedefDecl->structDef))
            removeGlobalDeclaration(&((*head).typedefDeclarations), auxTypedefDecl->headerDefinition);

        auxTypedefDecl = auxTypedefDecl->next;
    }

}
/* Used to insert global declaration before functions declaration when necessary */
GlobalDeclarations extractNeededGlobalDeclaractionsForFunctions(GlobalDeclarations ListOfFinalGlobalDeclarations, char * GlobalFctDependOutput){

    char * tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
    sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out", TXLTemporaryFolderMainThread);
    char * tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out", TXLTemporaryFolderMainThread);

    GlobalDeclarations GlobalNeededDeclarationForFunctions;

    GlobalDeclarations ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl;
    ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl.normalDeclarations = NULL;
    ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl.structUnionDeclarations = NULL;
    ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl.typedefDeclarations = NULL;

    ListOfString * ListOfNeededFunctionsDeclDependency =
            extractNeededFunctionsForDeclaration(GlobalFctDependOutput);

    GlobalNeededDeclarationForFunctions = returnMarkerGlobalDeclarationFromMarkersList(ListOfFinalGlobalDeclarations,
            ListOfNeededFunctionsDeclDependency);

    addGlobalDeclarationListToExistingOne(&ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl,
                                          ListOfFinalGlobalDeclarations);
    printListOfGlobalDeclarationsForOrgan(ListOfFinalGlobalDeclarations, GlobalNeededDeclarationForFunctions,
                                          tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

    removeGlobalDeclarationFromAnotheOne(&ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl, GlobalNeededDeclarationForFunctions);
    printListOfGlobalDeclarationsForOrgan(ListOfFinalGlobalDeclarations, ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl,
                                          tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);


    // removeAFileFromADirectory(tempHeaderGlobalsContent);
    //removeAFileFromADirectory(tempSourceCodeGlobalsContent);
    freeListOfStrings(&ListOfNeededFunctionsDeclDependency);
    freeGlobalDeclaration(&GlobalNeededDeclarationForFunctions);

    return ListOfFinalGlobalDeclarationsWithoutNeededFuncDecl;
}

/* Extract need function for global */
CallDependency * extractNeededFunctionsForGlobals(GlobalDeclarations ListOfGlobalDeclarations,
        char * GlobalsDependenciesOnFunctFileName) {
    FILE * fin = fopen(GlobalsDependenciesOnFunctFileName, "r");
    ListOfString * finalNeededFunctionsAsMarkers = NULL;

    CallDependency * calledFunctionsByGlobals = (CallDependency *) malloc(1 * sizeof (CallDependency));
    calledFunctionsByGlobals->LOCMarker = (char *) malloc(500 * sizeof (char));
    strcpy(calledFunctionsByGlobals->LOCMarker, "/* GLOBAL_CALLED */");

    ListOfFunctionSourceFile * listOfFctForGlobals = NULL;


    char * line;
    line = (char *) malloc(5000 * sizeof (char));

    char * StreamEnd = fgets(line, 4999, fin);

    while (StreamEnd != NULL) {

        char * declMarker = (char *) malloc(1000 * sizeof (char));
        fgets(line, 4999, fin);
        line[strlen(line) - 1] = '\0';
        strcpy(declMarker, line);
        if (searchForGlobalMarker(ListOfGlobalDeclarations, declMarker)) {
            while ((StreamEnd = fgets(line, 4999, fin)) != NULL && !strstr(line, DEPENDENCIES_FOR_GLOBALS_MARKER)) {
                char * functionName = (char *) malloc(1000 * sizeof (char));
                sscanf(line, "%s", functionName);

                //eliminate the function name, the space and the quotes after it
                line += strlen(functionName) + 2;
                //eliminate the final quotes and the new line symbol
                line[strlen(line) - 2] = 0;
                char * sourceFile = (char *) malloc(2000 * sizeof (char));
                strcpy(sourceFile, line);
                char * FunctionMarker = (char *) malloc(500 * sizeof (char));
                //sprintf(FunctionMarker, "/* %s */", functionName);
                if (!searchStringInListOfStrings(finalNeededFunctionsAsMarkers, FunctionMarker)) {
                    addNewFunctionSourceFile(&listOfFctForGlobals, functionName, sourceFile);
                }
            }
        } else {
            while ((StreamEnd = fgets(line, 4999, fin)) != NULL && !strstr(line, DEPENDENCIES_FOR_GLOBALS_MARKER)) {
            }
        }
    }

    calledFunctionsByGlobals->calledFunctions = listOfFctForGlobals;
    calledFunctionsByGlobals->next = NULL;

    return calledFunctionsByGlobals;
}

ListOfString * searchDependenciesInTypeVarDeclaration(ListOfDefinedTypesAndVarsDecl * head, char * searchedEl) {
    while (head) {
        char * currentDefType = NULL;
        currentDefType = (char *) malloc((strlen(head->definedTypes) + 100) * sizeof (char));
        fflush(stdout);
        strcpy(currentDefType,head->definedTypes);

        if (!strcmp(currentDefType, searchedEl)) {
            return head->definedVar;
        }
        head = head->next;
    }
    return NULL;
}

int searchDependenciesInIndividualTypeVarDeclaration(ListOfString * head, ListOfDefinedTypesAndVarsDecl * ListOfFinalGlobalDeclarationsPairTwo) {

    int result = 1;

    while(ListOfFinalGlobalDeclarationsPairTwo){
        ListOfString * currentVarsDeclaration = ListOfFinalGlobalDeclarationsPairTwo->definedVar;
        result = 0;
        if(!strcmp(head->el,currentVarsDeclaration->el)) {
          //  ListOfString * auxHead = head;
           // ListOfString * auxCurrentVarsDeclaration = currentVarsDeclaration;
            while (head && currentVarsDeclaration) {

                if(!strcmp(head->el, currentVarsDeclaration->el)){
                    result = 0;
                    currentVarsDeclaration = NULL;
                }else{
                    result = 1;
                }

                currentVarsDeclaration = currentVarsDeclaration->next;
                head = head->next;


            }

        }
        ListOfFinalGlobalDeclarationsPairTwo = ListOfFinalGlobalDeclarationsPairTwo->next;
    }

    return result;
}

GlobalDeclarations removeWantedGlobalDeclarationsDependencies(ListOfString * SelectedMarkers,
                                                              ListOfDefinedTypesAndVarsDecl * ListOfFinalGlobalDeclarationsPairOne,
                                                              ListOfDefinedTypesAndVarsDecl * ListOfFinalGlobalDeclarationsPairTwo,
                                                               DependencyList * GlobalDependencyList) {

    //Mapped declarations are globals which are mapped to the values in the host
    //these are not used for the moment
    ListOfString * MappedDeclarations = NULL;
    ListOfString * GlobalMarkersForTransplant = NULL;
    DependencyList * AllGlobalDependencies = NULL;
    addDependencyListToAnExistingOne(&AllGlobalDependencies, GlobalDependencyList);
    //first create the initial list of needed global markers, by the list of all
    //needed markers from the selected LOCs of the Skeleton
    ListOfString * auxSelectedMarkers = SelectedMarkers;
    while (auxSelectedMarkers) {
        ListOfString * neededDepsForCurrent = returnDependencyForAMarkerNewPointers(AllGlobalDependencies,
                                                                                    auxSelectedMarkers->el);
        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            while (auxListString) {
                ListOfString * auxListDefineVarInPairOne = copyCompleteListOfString(ListOfFinalGlobalDeclarationsPairTwo->definedVar);

                ListOfString * defineVar = searchDependenciesInTypeVarDeclaration(ListOfFinalGlobalDeclarationsPairOne, auxListString->el);

                if(!searchDependenciesInIndividualTypeVarDeclaration(defineVar, ListOfFinalGlobalDeclarationsPairTwo)){
                    addNewString(&GlobalMarkersForTransplant, auxListString->el);
                }

                auxListString = auxListString->next;
            }
            freeListOfStrings(&neededDepsForCurrent);
        }
        auxSelectedMarkers = auxSelectedMarkers->next;
    }
    /*
    ListOfString * auxNeededMarkers = GlobalMarkersForTransplant;
    //for all added line markers, add the one from dependency, if they are not mapped
    while (auxNeededMarkers) {
        //memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
        ListOfString * neededDepsForCurrent = returnDependencyForAMarkerNewPointers(AllGlobalDependencies,
                                                                                    auxNeededMarkers->el);
        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            while (auxListString) {
                if (!searchStringInListOfStrings(GlobalMarkersForTransplant, auxListString->el)) {
                    addNewString(&GlobalMarkersForTransplant, auxListString->el);
                }
                auxListString = auxListString->next;
            }
            //LOSCHANGE
            // freeListOfStrings(&neededDepsForCurrent);
        }
        auxNeededMarkers = auxNeededMarkers->next;
    }
*/
    //temporary add all the global declarations!!!

    // TODO: CHECK HERE
   // GlobalDeclarations NeededGlobalDeclarations = NULL;
        //    NeededGlobalDeclarations = returnMarkerGlobalDeclaration(ListOfFinalGlobalDeclarations, GlobalMarkersForTransplant);

    //printListOfGlobalDeclarations(NeededGlobalDeclarations, "/home/---/workspace/testGLOBALSnewSource.out",
    // "/home/---/workspace/testGLOBALSnewHeader.out");


  //  return NeededGlobalDeclarations;

}

// TODO rewrite this funcition to MULTIFILE
void printNewNeededGlobalDeclarations(
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        ListOfDefinedTypesAndVarsDecl * ListOfFinalGlobalDeclarationsPairOne,
        ListOfDefinedTypesAndVarsDecl * ListOfFinalGlobalDeclarationsPairTwo,
        DependencyList * GlobalDependencyList,
        ListOfString * ListOfSelectedFunctionNames) {


    GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
            removeWantedGlobalDeclarationsDependencies(
                    ListOfSelectedFunctionNames,
                    ListOfFinalGlobalDeclarationsPairOne,
                    ListOfFinalGlobalDeclarationsPairTwo,
                    GlobalDependencyList);

    GlobalDeclarations GlobalNeededCoreAndSkeleton;
    GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
    GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
    GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;

    addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
                                          AllGlobalNeededDeclarationsCoreFunctions);

    /* printListOfGlobalDeclarations2(GlobalNeededCoreAndSkeleton,
                                    tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);*/


    char * tempListOfVarsExtracted;
    tempListOfVarsExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfVarsExtracted, "%stemp_list_of_vars_extracted.out",
            TempVeinDirectory);

    printAllListOfGlobalDeclarationsExtracted(GlobalNeededCoreAndSkeleton,
                                              tempListOfVarsExtracted);

   // addLocsFromSourceToDestination(tempSourceCodeGlobalsContent, tempListOfVarsExtracted, TXLToolsPath);


}




void compareGlobalVarListParwise( GlobalDeclarations ListOfFinalGlobalDeclarations, char * GlobalTypeAndVarDependencyListPairOnePath,
                                  char * GlobalTypeAndVarDependencyListPairTwoPath,
                                  char * GlobalDependenciesPath){

    ListOfDefinedTypesAndVarsDecl * GlobalTypeAndVarDependencyListPairOne;
    ListOfDefinedTypesAndVarsDecl * GlobalTypeAndVarDependencyListPairTwo;

    GlobalTypeAndVarDependencyListPairOne = readCompletListOfDefinedTypesAndVarsFromFile(GlobalTypeAndVarDependencyListPairOnePath);
    GlobalTypeAndVarDependencyListPairTwo = readCompletListOfDefinedTypesAndVarsFromFile(GlobalTypeAndVarDependencyListPairTwoPath);

    DependencyList * GlobalDependencies = readDependencyListFromFile(GlobalDependenciesPath);

   // ListOfDefinedTypesAndVars * GlobalTypeAndVarDependencyList = readDependencyListFromFile(definedGlobalTypesAndVariablesFile);

    //DependencyList * GlobalDependencies = readDependencyListFromFile(tempGlobalDependencies);

    ListOfString * FinalListOfTransplantedGlobalVarAsMarkers = extractDependenciesMarkers(GlobalDependencies );

    //ListOfString * globalTypeAndVariable = readListOfStringFromFile(definedGlobalTypesAndVariablesFile);

    printNewNeededGlobalDeclarations(
            ListOfFinalGlobalDeclarations,
            GlobalTypeAndVarDependencyListPairOne,
            GlobalTypeAndVarDependencyListPairTwo,
            GlobalDependencies,
            FinalListOfTransplantedGlobalVarAsMarkers);



    /*  removeWantedGlobalDeclarationsDependencies(
              ListOfFinalGlobalDeclarations, GlobalTypeAndVarDependencyListPairOne,
              GlobalTypeAndVarDependencyListPairTwo,
              GlobalDependencies,
              FinalListOfTransplantedGlobalVarAsMarkers);
  */


}

#ifdef MAC_OSX
/* Add old and new mark in list of statment */
void addNewStatmentMark(ListOfStructMark ** head, char * currentDG, char * finalDG) {

    ListOfStructMark * newEl = (ListOfStructMark *) malloc(1 * sizeof (ListOfStructMark));
    newEl->oldStatment = NULL;
    newEl->newStatment = NULL;

    newEl->oldStatment = (char *) malloc((strlen(currentDG) + 1) * sizeof (char));
    strcpy(newEl->oldStatment, currentDG);

    newEl->newStatment = (char *) malloc((strlen(finalDG) + 1) * sizeof (char));
    strcpy(newEl->newStatment, finalDG);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfStructMark * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}
int comparTwoDeclarations(ListOfString * head1, ListOfString * head2) {

    int result = 0;

    while(head1 && head2 && result == 0) {
        if (!strcmp(head1->el, head2->el))
            result = 1;


        if ((strstr(head1->el, STRUCT_DECL_BEGINNING_MARKER) || strstr(head1->el, GLOBAL_DECL_BEGINNING_MARKER) ||
            strstr(head1->el, TYPEDEF_DECL_BEGINNING_MARKER) || strstr(head1->el, ENUM_DECL_BEGINNING_MARKER)) && (strstr(head2->el, STRUCT_DECL_BEGINNING_MARKER) ||
                strstr(head2->el, GLOBAL_DECL_BEGINNING_MARKER) || strstr(head2->el, TYPEDEF_DECL_BEGINNING_MARKER) || strstr(head2->el, ENUM_DECL_BEGINNING_MARKER))) {
            char *decl1 = NULL;
            char *decl2 = NULL;
            decl1 = (char *) malloc((strlen(head1->el) + 3) * sizeof(char));
            decl2 = (char *) malloc((strlen(head2->el) + 3) * sizeof(char));
           // decl1 = (char *) malloc(99999 * sizeof (char));
          //  decl2 = (char *) malloc(99999 * sizeof (char));
            strcpy(decl2, readSubstring("*/ ", head2->el, "\n"));
            strcpy(decl1, readSubstring("*/ ", head1->el, "\n"));
            if(!strcmp(decl1, decl2))
                    result = 1;
          //  free(decl1);
          //  free(decl2);
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return result;
}
void addStatementMark(ListOfStructMark ** listOfStructDefMark, ListOfStructDefinitions * finalGlobalDeclarations, ListOfStructDefinitions * currentGlobalDeclarations, char * mark) {

    ListOfStructDefinitions * currentGD = currentGlobalDeclarations;
    int found;
    ListOfStructDefinitions * finalGD = NULL;
    while (currentGD) {
        found = 0;
        finalGD = finalGlobalDeclarations;
        while (finalGD) {
            int c = 0, f = 0;
            if(strstr(finalGD->structDef, "/* GLOBAL_DECL_61 */"))
                printf("erro aqui");
            if(strstr(currentGD->structDef, "/* GLOBAL_DECL_0 */"))
                printf("erro aqui");

            if (comparTwoDeclarations(finalGD->structDef, currentGD->structDef)) {
                char *currentGDMark = (char *) malloc(
                        (strlen(currentGD->structDef->el) + 3) * sizeof(char));
                strcpy(currentGDMark, readSubstring("/* ", currentGD->structDef->el, " */"));
                char *finalGDMark = (char *) malloc(
                        (strlen(finalGD->structDef->el) + 3) * sizeof(char));
                strcpy(finalGDMark, readSubstring("/* ", finalGD->structDef->el, " */"));

                char *formattedFinalMark;
                formattedFinalMark = (char *) malloc((strlen(finalGDMark) + 10) * sizeof(char *));
                sprintf(formattedFinalMark, "/* %s */", finalGDMark);

                char *formattedCurrentGDMark;
                formattedCurrentGDMark = (char *) malloc((strlen(currentGDMark) + 10) * sizeof(char *));
                sprintf(formattedCurrentGDMark, "/* %s */", currentGDMark);

                addNewStatmentMark(listOfStructDefMark, formattedCurrentGDMark, formattedFinalMark);
                finalGD = NULL;
                found = 1;
                free(currentGDMark);
                free(finalGDMark);
                free(formattedFinalMark);
                free(formattedCurrentGDMark);
                fflush(stdout);
            }

            if (finalGD)
                finalGD = finalGD->next;

        }
        if (found == 0){
            printf("ERRO declaration not found.");
        }
        currentGD = currentGD->next;
    }
    freeListOfStructDefinitions(&finalGD);
    freeListOfStructDefinitions(&currentGD);
    fflush(stdout);
}


GlobalDeclarationsMark  createGlobalDeclarationsMark(GlobalDeclarations ListOfFinalGlobalDeclarations, GlobalDeclarations ListOfCurrentGlobalDeclarations){

    GlobalDeclarationsMark globalDeclarationsMark;

    addStatementMark(&(globalDeclarationsMark).normalDeclarations, ListOfFinalGlobalDeclarations.normalDeclarations, ListOfCurrentGlobalDeclarations.normalDeclarations, "GLOBAL_DECL_");
    addStatementMark(&(globalDeclarationsMark).typedefDeclarations, ListOfFinalGlobalDeclarations.typedefDeclarations, ListOfCurrentGlobalDeclarations.typedefDeclarations, "TYPEDEF_DECL_");
    addStatementMark(&(globalDeclarationsMark).structUnionDeclarations, ListOfFinalGlobalDeclarations.structUnionDeclarations, ListOfCurrentGlobalDeclarations.structUnionDeclarations,"STRUCT_DECL_" );

    return globalDeclarationsMark;

}

void freeListOfGlobalDeclarationMak(ListOfStructMark ** head) {
    ListOfStructMark * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        aux->newStatment = NULL;
        free(aux->oldStatment);
        aux->oldStatment = NULL;
        free(aux->newStatment);
        aux->newStatment = NULL;
        aux->next = NULL;
        free(aux);
    }
    (* head) = NULL; //just in case...
}


void printListOfGlobalDeclarationsinDefsOutput(GlobalDeclarations ListOfDecl, char * outputFile) {

    FILE * fout = fopen(outputFile, "w");

    ListOfStructDefinitions * auxNormalElements = ListOfDecl.normalDeclarations;
    fprintf(fout, "NORMAL_DECLARATION\n");
    while (auxNormalElements) {
        ListOfString * auxNormalDef = auxNormalElements->structDef;
        while (auxNormalDef) {
            fprintf(fout, "%s", auxNormalDef->el);
            auxNormalDef = auxNormalDef->next;
        }
        fprintf(fout, "HEADER_DECL\n");
        fprintf(fout, "%s", auxNormalElements->headerDefinition);

        auxNormalElements = auxNormalElements->next;
    }

    ListOfStructDefinitions * auxStructDecl = ListOfDecl.structUnionDeclarations;
    fprintf(fout, "STRUCT_DECLARATION\n");
    while (auxStructDecl) {
        ListOfString * auxStructDeclDef = auxStructDecl->structDef;
        while (auxStructDeclDef) {
            fprintf(fout, "%s", auxStructDeclDef->el);
            auxStructDeclDef = auxStructDeclDef->next;
        }

        fprintf(fout, "HEADER_DECL\n");
        if(auxStructDecl->headerDefinition != NULL)
            if(strstr("struct", auxStructDecl->headerDefinition) && !strstr(";;", auxStructDecl->headerDefinition)) {
                fprintf(fout, "%s", auxStructDecl->headerDefinition);
            }else {
             //TODO replace   strcpy(auxStructDecl->headerDefinition, replace_str(auxStructDecl->headerDefinition, ";;", ";"));
                fprintf(fout, "struct %s", auxStructDecl->headerDefinition);
            }
        auxStructDecl = auxStructDecl->next;
    }

    ListOfStructDefinitions * auxTypeDefDecl = ListOfDecl.typedefDeclarations;
    fprintf(fout, "TYPEDEF_DECLARATION\n");
    while (auxTypeDefDecl) {
        ListOfString * auxTypeDefDeclDef = auxTypeDefDecl->structDef;
        while (auxTypeDefDeclDef) {
            fprintf(fout, "%s", auxTypeDefDeclDef->el);
            auxTypeDefDeclDef = auxTypeDefDeclDef->next;
        }
        auxTypeDefDecl = auxTypeDefDecl->next;
    }

    fclose(fout);

}

void printListOfGlobalDeclarationsAndFileinDefsOutput(GlobalDeclarations ListOfDecl, char * outputFile) {

    FILE * fout = fopen(outputFile, "w");

    ListOfStructDefinitions * auxNormalElements = ListOfDecl.normalDeclarations;
    fprintf(fout, "NORMAL_DECLARATION\n");
    while (auxNormalElements) {
        ListOfString * auxNormalDef = auxNormalElements->structDef;
        while (auxNormalDef) {
            fprintf(fout, "%s", auxNormalDef->el);
            auxNormalDef = auxNormalDef->next;
        }
        fprintf(fout, "HEADER_DECL\n");
        fprintf(fout, "%s", auxNormalElements->headerDefinition);
        fprintf(fout, "FILE: ");
        fprintf(fout, "%s\n", auxNormalElements->file);
        fprintf(fout, "LINE: ");
        fprintf(fout, "%d", auxNormalElements->occurrenceLine);
        fprintf(fout, "\n-----------------------------------------\n");
        auxNormalElements = auxNormalElements->next;

    }

    ListOfStructDefinitions * auxStructDecl = ListOfDecl.structUnionDeclarations;
    fprintf(fout, "STRUCT_DECLARATION\n");
    while (auxStructDecl) {
        ListOfString * auxStructDeclDef = auxStructDecl->structDef;
        while (auxStructDeclDef) {
            fprintf(fout, "%s", auxStructDeclDef->el);
            auxStructDeclDef = auxStructDeclDef->next;
        }
        fprintf(fout, "HEADER_DECL\n");
        if(auxStructDecl->headerDefinition != NULL)
            fprintf(fout, "%s", auxStructDecl->headerDefinition);

        fprintf(fout, "FILE: ");
        fprintf(fout, "%s\n", auxStructDecl->file);
        fprintf(fout, "LINE: ");
        fprintf(fout, "%d", auxStructDecl->occurrenceLine);
        fprintf(fout, "\n-----------------------------------------\n");
        auxStructDecl = auxStructDecl->next;
    }

    ListOfStructDefinitions * auxTypeDefDecl = ListOfDecl.typedefDeclarations;
    fprintf(fout, "TYPEDEF_DECLARATION\n");
    while (auxTypeDefDecl) {
        ListOfString * auxTypeDefDeclDef = auxTypeDefDecl->structDef;
        while (auxTypeDefDeclDef) {
            fprintf(fout, "%s", auxTypeDefDeclDef->el);
            auxTypeDefDeclDef = auxTypeDefDeclDef->next;
        }
        fprintf(fout, "FILE: ");
        fprintf(fout, "%s\n", auxTypeDefDecl->file);
        fprintf(fout, "LINE: ");
        fprintf(fout, "%d", auxTypeDefDecl->occurrenceLine);
        fprintf(fout, "\n-----------------------------------------\n");
        auxTypeDefDecl = auxTypeDefDecl->next;
    }

    fclose(fout);

}

void printListOfGlobalListOfDefinedTypeVar(ListOfDefinedTypesAndVars * FinalGlobalListOfDefinedTypeVar, char * outputFile) {

    FILE * fout = fopen(outputFile, "w");

    while (FinalGlobalListOfDefinedTypeVar) {

       // fprintf(fout, "DECLARED_TYPES\n");
        fprintf(fout, "%s\n", FinalGlobalListOfDefinedTypeVar->lineMarker);
        fprintf(fout, "%s\n", FinalGlobalListOfDefinedTypeVar->declType);
        ListOfString * auxDefinedTypes = FinalGlobalListOfDefinedTypeVar->definedTypes;
        while (auxDefinedTypes) {
            fprintf(fout, "%s", auxDefinedTypes->el);
            auxDefinedTypes = auxDefinedTypes->next;
        }
        //fprintf(fout, "%s\n", FinalGlobalListOfDefinedTypeVar->definedVar);

        fprintf(fout, "%s\n",GLOBAL_END_MARKER);
        FinalGlobalListOfDefinedTypeVar = FinalGlobalListOfDefinedTypeVar->next;
    }

    fclose(fout);

}


void printListOfNeededFunctionsForGlobalDeclaration(CallDependency * FinalListOfNeededFunctionsForGlobals, char * outputFile) {

    FILE * fout = fopen(outputFile, "w");

    while (FinalListOfNeededFunctionsForGlobals) {

        fprintf(fout, "%s\n",DEPENDENCIES_FOR_GLOBALS_MARKER);
        fprintf(fout, "%s\n", FinalListOfNeededFunctionsForGlobals->LOCMarker);
        ListOfFunctionSourceFile * auxCalledFunctions = FinalListOfNeededFunctionsForGlobals->calledFunctions;
        while (auxCalledFunctions) {
            fprintf(fout, "%s %s\n", auxCalledFunctions->functionName, auxCalledFunctions->sourceFile);
            auxCalledFunctions = auxCalledFunctions->next;
        }

        FinalListOfNeededFunctionsForGlobals = FinalListOfNeededFunctionsForGlobals->next;
    }

    fclose(fout);

}

void printAListOfDeclarationMark(ListOfStructMark * head, char * outputFile) {
    ListOfStructMark * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s\n", p->oldStatment);
        fprintf(fout, "%s\n", p->newStatment);
        fprintf(fout, "--------------\n");
        p = p->next;
    }
    fclose(fout);
}

void addNewNeededFunctionMark(CallDependency ** head, CallDependency * source, ListOfStructMark * listOfStructMark ){
    CallDependency * CurrentListOfNeededFunctionsForGlobals = source;
    // ListOfStructMark * auxListOfStructMark;

    while (CurrentListOfNeededFunctionsForGlobals) {
        char * oldMarker = (char *) malloc((strlen( CurrentListOfNeededFunctionsForGlobals->LOCMarker) + 1) * sizeof (char));
        char * newMarker = NULL;
        strcpy(oldMarker, CurrentListOfNeededFunctionsForGlobals->LOCMarker);
        newMarker = returnNewMark(listOfStructMark, oldMarker);
        if(newMarker) {
            addNewListOfNeededFunctionsForGlobals(head, CurrentListOfNeededFunctionsForGlobals, newMarker);
        }else{
            printf("ERROR: Needed Call %s does not mapped",newMarker);
            exit(1);
        }

        free(oldMarker);
        free(newMarker);
        CurrentListOfNeededFunctionsForGlobals = CurrentListOfNeededFunctionsForGlobals->next;
    }

}

void replaceMarkInNeededCallFunction(CallDependency ** NewNeededCallFunction, CallDependency * CurrentNeededCallFunction, ListOfStructMark * listOfStructMark ){
    CallDependency * auxCurrentNeededCallFunction = CurrentNeededCallFunction;

    while (auxCurrentNeededCallFunction) {
        char * oldMarker = (char *) malloc((strlen( auxCurrentNeededCallFunction->LOCMarker) + 1) * sizeof (char));
        char * newMarker = NULL;
        strcpy(oldMarker, auxCurrentNeededCallFunction->LOCMarker);
        newMarker = returnNewMark(listOfStructMark, oldMarker);
        if(newMarker) {
            addNeededFunctionsDeclaration(NewNeededCallFunction, newMarker);
            ListOfFunctionSourceFile *currentListOfDependencies = auxCurrentNeededCallFunction->calledFunctions;
            // auxListOfStructMark = listOfStructMark;
            while (currentListOfDependencies) {
                addCalledFunction(NewNeededCallFunction, newMarker, currentListOfDependencies->functionName,currentListOfDependencies->sourceFile);
                currentListOfDependencies = currentListOfDependencies->next;
            }
        }else{
            printf("ERROR: Old Marker: %s does not mapped",oldMarker);
            exit(1);
        }

        free(oldMarker);
        free(newMarker);
        auxCurrentNeededCallFunction = auxCurrentNeededCallFunction->next;
    }
    freeListOfCallDependency(&auxCurrentNeededCallFunction);
}
//TODO improve search process
ListOfFunctionSourceFile * getListOfFunctionSourceFileFromDirective(ListOfFunctionSourceFile ** ListOfFunctionSourceFileFromDirectives, ListOfFunctionSourceFile * ListOfAndFunctionSource, char * directive){
    ListOfString * DirectiveAsWords = NULL;
    ListOfFunctionSourceFile * FoundListOfFunctionSourceFileFromDirectives = NULL;
    char * functionName = (char *) malloc(100 * sizeof(char));
    ListOfFunctionSourceFile * auxListOfAndFunctionSource;
    readStringAsWords( directive, &DirectiveAsWords);
    while(DirectiveAsWords){
        auxListOfAndFunctionSource = ListOfAndFunctionSource;
        fflush(stdout);
        if (strstr(DirectiveAsWords->el, "(")) {
            while(auxListOfAndFunctionSource){
                functionName = removeSpaceInString(DirectiveAsWords->el);
                if(strstr(functionName, auxListOfAndFunctionSource->functionName))
                    addNewFunctionSourceFile(ListOfFunctionSourceFileFromDirectives, auxListOfAndFunctionSource->functionName,
                                             auxListOfAndFunctionSource->sourceFile);
                fflush(stdout);
                auxListOfAndFunctionSource = auxListOfAndFunctionSource->next;
            }
            /*if(strstr(DirectiveAsWords->el, " "))
                strcpy(functionName, readSubstring(" ",DirectiveAsWords->el, "("));
            else
                strcpy(functionName, readSubstring("\t",DirectiveAsWords->el, "("));
        ///    FoundListOfFunctionSourceFileFromDirectives = searchFunctionInListOfFunctionsSourceFileFromFunction(ListOfAndFunctionSource, functionName);
            if(FoundListOfFunctionSourceFileFromDirectives) {
                addNewFunctionSourceFile(ListOfFunctionSourceFileFromDirectives, FoundListOfFunctionSourceFileFromDirectives->functionName,
                                         FoundListOfFunctionSourceFileFromDirectives->sourceFile);
            }*/
        }
        DirectiveAsWords = DirectiveAsWords->next;
    }

    free(functionName);
    freeListOfStrings(&DirectiveAsWords);
    return ListOfFunctionSourceFileFromDirectives;
}

ListOfFunctionSourceFile * readListOfFunctionNeededAsDirectives(ListOfFunctionSourceFile * ListOfFunctionSource , char * tempDefinesFileMultiFiles){
    ListOfFunctionSourceFile * ListOfFunctionSourceFileFromDirectives = NULL;
    ListOfString * ListOfDirectives = readListOfStringFromFile(tempDefinesFileMultiFiles);
    char * directive = (char *) malloc(100 * sizeof(char));
    char * functionName = NULL;

    while(ListOfDirectives){
        fflush(stdout);
        if(strstr(ListOfDirectives->el, "#define")) {
            getListOfFunctionSourceFileFromDirective( &ListOfFunctionSourceFileFromDirectives, ListOfFunctionSource,  ListOfDirectives->el);
        }
            ListOfDirectives = ListOfDirectives->next;
    }

    freeListOfStrings(&ListOfDirectives);
    free(directive);
    free(functionName);

    return ListOfFunctionSourceFileFromDirectives;

}

void replaceMarkOfGlobalListOfDefinedTypeVar(ListOfDefinedTypesAndVars * CurrentGlobalListOfDefinedTypeVar, ListOfDefinedTypesAndVars ** FinalListOfGlobalDefinedTypeVar,
        ListOfStructMark * ListOfDeclarationMark){

    while (CurrentGlobalListOfDefinedTypeVar) {

        char *newMark = NULL;
        char *oldMark = (char *) malloc(
            (strlen(CurrentGlobalListOfDefinedTypeVar->declType) + 1) * sizeof(char));
        strcpy(oldMark, CurrentGlobalListOfDefinedTypeVar->declType);
        strtok(oldMark, "\n");
        if (oldMark == NULL) {
            printf("ERRO: Old mark: %s does not find.\n", oldMark);
            exit(1);
        } else {
            newMark = returnNewMark(ListOfDeclarationMark, oldMark);
            if (newMark == NULL) {
                printf("ERRO: There is no new mark to: %s.\n", oldMark);
                exit(1);
            }
        }

        addNewListOfDefinedTypesAndVars(FinalListOfGlobalDefinedTypeVar, CurrentGlobalListOfDefinedTypeVar->lineMarker,
                CurrentGlobalListOfDefinedTypeVar->definedTypes, CurrentGlobalListOfDefinedTypeVar->definedVar, newMark);

            CurrentGlobalListOfDefinedTypeVar = CurrentGlobalListOfDefinedTypeVar->next;
    }
}
ListOfFunctionSourceFile * readAllFunctionSourceFileFromAllDefinitionInDonor(char * ListOfAllFunctionsSourceFileInDonorPath){
    ListOfString * ListOfAllFunctionsSourceFileInDonor = readListOfStringFromFile(ListOfAllFunctionsSourceFileInDonorPath);
    ListOfFunctionSourceFile * ListOfFunctionSource = NULL;
    char * currentFunction = (char *) malloc(200 * sizeof(char));
    char * currentSourceFile = (char *) malloc(200 * sizeof(char));
    while(ListOfAllFunctionsSourceFileInDonor){ // remove source file path
        strcpy(currentFunction, ListOfAllFunctionsSourceFileInDonor->el);
        strtok(currentFunction, " \"");
        strcpy(currentSourceFile, readSubstring("\"", ListOfAllFunctionsSourceFileInDonor->el, "\""));
        addNewFunctionSourceFile(&ListOfFunctionSource, currentFunction, currentSourceFile);

        ListOfAllFunctionsSourceFileInDonor = ListOfAllFunctionsSourceFileInDonor->next;
    }

    freeListOfStrings(&ListOfAllFunctionsSourceFileInDonor);
    free(currentFunction);
    free(currentSourceFile);
    return ListOfFunctionSource;
}
ListOfFunctionSourceFile * ListOfNeededFunctionAsDirectives;

GlobalDeclarations getGlobalDeclarationByFile(char * allSourceHeaderFilesInDonor,  ListOfDefinedTypesAndVars ** FinalListOfGlobalDefinedTypeVar ,
                                              CallDependency ** FinalListOfNeededFunctionsForGlobals, char * AllDefinedFunctionsInDonor,
                                              char * ListOfFileToSkipPath){

    int normalDeclarationsID = 0;
    int structUnionDeclarationsID = 0;
    int typedefDeclarationsID = 0;
    int countFiles = 1;

    GlobalDeclarations ListOfFinalGlobalDeclarations;
    ListOfFinalGlobalDeclarations.normalDeclarations = NULL;
    ListOfFinalGlobalDeclarations.structUnionDeclarations = NULL;
    ListOfFinalGlobalDeclarations.typedefDeclarations = NULL;
    fflush(stdout);
    //the output file of needed functions to be extracted for globals!
    char *tempGlobalFctDependOutput = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalFctDependOutput, "%stemp_needed_functions_for_global_declarations.out", TXLTemporaryMultiFileFolder);

    /* rewrite definedGlobalTypesAndVariablesFile for definedGlobalTypesAndVariablesMultiFiles */
    char *definedGlobalTypesAndVariablesMultiFiles = (char *) malloc(100 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesMultiFiles, "%stemp_global_type_var_declarations.out", TXLTemporaryMultiFileFolder);

    char *tempDefinesFileMultiFiles = (char *) malloc(100 * sizeof(char));
    sprintf(tempDefinesFileMultiFiles, "%stemp_define_file.out", TXLTemporaryMultiFileFolder);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput = (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryMultiFileFolder);

    /* temp global dependencies: temp_global_dependencies.out */
    char * tempGlobalDependencies = (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryMultiFileFolder);

    char *tempIncludeLibFileMultiFiles = (char *) malloc(100 * sizeof(char));
    sprintf(tempIncludeLibFileMultiFiles, "%stemp_include_lib_file.out",TXLTemporaryMultiFileFolder);

    char * tempSourceHeaderFilesTargetPath = (char *) malloc(100 * sizeof(char));
    sprintf(tempSourceHeaderFilesTargetPath, "%stemp_source_header_files_target.out", TXLTemporaryMultiFileFolder);
    fflush(stdout);
    ListOfString * ListOfFileToSkip = readListOfStringFromFileAsWords(ListOfFileToSkipPath);

    /* Get all functions in Donor to check directives with needed functions */
    ListOfFunctionSourceFile * AllFunctionSourceFileInDonor = NULL;
    AllFunctionSourceFileInDonor = readAllFunctionSourceFileFromAllDefinitionInDonor(AllDefinedFunctionsInDonor);

    /* Read list of functions already extracted ----------------------------*/
    ListOfString *listOfAllSourceHeaderFiles = readListOfStringFromFileAsWords(allSourceHeaderFilesInDonor);
    while (listOfAllSourceHeaderFiles) {

        char * currentHeaderFile = NULL;
        ListOfStructMark *ListOfDeclarationMark = NULL;
        CallDependency *NewCurrentListOfNeededFunctionsForGlobals = NULL;
        GlobalDeclarations ListOfCurrentGlobalDeclarations;
        ListOfDefinedTypesAndVars *CurrentGlobalListOfDefinedTypeVar = NULL;
        CallDependency *CurrentListOfNeededFunctionsForGlobals = NULL;

        currentHeaderFile = (char *) malloc((strlen(listOfAllSourceHeaderFiles->el) + 1) * sizeof (char));
        strcpy(currentHeaderFile, listOfAllSourceHeaderFiles->el);
        if(!searchOccurrenceOfStringInListOfStringsUsingSTRSTR(ListOfFileToSkip, currentHeaderFile)) {// skip not wanted files listed in listFilesToSkip.in
         ///   printf("--------------------------------------\n");
         ///   printf("[TXL] Global Declarations Extractor \n\tFile[%d]:  %s\n", countFiles, currentHeaderFile);
    //        if(strstr(currentHeaderFile, "vi.h"))
    //            printf("Aqui\n");
            addAStringsInTheFile(currentHeaderFile, tempSourceHeaderFilesTargetPath);

            ListOfCurrentGlobalDeclarations = constructListOfGlobalDeclarationsMultiFiles(&CurrentGlobalListOfDefinedTypeVar, &CurrentListOfNeededFunctionsForGlobals, tempGlobalDefsOutput, definedGlobalTypesAndVariablesMultiFiles,
                                                                                           tempDefinesFileMultiFiles, tempIncludeLibFileMultiFiles,
                                                                                           AllDefinedFunctionsInDonor, tempGlobalFctDependOutput,
                                                                                           TXLTemporaryFolderMainThread, tempSourceHeaderFilesTargetPath,
                                                                                           TXLTemporaryMultiFileFolder, tempGlobalDependencies);
             /* Add ListOfCurrentGlobalDeclarations into ListOfFinalGlobalDeclarations */
            addGlobalDeclarationListToExistingOneWithNewDefinitionID(&ListOfFinalGlobalDeclarations,
                                                                     ListOfCurrentGlobalDeclarations,
                                                                     &normalDeclarationsID, &structUnionDeclarationsID,
                                                                     &typedefDeclarationsID,
                                                                     &ListOfDeclarationMark);

            /* Extract needed function defined from directives */
            char * AllDefinedFunctionsInDonor;
            AllDefinedFunctionsInDonor = (char *) malloc(100 * sizeof(char));
            sprintf(AllDefinedFunctionsInDonor,	"%stemp_all_defined_functions_int_donor.out",
                    TXLTemporaryFolderMainThread);
            fflush(stdout);
            ListOfNeededFunctionAsDirectives = readListOfFunctionNeededAsDirectives(AllFunctionSourceFileInDonor, tempDefinesFileMultiFiles);
            while(ListOfNeededFunctionAsDirectives) {
                fflush(stdout);
                extractFunctionality(ListOfNeededFunctionAsDirectives->functionName, ListOfNeededFunctionAsDirectives->sourceFile,
                                     donorSourceFileFolder,
                                     TXLToolsPath, TXLTemporaryFolderMainThread, TXLTemporaryMultiFileFolder);

                ListOfNeededFunctionAsDirectives = ListOfNeededFunctionAsDirectives->next;
            }
           /* char *tempListGlobalDefFile = (char *) malloc(100 * sizeof (char));
            sprintf(tempListGlobalDefFile, "%sList_defs_output.out", TXLTemporaryFolderMainThread);
            printListOfGlobalDeclarationsinDefsOutput(ListOfCurrentGlobalDeclarations, tempListGlobalDefFile);
            fflush(stdout);

            char *tempGlobalDefFile = (char *) malloc(100 * sizeof (char));
            sprintf(tempGlobalDefFile, "%sFinal_partial_defs_output.out", TXLTemporaryFolderMainThread);
            printListOfGlobalDeclarationsinDefsOutput(ListOfFinalGlobalDeclarations, tempGlobalDefFile);*/

#if 0
            char *tempMarks = (char *) malloc(100 * sizeof(char));
            sprintf(tempMarks, "%stemp_marks.out", TXLTemporaryMultiFileFolder);
            printAListOfDeclarationMark(ListOfDeclarationMark, tempMarks);
#endif
            /* Replace Global List of Defined type var */
            replaceMarkOfGlobalListOfDefinedTypeVar(CurrentGlobalListOfDefinedTypeVar, FinalListOfGlobalDefinedTypeVar, ListOfDeclarationMark);

            char *tempFinalGlobalDefFile = (char *) malloc(100 * sizeof (char));
            sprintf(tempFinalGlobalDefFile, "%sFinal_defs_output.out", TXLTemporaryFolderMainThread);
            printListOfGlobalDeclarationsinDefsOutput(ListOfFinalGlobalDeclarations, tempFinalGlobalDefFile);
            /* Replace needed call function */
            replaceMarkInNeededCallFunction(&NewCurrentListOfNeededFunctionsForGlobals, CurrentListOfNeededFunctionsForGlobals, ListOfDeclarationMark);
            addNeededCallFunctionDeclarationListToAnExistingOne(FinalListOfNeededFunctionsForGlobals, NewCurrentListOfNeededFunctionsForGlobals);

            countFiles++;
            freeListOfCallDependency(&NewCurrentListOfNeededFunctionsForGlobals);
            freeListOfCallDependency(&CurrentListOfNeededFunctionsForGlobals);
            freeListOfListOfDefinedTypesAndVars(&CurrentGlobalListOfDefinedTypeVar);
            freeGlobalDeclaration(&ListOfCurrentGlobalDeclarations);

        }
        listOfAllSourceHeaderFiles = listOfAllSourceHeaderFiles->next;
        fflush(stdout);
    }

    removeAFileFromADirectory(tempGlobalFctDependOutput);
    removeAFileFromADirectory(definedGlobalTypesAndVariablesMultiFiles);
    removeAFileFromADirectory(tempDefinesFileMultiFiles);
    removeAFileFromADirectory(tempIncludeLibFileMultiFiles);
    removeAFileFromADirectory(tempSourceHeaderFilesTargetPath);
    removeAFileFromADirectory(tempGlobalDefsOutput);
    removeAFileFromADirectory(tempGlobalDependencies);

    freeListOfFunctionSourceFile(&AllFunctionSourceFileInDonor);
    free(tempGlobalFctDependOutput);
    free(definedGlobalTypesAndVariablesMultiFiles);
    free(tempDefinesFileMultiFiles);
    free(tempIncludeLibFileMultiFiles);
    free(tempSourceHeaderFilesTargetPath);
    free(tempGlobalDefsOutput);
    free(tempGlobalDependencies);

    return ListOfFinalGlobalDeclarations;
}

GlobalDeclarations extractGlobalDeclaration( char * AllDefinedFunctionsInDonor, char * definedGlobalTypesAndVariablesFile){
    printf("[AUTOSCALPEL] Extracting Global Declarations...\n");

    GlobalDeclarations ListOfFinalGlobalDeclarations;
    ListOfDefinedTypesAndVars * FinalListOfGlobalDefinedTypeVar = NULL;
    CallDependency * FinalListOfNeededFunctionsForGlobals = NULL;

    /* List of C++ files provider by user. It is used to identi to vein functions declaration */
    char * temListOfFilesToSkip = (char *) malloc(100 * sizeof (char));
    sprintf(temListOfFilesToSkip, "%slistFileToSkip.in", transplantWorkFolderMainThread);

    /* CHANGED TO USE ALL HEADER FILES */
    char *allSourceHeaderFilesInDonor = (char *) malloc(100 * sizeof(char));
    sprintf(allSourceHeaderFilesInDonor, "%sAllSourceHeaderFilesInDonor.out", TXLTemporaryMultiFileFolder);

    /* Extract Global declarations by file */
    ListOfFinalGlobalDeclarations =  getGlobalDeclarationByFile(allSourceHeaderFilesInDonor,&FinalListOfGlobalDefinedTypeVar,
            &FinalListOfNeededFunctionsForGlobals, AllDefinedFunctionsInDonor, temListOfFilesToSkip);

    /*PRINT FINAL GLOBAL DEFS: temp_global_defs_output.out */
    char *tempGlobalDef= (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDef, "%stemp_global_defs_output.out", TXLTemporaryFolderMainThread);
    printListOfGlobalDeclarationsinDefsOutput(ListOfFinalGlobalDeclarations, tempGlobalDef);

    /*PRINT FINAL GLOBAL DEFS: temp_global_defs_output.out */
    char *tempGlobalDefFile = (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDefFile, "%stemp_global_defs_file_output.out", TXLTemporaryFolderMainThread);
    printListOfGlobalDeclarationsAndFileinDefsOutput(ListOfFinalGlobalDeclarations, tempGlobalDefFile);

    /*PRINT FINAL GLOBAL TYPE VAR DECALRATION: temp_global_type_var_declarations.out */
    printListOfGlobalListOfDefinedTypeVar(FinalListOfGlobalDefinedTypeVar, definedGlobalTypesAndVariablesFile);

    /*PRINT FINAL NEEDED CALL FUNCTION DECLARATION: temp_needed_functions_for_global_declarations.out*/
    char * tempNeededFunctionForGlobalDeclpath = (char *) malloc(100 * sizeof (char));
    sprintf(tempNeededFunctionForGlobalDeclpath, "%stemp_needed_functions_for_global_declarations.out", TXLTemporaryFolderMainThread);
    printListOfNeededFunctionsForGlobalDeclaration(FinalListOfNeededFunctionsForGlobals, tempNeededFunctionForGlobalDeclpath);
    fflush(stdout);
    return ListOfFinalGlobalDeclarations;
}


/*
GlobalDeclarations extractGlobalDeclaration(GlobalDeclarations ListOfFinalGlobalDeclarations, char *tempGlobalFctDependOutputPath,
                                            char *tempIncludeLibFileMultiFiles, char *tempDefinesFileMultiFiles,
                                            char *definedGlobalTypesAndVariablesMultiFiles, char *tempGlobalDeclarationsPath,
                                            char * listOfSourceHeaderFilePaph, char * tempSourceHeaderFilesTargetPath,
                                            char * AllDefinedFunctionsInDonor, char * tempGlobalDependencies){

    printf("[AUTOSCALPEL] Extract Global Declarations\n");

    int normalDeclarationsID = 0;
    int structUnionDeclarationsID = 0;
    int typedefDeclarationsID = 0;
    int countFiles = 1;

    ListOfDefinedTypesAndVars * FinalListOfGlobalDefinedTypeVar = NULL;
    CallDependency * FinalListOfNeededFunctionsForGlobals = NULL;
    ListOfString *listOfAllSourceHeaderFiles = readListOfStringFromFileAsWords(listOfSourceHeaderFilePaph);

    char * tempPartialNeededFunctionForGlobalDeclpath;

    while (listOfAllSourceHeaderFiles) {

        char * currentHeaderFile = NULL;
        ListOfStructMark *ListOfDeclarationMark = NULL;

        currentHeaderFile = (char *) malloc((strlen(listOfAllSourceHeaderFiles->el) + 1) * sizeof (char));
        strcpy(currentHeaderFile, listOfAllSourceHeaderFiles->el);
        printf("--------------------------------------\n");
        printf("[TXL] Global Declarations Extractor \n\tFile[%d]:  %s\n",countFiles, currentHeaderFile);

        addAStringsInTheFile(currentHeaderFile, tempSourceHeaderFilesTargetPath);
        GlobalDeclarations ListOfCurrentGlobalDeclarations =
                fixGlobalDeclarationsForSkeletonMultiFiles( tempGlobalDeclarationsPath, definedGlobalTypesAndVariablesMultiFiles, tempDefinesFileMultiFiles,
                                                           tempIncludeLibFileMultiFiles, AllDefinedFunctionsInDonor, tempGlobalFctDependOutputPath, tempSourceHeaderFilesTargetPath,
                                                           TXLTemporaryFolderMainThread, tempGlobalDependencies);

        insertFileNameIntoListOfFinalGlobalDeclarations(ListOfCurrentGlobalDeclarations.normalDeclarations,
                                                        ListOfFinalGlobalDeclarations.normalDeclarations, currentHeaderFile);
        insertFileNameIntoListOfFinalGlobalDeclarations(ListOfCurrentGlobalDeclarations.structUnionDeclarations,
                                                        ListOfFinalGlobalDeclarations.structUnionDeclarations, currentHeaderFile);
        insertFileNameIntoListOfFinalGlobalDeclarations(ListOfCurrentGlobalDeclarations.typedefDeclarations,
                                                        ListOfFinalGlobalDeclarations.typedefDeclarations, currentHeaderFile);
#if 0 //LOSTEMP
        char *tempPartialGlobalDefFile;
        tempPartialGlobalDefFile = (char *) malloc((strlen("temp_partial_global_defs_output.out") + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof (char));
        sprintf(tempPartialGlobalDefFile, "%stemp_partial_global_defs_output.out",
                TXLTemporaryMultiFileFolder);
        printListOfGlobalDeclarationsAndFileinDefsOutput(ListOfCurrentGlobalDeclarations, tempPartialGlobalDefFile);
#endif
        addGlobalDeclarationListToExistingOneWithNewDefinitionID(&ListOfFinalGlobalDeclarations, ListOfCurrentGlobalDeclarations,
                                                                 &normalDeclarationsID,&structUnionDeclarationsID, &typedefDeclarationsID,
                                                                 &ListOfDeclarationMark );
        ListOfDefinedTypesAndVars *CurrentGlobalListOfDefinedTypeVar;

        /*Construc defined type var list without final mark
        /* TODO  use construct... here
        CurrentGlobalListOfDefinedTypeVar= readListOfDefinedTypesAndVarsFromFile(definedGlobalTypesAndVariablesMultiFiles);
        char *tempMarks;
        tempMarks = (char *) malloc((strlen("temp_marks.out") + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof (char));
        sprintf(tempMarks, "%stemp_marks.out",
                TXLTemporaryMultiFileFolder);
        printAListOfDeclarationMark(ListOfDeclarationMark, tempMarks);
        while(CurrentGlobalListOfDefinedTypeVar) {

            char *newMark = NULL;
            char *oldMark = (char *) malloc((strlen(CurrentGlobalListOfDefinedTypeVar->declType) + 1) * sizeof(char));
            strcpy(oldMark, CurrentGlobalListOfDefinedTypeVar->declType);
            strtok(oldMark, "\n");
            if (oldMark == NULL) {
                printf("ERRO: Old mark: %s does not find.\n", oldMark);
                exit(1);
            } else {
                newMark = returnNewMark(ListOfDeclarationMark, oldMark);
                if (newMark == NULL) {
                    printf("ERRO: There is no new mark to: %s.\n", oldMark);
                    exit(1);
                }
            }

            addNewListOfDefinedTypesAndVars(&FinalListOfGlobalDefinedTypeVar, CurrentGlobalListOfDefinedTypeVar->lineMarker, CurrentGlobalListOfDefinedTypeVar->definedTypes, CurrentGlobalListOfDefinedTypeVar->definedVar,newMark);
            CurrentGlobalListOfDefinedTypeVar = CurrentGlobalListOfDefinedTypeVar->next;
        }

        //the output file of needed functions to be extracted for globals!
        char *tempGlobalFctDependOutput;
        tempGlobalFctDependOutput = (char *) malloc(1000 * sizeof(char));

        sprintf(tempGlobalFctDependOutput,
                "%stemp_needed_functions_for_global_declarations.out",
                TXLTemporaryMultiFileFolder);

        CallDependency * CurrentListOfNeededFunctionsForGlobals = readListOfNeededFunctionsDeclaration(tempGlobalFctDependOutput);
        CallDependency * NewCurrentListOfNeededFunctionsForGlobals = NULL;

        fixMarkInNeededCallFunction(&NewCurrentListOfNeededFunctionsForGlobals, CurrentListOfNeededFunctionsForGlobals,
                                 ListOfDeclarationMark);

        addNeededCallFunctionDeclarationListToAnExistingOne(&FinalListOfNeededFunctionsForGlobals,
                                                               NewCurrentListOfNeededFunctionsForGlobals);


        tempPartialNeededFunctionForGlobalDeclpath = (char *) malloc(500 * sizeof (char));
        sprintf(tempPartialNeededFunctionForGlobalDeclpath, "%stemp_partial_needed_function.out", TXLTemporaryMultiFileFolder);
        printListOfNeededFunctionsForGlobalDeclaration(NewCurrentListOfNeededFunctionsForGlobals, tempPartialNeededFunctionForGlobalDeclpath);

        listOfAllSourceHeaderFiles = listOfAllSourceHeaderFiles->next;
        countFiles++;

        freeListOfCallDependency(&NewCurrentListOfNeededFunctionsForGlobals);
        freeListOfCallDependency(&CurrentListOfNeededFunctionsForGlobals);
        fflush(stdout);
    }

    removeAFileFromADirectory(tempPartialNeededFunctionForGlobalDeclpath);

    /*PRINT FINAL GLOBAL DEFS: temp_global_defs_output.out
    char *tempGlobalDef;
    tempGlobalDef = (char *) malloc((strlen("temp_global_defs_output.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempGlobalDef, "%stemp_global_defs_output.out",
            TXLTemporaryFolderMainThread);
    printListOfGlobalDeclarationsinDefsOutput(ListOfFinalGlobalDeclarations, tempGlobalDef);

    /*PRINT FINAL GLOBAL DEFS: temp_global_defs_output.out
    char *tempGlobalDefFile;
    tempGlobalDefFile = (char *) malloc((strlen("temp_global_defs_file_output.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempGlobalDefFile, "%stemp_global_defs_file_output.out",
            TXLTemporaryFolderMainThread);
    printListOfGlobalDeclarationsAndFileinDefsOutput(ListOfFinalGlobalDeclarations, tempGlobalDefFile);

    /*PRINT FINAL GLOBAL TYPE VAR DECALRATION: temp_global_type_var_declarations.out
    char * tempDefTypes;
    tempDefTypes = (char *) malloc(500 * sizeof (char));
    sprintf(tempDefTypes, "%stemp_global_type_var_declarations.out", TXLTemporaryFolderMainThread);
    printListOfGlobalListOfDefinedTypeVar(FinalListOfGlobalDefinedTypeVar, tempDefTypes);

    /*PRINT FINAL NEEDED CALL FUNCTION DECLARATION: temp_needed_functions_for_global_declarations.out
    char * tempNeededFunctionForGlobalDeclpath;
    tempNeededFunctionForGlobalDeclpath = (char *) malloc(500 * sizeof (char));
    sprintf(tempNeededFunctionForGlobalDeclpath, "%stemp_needed_functions_for_global_declarations.out", TXLTemporaryFolderMainThread);
    printListOfNeededFunctionsForGlobalDeclaration(FinalListOfNeededFunctionsForGlobals, tempNeededFunctionForGlobalDeclpath);

    return ListOfFinalGlobalDeclarations;
}*/


void addNewMark(ListOfStructMark ** head, char * oldMark, char * newMark) {
    ListOfStructMark * newEl = (ListOfStructMark *) malloc(1 * sizeof (ListOfStructMark));
    newEl->oldStatment = (char *) malloc(1000 * sizeof (char));
    strcpy(newEl->oldStatment, oldMark);
    newEl->newStatment = (char *) malloc(1000 * sizeof (char));
    strcpy(newEl->newStatment, oldMark);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DependencyList * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

DependencyList * readDeclarationMark(char * inputFile) {
    FILE * fin = fopen(inputFile, "r");
    char * line;
    line = (char *) malloc(100 * sizeof (char));
    ListOfStructMark * ListOfGlobalDeclMark = NULL;
    char * oldMark;
    oldMark = (char*) malloc(100 * sizeof (char));
    char * newMark;
    newMark = (char*) malloc(100 * sizeof (char));
    while (fgets(line, 99, fin) != NULL) {
        fgets(line, 99, fin);
        strtok(line, "\n");
        strcpy(oldMark, line);
        fgets(line, 99, fin);
        strtok(line, "\n");
        strcpy(newMark, line);
        fgets(line, 99, fin);
        if(strcmp(line, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"))
            addNewMark(&ListOfGlobalDeclMark, oldMark, newMark);
    }
    free(line);
    free(oldMark);
    free(newMark);
    fclose(fin);
    return ListOfGlobalDeclMark;
}

void printDeclarationMark(char * outputFile, ListOfStructMark * head) {
    FILE * fout = fopen(outputFile, "w");
    ListOfStructMark * p;
    p = head;
    while (p) {
        fprintf(fout, "%s\n", p->oldStatment);
        fprintf(fout, "%s\n", p->oldStatment);
        fprintf(fout, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        p = p ->next;
    }
    fclose(fout);
}
/*
DependencyList * extractGlobalDependencies(GlobalDeclarations ListOfFinalGlobalDeclarations, char * allSourceFiles, char * allHeaderFiles,
                                         char * tempSourceHeaderFilesTargetPath, char * tempGlobalTypeVarDeclaration, char * tempDefinesFile,
                                         char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                         char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder){

    printf("[AUTOSCALPEL] Extract Global Dependencies\n");

    DependencyList * FinalGlobalDependencyList = NULL;

    char *tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc((strlen("temp_global_dependencies.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out",
            TXLTemporaryFolderMainThread);

    char *tempPartialGlobalDependencies;
    tempPartialGlobalDependencies = (char *) malloc((strlen("temp_partial_global_dependencies.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempPartialGlobalDependencies, "%stemp_partial_global_dependencies.out",
            TXLTemporaryFolderMainThread);

    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

    ListOfString * ListOfSourceHeaderFiles = readListOfStringFromFileAsWords(allSourceFiles);
    ListOfString * ListOfAllDonorHeaderFiles = readListOfStringFromFileAsWords(allHeaderFiles);
    ListOfString * auxListOfSourceHeaderFiles = ListOfSourceHeaderFiles;
    ListOfString * auxListOfHeaderFiles = ListOfAllDonorHeaderFiles;

    while(auxListOfHeaderFiles){
        addNewString(&auxListOfSourceHeaderFiles, auxListOfHeaderFiles->el);
        auxListOfHeaderFiles = auxListOfHeaderFiles->next;
    }

    ListOfString * auxCurrentListOfHeaderFiles;

    char *tempFileGlobalDependencies;
    tempFileGlobalDependencies = (char *) malloc((strlen("temp_partial_dependencies_files_extracted.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempFileGlobalDependencies, "%stemp_partial_dependencies_files_extracted.out",
            TXLTemporaryFolderMainThread);

    char *tempFileDeclarationMark;
    tempFileDeclarationMark = (char *) malloc((strlen("temp_partial_declaration_file.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempFileDeclarationMark, "%temp_partial_declaration_file.out",
            TXLTemporaryFolderMainThread);

    if(file_exists(tempFileGlobalDependencies))
        createFile(tempFileGlobalDependencies);

    ListOfString * listOfFilesDepencenceExtracted = readListOfStringFromFile(tempFileGlobalDependencies);

    DependencyList *NewGlobalCurrentDependencyList = NULL;
    ListOfStructMark *ListOfDeclarationMark = NULL;
    DependencyList *GlobalCurrentDependencyList = NULL;


    char *currentSourceOrHeaderFileFormatted = NULL;
    currentSourceOrHeaderFileFormatted = (char *) malloc(200 * sizeof(char));

    while (auxListOfSourceHeaderFiles) {

        //char *currentSourceOrHeaderFile = NULL;
       // currentSourceOrHeaderFile = (char *) malloc((strlen(auxListOfSourceHeaderFiles->el) + 1) * sizeof(char));
        //strcpy(currentSourceOrHeaderFile, auxListOfSourceHeaderFiles->el);

       // char *currentSourceOrHeaderFileFormatted = NULL;
        //currentSourceOrHeaderFileFormatted = (char *) malloc((strlen(auxListOfSourceHeaderFiles->el) + 3) * sizeof(char));
        strcpy(currentSourceOrHeaderFileFormatted, auxListOfSourceHeaderFiles->el);
        strcat(currentSourceOrHeaderFileFormatted,"\n");

        //FinalGlobalDependencyList =  readDependencyListFromFile(tempGlobalDependencies);

        if(!searchStringInListOfStrings(listOfFilesDepencenceExtracted,currentSourceOrHeaderFileFormatted)) {

            if (!strstr(auxListOfSourceHeaderFiles->el, ".h"))
                auxCurrentListOfHeaderFiles = ListOfAllDonorHeaderFiles;
            else
                auxCurrentListOfHeaderFiles = ListOfAllDonorHeaderFiles->next;

            while (auxCurrentListOfHeaderFiles) {

                addAStringsInTheFile(auxListOfSourceHeaderFiles->el, tempSourceHeaderFilesTargetPath);

                char *currentHeaderFile = NULL;
                currentHeaderFile = (char *) malloc((strlen(auxCurrentListOfHeaderFiles->el) + 1) * sizeof(char));
                strcpy(currentHeaderFile, auxCurrentListOfHeaderFiles->el);

                /* LOS used to not compare the same header file
                if (strcmp(currentHeaderFile, auxListOfSourceHeaderFiles->el)) {

                    printf("\tFiles:  %s -> %s\n", auxListOfSourceHeaderFiles->el, currentHeaderFile);

                   /// ListOfDeclarationMark = readDeclarationMark(tempFileDeclarationMark);

                    addAStringsInTheEndFile(currentHeaderFile, tempSourceHeaderFilesTargetPath);

                    GlobalDeclarations ListOfCurrentGlobalDeclarations = constructListOfGlobalDeclarationsForSGD(
                            &GlobalCurrentDependencyList,
                            &GlobalListOfDefinedTypeVar, tempGlobalTypeVarDeclaration,
                            tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor,
                            GlobalFctDependOutput, TXLTemporaryFolderMainThread, TXLTemporaryMultiFileFolder);

                    addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.normalDeclarations,
                                    ListOfCurrentGlobalDeclarations.normalDeclarations, "GLOBAL_DECL_");
                    addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.structUnionDeclarations,
                                    ListOfCurrentGlobalDeclarations.structUnionDeclarations, "STRUCT_DECL_");
                    addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.typedefDeclarations,
                                    ListOfCurrentGlobalDeclarations.typedefDeclarations, "TYPEDEF_DECL_");

                    /*Create new dependency list with final marks
                    addNewDependencyListMark(&NewGlobalCurrentDependencyList, GlobalCurrentDependencyList,
                                             ListOfDeclarationMark);

                    /*LOS Add current dependency list in Final dependency list
                    addDependencyListToAnExistingOneSearchingIfVarExisting(&FinalGlobalDependencyList,
                                                                           NewGlobalCurrentDependencyList);

                    printADependencyList(tempPartialGlobalDependencies, NewGlobalCurrentDependencyList);
                    freeListOfListOfDefinedTypesAndVars(&GlobalListOfDefinedTypeVar);
                    freeDependencyList(&NewGlobalCurrentDependencyList);
                    freeDependencyList(&GlobalCurrentDependencyList);
                    freeListOfGlobalDeclarationMak(&ListOfDeclarationMark);
                }
                free(currentHeaderFile);
                auxCurrentListOfHeaderFiles = auxCurrentListOfHeaderFiles->next;
                fflush(stdout);

            }

            printADependencyList(tempGlobalDependencies, FinalGlobalDependencyList);
            addNewString(&listOfFilesDepencenceExtracted, currentSourceOrHeaderFileFormatted);
            printAListOfStrings(listOfFilesDepencenceExtracted, tempFileGlobalDependencies);

            //freeListOfStrings(&listOfFilesDepencenceExtracted);
           // free(currentSourceOrHeaderFile);
           // free(currentSourceOrHeaderFileFormatted);
            //freeDependencyList(&FinalGlobalDependencyList);
        }
        auxListOfSourceHeaderFiles = auxListOfSourceHeaderFiles->next;
        fflush(stdout);
    }

   /// FinalGlobalDependencyList =  readDependencyListFromFile(tempGlobalDependencies);
   // printADependencyList(tempGlobalDependencies, FinalGlobalDependencyList);

    return FinalGlobalDependencyList;
}
*/



void searchAddEnumDependency(ListOfStructDefinitions * nextListOfStructDeclarations, DependencyList **FinalGlobalDependencyList, char *structDefinition,char * declStructMark){
    ListOfString * ListOfStructsElements;
    char * currentDeclStructMark = NULL;
    char *currentStructElement = (char *) malloc(99999 * sizeof (char));
    char *formatedDeclStructMark = (char *) malloc(500 * sizeof(char));
    char *formatedCurrentDeclStructMark = (char *) malloc(500 * sizeof(char));
    DependencyList * stmDepend = NULL;
    char *isDependecy = NULL;
    while(nextListOfStructDeclarations) {
        ListOfStructsElements = nextListOfStructDeclarations->structDef;
        while (ListOfStructsElements) {
            strcpy(currentStructElement,ListOfStructsElements->el);
            if (strstr(currentStructElement, structDefinition)) {
                currentDeclStructMark = getMarkFromDeclaration(nextListOfStructDeclarations,
                                                               nextListOfStructDeclarations->structDef->el);

                sprintf(formatedCurrentDeclStructMark, "/* %s */", currentDeclStructMark);
                sprintf(formatedDeclStructMark, "/* %s */", declStructMark);
                stmDepend = searchDependenciesForAnElement(*FinalGlobalDependencyList,
                                                           formatedDeclStructMark);
                if(declStructMark != NULL) {
                    if (stmDepend == NULL) {
                        addNewStatement(FinalGlobalDependencyList, formatedDeclStructMark);
                        addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedDeclStructMark, formatedCurrentDeclStructMark);
                    } else {
                        isDependecy = searchDependencies(stmDepend->ListOfDependencies, formatedCurrentDeclStructMark);
                        if (isDependecy == NULL)
                            addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedDeclStructMark,
                                                          formatedCurrentDeclStructMark);
                    }
                } else
                    printf("Error: Trying to find mark!\n");
            }
            stmDepend = NULL;
            isDependecy = NULL;
            ListOfStructsElements = ListOfStructsElements->next;
        }

        nextListOfStructDeclarations = nextListOfStructDeclarations->next;
    }

    free(formatedCurrentDeclStructMark);
    free(formatedDeclStructMark);
    free(currentDeclStructMark);
    freeDependencyList(&stmDepend);
    free(isDependecy);
    free(currentStructElement);
}

void searchAddDependency(ListOfStructDefinitions * nextListOfStructDeclarations, DependencyList **FinalGlobalDependencyList, char *structDefinition,char * declStructMark){
    ListOfString * ListOfStructsElements;
    char * currentDeclStructMark = NULL;
    char *currentStructElement = (char *) malloc(99999 * sizeof (char));
    char *formatedDeclStructMark = (char *) malloc(500 * sizeof(char));
    char *formatedCurrentDeclStructMark = (char *) malloc(500 * sizeof(char));
    DependencyList * stmDepend = NULL;
    char *isDependecy = NULL;
    while(nextListOfStructDeclarations) {
        ListOfStructsElements = nextListOfStructDeclarations->structDef;
        while (ListOfStructsElements) {
            strcpy(currentStructElement,ListOfStructsElements->el);
            if (strstr(currentStructElement, structDefinition)) {
                currentDeclStructMark = getMarkFromDeclaration(nextListOfStructDeclarations,
                                                               nextListOfStructDeclarations->structDef->el);

                sprintf(formatedCurrentDeclStructMark, "/* %s */", currentDeclStructMark);
                sprintf(formatedDeclStructMark, "/* %s */", declStructMark);
                stmDepend = searchDependenciesForAnElement(*FinalGlobalDependencyList,
                                                           formatedCurrentDeclStructMark);
                if(declStructMark != NULL) {
                    if (stmDepend == NULL) {
                        addNewStatement(FinalGlobalDependencyList, formatedCurrentDeclStructMark);
                        addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedCurrentDeclStructMark, formatedDeclStructMark);
                    } else {
                        isDependecy = searchDependencies(stmDepend->ListOfDependencies, formatedDeclStructMark);
                        if (isDependecy == NULL)
                            addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedCurrentDeclStructMark,
                                                          formatedDeclStructMark);
                    }
                } else
                    printf("Error: Trying to find mark!\n");
            }
            stmDepend = NULL;
            isDependecy = NULL;
            ListOfStructsElements = ListOfStructsElements->next;
        }

        nextListOfStructDeclarations = nextListOfStructDeclarations->next;
    }
    free(formatedCurrentDeclStructMark);
    free(formatedDeclStructMark);
    free(declStructMark);
    free(currentDeclStructMark);
    freeDependencyList(&stmDepend);
    free(isDependecy);
}

void checkEnumDefDependency(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations){
    ListOfStructDefinitions * auxListOfStructDeclarations = ListOfFinalGlobalDeclarations.structUnionDeclarations;
    ListOfStructDefinitions * ListOfNormalDeclaration = NULL;
    ListOfString * ListOfStructsElements;
    char * declStructMark = NULL;
    char *currentEnumDefinition = (char *) malloc(500 * sizeof(char));
    char *formatedCurrentDeclStructMark = (char *) malloc(500 * sizeof(char));
    while(auxListOfStructDeclarations){
        ListOfStructsElements = auxListOfStructDeclarations->structDef;
        declStructMark = getMarkFromDeclaration(auxListOfStructDeclarations, ListOfStructsElements->el);
        ListOfStructsElements = ListOfStructsElements->next;
        while(ListOfStructsElements){
            char *currentStructDecl = (char *) malloc((strlen(ListOfStructsElements->el) + 1) * sizeof(char));
            strcpy(currentStructDecl,ListOfStructsElements->el);
            if(strstr(currentStructDecl, "enum")){
                sprintf(currentEnumDefinition,"enum %s", readSubstring("enum ", currentStructDecl, " "));
                ListOfNormalDeclaration =  ListOfFinalGlobalDeclarations.normalDeclarations;
                searchAddEnumDependency(ListOfNormalDeclaration,FinalGlobalDependencyList, currentEnumDefinition, declStructMark);
            }
           ListOfStructsElements = ListOfStructsElements->next;
        }
#if 0
        while(nextListOfStructDeclarations) {
            ListOfStructsElements = nextListOfStructDeclarations->structDef;
            while (ListOfStructsElements) {
                strcpy(currentStructElement,ListOfStructsElements->el);
                if (strstr(currentStructElement, structDefinition)) {
                    currentDeclStructMark = getMarkFromDeclaration(nextListOfStructDeclarations,
                                                                   nextListOfStructDeclarations->structDef->el);

                    sprintf(formatedCurrentDeclStructMark, "/* %s */", currentDeclStructMark);
                    sprintf(formatedDeclStructMark, "/* %s */", declStructMark);
                    stmDepend = searchDependenciesForAnElement(*FinalGlobalDependencyList,
                                                                                formatedCurrentDeclStructMark);
                    if(declStructMark != NULL) {
                        if (stmDepend == NULL) {
                            addNewStatement(FinalGlobalDependencyList, formatedCurrentDeclStructMark);
                            addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedCurrentDeclStructMark, formatedDeclStructMark);
                        } else {
                            isDependecy = searchDependencies(stmDepend->ListOfDependencies, formatedDeclStructMark);
                            if (isDependecy == NULL)
                                addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedCurrentDeclStructMark,
                                                              formatedDeclStructMark);
                        }
                    } else
                        printf("Error: Trying to find mark!\n");
                }
                stmDepend = NULL;
                isDependecy = NULL;
                ListOfStructsElements = ListOfStructsElements->next;
            }

            nextListOfStructDeclarations = nextListOfStructDeclarations->next;
        }
#endif
        auxListOfStructDeclarations = auxListOfStructDeclarations->next;
    }
    free(formatedCurrentDeclStructMark);
    free(declStructMark);
}

 #define GLOBAL_DECL_MARKER "GLOBAL_DECL_"

void checkTypeDefDependency(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations){
    ListOfStructDefinitions * auxListOfStructDeclarations = ListOfFinalGlobalDeclarations.structUnionDeclarations;
    char *structDefinition = (char *) malloc(99999 * sizeof (char));
    ListOfStructDefinitions * ListOfTypeDefDeclarations = NULL;
    char * declStructMark = NULL;
    while(auxListOfStructDeclarations){
        char *currentStructDecl = (char *) malloc((strlen(auxListOfStructDeclarations->structDef->el) + 1) * sizeof(char));
        strcpy(currentStructDecl,auxListOfStructDeclarations->structDef->el);
        strcpy(structDefinition,readSubstring("*/ ", currentStructDecl, " {"));
        declStructMark = getMarkFromDeclaration(auxListOfStructDeclarations, currentStructDecl);
        ListOfTypeDefDeclarations =  ListOfFinalGlobalDeclarations.typedefDeclarations;
        searchAddDependency(ListOfTypeDefDeclarations,FinalGlobalDependencyList, structDefinition, declStructMark);

        auxListOfStructDeclarations = auxListOfStructDeclarations->next;
    }

    free(structDefinition);
}

void checkStrucDependency(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations){
    ListOfStructDefinitions * auxListOfStructDeclarations = ListOfFinalGlobalDeclarations.structUnionDeclarations;
    char *structDefinition = (char *) malloc(99999 * sizeof (char));
    ListOfStructDefinitions * nextListOfStructDeclarations;
    char * declStructMark = NULL;

    while(auxListOfStructDeclarations){
        char *currentStructDecl = (char *) malloc((strlen(auxListOfStructDeclarations->structDef->el) + 1) * sizeof(char));
        strcpy(currentStructDecl,auxListOfStructDeclarations->structDef->el);
        strcpy(structDefinition,readSubstring("*/ ", currentStructDecl, " {"));
        declStructMark = getMarkFromDeclaration(auxListOfStructDeclarations, currentStructDecl);
        nextListOfStructDeclarations = auxListOfStructDeclarations;
        nextListOfStructDeclarations = nextListOfStructDeclarations->next;
        searchAddDependency(nextListOfStructDeclarations,FinalGlobalDependencyList, structDefinition, declStructMark);

        auxListOfStructDeclarations = auxListOfStructDeclarations->next;
    }

}

void checkDependecyFromDeclaration(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations){
    /* Look for struct declaration does not found */

    ListOfStructDefinitions * auxListOfNormalDeclarations = ListOfFinalGlobalDeclarations.normalDeclarations;
    ListOfStructDefinitions * auxListOfStructUnionDeclarations = NULL;

    while(auxListOfNormalDeclarations){
       char *currentGlobalDecl = (char *) malloc((strlen(auxListOfNormalDeclarations->structDef->el) + 1) * sizeof(char));
       strcpy(currentGlobalDecl,auxListOfNormalDeclarations->structDef->el);
       if (strstr(currentGlobalDecl, GLOBAL_DECL_BEGINNING_MARKER)) {
          ListOfString * currentDeclarationAsWords = NULL;
          readStringAsWords(currentGlobalDecl, &currentDeclarationAsWords);
          currentDeclarationAsWords = currentDeclarationAsWords->next;
          char * globalDeclMark = (char *) malloc((strlen(currentDeclarationAsWords->el) + 1) * sizeof(char));
          strcpy(globalDeclMark,currentDeclarationAsWords->el);
          if (strstr(globalDeclMark, GLOBAL_DECL_MARKER)) {
              currentDeclarationAsWords = currentDeclarationAsWords->next;
              char * structMark = (char *) malloc((strlen(currentDeclarationAsWords->el) + 1) * sizeof(char));
              currentDeclarationAsWords = currentDeclarationAsWords->next; 
              strcpy(structMark,currentDeclarationAsWords->el);
              /* Get struct mark */
              if(strstr(structMark, "struct")){
                  currentDeclarationAsWords = currentDeclarationAsWords->next;
                  /*Get declaration type */
                  char * currentDeclType = (char *) malloc((strlen(currentDeclarationAsWords->el) + 1) * sizeof(char));
                  strcpy(currentDeclType,currentDeclarationAsWords->el);
                  auxListOfStructUnionDeclarations = ListOfFinalGlobalDeclarations.structUnionDeclarations;
                  char * declTypeMark = NULL;
                  declTypeMark = getMarkFromDeclaration(auxListOfStructUnionDeclarations, currentDeclType);
                  if(declTypeMark != NULL){
                     char * formatedDeclTypeMark;
                     formatedDeclTypeMark = (char *) malloc(500 * sizeof(char));
                     sprintf(formatedDeclTypeMark, "/* %s */",  declTypeMark);
                     char * formatedGlobalDeclMark;
                     formatedGlobalDeclMark = (char *) malloc(500 * sizeof(char));
                     sprintf(formatedGlobalDeclMark, "/* %s */",  globalDeclMark);
                     DependencyList * stmDepend =    NULL;
                     stmDepend = searchDependenciesForAnElement(*FinalGlobalDependencyList, formatedGlobalDeclMark);
                     if(stmDepend == NULL) {
                         if(strstr(formatedDeclTypeMark, "STRUCT_DECL_10"))
                             printf("aqui");
                         addNewStatement(FinalGlobalDependencyList, formatedGlobalDeclMark) ;
                         addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedGlobalDeclMark, formatedDeclTypeMark);
                     } else {
                          char *isDependecy = NULL;
                          isDependecy = searchDependencies(stmDepend->ListOfDependencies, formatedDeclTypeMark);
                          if(isDependecy == NULL)
                              addNewDependencyInExistingOne(FinalGlobalDependencyList, formatedGlobalDeclMark, formatedDeclTypeMark);
                    }

                  }
               }
             }
          }
       auxListOfNormalDeclarations = auxListOfNormalDeclarations->next;
   }

}

void constructListOfGlobalDeclarations2(DependencyList ** globalDependencyList,
                                                           char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                                           char * TXLTemporaryMultiFileFolder) {

    char * sourceFileTargetNames;
    sourceFileTargetNames = (char *) malloc(500 * sizeof (char));
    sprintf(sourceFileTargetNames, "%stemp_source_header_files_target.out", TXLTemporaryMultiFileFolder);

    /* text ifdef program definition: sifdef.x*/
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(1000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLToolsPath);

    /* temp global definition output: temp_global_defs_output.out */
    char * tempGlobalDefsOutput;
    tempGlobalDefsOutput = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDefsOutput, "%stemp_global_defs_output.out", TXLTemporaryMultiFileFolder);

    /* temp global type variable declarations: temp_global_type_var_declarations.out */
    char *definedGlobalTypesAndVariablesFile;
    definedGlobalTypesAndVariablesFile = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryMultiFileFolder);

    char * tempGlobalFctDependOutputMultiFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempGlobalFctDependOutputMultiFile, "%stemp_needed_functions_for_global_declarations.out",
            TXLTemporaryMultiFileFolder);

    fflush(stdout);
    /* temp global dependencies: temp_global_dependencies.out */
    char * tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryFolderMainThread);

    extractAllGlobalDeclStructAndTypedefDefinitionsFromOrgan(sourceFileTargetNames, tempGlobalDefsOutput,
                                                             tempGlobalDependencies, definedGlobalTypesAndVariablesFile, txlIfDefProg, TXLToolsPath,
                                                             tempDefinesFile, tempIncludeLibFile, AllDefinedFunctionsInDonor, tempGlobalFctDependOutputMultiFile);

    * globalDependencyList = readDependencyListFromFile(tempGlobalDependencies);


    free(tempGlobalDependencies);
    free(sourceFileTargetNames);
    free(txlIfDefProg);
    free(tempGlobalDefsOutput);
    free(definedGlobalTypesAndVariablesFile);
    free(tempGlobalFctDependOutputMultiFile);

    fflush(stdout);

}


DependencyList * extractGlobalDependencies2(char * AllDefinedFunctionsInTargetPath, char * inputFilesPath ) {
    /* LOS: Create list of old and new IDs */
    char *tempGlobalTypeVarDeclaration;
    tempGlobalTypeVarDeclaration = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalTypeVarDeclaration,
            "%stemp_global_type_var_declarations.out",
            inputFilesPath);

    char *tempDefinesFile;
    tempDefinesFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempDefinesFile, "%stemp_define_file.out", inputFilesPath);
    fflush(stdout);

    char *tempIncludeLibFile;
    tempIncludeLibFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out", inputFilesPath);
    fflush(stdout);

    char *GlobalFctDependOutput;
    GlobalFctDependOutput = (char *) malloc(1000 * sizeof(char));
    sprintf(GlobalFctDependOutput, "%stemp_needed_functions_for_global_declarations.out",
            inputFilesPath);

    DependencyList *GlobalDependencyList = NULL;

    constructListOfGlobalDeclarations2( &GlobalDependencyList, tempDefinesFile,
            tempIncludeLibFile, AllDefinedFunctionsInTargetPath, inputFilesPath);

    return GlobalDependencyList;
}

DependencyList * extractGlobalDependenciesMultFile(GlobalDeclarations ListOfFinalGlobalDeclarations,
                                         char * tempSourceHeaderFilesTargetPath, char * tempGlobalTypeVarDeclaration,
                                         char * AllDefinedFunctionsInDonor, char * TXLTemporaryMultiFileFolder){
    printf("[AUTOSCALPEL] Extracting Global Dependencies\n");

    char * allSourceFiles = (char *) malloc(100 * sizeof (char));
    sprintf(allSourceFiles, "%ssourceFilesInDonor.out", TXLTemporaryMultiFileFolder);

    char * allHeaderFiles = (char *) malloc(100 * sizeof (char));
    sprintf(allHeaderFiles, "%sheaderFilesInDonor.out", TXLTemporaryMultiFileFolder);

    char *tempFileGlobalDependencies = (char *) malloc(100 * sizeof (char));
    sprintf(tempFileGlobalDependencies, "%stemp_dependencies_files_extracted.out", TXLTemporaryFolderMainThread);

    fflush(stdout);

    ListOfString * ListOfAllSourceFilesInDonor = readListOfStringFromFileAsWords(allSourceFiles);
    ListOfString * ListOfAllHeaderFilesInDonor = readListOfStringFromFileAsWords(allHeaderFiles);

    ListOfString * auxListOfHeaderFiles = NULL;
    DependencyList * FinalGlobalDependencyList = NULL;

    ListOfString * listOfFilesDepencenceExtracted = readListOfStringFromFile(tempFileGlobalDependencies);
   /// FinalGlobalDependencyList = readDependencyListFromFile(tempGlobalDependencies);

    DependencyList *NewGlobalCurrentDependencyList = NULL;
    ListOfStructMark *ListOfDeclarationMark = NULL;
    DependencyList *GlobalCurrentDependencyList = NULL;

    char *currentSourceFileFormatted = NULL;
    currentSourceFileFormatted = (char *) malloc(200 * sizeof(char));
   // printf("\tExtracting Dependency...\n\t");

    while (ListOfAllSourceFilesInDonor) {
        strcpy(currentSourceFileFormatted, ListOfAllSourceFilesInDonor->el);
        strcat(currentSourceFileFormatted,"\n");
      ///  if(strstr(currentSourceFileFormatted, "regex.c"))
      ///           printf("stop");


        printf("#");    //progress bar
        ///addAListOfStringsInTheEndOfFileLN(ListOfAllSourceFilesInDonor, tempSourceHeaderFilesTargetPath)
        addAStringsInTheFile(ListOfAllSourceFilesInDonor->el, tempSourceHeaderFilesTargetPath);

        if(!searchStringInListOfStrings(listOfFilesDepencenceExtracted,currentSourceFileFormatted)) {
            auxListOfHeaderFiles = ListOfAllHeaderFilesInDonor;
            ///if(strstr(auxListOfHeaderFiles, "regex.h"))
           ///     printf("stop");
#ifdef DEBUGING
        ///    printf("\tExtracting Dependences from:  %s ....\n", auxListOfSourceFiles->el);
#endif
            addAListOfStringsInTheEndOfFileLN(auxListOfHeaderFiles, tempSourceHeaderFilesTargetPath);

            GlobalDeclarations ListOfCurrentGlobalDeclarations = constructListOfGlobalDeclarationsForSGD(
                            &GlobalCurrentDependencyList,
                            AllDefinedFunctionsInDonor, TXLTemporaryMultiFileFolder);

            /* Construct list of statment current and final marks */
            addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.normalDeclarations,
                                    ListOfCurrentGlobalDeclarations.normalDeclarations, "GLOBAL_DECL_");
            addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.structUnionDeclarations,
                                    ListOfCurrentGlobalDeclarations.structUnionDeclarations, "STRUCT_DECL_");
            addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.typedefDeclarations,
                                    ListOfCurrentGlobalDeclarations.typedefDeclarations, "TYPEDEF_DECL_");

            /* Create new dependency list with final marks */
            addNewDependencyListMark(&NewGlobalCurrentDependencyList, GlobalCurrentDependencyList,
                                             ListOfDeclarationMark);

#ifdef DEBUGING
            char *tempPartialGlobalDependencies;
            tempPartialGlobalDependencies = (char *) malloc((strlen("temp_partial_global_dependencies.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
            sprintf(tempPartialGlobalDependencies, "%stemp_partial_global_dependencies.out",
                    TXLTemporaryFolderMainThread);
            printADependencyList(NewGlobalCurrentDependencyList, tempPartialGlobalDependencies);
#endif
            /* Add current dependency list in Final dependency list */
      ///     addDependencyListToAnExistingOne(&FinalGlobalDependencyList, NewGlobalCurrentDependencyList);
        /*    char * tempGlobalDependencies;
            tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
            sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryFolderMainThread);
            printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);
            char *tempGlobalDef= (char *) malloc(100 * sizeof (char));
            sprintf(tempGlobalDef, "%stemp_global_defs_output.out", TXLTemporaryFolderMainThread);
            printListOfGlobalDeclarationsinDefsOutput(ListOfFinalGlobalDeclarations, tempGlobalDef);*/
#ifdef DEBUGING
            char * tempGlobalDependencies;
            tempGlobalDependencies = (char *) malloc(500 * sizeof (char));
            sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryFolderMainThread);
            /* Print FinalGlobalDependencyList */
            printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);
#endif
            /* Save temp file already checked */
            addNewString(&listOfFilesDepencenceExtracted, currentSourceFileFormatted);
            printAListOfStrings(listOfFilesDepencenceExtracted, tempFileGlobalDependencies);

            freeDependencyList(&NewGlobalCurrentDependencyList);
            freeDependencyList(&GlobalCurrentDependencyList);

        }
        ListOfAllSourceFilesInDonor = ListOfAllSourceFilesInDonor->next;
        fflush(stdout);
    }

    char *tempGlobalDef =  (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDef, "%stemp_global_defs_file_output.out", TXLTemporaryFolderMainThread);

    char *tempGlobalDependencies =  (char *) malloc(100 * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out", TXLTemporaryFolderMainThread);
//TODO Refactor checks functions
    checkDependecyFromDeclaration(&FinalGlobalDependencyList,ListOfFinalGlobalDeclarations );
    printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);

    checkStrucDependency(&FinalGlobalDependencyList,ListOfFinalGlobalDeclarations );
    printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);

    checkTypeDefDependency(&FinalGlobalDependencyList,ListOfFinalGlobalDeclarations );
    printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);

    checkEnumDefDependency(&FinalGlobalDependencyList,ListOfFinalGlobalDeclarations );
    printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);


    free(allSourceFiles);
    free(allHeaderFiles);
    free(tempGlobalDependencies);
    free(tempFileGlobalDependencies);
    freeListOfStrings(&listOfFilesDepencenceExtracted);

    return FinalGlobalDependencyList;
}



DependencyList * extractGlobalDependenciesOrgan(GlobalDeclarations ListOfFinalGlobalDeclarations,
                                         char * tempSourceHeaderFilesTargetPath, char * tempGlobalTypeVarDeclaration, char * tempDefinesFile,
                                         char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                         char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder){

    printf("[AUTOSCALPEL] Extracting Global Dependencies\n");

    DependencyList * FinalGlobalDependencyList = NULL;

    char *tempGlobalDependencies;
    tempGlobalDependencies = (char *) malloc((strlen("temp_global_dependencies.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempGlobalDependencies, "%stemp_global_dependencies.out",
            TXLTemporaryFolderMainThread);

    char *tempPartialGlobalDependencies;
    tempPartialGlobalDependencies = (char *) malloc((strlen("temp_partial_global_dependencies.out") + strlen(TXLTemporaryFolderMainThread) + 1) * sizeof (char));
    sprintf(tempPartialGlobalDependencies, "%stemp_partial_global_dependencies.out",
            TXLTemporaryFolderMainThread);

    ListOfDefinedTypesAndVars * GlobalListOfDefinedTypeVar;

   // FinalGlobalDependencyList = readDependencyListFromFile(tempGlobalDependencies);

    DependencyList *NewGlobalCurrentDependencyList = NULL;
    ListOfStructMark *ListOfDeclarationMark = NULL;
    DependencyList *GlobalCurrentDependencyList = NULL;

    GlobalDeclarations ListOfCurrentGlobalDeclarations = constructListOfGlobalDeclarationsForSGD(
            &GlobalCurrentDependencyList,
             AllDefinedFunctionsInDonor,
             TXLTemporaryMultiFileFolder);

    addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.normalDeclarations,
                    ListOfCurrentGlobalDeclarations.normalDeclarations, "GLOBAL_DECL_");
    addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.structUnionDeclarations,
                    ListOfCurrentGlobalDeclarations.structUnionDeclarations, "STRUCT_DECL_");
    addStatementMark(&ListOfDeclarationMark, ListOfFinalGlobalDeclarations.typedefDeclarations,
                    ListOfCurrentGlobalDeclarations.typedefDeclarations, "TYPEDEF_DECL_");

    /*Create new dependency list with final marks */
    addNewDependencyListMark(&NewGlobalCurrentDependencyList, GlobalCurrentDependencyList,
                                     ListOfDeclarationMark);

    /*LOS Add current dependency list in Final dependency list */
    addDependencyListToAnExistingOne(&FinalGlobalDependencyList, NewGlobalCurrentDependencyList);

    printADependencyList(NewGlobalCurrentDependencyList, tempPartialGlobalDependencies);
    printADependencyList(FinalGlobalDependencyList, tempGlobalDependencies);

    freeListOfListOfDefinedTypesAndVars(&GlobalListOfDefinedTypeVar);
    freeDependencyList(&NewGlobalCurrentDependencyList);
    freeDependencyList(&GlobalCurrentDependencyList);

    /// FinalGlobalDependencyList =  readDependencyListFromFile(tempGlobalDependencies);
    // printADependencyList(tempGlobalDependencies, FinalGlobalDependencyList);

    return FinalGlobalDependencyList;
}

#endif

#if 1


ListOfString * getListOfHeaderDependency(char * sourceFile, char * outputFile, char *headerFilesTarget){
    ListOfString *ListOfHeaderFiles = NULL;
    char gccCommand[10000];
    sprintf(gccCommand, "gcc -MM %s > %s 2> ErrorFile.out", sourceFile, outputFile);
    int status = system(gccCommand);
    if (status != 0) {
        printf("[Running gcc -MM] %s has no include header dependency\n", sourceFile);
       /// exit(1);
    } else {
        ListOfString *ListOfFullHeaderFiles = readListOfStringFromFileAsWords(outputFile);
        while (ListOfFullHeaderFiles) {
            if (strstr(ListOfFullHeaderFiles->el, ".h") != NULL && strstr(ListOfFullHeaderFiles->el, headerFilesTarget) ) {
                addNewString(&ListOfHeaderFiles, ListOfFullHeaderFiles->el);
            }
            ListOfFullHeaderFiles = ListOfFullHeaderFiles->next;
        }
    }
    return ListOfHeaderFiles;
}
void extractNeededGlobalDeclarationsForExtractedLOCsMultiFiles( CallDependency * ListOfNeededFunctionsForAllLOCs,
                                                      DependencyList * SkeletonDependenciesOnGlobals,
                                                      GlobalDeclarations ListOfFinalGlobalDeclarations, DependencyList * FinalGlobalDependencyList,
                                                      char * tempGlobalDeclarations,
                                                      char * definedGlobalTypesAndVariablesFile,
                                                      ListOfString * FinalSkeletonSourceCode,
                                                      ListOfString * TheListOfTransplantedMarkers,
                                                      char * outputFileGlobalDependenciesOnFunctions) {
    printf("[AUTOSCALPEL] Extracting needed global declarations for extracted LOCs\n");

    char *fSoureFilesTargetFullPath = (char *) malloc(500 * sizeof(char));
    sprintf(fSoureFilesTargetFullPath, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

    char *tempAllHeaderFilesTargetPath = NULL;
    tempAllHeaderFilesTargetPath = (char *) malloc(500 * sizeof(char));
    sprintf(tempAllHeaderFilesTargetPath, "%stemp_list_of_header_files_extracted.out", TXLTemporaryMultiFileFolder);

    char *partialListOfFileDeclarationExtracted;
    partialListOfFileDeclarationExtracted = (char *) malloc((strlen("partial_list_source_file_declaration_extracted.out") + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof (char));
    sprintf(partialListOfFileDeclarationExtracted, "%spartial_list_source_file_declaration_extracted.out", TXLTemporaryMultiFileFolder);
    if(file_exists(partialListOfFileDeclarationExtracted))
        createFile(partialListOfFileDeclarationExtracted);


    /* read list of all source files target*/
    ListOfString *listFilesExtracted = readListOfStringFromFile(fSoureFilesTargetFullPath);

    /* Create partial declaration list in case of stop running in the middle of process */
    ListOfString * listOfFilesDeclarationExtracted = readListOfStringFromFile(partialListOfFileDeclarationExtracted);

    int countFiles = 1;
    while(listFilesExtracted) {

        if(!searchStringInListOfStrings(listOfFilesDeclarationExtracted,listFilesExtracted->el)) {
            char * currentSourceFileDonorPath = NULL;
            currentSourceFileDonorPath = (char *) malloc(500 * sizeof(char));
            strtok(listFilesExtracted->el, "\n");

//            if(!strcmp(listFilesExtracted->el, "ex.c"))
 //               printf("Aqui");
            sprintf(currentSourceFileDonorPath,"%s%s", donorSourceFileFolder,  listFilesExtracted->el);

            char * currentSourceFileTempPath = NULL;
            currentSourceFileTempPath = (char *) malloc(500 * sizeof(char));
            sprintf(currentSourceFileTempPath,"%s%s", TXLTemporaryMultiFileFolder,  listFilesExtracted->el);

            ListOfString * ListOfSourceHeaderFilesNeeded = NULL;

            printf("\tFile[%d]: %s\n", countFiles, currentSourceFileDonorPath);
            char *outputHeaderFileList = (char *) malloc((strlen("temp_partial_list_header_file_dependencies.out") + strlen(TXLTemporaryMultiFileFolder) + 5) * sizeof (char));
            sprintf(outputHeaderFileList, "%stemp_partial_list_header_file_dependencies.out",
                    TXLTemporaryMultiFileFolder);

            ListOfSourceHeaderFilesNeeded = getListOfHeaderDependency(currentSourceFileDonorPath, outputHeaderFileList, donorSourceFileFolder);

            /* Format soure and headers files to needed function global declaration */
            ListOfString * ListOfSourceHeaderFilesNeededFormatted = NULL;
            while(ListOfSourceHeaderFilesNeeded) {
                char *currentHeaderFileFormatted = NULL;
                currentHeaderFileFormatted = (char *) malloc((strlen(ListOfSourceHeaderFilesNeeded->el) + 10) * sizeof(char));

                char * currentHeader = NULL;
                currentHeader = (char *) malloc(500 * sizeof(char));
                strcpy(currentHeader, ListOfSourceHeaderFilesNeeded->el);
                removeFirst( currentHeader, donorSourceFileFolder);
                fflush(stdout);
                sprintf(currentHeaderFileFormatted, "\"%s%s\"",TXLTemporaryMultiFileFolder, currentHeader);
                addNewString(&ListOfSourceHeaderFilesNeededFormatted, currentHeaderFileFormatted);

                char *formattedFileOutputPath = NULL;
                formattedFileOutputPath = (char *) malloc(
                        (strlen(currentHeader) + strlen(TXLTemporaryMultiFileFolder) + 1) * sizeof(char));
                sprintf(formattedFileOutputPath, "%s%s", TXLTemporaryMultiFileFolder, currentHeader);
                fflush(stdout);
                if (file_exists(formattedFileOutputPath)) {
                    char *hederTempDonorFolder = (char *) malloc(500 * sizeof(char));
                    sprintf(hederTempDonorFolder, "%s%s", tempDonorSourceFileFolder, currentHeader);
                    char *commandCopySourceFiles = (char *) malloc(5000 * sizeof(char));
                    sprintf(commandCopySourceFiles, "cp %s %s", hederTempDonorFolder, formattedFileOutputPath);
                    int statusCommand = system(commandCopySourceFiles);
                    if(statusCommand != 0) {
                        printf("Erro: Trying copy header file: %s", hederTempDonorFolder);
                        exit(1);
                    }
                    addAStringsInTheEndFileLN(currentHeader, tempAllHeaderFilesTargetPath);
                }
                fflush(stdout);
                ListOfSourceHeaderFilesNeeded = ListOfSourceHeaderFilesNeeded->next;
            }

            char *outputSourceHeaderFileList = (char *) malloc((strlen("temp_source_header_files_target.out") + strlen(TXLTemporaryMultiFileFolder) + 5) * sizeof (char));;
            sprintf(outputSourceHeaderFileList, "%stemp_source_header_files_target.out",
                    TXLTemporaryMultiFileFolder);
            addAStringsInTheFile(currentSourceFileTempPath, outputSourceHeaderFileList);
            addAListOfStringsInTheEndOfFileLN(ListOfSourceHeaderFilesNeededFormatted,outputSourceHeaderFileList);
            /* Extract and print needed global declaration in the current file */
            extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsFromOrgan(ListOfSourceHeaderFilesNeeded, currentSourceFileTempPath,
                                                                                ListOfNeededFunctionsForAllLOCs,
                                                                                ListOfFinalGlobalDeclarations,
                                                                                FinalGlobalDependencyList,
                                                                                SkeletonDependenciesOnGlobals,
                                                                                tempGlobalDeclarations,
                                                                                definedGlobalTypesAndVariablesFile,
                                                                                FinalSkeletonSourceCode,
                                                                                TheListOfTransplantedMarkers,
                                                                                outputFileGlobalDependenciesOnFunctions,
                                                                                TXLTemporaryFolderMainThread);

            addNewString(&listOfFilesDeclarationExtracted, listFilesExtracted->el);
            printAListOfStrings(listOfFilesDeclarationExtracted, partialListOfFileDeclarationExtracted);
            free(currentSourceFileDonorPath);
         ///   printf("\t-----------------------------------------------\n");
        }
        listFilesExtracted = listFilesExtracted->next;
        countFiles++;
    }

}


#endif