/* 
 * File:   DependencyList.h
 * Author: ---
 *
 * Created on 30 June 2014, 00:42
 */

#ifndef DEPENDENCYLIST_H
#define	DEPENDENCYLIST_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "ListOfString.h"
#include <stdio.h>
#include "Mapping.h"

    struct dependencyList {
        char * Statement;
        int visited;
        ListOfString * ListOfDependencies;
        struct dependencyList *next;
    };

    typedef struct dependencyList DependencyList;


    void freeDependencyList(DependencyList ** head);

    DependencyList * searchDependenciesForAnElement(DependencyList * head, char * statement);

    void addNewStatement(DependencyList ** head, char * statement);

    int addNewDependency(DependencyList ** head, char * statement, char * declaration);

    void printADependencyList( DependencyList * head, char * outputFile);

    DependencyList * readDependencyListFromFile(char * inputFile);

    ListOfString * returnDependencyForAMarkerNewPointers(DependencyList * head, char * marker);

    void addDependencyListToAnExistingOne(DependencyList ** destination, DependencyList * source);

    DependencyList * dependencyListForDeclWithAbstractValues(Mapping * ListOfMappingsFromCurrentDonor,
            ListOfString * FinalSkeletonSourceCode, ListOfString * ListOfMarkersForAbstractVariables,
			char * TXLTemporaryFolder);

    DependencyList * copyDependencyList (DependencyList * initial);

    void setDependencyStatmentVisited(DependencyList * head, char * marker) ;
    int getDependencyStatmentVisited(DependencyList * head, char * marker);

    int addNewDependencyInExistingOne(DependencyList ** head, char * statement, char * declaration);
    int searchStatment(DependencyList ** head, char * statement);
    char * searchDependencies(ListOfString * head, char * depend);



#ifdef	__cplusplus
}
#endif

#endif	/* DEPENDENCYLIST_H */

#ifdef MAC_OSX
    void addDependencyListToAnExistingOneSearchingIfVarExisting(DependencyList ** destination, DependencyList * source);
#endif
