/* 
 * File:   CallGraph.h
 * Author: ---
 *
 * Created on 10 January 2018, 17:56
 */

#ifndef CALLGRAPH_H
#define	CALLGRAPH_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfFunctionForGraph.h"
#if 0
typedef enum {UNDIRECTED=0,DIRECTED} graph_type_e;

/* Adjacency list node*/
typedef struct adjlist_node
{
    int vertex;                /*Index to adjacency list array*/
    struct adjlist_node *next; /*Pointer to the next node*/
}adjlist_node_t, *adjlist_node_p;

/* Adjacency list */
typedef struct adjlist
{
    int num_members;           /*number of members in the list (for future use)*/
    adjlist_node_t *head;      /*head of the adjacency linked list*/
}adjlist_t, *adjlist_p;

/* Graph structure. A graph is an array of adjacency lists.
   Size of array will be number of vertices in graph*/
typedef struct graph
{
    graph_type_e type;        /*Directed or undirected graph */
    int num_vertices;         /*Number of vertices*/
    adjlist_p adjListArr;     /*Adjacency lists' array*/
}graph_t, *graph_p;


typedef struct graph Graph;
/* Exit function to handle fatal errors*/
/*__inline void err_exit(char* msg)
{
    printf("[Fatal Error]: %s \nExiting...\n", msg);
    exit(1);
}
*/

#endif

struct node
{
    int vertex;
    char * nodeId;
    char * functionName;
    char * sourceFile;
    struct node * next;
};



struct Graph
{
    int numVertices;
    int* visited;
    char * nodeId;
    char * functionName;
    char * sourceFile;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};



struct elemento{
    long int nodeId;
    struct elemento *prox;
};

typedef struct elemento* Stack;
typedef struct grafo Grafo;

    struct Graph* createGraph(long int vertices);
    struct Graph * readAGraph(ListOfFunctionForGraph * listOfFunctionSourceFile, char * graphDir, char * targetFunction);
    void readReverseFunctionFromGraph(struct Graph* graph, int vertex, int countSpace, ListOfFunctionForGraph *listFunctions, int maxSpace, int n);
    //void readReverseGraph1(struct Graph* graph, int vertex, int countSpace, ListOfFunctionSourceFile *listFunctions, char ** tempListOfFunctionSourceFile, int *countFunction ) ;
    //void readReverseGraph1(struct Graph* graph, int vertex, int countSpace);

    //void addEdge(struct Graph* graph, int src, int dest , ListOfFunctionSourceFile * nodeList);
    void printGraph(struct Graph*);
    void DFS(struct Graph*, int);
    void addEdge(struct Graph*, int, int);
/// void addEdge(struct Graph* graph, int src, int dest, char * funcOrig, char * funcDest);

///void addEdge(struct Graph*, int, int, char *, char *);
    void addEdgeWithFunctionName(struct Graph* graph, int src, ListOfFunctionForGraph *destNodeReference );
    char * searchNodeFunctionName(ListOfFunctionForGraph * head, char * searchedNode) ;
    //struct node* createNode(int v);
    struct node* createNodeWithFunctionName(ListOfFunctionForGraph *destNodeReference );
    void tostring(char str[], int num);

    //struct node* createNode(int v, ListOfFunctionSourceFile * nodeRef );

    void generateCallAndCallerGraphs();
    ListOfFunctionForGraph * callAndCallerGraphParser(char * graftFileFullPath, char * graftMethod, char * graphType);
    ListOfFunctionForGraph * readACallGraphAsList( char * graftMethod);
   // ListOfFunctionSourceFile * callerGraphParser(char * graftFileFullPath, char * graftMethod, char * graphType);

    ListOfFunctionForGraph * readACallerGraphAsList( char * graftMethod) ;
    ///struct Graph * readACallerGraph( char * targetFunction, ListOfFunctionForGraph * ListOfFuncitonSourceFile);
    struct Graph * readACallerGraph( ListOfFunctionForGraph * ListOfFuncitonSourceFile, char * targetFunction);

/* graph_p createGraph(int n, graph_type_e type);
    void displayGraph(Graph * graph, int numVertices);
    void destroyGraph(graph_p graph);
    void addEdge(Graph * graph, int src, int dest, int numVertices);
    graph_p createGraph(int n, graph_type_e type);
    adjlist_node_p createNode(int v);
    long int readIdFromNodeListOfFunctionSourceFile( ListOfFunctionSourceFile * head, char * searchedNode) ;
    adjlist_node_p searchNodeReference(Graph *graph, int searchedNode, int numVertices);
*/

    void writeCallGraph(struct Graph* graph, char * sourceOutputFilePath);

    char * constructSubDirectoryPath(const char *subPath, const char *sourceFileName);

    void DFSPath(struct Graph *graph, int vertex, int sourceNode);
    Stack *searchPath(struct Graph *graph, ListOfFunctionForGraph * listOfFunction);
    ListOfFunctionForGraph *  readPath(Stack* path, ListOfFunctionForGraph * listOfFunction);


#ifdef	__cplusplus
}
#endif

#endif	/* CALLGRAPH_H */

