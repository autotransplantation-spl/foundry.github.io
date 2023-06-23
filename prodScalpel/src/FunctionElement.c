#include "FunctionElement.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenTrans.h"

void freeListOfFunctionElement(FunctionElement ** head) {
	FunctionElement * aux;
	while (*head) {
		aux = *head;
		*head = (*head)->next;
		freeListOfStrings(&(aux->LOCs));
		aux->LOCs = NULL;
		free(aux->NameOfFunction);
		aux->NameOfFunction = NULL;
		aux->next = NULL;
		free(aux);
		aux = NULL;
	}
	(*head) = NULL; //just in case...
}

FunctionElement * searchAnElement(FunctionElement * head, char * name) {
	FunctionElement * p;
	p = head;
	int s = 0;
	while (p && !s) {
		if (!strcmp(p->NameOfFunction, name)) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void addNewFunction(FunctionElement ** head, char * name) {
	FunctionElement * newEl = (FunctionElement *) malloc(
			1 * sizeof(FunctionElement));
	newEl->NameOfFunction = (char *) malloc((strlen(name) + 1) * sizeof(char));
	strcpy(newEl->NameOfFunction, name);
	newEl->LOCs = NULL;
	newEl->next = NULL;
	if (*head == NULL) {
		*head = newEl;
	} else {
		FunctionElement * p;
		p = *head;
		while (p->next) {
			p = p->next;
		}
		p->next = newEl;
	}
}

int addNewLOC(FunctionElement ** head, char * name, char * LOC) {
	FunctionElement * p;
	p = *head;
	int s = 0;
	while (p->next && s == 0) {
		if (!strcmp(name, p->NameOfFunction)) {
			s = 1;
		} else {
			p = p->next;
		}
	}
	if (!strcmp(p->NameOfFunction, name)) {
		s = 1;
	}
	if (s == 0) {
		return 0;
	} else {
		addNewString(&(p->LOCs), LOC);
		return 1;
	}
}

void fixCloseBracketsNoMarker(ListOfString ** head) {
	ListOfString * p;
	p = *head;
	int countOpen = 0;
	int countClose = 0;
	while (p) {
		char * findOpen = strstr(p->el, "{");
		if (findOpen) {
			countOpen++;
		}
		char * findClose = strstr(p->el, "}");
		if (findClose) {
			countClose++;
		}
		p = p->next;
	}

	int diff = countOpen - countClose;
	while (diff > 0) {
		addNewString(head, "}\n");
		diff--;
	}
}

void fixCloseBrackets(ListOfString ** head) {
	ListOfString * p;
	p = *head;
	int countOpen = 0;
	int countClose = 0;
	while (p) {
		char * findOpen = strstr(p->el, "{");
		if (findOpen) {
			countOpen++;
		}
		char * findClose = strstr(p->el, "}");
		if (findClose) {
			countClose++;
		}
		p = p->next;
	}

	int diff = countOpen - countClose;
	while (diff > 0) {
		addNewString(head, "/* COMPOUND_CLOSED */ }\n");
		diff--;
	}
}

void addNewFunctionElement(FunctionElement ** head,
		FunctionElement * newElement) {
	addNewFunction(head, newElement->NameOfFunction);

	(*head)->LOCs = copyListOfString(newElement->LOCs);
	fixCloseBracketsNoMarker(&(*head)->LOCs);
}

void printListOfFunctions(FILE * fout, FunctionElement * head) {
	FunctionElement * p;
	p = head;
	while (p) {
		ListOfString * aux;
		aux = p->LOCs;
		while (aux) {
			fprintf(fout, "%s", aux->el);
			aux = aux->next;
		}
		p = p->next;
	}
}

void printAFunctionElement(FILE * fout, FunctionElement * head) {
	ListOfString * aux;
	aux = head->LOCs;
	while (aux) {
		fprintf(fout, "%s", aux->el);
		aux = aux->next;
	}
}

void removeLOCsFromAListOfStringAfterCall(ListOfString ** head, char * nextFunction) {
	ListOfString * p;
	p = *head;
	int signal = 0;
	while (p->next && signal == 0) {
		char * marker;
		marker = (char *) malloc(400 * sizeof(char));
		char * calledFunctionName;
		calledFunctionName = (char *) malloc(400 * sizeof(char));
		sscanf(p->el, "%s %s", marker, calledFunctionName);
		if (!strcmp(marker, FUNCTION_CALL_MARKER) && !strcmp(calledFunctionName, nextFunction)) {
			//now check if it is the next function
			signal = 1;
		} else {

			p = p->next;
		}
		free(marker);
	}

	ListOfString * aux;
	aux = p->next;
	p->next = NULL;
	while (aux) {
		removeFirstEl(&aux);
	}
}

void removeLOCsAfterCallForAList(FunctionElement ** head,
		ListOfString * reverseCallGraph) {
	FunctionElement *p;
	p = *head;

	while (p) {

		char * currentFunctionName = p->NameOfFunction;
		ListOfString * reverseCallGraphAux = reverseCallGraph;

		char * calledFunction = (char *) malloc (1000 * sizeof(char));
		strcpy(calledFunction, GraftFunctionName);

		int found = 0;
		while (reverseCallGraphAux && !found) {
			if (!strcmp(reverseCallGraphAux->el, currentFunctionName)) {
				found = 1;
			}
			else{
				calledFunction = reverseCallGraphAux->el;
				reverseCallGraphAux = reverseCallGraphAux->next;
			}
		}

		if(!found){
			// Not found, so add a function name that do not exists
			calledFunction = (char *) malloc (1000 * sizeof(char));
			strcpy(calledFunction, "NON_EXISTENT_FUNCTION!!!");
		}

		//if (reverseCallGraphAux) {
			ListOfString * locsCurrent;
			locsCurrent = p->LOCs;
			removeLOCsFromAListOfStringAfterCall(&locsCurrent,calledFunction);
			fixCloseBrackets(&locsCurrent);
			p = p->next;
		//}
	}
}

FunctionElement * readFunctionElemenentListFromFile(char * inputFile,
		ListOfString * reverseCallGraph) {

	FILE * fin = fopen(inputFile, "r");

	char * line;
	line = (char *) malloc(800 * sizeof(char));
	FunctionElement * ListOfFunctions = NULL;
	char * currentName;
	currentName = (char*) malloc(800 * sizeof(char));
	while (fgets(line, 400, fin) != NULL) {
		char * newFunctionName;
		newFunctionName = (char *) malloc(400 * sizeof(char));
		sscanf(line, "%s", newFunctionName);
		strcpy(currentName, newFunctionName);
		addNewFunction(&ListOfFunctions, currentName);
		int s = 0;
		while (s == 0 && fgets(line, 400, fin) != NULL) {
			if (!strcmp(line, LINE_END)) {
				s = 1;
			} else {
				addNewLOC(&ListOfFunctions, currentName, line);
			}
		}
		free(newFunctionName);
	}
	// here we should remove just after a call to the next one
	removeLOCsAfterCallForAList(&ListOfFunctions, reverseCallGraph);
	free(line);
	free(currentName);
	fclose(fin);
	return ListOfFunctions;
}
