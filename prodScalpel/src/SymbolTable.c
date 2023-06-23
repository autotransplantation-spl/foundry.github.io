//
//  SymbolTable.c
//  ResearchProject
//
//  Created by Marginean ---andru on 01/03/14.
//  Copyright (c) 2014 Marginean ---andru. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SymbolTable.h"

void freeListOfIdOfVar(IdOfVariable ** head) {
	IdOfVariable * aux;
	while (*head) {
		aux = *head;
		*head = (*head)->next;
		free(aux->ID);
		aux->ID = NULL;
		aux->next = NULL;
		free(aux);
		aux = NULL;
	}
	(*head) = NULL; //just in case...
}

void freeListOfSymbolTable(SymbolTable ** head) {
	SymbolTable * aux;
	while (*head) {
		aux = *head;
		*head = (*head)->next;
		free(aux->TypeOfVar);
		freeListOfIdOfVar(&(aux->ListOfIdentifiers));
		aux->TypeOfVar = NULL;
		aux->ListOfIdentifiers = NULL;
		aux->next = NULL;
		free(aux);
		aux = NULL;
	}
	(*head) = NULL; //just in case...

}

void addNewID(IdOfVariable **head, char * idName) {
	IdOfVariable * newID;
	newID = (IdOfVariable *) malloc(sizeof(IdOfVariable));
	newID->ID = (char*) malloc((strlen(idName) + 1) * sizeof(char));
	strcpy(newID->ID, idName);

	if (*head == NULL) {
		newID->next = NULL;
	} else {
		newID->next = *head;
	}
	*head = newID;
}

void addNewVarType(SymbolTable **head, char* varTypeName) {
	SymbolTable * newSymbol;
	newSymbol = (SymbolTable *) malloc(sizeof(SymbolTable));

	newSymbol->TypeOfVar = (char*) malloc(
			(strlen(varTypeName) + 1) * sizeof(char));
	newSymbol->ListOfIdentifiers = NULL;
	strcpy(newSymbol->TypeOfVar, varTypeName);

	if (*head == NULL) {
		newSymbol->next = NULL;
	} else {
		newSymbol->next = *head;
	}

	*head = newSymbol;
}

void addNewVariableDeclaration(SymbolTable ** head, char * varType,
		char * varID) {
	SymbolTable * currentHead = *head;
	while (currentHead && strcmp(currentHead->TypeOfVar, varType)) {
		currentHead = currentHead->next;
	}
	if (currentHead == NULL) {
		addNewVarType(head, varType);
		addNewID(&(*head)->ListOfIdentifiers, varID);
	} else {
		addNewID(&currentHead->ListOfIdentifiers, varID);
	}
}

void printSymbolTable(SymbolTable * head, char * outputFile) {
	SymbolTable * aux = head;

	FILE * fout = fopen(outputFile, "w");

	while (aux) {
		IdOfVariable * auxIdList = aux->ListOfIdentifiers;
		while (auxIdList) {
			fprintf(fout, "%s %s \n", aux->TypeOfVar, auxIdList->ID);
			auxIdList = auxIdList->next;
		}
		aux = aux->next;
	}
	fclose(fout);
}

char * searchForASymbolTableEntry(SymbolTable * head, char * varID) {
	int signal = 0;
	SymbolTable * aux = head;
	while (aux && !signal) {
		IdOfVariable * auxIdList = aux->ListOfIdentifiers;
		while (auxIdList && !signal) {
			if (!strcmp(auxIdList->ID, varID)) {
				signal = 1;
			} else {
				auxIdList = auxIdList->next;
			}
		}
		if (!signal) {
			aux = aux->next;
		}
	}

	if (signal) {
		return aux->TypeOfVar;
	} else {
		return NULL;
	}
}

IdOfVariable * copyIdOfVar(IdOfVariable * head) {
	IdOfVariable * aux = head;
	IdOfVariable * newIdList = NULL;

	while (aux) {
		addNewID(&newIdList, aux->ID);
		aux = aux->next;
	}
	return newIdList;
}

SymbolTable * copySymbolTableList(SymbolTable * initial) {
	SymbolTable * newSymbolTable = NULL;
	addOneSymbolTableToTheOther(&newSymbolTable, initial);
	return newSymbolTable;
}

//read symbol table from a file, where it was genereted by the TXL program

SymbolTable * readSymbolTableAddedEntryPoint(char * HostSymbolTableFile,
		SymbolTable ** EntryPointSymbolTable) {
	SymbolTable * thisDeclaration = NULL;

    FILE * finHostSymbolTable = fopen(HostSymbolTableFile, "r");

	char * line;
	line = (char *) malloc(10000 * sizeof(char));
	//char * originalLine = line;

	char * initialLinePos; // hold the initial position of line, so we will reset it after each move
	initialLinePos = line;

	while ((fgets(line, 1000, finHostSymbolTable) != NULL)
			&& (strcmp(line, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"))) {

		char * typeOfNewDecl = (char *) malloc(2000 * sizeof(char));
		char * idOfNewDecl = (char *) malloc(2000 * sizeof(char));
		strcpy(typeOfNewDecl, "");
		strcpy(idOfNewDecl, "");

		char * previous = (char *) malloc(2000 * sizeof(char));
		char * current = (char *) malloc(2000 * sizeof(char));
		sscanf(line, "%s", previous);

		//avoid spaces
		line += (strlen(previous) + 1);

		int signal = 0;

		while ((sscanf(line, "%s", current) == 1) && (!signal)) {

			if (current[0] == '['
					&& ((current[strlen(current) - 1] == ']')
							|| ((current[strlen(current) - 2] == ']')
									&& (current[strlen(current) - 1] == ';')))) {
				signal = 1;
				//previous is the id of variable!
				while (previous[0] == '*') {
					strcat(typeOfNewDecl, "*");
					previous++;
				}
				strcat(idOfNewDecl, previous);

				line += (strlen(current) + 1);
				strcpy(previous, current);

				while (sscanf(line, "%s", current) == 1) {
					//strcat(typeOfNewDecl, " ");
					strcat(typeOfNewDecl, previous);

					line += (strlen(current) + 1);
				}

				//remove last ;
				if (previous[strlen(previous) - 1] == ';') {
					previous[strlen(previous) - 1] = '\0';
				}
				//strcat(typeOfNewDecl, " ");
				strcat(typeOfNewDecl, previous);

			} else {
				//check for not being at the beginning of the type string, since
				//then it shouldn't be added the space
				if (strcmp(typeOfNewDecl, "")) {
					strcat(typeOfNewDecl, " ");
				}
				strcat(typeOfNewDecl, previous);

				strcpy(previous, current);
				//avoid spaces
				line += (strlen(current) + 1);
			}

		}

		if (!signal) {
			while (previous[0] == '*') {
				strcat(typeOfNewDecl, "*");
				previous++;
			}
			if (previous[strlen(previous) - 1] == ';') {

				previous[strlen(previous) - 1] = '\0';
			}
			strcat(idOfNewDecl, previous);
		}

		addNewVariableDeclaration(&thisDeclaration, typeOfNewDecl, idOfNewDecl);

		line = initialLinePos;

	}

	while (fgets(line, 1000, finHostSymbolTable) != NULL) {

		char * typeOfNewDecl = (char *) malloc(2000 * sizeof(char));
		char * idOfNewDecl = (char *) malloc(2000 * sizeof(char));
		strcpy(typeOfNewDecl, "");
		strcpy(idOfNewDecl, "");

		char * previous = (char *) malloc(2000 * sizeof(char));
		char * current = (char *) malloc(2000 * sizeof(char));
		sscanf(line, "%s", previous);

		//avoid spaces
		line += (strlen(previous) + 1);

		int signal = 0;

		while ((sscanf(line, "%s", current) == 1) && (!signal)) {

			if (current[0] == '['
					&& ((current[strlen(current) - 1] == ']')
							|| ((current[strlen(current) - 2] == ']')
									&& (current[strlen(current) - 1] == ';')))) {
				signal = 1;
				//previous is the id of variable!
				while (previous[0] == '*') {
					strcat(typeOfNewDecl, "*");
					previous++;
				}
				strcat(idOfNewDecl, previous);

				line += (strlen(current) + 1);
				strcpy(previous, current);

				while (sscanf(line, "%s", current) == 1) {
					//strcat(typeOfNewDecl, " ");
					strcat(typeOfNewDecl, previous);

					line += (strlen(current) + 1);
				}

				//remove last ;
				if (previous[strlen(previous) - 1] == ';') {
					previous[strlen(previous) - 1] = '\0';
				}
				//strcat(typeOfNewDecl, " ");
				strcat(typeOfNewDecl, previous);

			} else {
				//check for not being at the beginning of the type string, since
				//then it shouldn't be added the space
				if (strcmp(typeOfNewDecl, "")) {
					strcat(typeOfNewDecl, " ");
				}
				strcat(typeOfNewDecl, previous);

				strcpy(previous, current);
				//avoid spaces
				line += (strlen(current) + 1);
			}

		}

		if (!signal) {
			while (previous[0] == '*') {
				strcat(typeOfNewDecl, "*");
				previous++;
			}
			if (previous[strlen(previous) - 1] == ';') {

				previous[strlen(previous) - 1] = '\0';
			}
			strcat(idOfNewDecl, previous);
		}

		addNewVariableDeclaration(&(*EntryPointSymbolTable), typeOfNewDecl,
				idOfNewDecl);

	}
	fclose(finHostSymbolTable);
	return thisDeclaration;
}

//read symbol table from a file, where it was genereted by the TXL program

SymbolTable * readSymbolTable(FILE *fin) {
	SymbolTable * thisDeclaration = NULL;

	//char * varName;
	//char * additionalForArrays, varType [200];
	//varName = (char*) malloc(300 * sizeof (char));
	//char * auxVarName;
	//auxVarName = varName;
	//additionalForArrays = (char*) malloc(300 * sizeof (char));
	//int expectedValue = 0;

	//because of the arrays it is possible for a variable declaration to have 3 terms: int x [100]
	//because of this I've read the terms 1 by 1 and then I've done the necesary modifications
	//so the resulted type will be int[100], and the name will be x

	//two cases: with array at the end, or not!!!

	char * line;
	line = (char *) malloc(1000 * sizeof(char));
	//char * originalLine = line;

	char * typeOfNewDecl = (char *) malloc(500 * sizeof(char));

	char * idOfNewDecl = (char *) malloc(500 * sizeof(char));

	while (fgets(line, 1000, fin) != NULL) {

		strcpy(typeOfNewDecl, "");
		strcpy(idOfNewDecl, "");

		char * previous = (char *) malloc(500 * sizeof(char));
		char * current = (char *) malloc(500 * sizeof(char));
		sscanf(line, "%s", previous);

		//avoid spaces
		line += (strlen(previous) + 1);

		int signal = 0;

		while ((sscanf(line, "%s", current) == 1) && (!signal)) {

			if (current[0] == '['
					&& ((current[strlen(current) - 1] == ']')
							|| ((current[strlen(current) - 2] == ']')
									&& (current[strlen(current) - 1] == ';')))) {
				signal = 1;
				//previous is the id of variable!
				while (previous[0] == '*') {
					strcat(typeOfNewDecl, "*");
					previous++;
				}
				strcat(idOfNewDecl, previous);

				line += (strlen(current) + 1);
				strcpy(previous, current);

				while (sscanf(line, "%s", current) == 1) {
					//strcat(typeOfNewDecl, " ");
					strcat(typeOfNewDecl, previous);

					line += (strlen(current) + 1);
				}

				//remove last ;
				if (previous[strlen(previous) - 1] == ';') {
					previous[strlen(previous) - 1] = '\0';
				}
				//strcat(typeOfNewDecl, " ");
				strcat(typeOfNewDecl, previous);

			} else {
				//check for not being at the beginning of the type string, since
				//then it shouldn't be added the space
				if (strcmp(typeOfNewDecl, "")) {
					strcat(typeOfNewDecl, " ");
				}
				strcat(typeOfNewDecl, previous);

				strcpy(previous, current);
				//avoid spaces
				line += (strlen(current) + 1);
			}

		}

		if (!signal) {
			while (previous[0] == '*') {
				strcat(typeOfNewDecl, "*");
				previous++;
			}
			if (previous[strlen(previous) - 1] == ';') {

				previous[strlen(previous) - 1] = '\0';
			}
			strcat(idOfNewDecl, previous);
		}

		addNewVariableDeclaration(&thisDeclaration, typeOfNewDecl, idOfNewDecl);

	}

	//old version

	/*

	 if (fscanf(fin, "%s %s", varType, varName) != 2) {
	 return NULL;
	 }
	 //fscanf(fin, "%s %s", varType, varName);
	 while (fscanf(fin, "%s", additionalForArrays) != EOF) {
	 if (expectedValue == 0) {
	 if (additionalForArrays[0] == '[' && additionalForArrays[strlen(additionalForArrays) - 1] == ';') {
	 unsigned long lengthAdd = strlen(varType);
	 varType[lengthAdd] = '[';
	 varType[lengthAdd + 1] = ']';
	 varType[lengthAdd + 2] = 0;
	 } else {
	 while (varName[0] == '*') {
	 int length = (int) strlen(varType);
	 varType[length] = '*';
	 varType[length + 1] = 0;

	 varName = varName + 1;
	 }
	 varName[strlen(varName) - 1] = 0;
	 addNewVariableDeclaration(&thisDeclaration, varType, varName);
	 expectedValue = 1;
	 strcpy(varType, additionalForArrays);
	 }
	 } else {
	 strcpy(varName, additionalForArrays);
	 expectedValue = 0;
	 }
	 }
	 while (varName[0] == '*') {
	 int length = (int) strlen(varType);
	 varType[length] = '*';
	 varType[length + 1] = 0;


	 varName = varName + 1;
	 }
	 varName[strlen(varName) - 1] = 0;
	 addNewVariableDeclaration(&thisDeclaration, varType, varName);
	 expectedValue = 1;
	 strcpy(varType, additionalForArrays);
	 */

	//free(auxVarName);
	//free(additionalForArrays);
	return thisDeclaration;
}

















SymbolTable * readSymbolTableForHost(FILE *fin) {
	SymbolTable * thisDeclaration = NULL;

	//because of the arrays it is possible for a variable declaration to have 3 terms: int x [100]
	//because of this I've read the terms 1 by 1 and then I've done the necesary modifications
	//so the resulted type will be int[100], and the name will be x

	//two cases: with array at the end, or not!!!

	char * line;
	line = (char *) malloc(1000 * sizeof(char));
	//char * originalLine = line;

	char * typeOfNewDecl = (char *) malloc(500 * sizeof(char));

	char * idOfNewDecl = (char *) malloc(500 * sizeof(char));

	while (fgets(line, 1000, fin) != NULL) {

		strcpy(typeOfNewDecl, "");
		strcpy(idOfNewDecl, "");

		char * previous = (char *) malloc(500 * sizeof(char));
		char * current = (char *) malloc(500 * sizeof(char));
		sscanf(line, "%s", previous);

		//avoid spaces
		line += (strlen(previous) + 1);

		int signal = 0;
        int function_pointer = 0;

		while ((sscanf(line, "%s", current) == 1) && (!signal)) {

		    if(strchr(current,'(') && strchr(current,')') && strchr(current,'*'))
		        function_pointer = 1;

			if (current[0] == '['
					&& ((current[strlen(current) - 1] == ']')
							|| ((current[strlen(current) - 2] == ']')
									&& (current[strlen(current) - 1] == ';')))) {
				signal = 1;
				//previous is the id of variable!
				while (previous[0] == '*') {
					strcat(typeOfNewDecl, "*");
					previous++;
				}
				strcat(idOfNewDecl, previous);

				line += (strlen(current) + 1);
				strcpy(previous, current);

				while (sscanf(line, "%s", current) == 1) {
					//strcat(typeOfNewDecl, " ");
					strcat(typeOfNewDecl, previous);

					line += (strlen(current) + 1);
				}

				//remove last ;
				if (previous[strlen(previous) - 1] == ';') {
					previous[strlen(previous) - 1] = '\0';
				}
				//strcat(typeOfNewDecl, " ");
				strcat(typeOfNewDecl, previous);

			} else {
				//check for not being at the beginning of the type string, since
				//then it shouldn't be added the space
				if (strcmp(typeOfNewDecl, "")) {
					strcat(typeOfNewDecl, " ");
				}
				strcat(typeOfNewDecl, previous);

				strcpy(previous, current);


                strcpy(previous, current);
				//avoid spaces
				line += (strlen(current) + 1);
			}

		}

		if (!signal) {
			while (previous[0] == '*') {
				strcat(typeOfNewDecl, "*");
				previous++;
			}
			if (previous[strlen(previous) - 1] == ';') {

				previous[strlen(previous) - 1] = '\0';
			}
			strcat(idOfNewDecl, previous);
		}


		char * hostIdOfNewDeclaration = (char *) malloc (2000*sizeof(char));
		if(!function_pointer) // concat host_mark if it is no a function pointer
		    sprintf(hostIdOfNewDeclaration, "$_host_%s", idOfNewDecl);
        else
            strcpy(hostIdOfNewDeclaration, idOfNewDecl);

		addNewVariableDeclaration(&thisDeclaration, typeOfNewDecl, hostIdOfNewDeclaration);

	}

	//old version

	/*

	 if (fscanf(fin, "%s %s", varType, varName) != 2) {
	 return NULL;
	 }
	 //fscanf(fin, "%s %s", varType, varName);
	 while (fscanf(fin, "%s", additionalForArrays) != EOF) {
	 if (expectedValue == 0) {
	 if (additionalForArrays[0] == '[' && additionalForArrays[strlen(additionalForArrays) - 1] == ';') {
	 unsigned long lengthAdd = strlen(varType);
	 varType[lengthAdd] = '[';
	 varType[lengthAdd + 1] = ']';
	 varType[lengthAdd + 2] = 0;
	 } else {
	 while (varName[0] == '*') {
	 int length = (int) strlen(varType);
	 varType[length] = '*';
	 varType[length + 1] = 0;

	 varName = varName + 1;
	 }
	 varName[strlen(varName) - 1] = 0;
	 addNewVariableDeclaration(&thisDeclaration, varType, varName);
	 expectedValue = 1;
	 strcpy(varType, additionalForArrays);
	 }
	 } else {
	 strcpy(varName, additionalForArrays);
	 expectedValue = 0;
	 }
	 }
	 while (varName[0] == '*') {
	 int length = (int) strlen(varType);
	 varType[length] = '*';
	 varType[length + 1] = 0;


	 varName = varName + 1;
	 }
	 varName[strlen(varName) - 1] = 0;
	 addNewVariableDeclaration(&thisDeclaration, varType, varName);
	 expectedValue = 1;
	 strcpy(varType, additionalForArrays);
	 */

	//free(auxVarName);
	//free(additionalForArrays);
	return thisDeclaration;
}








int countIDsInSymbolTable(SymbolTable * head) {
	SymbolTable * aux = head;

	int countIDs = 0;

	while (aux) {
		IdOfVariable * auxIDsVar = aux->ListOfIdentifiers;
		while (auxIDsVar) {
			countIDs++;
			auxIDsVar = auxIDsVar->next;
		}
		aux = aux->next;
	}

	return countIDs;
}

void addOneSymbolTableToTheOther(SymbolTable ** destination,
		SymbolTable * source) {
	while (source) {

		IdOfVariable * auxIdVars = source->ListOfIdentifiers;

		while (auxIdVars) {
			addNewVariableDeclaration(&(*destination), source->TypeOfVar,
					auxIdVars->ID);
			auxIdVars = auxIdVars->next;
		}

		source = source->next;
	}
}

void freeSymbolTableMemory() {
	//TO BE DONE
}

int removeSymbolTable(SymbolTable ** head, char * TypeOfVar, IdOfVariable * ListOfIdentifiers) {

   //TO BE DONE
}