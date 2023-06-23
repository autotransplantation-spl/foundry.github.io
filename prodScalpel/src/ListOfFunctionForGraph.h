/* 
 * File:   ListOfFunctionSourceFile.h
 * Author: ---
 *
 * Created on 03 July 2014, 19:12
 */

#ifndef LISTOFFUNCTIONFORGRAPH_H
#define	LISTOFFUNCTIONFORGRAPH_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "ListOfString.h"

    struct listOfFunctionForGraph {
        long int id;
        char * functionName;
        char * nodeId;
        char * sourceFile;
        char * hostTargetFile;
        char * startFunctionMarker;
        char * startFunctionMarkerSourceFile;
        struct listOfFunctionForGraph * next;
    };

    typedef struct listOfFunctionForGraph ListOfFunctionForGraph;

    void freeListOfFunctionForGraph(ListOfFunctionForGraph ** head);
    
    void addNewFunctionForGraph(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile);

    void addNewFunctionForGraphNode(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char *nodeId, long int id);

    void addNewFunctionHeaderSourceFileForGraph(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char *headerFile);

    void addNewFunctionForGraphDonor(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char * hostTarget);

    int removeFunctionForGraph(ListOfFunctionForGraph ** head, char * functionName);
    
    void printAListOfFunctionForGraph(ListOfFunctionForGraph * head, char * outputFile);
    
    int searchForFunctionForGraph(ListOfFunctionForGraph * head, char * searchedFunctionName);
    
    int countElementsInListOfFunctionsForGraph(ListOfFunctionForGraph * head);

    ListOfFunctionForGraph * readCoreFunctionFromFileForGraph();

    int countElementsInListOfFunctionSourceFileForGraph(ListOfFunctionForGraph * head);

    void addNewFunctionGraphWithstartFunctionMarkerArguments(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char * hostTargetFile, char * startFunctionMarker, char * startFunctionMarkerSourceFile);

    ListOfFunctionForGraph * readInputFileForGraph(char * inputFile);

    int searchNodeId(ListOfFunctionForGraph * head, char * searchedNode) ;

    ListOfFunctionForGraph *searchNodeReference(ListOfFunctionForGraph * head, char * searchedIdNode);

    ListOfFunctionForGraph *searchNodeReferenceFromId(ListOfFunctionForGraph * head, long int searchedId);

    int searchFunctionInListOfFunctionsForGraph(ListOfFunctionForGraph * head, char * searchedFunctionName);

    ListOfFunctionForGraph * searchNodeIdFromFunctionName(ListOfFunctionForGraph * head, char * searchedName) ;

    int searchIdFromFunctionName(ListOfFunctionForGraph * head, char * searchedName);

    ListOfString  * addDirectivesInFunction(char * sourceOutputFileForOrgan);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTOFFUNCTIONFORGRAPH_H */

