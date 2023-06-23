/* 
 * File:   ListOfString.h
 * Author: ---
 *
 * Created on 27 June 2014, 18:41
 */

#ifndef LISTOFSTRING_H
#define	LISTOFSTRING_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct listOfString {
        char * el;
        struct listOfString * next;
    };

    struct listGlobalTypeVarDeclaration {
        char * declaredType;
        char * declaredTypeID;
        int occurrence;
        struct listOfString * next;
    };

    struct listOfIdsForGrobalDeclaration {
        char * newId;
        char * oldId;
        struct listOfIdsForGrobalDeclaration * next;
    };

    typedef struct listOfString ListOfString;
    typedef struct listOfIdsForGrobalDeclaration ListOfIdsForGrobalDeclaration;
    typedef struct listGlobalTypeVarDeclaration ListGlobalTypeVarDeclaration ;

    int searchOccurrenceOfStringInListOfStrings(ListOfString * head, char * searchedEl);
    int searchOccurrenceOfStringInListOfStringsUsingSTRSTR(ListOfString * head, char * searchedEl);

    void addNewGlobalDeclarationType(ListGlobalTypeVarDeclaration ** head, char * declID, char * declaration);
    void freeListOfStrings(ListOfString ** head);

    void addNewString(ListOfString ** head, char * string);
    void addIDs(ListOfIdsForGrobalDeclaration ** head, char * oldId, char * newId);

    ListOfString * copyListOfString(ListOfString * head);

    ListOfString * copyListOfStringNoLastElement(ListOfString * head);

    void removeFirstEl(ListOfString **head);

    void removeLastString(ListOfString ** head);

    int removeString(ListOfString ** head, char * string);

    int removeStringLabels(ListOfString ** head, char * string);

    void replaceOneLineWithAListKeepPenultimate(ListOfString ** head, ListOfString * newList, char * line);

    void replaceOneLineWithAList(ListOfString ** head, ListOfString * newList, char * line);

    void printAListOfStrings(ListOfString * head, char * outputFile);

    ListOfString * readListOfStringFromFile(char * input);

    ListOfString * readListOfStringFromFileAsWords(char * input);

    int searchStringInListOfStrings(ListOfString * head, char * searchedEl);

    int countElementsInListOfString(ListOfString * head);

    ListOfString * copyCompleteListOfString(ListOfString * head);

    void addListOfStringToExistingOneUniqueEl(ListOfString ** destination, ListOfString * source);

    void addListOfStringToExistingOneUnique(ListOfString * head, char *source);

    char * nthElementInListString(ListOfString * head, int n);

    ListOfString * returnListOfStringFromMarkersFile(char * inputFile);
    
    void printAListOfStringsWithSpaces(ListOfString * head, char * outputFile);
    
    char * nthElementInListStringExceptingOneString(ListOfString * head, int n, char * exception);
    
    int countElementsInListOfStringNotAnElement(ListOfString * head, char * element);

    void printAListOfStringsNL(ListOfString * head, char * outputFile);

    void addAListOfStringsInTheEnd(ListOfString * head, char * outputFile);

    int comparTwoListOfString(ListOfString * head1, ListOfString * head2);

    char * readAStringFromFileAsWords(char * input);

    void addAListOfStringsInTheEndOfFileLN(ListOfString * head, char * outputFile);

    ListOfString * reverseListOfString(ListOfString * head);
    ListOfString * orderListOfString(ListOfString * head);

    ListOfString * combineLists(ListOfString * destinate, ListOfString * source);

    ListOfString * searchStringDuplicationInTwoLists(ListOfString * list1, ListOfString * list2);

    char * returnLastElementInListString(ListOfString * head);
    void readStringAsWords(char *string, ListOfString ** words);
    void addListOfStringToExistingFile(ListOfString * head, char * outputFile);

    void printAListOfStringsExstingFileNL(ListOfString * head, char * outputFile);
    char * readAStringFromFile(char * input);

    void addListOfStringToExistingOne(ListOfString ** destination, ListOfString * source);
    ListOfString * concatTwoListOfStrings(ListOfString * list1, ListOfString * list2);

    ListOfString * addQuotesInAList(ListOfString ** head );

    void replaceOneLineInALIst(ListOfString ** head, char * line, char * newLine);

    void replaceOneLineWithAListWithStr(ListOfString ** head, ListOfString * newList, char * line);

    void addNewStringInTheBegging(ListOfString ** head, char * string);
    void removeCharactersBefore(char** str, char c);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTOFSTRING_H */

