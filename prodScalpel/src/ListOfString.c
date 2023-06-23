#include "ListOfString.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void addIDs(ListOfIdsForGrobalDeclaration ** head, char * oldId, char * newId) {
    ListOfIdsForGrobalDeclaration * newEl = (ListOfIdsForGrobalDeclaration *) malloc(1 * sizeof (ListOfIdsForGrobalDeclaration));
    newEl->oldId = (char *) malloc((strlen(oldId) + 1) * sizeof (char *));
    newEl->newId = (char *) malloc((strlen(newId) + 1) * sizeof (char *));
    strcpy(newEl->oldId, oldId);
    strcpy(newEl->newId, newId);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfIdsForGrobalDeclaration * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}


void freeListOfStrings(ListOfString ** head) {
    ListOfString * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        fflush(stdout);
        aux->el = NULL;
        aux->next = NULL;
        //if(* head)
            free(aux->el);


        free(aux);
        aux = NULL;

    }
    (* head) = NULL; //just in case...
}

void addNewStringInTheBegging(ListOfString ** head, char * string) {
    ListOfString * newEl = (ListOfString *) malloc(1 * sizeof (ListOfString));
    newEl->el = (char *) malloc((strlen(string) + 2) * sizeof (char *));
    strcpy(newEl->el, string);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfString * p;
        p = *head;
        newEl->next = p;
        * head = newEl;
    }

}

void addNewString(ListOfString ** head, char * string) {
    ListOfString * newEl = (ListOfString *) malloc(1 * sizeof (ListOfString));
    newEl->el = (char *) malloc((strlen(string) + 2) * sizeof (char *));
    strcpy(newEl->el, string);
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


void addNewGlobalDeclarationType(ListGlobalTypeVarDeclaration ** head, char * declID, char * declaration) {
    ListGlobalTypeVarDeclaration * newEl = (ListGlobalTypeVarDeclaration *) malloc(1 * sizeof (ListGlobalTypeVarDeclaration));
    newEl->declaredTypeID = (char *) malloc((strlen(declID) + 1) * sizeof (char *));
    newEl->declaredType = (char *) malloc((strlen(declaration) + 1) * sizeof (char *));
    strcpy(newEl->declaredTypeID, declID);
    strcpy(newEl->declaredType, declaration);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListGlobalTypeVarDeclaration * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int comparTwoListOfString(ListOfString * head1, ListOfString * head2) {

    int result = 1;

    while(head1 && head2){
        if(!strcmp(head1,head2))
            result = 0;

            head1 = head1->next;
            head2 = head2->next;
    }

    return result;
}

ListOfString * copyListOfString(ListOfString * head) {
    ListOfString * newHead = NULL;
    ListOfString * pHead = NULL;
    pHead = head;
    if (head == NULL) {
        return NULL;
    }
    //the last element is the bracket from function call
    while (pHead -> next) {
        addNewString(&newHead, pHead->el);
        pHead = pHead->next;
    }
    return newHead;
}

ListOfString * copyCompleteListOfString(ListOfString * head) {
    ListOfString * newHead = NULL;
    ListOfString * pHead = NULL;
    pHead = head;
    if (head == NULL) {
        return NULL;
    }
    while (pHead) {
        addNewString(&newHead, pHead->el);
        pHead = pHead->next;
    }
    return newHead;
}

ListOfString * copyListOfStringNoLastElement(ListOfString * head) {
    ListOfString * newHead = NULL;
    ListOfString * pHead = NULL;
    pHead = head;
    //the last element is the bracket from function call
    if (pHead->next) {
        while (pHead -> next -> next) {
            addNewString(&newHead, pHead->el);
            pHead = pHead->next;
        }
    }
    return newHead;
}

void removeFirstEl(ListOfString **head) {
    if (!(*head)) {
        return;
    } else if (!(*head)->next) {
        free((*head)->el);
        free(*head);
        (*head) = NULL;
    } else {
        ListOfString * aux;
        aux = *head;
        (*head) = (*head)->next;
        free(aux->el);
        free(aux);
        aux = NULL;
    }
}

void removeLastString(ListOfString ** head) {
    ListOfString * p;
    p = *head;
    if (!p) {
        return;
    }
    if (!p->next) {
        free(p->el);
        free(p);
        p = NULL;
        *head = NULL;
    }
    while (p->next->next) {
        p = p->next;
    }
    free(p->next->el);
    free(p->next);
    p->next = NULL;
}

void removeCharactersBefore(char** str, char c) {
    char* p = strchr(*str, c);  // Find first occurrence of c in str
    if (p != NULL) {
        memmove(*str, p, strlen(p) + 1);  // Move remainder of string forward
    } else {
        **str = '\0';  // Character not found, return empty string
    }
}

int removeString(ListOfString ** head, char * string) {
    ListOfString * p;
    p = *head;
    int s = 0;
    if (!strcmp(p->el, string)) {
        *head = p->next;
        free(p->el);
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if (!strcmp(p->next->el, string)) {
                ListOfString * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                free(aux->el);
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

/*
int removeString(ListOfString** head, char* string) {
    ListOfString* current = *head;
    ListOfString* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->el, string) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->el);
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}*/
int removeStringLabels(ListOfString ** head, char * string) {
    ListOfString * p;
    p = *head;
    int s = 0;

    //char * fixedElement = (char *) malloc (strlen(p->el) * sizeof(char));

    //strcpy(fixedElement, p->el + 1);
    //fixedElement[strlen(fixedElement) - 2 ] = 0;

    if (strstr(string,  p->el)) {
        *head = p->next;
        free(p->el);
       	free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
        	//fixedElement = (char *) malloc (strlen(p->next->el) * sizeof(char));
        	//strcpy(fixedElement, p->next->el + 1);
        	//fixedElement[strlen(fixedElement) - 2 ] = 0;
            if (strstr(string, p->next->el)) {
                ListOfString * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                free(aux->el);
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

void replaceOneLineInALIst(ListOfString ** head, char * line , char * newLine) {
    ListOfString * aux = (*head);
    char *currentLine = (char *) malloc(500 * sizeof(char));
    while (aux) {
        fflush(stdout);
        if(aux->el && strcmp(aux->el,"") ) {
           strcpy(currentLine, aux->el);
            if (strstr(aux->el, line)) {
                strcpy(aux->el, newLine);
            }
        }
        aux = aux->next;
        fflush(stdout);
    }

}


void replaceOneLineWithAListKeepPenultimate(ListOfString ** head, ListOfString * newList, char * line) {
    ListOfString * newCopy;
    newCopy = copyListOfString(newList);
    if (!strcmp((*head)->el, line)) {
        ListOfString * aux;
        aux = *head;
        ListOfString * aux2;
        aux2 = newCopy;
        while (aux2->next) {
            aux2 = aux2->next;
        }
        aux2->next = (*head)->next;
        (*head) = newCopy;
        free(aux->el);
        free(aux);
        aux = NULL;
    } else {
        ListOfString * p;
        p = *head;
        int s = 0;
        while (p->next && !s) {
            if (!strcmp(p->next->el, line)) {
                s = 1;
            } else {
                p = p->next;
            }
        }
        if (!s) {
            return;
        } else {
            ListOfString * aux;
            aux = p->next;

            ListOfString * aux2;
            aux2 = newCopy;
            if (aux2) {
                while (aux2->next) {
                    aux2 = aux2->next;
                }
                aux2->next = p->next->next;
                p->next = newCopy;
                free(aux->el);
                free(aux);
                aux = NULL;
            } else {
                ListOfString * auxRemoveString = p->next;
                p->next = p->next->next;
                free(auxRemoveString->el);
                free(auxRemoveString);
            }

        }
    }
}

void replaceOneLineWithAList(ListOfString ** head, ListOfString * newList, char * line) {
    ListOfString * newCopy;
    newCopy = copyListOfStringNoLastElement(newList);
    if (!strcmp((*head)->el, line)) {
        ListOfString * aux;
        aux = *head;
        ListOfString * aux2;
        aux2 = newCopy;
        while (aux2->next) {
            aux2 = aux2->next;
        }
        aux2->next = (*head)->next;
        (*head) = newCopy;
        free(aux->el);
        free(aux);
        aux = NULL;
    } else {
        ListOfString * p;
        p = *head;
        int s = 0;
        while (p->next && !s) {
            if (!strcmp(p->next->el, line)) {
                s = 1;
            } else {
                p = p->next;
            }
        }
        if (!s) {
            return;
        } else {
            ListOfString * aux;
            aux = p->next;

            ListOfString * aux2;
            aux2 = newCopy;
            while (aux2->next) {
                aux2 = aux2->next;
            }
            aux2->next = p->next->next;
            p->next = newCopy;
            //free(aux->el);
            //free(aux);
            aux = NULL;
        }
    }
}


void replaceOneLineWithAListWithStr(ListOfString ** head, ListOfString * newList, char * line) {
    ListOfString * newCopy;
    newCopy = copyListOfStringNoLastElement(newList);
    if (strstr((*head)->el, line)) {
        ListOfString * aux;
        aux = *head;
        ListOfString * aux2;
        aux2 = newCopy;
        while (aux2->next) {
            aux2 = aux2->next;
        }
        aux2->next = (*head)->next;
        (*head) = newCopy;
        free(aux->el);
        free(aux);
        aux = NULL;
    } else {
        ListOfString * p;
        p = *head;
        int s = 0;
        while (p->next && !s) {
            if (strstr(p->next->el, line)) {
                s = 1;
            } else {
                p = p->next;
            }
        }
        if (!s) {
            return;
        } else {
            ListOfString * aux;
            aux = p->next;

            ListOfString * aux2;
            aux2 = newCopy;
            while (aux2->next) {
                aux2 = aux2->next;
            }
            aux2->next = p->next->next;
            p->next = newCopy;
            //free(aux->el);
            //free(aux);
            aux = NULL;
        }
    }
}

void printAListOfStrings(ListOfString * head, char * outputFile) {
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s", p->el);
        p = p->next;
    }
    fclose(fout);
}

void printAListOfStringsNL(ListOfString * head, char * outputFile) {
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s\n", p->el);
        p = p->next;
    }
    fclose(fout);
}

void printAListOfStringsExstingFileNL(ListOfString * head, char * outputFile) {
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "w+");
    while (p) {
        fprintf(fout, "%s\n", p->el);
        p = p->next;
    }
    fclose(fout);
}

void addListOfStringToExistingFile(ListOfString * head, char * outputFile){
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "w+");
    while (p) {
        fprintf(fout, "%s\n", p->el);
        p = p->next;
    }
    fclose(fout);
}

void addAListOfStringsInTheEnd(ListOfString * head, char * outputFile) {
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "a");
    while (p) {
        fprintf(fout, "%s", p->el);
        p = p->next;
    }
    fclose(fout);
}

void addAListOfStringsInTheEndOfFileLN(ListOfString * head, char * outputFile) {
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "a");
    while (p) {
        fprintf(fout, "%s\n", p->el);
        p = p->next;
    }
    fclose(fout);
}

void printAListOfStringsWithSpaces(ListOfString * head, char * outputFile) {
    ListOfString * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s ", p->el);
        p = p->next;
    }
    fclose(fout);
}

ListOfString * readListOfStringFromFile(char * input) {
    ListOfString * head = NULL;

    FILE * fin = fopen(input, "r");
    if(fin == NULL)
        return NULL;

    char * line;
    line = (char *) malloc(3000 * sizeof (char));

    while (fgets(line, 2999, fin) != NULL) {
        addNewString(&head, line);
    }

    free(line);
    fclose(fin);
    return head;
}

ListOfString * readListOfStringFromFileAsWords(char * input) {
    ListOfString * head = NULL;

    FILE * fin = fopen(input, "r");
    if(fin == NULL)
        return NULL;

    char * word;
    word = (char *) malloc(3000 * sizeof (char));

    while (fscanf(fin, "%s", word) != EOF) {
        addNewString(&head, word);
    }

    free(word);
    fclose(fin);
    return head;
}

char * readAStringFromFileAsWords(char * input) {
    ListOfString * head = NULL;

    FILE * fin = fopen(input, "r");
    char * word;
    word = (char *) malloc(3000 * sizeof (char));

    fscanf(fin, "%s", word);
    fclose(fin);
    return word;
}

char * readAStringFromFile(char * input) {
    char * line;
    line = (char *) malloc(100000 * sizeof (char));
    FILE * fin = fopen(input, "r");
    fgets(line, 99999, fin);
    fclose(fin);
    return line;
}
#define TRUE 1
void readStringAsWords(char *string, ListOfString ** words)
{
    char * str = string;
    char * token = strtok(str, " ");
    while( token != NULL ) {
        addNewString( words, token );
        token = strtok(NULL, " ");
    }

}
#define MAX_SIZE            1000
// Swaps two strings (assuming memory allocation is already correct)
void swap_str(char str1[], char str2[]) {

    char temp[MAX_SIZE];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

}



ListOfString * reverseListOfString(ListOfString * head) {
    ListOfString * newHead = NULL;
    int n = countElementsInListOfString(head);
    int j = n - 1;
    char **str= NULL;
    str = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        str[i] = (char*) malloc(100 * sizeof(char));
    }
    for (int i = 0; i < n; i++) {
        strcpy(str[i], head->el);
        head = head->next;
    }
    char* temp;
    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }

    for (int i = 0; i < n; i++) {
        char* temp1 = (char *) malloc((strlen(str[i]) + 1) * sizeof (char *));
        strcpy(temp1, str[i]);
        addNewString(&newHead, temp1);
    }
    free(str);
    return newHead;
}

int searchStringInListOfStrings(ListOfString * head, char * searchedEl) {
    while (head) {
        if (!strcmp(head->el, searchedEl)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int searchOccurrenceOfStringInListOfStrings(ListOfString * head, char * searchedEl) {
    int countOccurrence = 0;
    while (head) {
        if (!strcmp(head->el, searchedEl)) {
            countOccurrence++;
        }
        head = head->next;
    }
    return countOccurrence;
}

int searchOccurrenceOfStringInListOfStringsUsingSTRSTR(ListOfString * head, char * searchedEl) {
    int countOccurrence = 0;
    while (head) {
        if (strstr(head->el, searchedEl)) {
            countOccurrence++;
        }
        head = head->next;
    }
    return countOccurrence;
}

int countElementsInListOfString(ListOfString * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

int countElementsInListOfStringNotAnElement(ListOfString * head, char * element) {
    int count = 0;
    while (head) {
        if (strcmp(head->el, element)) {
            count++;
        }
        head = head->next;

    }
    return count;
}

void addListOfStringToExistingOneUniqueEl(ListOfString ** destination, ListOfString * source) {
    ListOfString * aux = source;

    while (aux) {
        if (!searchStringInListOfStrings((*destination), aux->el)) {
            addNewString(&(*destination), aux->el);
        }
        aux = aux->next;
    }
}

void addListOfStringToExistingOne(ListOfString ** destination, ListOfString * source) {
    ListOfString * aux = source;

    while (aux) {
        addNewString(&(*destination), aux->el);
        aux = aux->next;
    }
}



ListOfString * concatTwoListOfStrings(ListOfString * list1, ListOfString * list2) {
    ListOfString * concatedList = list1;

    while (list2) {
        addNewString(&concatedList, list2->el);
        list2 = list2->next;
    }
    return concatedList;
}

ListOfString * addQuotesInAList(ListOfString ** head ){
    ListOfString * p, *q;
    p = q = *head;

    while (p) {
        sprintf(&(*head), "\"%s\"", p->el);
        *head = p->next;
        p = p->next;
    }
    head;
}

void addListOfStringToExistingOneUnique(ListOfString * destination, char * source) {
    ListOfString * aux = destination;

    while (aux) {
        if (!searchStringInListOfStrings(destination, source)) {
            addNewString(&destination, source);
        }
        aux = aux->next;
    }
}

char * nthElementInListString(ListOfString * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        char * selectedMappingCandidate = NULL;
        selectedMappingCandidate = (char *) malloc((strlen(head->el) + 1) * sizeof (char));

        strcpy(selectedMappingCandidate, head->el);

        return selectedMappingCandidate;
    } else {
        return NULL;
    }
}

char * returnLastElementInListString(ListOfString * head) {

    while (head) {
        if(head->next == NULL)
            return head->el;
        head = head->next;
    }
    return NULL;
}

ListOfString * returnListOfStringFromMarkersFile(char * inputFile) {
    ListOfString * TempListOfStrings = NULL;
    FILE * fileOfMarkers = fopen(inputFile, "r");
    char * allMarkers;
    allMarkers = (char *) malloc(10000 * sizeof (char));
    if (fgets(allMarkers, 10000, fileOfMarkers) == NULL) {
        return NULL;
    }
    char * token;
    char * tokenNoBeginSpace;
    tokenNoBeginSpace = (char *) malloc(500 * sizeof (char));
    token = strtok(allMarkers, ",");
    if (token) {
        if (token[strlen(token) - 1 ] == '\n') {
            token[strlen(token) - 1 ] = '\0';
        }
        addNewString(&TempListOfStrings, token);
    }
    while (token) {
        token = strtok(NULL, ",");
        if (token) {

            strcpy(tokenNoBeginSpace, token + 1);
            if (tokenNoBeginSpace[strlen(tokenNoBeginSpace) - 1 ] == '\n') {
                tokenNoBeginSpace[strlen(tokenNoBeginSpace) - 1 ] = '\0';
            }
            if (!searchStringInListOfStrings(TempListOfStrings, tokenNoBeginSpace)) {
                addNewString(&TempListOfStrings, tokenNoBeginSpace);
            }
        }
    }
    free(allMarkers);
    fclose(fileOfMarkers);
    return TempListOfStrings;
}

char * nthElementInListStringExceptingOneString(ListOfString * head, int n, char * exception) {
    ListOfString * currentSelected = NULL;
    
    while (n >= 0 && head) {
        if (strcmp(head->el, exception)) {
            n--;
            currentSelected = head;
        }
        head = head->next;
    }
    if (n == -1) {
        char * selectedMappingCandidate = NULL;
        selectedMappingCandidate = (char *) malloc((strlen(currentSelected->el) + 1) * sizeof (char));

        strcpy(selectedMappingCandidate, currentSelected->el);

        return selectedMappingCandidate;
    } else {
        return NULL;
    }
}

ListOfString * combineLists(ListOfString * destinate, ListOfString * source){
    ListOfString * listOfSource = readListOfStringFromFile(source);
    ListOfString * listOfDestinate = readListOfStringFromFile(destinate);
    ListOfString * ListsCombined = listOfDestinate;

    while (listOfSource){
        if (!searchStringInListOfStrings(listOfDestinate, listOfSource->el))
            addNewString(&ListsCombined, listOfSource->el);

        listOfSource = listOfSource->next;
    }

    return ListsCombined;
}

ListOfString * searchStringDuplicationInTwoLists(ListOfString * list1, ListOfString * list2){

    ListOfString * listOfDuplicatedElements= NULL;

    while(list1){
        char * currentStr = NULL;
        currentStr = (char *) malloc(9999 * sizeof (char));
        strcpy(currentStr, list1->el);

        if (searchStringInListOfStrings(list2, currentStr)){
            addNewString(&listOfDuplicatedElements, currentStr);
        }
        list1 = list1->next;
        free(currentStr);
    }
    return listOfDuplicatedElements;
}