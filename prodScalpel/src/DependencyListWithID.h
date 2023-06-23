/* 
 * File:   DependencyListWithID.h
 * Author: ---
 *
 * Created on 13 July 2014, 16:47
 */

#ifndef DEPENDENCYLISTWITHID_H
#define	DEPENDENCYLISTWITHID_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfString.h"
#include <stdio.h>
#include "Mapping.h"

    struct dependencyListWithID {
        char * Statement;
        char * DependendID;
        ListOfString * ListOfDependencies;
        struct dependencyListWithID *next;
    };

    typedef struct dependencyListWithID DependencyListWithID;

    void freeDependencyListWithID(DependencyListWithID ** head);

    DependencyListWithID * searchDependencyListWithIDForAnElement(DependencyListWithID * head, char * statement,
        char * dependendID);

    void addNewStatementDependencyListWithID(DependencyListWithID ** head, char * statement,
        char * ID);

    int addNewDependencyListWithID(DependencyListWithID ** head, char * statement, char * ID, 
        char * declaration);

    void printADependencyListWithID(char * outputFile, DependencyListWithID * head);

    DependencyListWithID * readDependencyListWithIDFromFile(char * inputFile);

    ListOfString * returnDependencyListWithIDForAMarkerNewPointers(DependencyListWithID * head,
        char * ID, char ** dependencyLineMarker) ;

    void addDependencyListWithIDToAnExistingOne(DependencyListWithID ** destination, DependencyListWithID * source);

    DependencyListWithID * copyDependencyListWithID(DependencyListWithID * initial);

    DependencyListWithID * dependencyListWithIDForDeclWithAbstractValues(Mapping * ListOfMappingsFromCurrentDonor,
            ListOfString * FinalSkeletonSourceCode, ListOfString * ListOfMarkersForAbstractVariables,
			char * TXLTemporaryFolder);


#ifdef	__cplusplus
}
#endif

#endif	/* DEPENDENCYLISTWITHID_H */

