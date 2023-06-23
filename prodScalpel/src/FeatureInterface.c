#include "GenTrans.h"
#include "SymbolTable.h"
#include "ListOfString.h"
#include "IndividualInstantiator.h"

#include <stdio.h>
//#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "Utils.h"
#include <errno.h>


void symbolTableToArgDecls(SymbolTable * head, char * outputFileName) {
    FILE * fout = fopen(outputFileName, "w");
    SymbolTable * p;
    p = head;
    if(!p){
        return;
    }
    while (p->next) {
        char * arrayMarker;
        arrayMarker = (char *) malloc(5 * sizeof (char));
        strcpy(arrayMarker, "");
        char * fixedVarType;
        fixedVarType = (char *) malloc(300 * sizeof (char));
        strcpy(fixedVarType, p->TypeOfVar);
        if ((p->TypeOfVar)[strlen(p->TypeOfVar) - 1] == ']') {
        	char * posStartArray = strstr(fixedVarType, "[");
        	posStartArray[0] = 0;
            //fixedVarType [strlen(fixedVarType) - 2] = 0;
            strcpy(arrayMarker, " []");
        }
        IdOfVariable * aux = p->ListOfIdentifiers;
        while (aux) {
            fprintf(fout, "%s %s%s , ", fixedVarType, aux->ID, arrayMarker);
            aux = aux->next;
        }
        p = p->next;
        free(fixedVarType);
        free(arrayMarker);
    }
    if (p) {
        char * arrayMarker;
        arrayMarker = (char *) malloc(5 * sizeof (char));
        strcpy(arrayMarker, "");
        char * fixedVarType;
        fixedVarType = (char *) malloc(300 * sizeof (char));
        strcpy(fixedVarType, p->TypeOfVar);
        if ((p->TypeOfVar)[strlen(p->TypeOfVar) - 1] == ']') {
        	while(fixedVarType[strlen(fixedVarType) - 1] != '['){
        		fixedVarType[strlen(fixedVarType) -1] = 0;
        	}
            fixedVarType [strlen(fixedVarType) - 1] = 0;
            strcpy(arrayMarker, " []");
        }
        IdOfVariable * aux = p->ListOfIdentifiers;
        while (aux->next) {
            fprintf(fout, "%s %s%s , ", fixedVarType, aux->ID, arrayMarker);
            aux = aux->next;
        }
        fprintf(fout, "%s %s%s", fixedVarType, aux->ID, arrayMarker);
        p = p->next;
        free(fixedVarType);
        free(arrayMarker);
    }
    fclose(fout);
}

extern int errno ;

void generateInterfaceDefinition(char * TXLPath, char * theGraftFctName, char * graftFile, char * interfaceName, 
        char * newVariableName, char * argumentsFilePath, char * outputFilePath, char * interfaceHeaderFile, 
        char * JustInterfaceFileName, char * hostFileSourceFile) {
    char * command;
    command = (char *) malloc(1000 * sizeof (char));

    sprintf(command, "%screateInterface.x", TXLPath);
    char * commandTXL;
    commandTXL = (char *) malloc(5000 * sizeof (char));
//TODO rewrite
    if (strcmp(TXLToolsPath, "./")) {
        IfDefProgramPath = (char *) malloc((strlen(TXLToolsPath) + 10) * sizeof (char));
        sprintf(IfDefProgramPath, "%sifdef.x", TXLToolsPath);
    } else {
        IfDefProgramPath = (char *) malloc(10 * sizeof (char));
        sprintf(IfDefProgramPath, "./ifdef.x");
    }

    printf("[TXL] createInterface.x >> Create Interface\n");
    sprintf(commandTXL, "%s %s %s %s %s %s %s %s %s %s %s %s %s", command, transplantHostInputFile /*any syntax correct c program*/,
            graftFile, theGraftFctName, interfaceName,
            newVariableName, argumentsFilePath, outputFilePath, interfaceHeaderFile, JustInterfaceFileName,
            hostFileSourceFile, IfDefProgramPath, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR generateInterfaceDefinition!\n");
        printf("\t%s\n", commandTXL);
        system("open ErrorFile.out");
        exit(1);
    }
    free(command);
    free(commandTXL);
}



void extractHostIncludes(char * TXLProgsPath, char * source, char * destination) {
    char * commandTXL;
    commandTXL = (char *) malloc(500 * sizeof (char));
    printf("[TXL] ExtractHostIncludes.x >> Extract Host Includes\n");
    sprintf(commandTXL, "%sextractHostIncludes.x %s %s %s", TXLProgsPath, source, destination,
            ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR extract host includes!");
        printf("\t%s\n", commandTXL);
        fflush(stdout);
        exit(1);}
    free(commandTXL);
}

void generateNewDonorAndInterface(char * TXLPath, char * hostTargetPlaceFile, char * tempInterfaceDecl,
        char * outputFileName, char * newInterfaceFileName, char * interfaceHeaderFile) {

    char * command;
    command = (char *) malloc(400 * sizeof (char));
    sprintf(command, "%saddInterfaceToHost.x", TXLPath);

    char * commandTXL;
    commandTXL = (char *) malloc(2000 * sizeof (char));
    printf("[TXL] addInterfaceToHost.x >> Add Interface To Host\n");
    sprintf(commandTXL, "%s %s %s %s %s %s %s", command, hostTargetPlaceFile, tempInterfaceDecl,
            outputFileName, newInterfaceFileName, interfaceHeaderFile, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! generateNewDonorAndInterface\n");
        system("open ErrorFile.out");
        exit(1);
    }
    free(command);
    free(commandTXL);
}

/* Fix static and void interface declaration */
void fixOutputDeclOfInterface(char * tempInterfaceDecl, char * interfaceName, char * newVariableName){
    /* Replace interface declaration from static functions in temp_decl_from_interface.out */
    ListOfString * declFromInterface = NULL;
    declFromInterface = readListOfStringFromFile(tempInterfaceDecl);
    ListOfString * auxDeclFromInterface = copyCompleteListOfString(declFromInterface);
    char * formattedLine  = (char *) malloc(500 * sizeof (char));
    char * currentLine  = (char *) malloc(500 * sizeof (char));
    char * newInterfaceCall  = (char *) malloc(500 * sizeof (char));
    int signal_void = 0;
    while(auxDeclFromInterface->next!=NULL) {
        fflush(stdout);
        strcpy(currentLine, auxDeclFromInterface->el);
        if (strstr(currentLine, "static") && (strstr(currentLine, interfaceName)))
            auxDeclFromInterface->el = replace_str(currentLine, "static", "");
        //LOSCHANGE 5.23 TODO test
        if (strstr(auxDeclFromInterface->el, "void")
            && strstr(auxDeclFromInterface->el, newVariableName)) {
            removeString(&declFromInterface, currentLine);
            signal_void = 1;
        }
        if(signal_void == 1 && strstr(auxDeclFromInterface->el, "GRAFT_INTERFACE")) {
            strcpy(newInterfaceCall, readSubstring("=", auxDeclFromInterface->el,";"));
            strcat(newInterfaceCall, ";\n");
            replaceOneLineInALIst(&declFromInterface, newInterfaceCall, newInterfaceCall);
            signal_void = 0;
        }


       // printAListOfStrings(declFromInterface,tempInterfaceDecl );
/*
        if (strstr(auxDeclFromInterface->el, interfaceName) &&  strstr(auxDeclFromInterface->el, newVariableName)) {
            sprintf(formattedLine, "%s%s", newVariableName, " = ");
            auxDeclFromInterface->el = replace_str(auxDeclFromInterface->el, auxDeclFromInterface->el,
                                                   readSubstring(formattedLine, auxDeclFromInterface->el, ";"));
        }*/
        auxDeclFromInterface = auxDeclFromInterface->next;
    }

    printAListOfStrings(declFromInterface,tempInterfaceDecl );
    declFromInterface = readListOfStringFromFile(tempInterfaceDecl);
    auxDeclFromInterface = declFromInterface;
    char * newLine  = NULL;
    while(auxDeclFromInterface){
        fflush(stdout);
        strcpy(currentLine, auxDeclFromInterface->el);
        if (strstr(currentLine, "static") && (strstr(currentLine, newVariableName)))
            auxDeclFromInterface->el = replace_str(currentLine, "static", "");

     /*   if (strstr(auxDeclFromInterface->el, interfaceName) &&  strstr(auxDeclFromInterface->el, newVariableName)) {
            sprintf(formattedLine, "%s%s", newVariableName, " = ");
            newLine = replace_str(auxDeclFromInterface->el, auxDeclFromInterface->el,
                                  readSubstring(formattedLine, auxDeclFromInterface->el, "\n"));
            sprintf(auxDeclFromInterface->el, "\t%s\n", newLine);

        }*/ //LOSCHANGE23 commented
        auxDeclFromInterface = auxDeclFromInterface->next;
    }

    printAListOfStrings(declFromInterface,tempInterfaceDecl );
    freeListOfStrings(&declFromInterface);
    freeListOfStrings(&auxDeclFromInterface);
    free(formattedLine);
    free(currentLine);
}

/* Fix static interface definition */
void fixOutputInterfaceForIndividual(char * interfaceHeaderFile, char * interfaceName){
    /* Replace interface for individual instantiation from temp_interface_for_idividual_instantiation.out */
    ListOfString * interfaceForIndividualDefinition = readListOfStringFromFile(interfaceHeaderFile);
    ListOfString * auxInterfaceForIndividualDefinition = interfaceForIndividualDefinition;
    while(auxInterfaceForIndividualDefinition){
        if (strstr(auxInterfaceForIndividualDefinition->el, "static")
            && strstr(auxInterfaceForIndividualDefinition->el, interfaceName))
            auxInterfaceForIndividualDefinition->el = replace_str(auxInterfaceForIndividualDefinition->el, "static", "");

        auxInterfaceForIndividualDefinition = auxInterfaceForIndividualDefinition->next;
    }
    printAListOfStrings(interfaceForIndividualDefinition,interfaceHeaderFile );
    freeListOfStrings(&interfaceForIndividualDefinition);
    freeListOfStrings(&auxInterfaceForIndividualDefinition);
}

void generateHostInterface(SymbolTable * head, char * tempFilesPath,
        char * TXLPath, char * graftFile, char * outputFileName,
        char * interfaceHeaderFile, char * hostTargetPlaceFile, char * newInterfaceFileName, 
        char * justInterfaceFileName, char * theGraftFunctionName) {

    /* Set InterfaceName defines GRAFT_INTERFACE as the name of coreFunction+_GRAFT_INTERFACE */
    char *interfaceName;
    interfaceName = (char *) malloc(500 * sizeof(char));
    sprintf(interfaceName, "%s_GRAFT_INTERFACE", theGraftFunctionName);

    /* NewVariableName defines TRANSPLANT_RESULT as the name of coreFunction+_RESULT */
    char *newVariableName;
    newVariableName = (char *) malloc(500 * sizeof(char));
    sprintf(newVariableName, "%s_TRANSPLANT_RESULT", theGraftFunctionName);
    fflush(stdout);

    char * argumentsFileOutput;
    argumentsFileOutput = (char *) malloc(500 * sizeof (char));
    strcpy(argumentsFileOutput, tempFilesPath);
    strcat(argumentsFileOutput, "temp_argTable.out");
    char * tempInterfaceDecl;
    tempInterfaceDecl = (char *) malloc(500 * sizeof (char));
    strcpy(tempInterfaceDecl, tempFilesPath);
    strcat(tempInterfaceDecl, "temp_decl_from_interface.out");
    symbolTableToArgDecls(head, argumentsFileOutput);
    generateInterfaceDefinition(TXLPath, theGraftFunctionName, graftFile, interfaceName, newVariableName,
            argumentsFileOutput, tempInterfaceDecl, interfaceHeaderFile, justInterfaceFileName, hostTargetPlaceFile);

    /* Replace interface declaration from static functions in temp_decl_from_interface.out */
    fixOutputDeclOfInterface(tempInterfaceDecl, interfaceName, newVariableName);

    /* Replace interface for individual instantiation from temp_interface_for_idividual_instantiation.out */
    fixOutputInterfaceForIndividual(interfaceHeaderFile, interfaceName);

    generateNewDonorAndInterface(TXLPath, hostTargetPlaceFile, tempInterfaceDecl, outputFileName,
            newInterfaceFileName, interfaceHeaderFile);
    free(argumentsFileOutput);
    free(tempInterfaceDecl);
    free(interfaceName);
}
