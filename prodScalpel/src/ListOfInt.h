/* 
 * File:   ListOfInt.h
 * Author: ---
 *
 * Created on 03 July 2014, 01:19
 */

#ifndef LISTOFINT_H
#define	LISTOFINT_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct listOfInt {
        int value;
        struct listOfInt * next;
    };

    typedef struct listOfInt ListOfInt;

    void freeListOfInt(ListOfInt ** head);

    void addNewInt(ListOfInt ** head, int value);

    ListOfInt * copyListOfInt(ListOfInt * head);

    int removeInt(ListOfInt ** head, int value);

    void printAListOfInt(ListOfInt * head, char * outputFile);

    int searchAnIntInListOfInt(ListOfInt * head, int searchedEl);

    int countElementsInListOfInt(ListOfInt * head);
    
    void deleteElementInListOfIntAtPosition(ListOfInt ** head, int position);
    
    int nthElementInListOfInt(ListOfInt * head, int n);
    
    int searchIntInListOfInts(ListOfInt * head, int searchedEl);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTOFINT_H */

