#include "ListOfString.h"
#include "GenTrans.h"

#include <stdio.h>
#include <stdlib.h>

//#include <malloc.h>
#include <string.h>
#include <errno.h>
#include "Utils.h"
#include "folderContent.h"
#include "GlobalDependenceGraph.h"
#include "DependencyList.h"
#include "GlobalDeclarations.h"


void addNewDeclarationNode(ListOfStatmentMark ** head, char *nodeId, long int id) {
    ListOfStatmentMark * newEl = (ListOfStatmentMark *) malloc(1 * sizeof (ListOfStatmentMark));
    newEl->nodeId = (char *) malloc((strlen(nodeId) + 1) * sizeof (char *));
    strcpy(newEl->nodeId, nodeId);
    newEl->id = id;
    newEl->next = NULL;

    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfStatmentMark * p;
        p = *head;
        while (p->next) {
            p = p->next;
        }
        p->next = newEl;
    }
}

ListOfStatmentMark * readListStatmentMark(GlobalDeclarations ListOfDecl) {
    ListOfStatmentMark * auxMarkers = NULL;

    long int id = 0;

    ListOfStructDefinitions * auxNormalDecl = ListOfDecl.normalDeclarations;
    ListOfStructDefinitions * auxStructDecl = ListOfDecl.structUnionDeclarations;
    ListOfStructDefinitions * auxTypedefDecl = ListOfDecl.typedefDeclarations;

    while (auxNormalDecl) {
        char *currentMark = (char *) malloc((strlen(auxNormalDecl->structDef->el) + 3) * sizeof(char));
        strcpy(currentMark,readSubstring("/* ", auxNormalDecl->structDef->el, " */"));
        char * formattedMarker = NULL;
        formattedMarker = (char *) malloc((strlen(currentMark) + 10) * sizeof (char *));
        sprintf(formattedMarker, "/* %s */", currentMark);
        addNewDeclarationNode(&auxMarkers, formattedMarker, id);
        id++;
        auxNormalDecl = auxNormalDecl->next;
    }

    while (auxStructDecl) {
        char *currentMark = (char *) malloc((strlen(auxStructDecl->structDef->el) + 3) * sizeof(char));
        strcpy(currentMark,readSubstring("/* ", auxStructDecl->structDef->el, " */"));
        char * formattedMarker = NULL;
        formattedMarker = (char *) malloc((strlen(currentMark) + 10) * sizeof (char *));
        sprintf(formattedMarker, "/* %s */", currentMark);
        addNewDeclarationNode(&auxMarkers, formattedMarker, id);
        id++;
        auxStructDecl = auxStructDecl->next;
    }

    while (auxTypedefDecl) {
        char *currentMark = (char *) malloc((strlen(auxTypedefDecl->structDef->el) + 3) * sizeof(char));
        strcpy(currentMark,readSubstring("/* ", auxTypedefDecl->structDef->el, " */"));
        char * formattedMarker = NULL;
        formattedMarker = (char *) malloc((strlen(currentMark) + 10) * sizeof (char *));
        sprintf(formattedMarker, "/* %s */", currentMark);
        addNewDeclarationNode(&auxMarkers, formattedMarker, id);
        id++;
        auxTypedefDecl = auxTypedefDecl->next;
    }

    return auxMarkers;
}


struct DependenceGraph* createDeclGraph(long int vertices)
{
    struct DependenceGraph* graph = malloc(sizeof(struct DependenceGraph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct DependenceNode*));

    graph->visited = malloc(vertices * sizeof(int));

    long int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

long int searchDeclNodeId(ListOfStatmentMark * head, char * searchedNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfStatmentMark * listOfMarker = head;
    while(listOfMarker) {
        char * nodeId = listOfMarker->nodeId;
        if (!strcmp(nodeId, searchedNode)){
            // printf("%d: %s\n", listFunctions->id,listFunctions->nodeId);
            return listOfMarker->id;
        }
        listOfMarker = listOfMarker->next;
    }
    return NULL;
}

char * searchDeclNodeMarker(ListOfStatmentMark * head, char * searchedNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfStatmentMark * listOfMarker = head;
    while(listOfMarker) {
        char * nodeId = listOfMarker->nodeId;
        if (!strcmp(nodeId, searchedNode)){
            // printf("%d: %s\n", listFunctions->id,listFunctions->nodeId);
            return listOfMarker->nodeId;
        }
        listOfMarker = listOfMarker->next;
    }
    return NULL;
}

char * searchDeclNodeMarkerFromId(ListOfStatmentMark * head, long int id) {
    ListOfStatmentMark * listOfMarker = head;
    while(listOfMarker) {
        char * nodeId = listOfMarker->nodeId;
        if (listOfMarker->id == id){
            // printf("%d: %s\n", listFunctions->id,listFunctions->nodeId);
            return listOfMarker->nodeId;
        }
        listOfMarker = listOfMarker->next;
    }
    return NULL;
}

struct dependenceNode* createDeclNode(int v, char * nodeId)
{
    struct dependenceNode * newNode = malloc(sizeof(struct dependenceNode));
    newNode->nodeId = (char *) malloc((strlen(nodeId) + 1) * sizeof (char *));
    newNode->vertex = v;
    newNode->next = NULL;
    strcpy(newNode->nodeId , nodeId);
    return newNode;
}

void addDeclEdge(struct DependenceGraph* graph, int src, int dest, char * markerDest)
{
    struct dependenceNode* newNode = createDeclNode(dest, markerDest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}


long int countDeclarationMarkerList(ListOfStatmentMark * markersList){
    long int count = 0;
    while(markersList){
        count++;
        markersList = markersList->next;
    }
    return count;
}

struct DependenceGraph * generateDependenceGraph(DependencyList * GlobalDependencyList, ListOfStatmentMark * listOfStatmentMark){

    long int countNodes = 0;
    long int countNumberOfMarkers = countDeclarationMarkerList(listOfStatmentMark);
    struct DependenceGraph* graph = createDeclGraph(countNumberOfMarkers+1);

    DependencyList * ListOfDeclarationsDependencies = NULL;
    DependencyList * auxGlobalDependencyList = GlobalDependencyList;

    while (auxGlobalDependencyList) {
        int idNodeOrig = searchDeclNodeId(listOfStatmentMark, auxGlobalDependencyList->Statement);
        char * declMarkerOrig = searchDeclNodeMarker(listOfStatmentMark, auxGlobalDependencyList->Statement);

        ListOfString * currentStmDependList = returnDependencyForAMarkerNewPointers(GlobalDependencyList, auxGlobalDependencyList->Statement);
        while (currentStmDependList) {
            int idNodeDest = searchDeclNodeId(listOfStatmentMark, currentStmDependList->el);
            char * declMarkerDest = searchDeclNodeMarker(listOfStatmentMark, currentStmDependList->el);

            if(declMarkerDest ==NULL){
                declMarkerDest = (char *) malloc((strlen(listOfStatmentMark->nodeId) + 1) * sizeof (char *));
                strcpy(declMarkerDest, listOfStatmentMark->nodeId);
            }

            if(declMarkerOrig ==NULL){
                declMarkerOrig = (char *) malloc((strlen(listOfStatmentMark->nodeId) + 1) * sizeof (char *));
                strcpy(declMarkerOrig, listOfStatmentMark->nodeId);
            }

            addDeclEdge(graph, idNodeOrig, idNodeDest, declMarkerDest);
            countNodes++;
            currentStmDependList = currentStmDependList->next;
        }
        fflush(stdout);
        auxGlobalDependencyList = auxGlobalDependencyList->next;
    }

    //   printGraph(graph);
    // DFS(graph, 1);
    return graph;

}


void printDependenceListForTransplantAsGraph(struct DependenceGraph* graph)
{
    int v;

    for (v = 0; v < graph->numVertices; v++)
    {
        struct dependenceNode* temp = graph->adjLists[v];
        printf("\n %d|| ", v);
        while (temp)
        {
            printf("%d (%s)| ", temp->vertex,temp->nodeId);

            //  printf("%s , ", temp->functionName);
            // printf("%s , ", temp->nodeId);

            temp = temp->next;
        }
        printf("\n--------------------");
    }
    printf("\n=======================\n");
}

void readDeclDependenceForTransplant(struct DependenceGraph* graph, ListOfString **newGlobalMarkersForTransplant, ListOfStatmentMark * listOfStatmentMark, int vertex) {
    struct dependenceNode* adjList = graph->adjLists[vertex];
    struct dependenceNode* temp = adjList;

    graph->visited[vertex] = 1;
    //printf("Visited %d \n", vertex);
    char * declMarker =  (char *) malloc(500 * sizeof(char));
    declMarker = searchDeclNodeMarkerFromId(listOfStatmentMark,vertex);
    //if(!searchStringInListOfStrings(newGlobalMarkersForTransplant, declMarker)) {
        addNewString(newGlobalMarkersForTransplant, declMarker);
        char *recursiveGlobalForTransplant;
        recursiveGlobalForTransplant = (char *) malloc(500 * sizeof(char));
        sprintf(recursiveGlobalForTransplant, "%srecursive_global_for_transplant.out", TXLTemporaryFolderMainThread);
        printAListOfStringsNL((*newGlobalMarkersForTransplant), recursiveGlobalForTransplant);
    //}
    while(temp!=NULL) {
        int connectedVertex = temp->vertex;

        if(graph->visited[connectedVertex] == 0) {
            readDeclDependenceForTransplant(graph, newGlobalMarkersForTransplant, listOfStatmentMark, connectedVertex);
        }
        temp = temp->next;
    }
}


ListOfStatmentMark * dependenceGraphParser( GlobalDeclarations listOfDecl) {
    ListOfStatmentMark * listOfStatmentMark = NULL;
    ListOfString * stmMarkers = readListStatmentMark(listOfDecl);

    long int idStatment = 0;
    while (stmMarkers){
        addNewDeclarationNode(&listOfStatmentMark, stmMarkers->el, idStatment);

        stmMarkers = stmMarkers->next;
    }

    return listOfStatmentMark;
}
//-------------------------------------------------------------------------------------------------------------




