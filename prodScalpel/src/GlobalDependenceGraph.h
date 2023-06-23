/* 
 * File:   CallGraph.h
 * Author: ---
 *
 * Created on 10 January 2018, 17:56
 */
#include "DependencyList.h"
#include "GlobalDeclarations.h"

struct dependenceNode
{
    long int vertex;
    char * nodeId;
    struct dependenceNode * next;
};



struct DependenceGraph
{
    int numVertices;
    int* visited;
    char * nodeId;
    char * maker;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};

struct listOfStatmentMark {
    long int id;
    char * nodeId;
    struct listOfStatmentMark * next;
};

typedef struct listOfStatmentMark ListOfStatmentMark;


struct DependenceGraph * generateDependenceGraph(DependencyList * GlobalDependencyList, ListOfStatmentMark * listOfStatmentMark);

void readDeclDependenceForTransplant(struct DependenceGraph* graph, ListOfString **newGlobalMarkersForTransplant, ListOfStatmentMark * listOfStatmentMark, int vertex);
long int searchDeclNodeId(ListOfStatmentMark * head, char * searchedNode);
ListOfStatmentMark * readListStatmentMark(GlobalDeclarations listOfDecl);