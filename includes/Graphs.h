#ifdef GRAPHS_H
#define GRAPHS_H


#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedLists.h"

#define TYPEOFLIST int
#define TYPEOFGRAPH char
#define NUMBEROFVERTICES 10


//No Vertice can be 0
//This Graph is undirected and unweighted
struct Graph{
    TYPEOFGRAPH vertices[NUMBEROFVERTICES];
    struct SLL_Node* edges[NUMBEROFVERTICES];
};

//Finds Position of a Vertice in Vertices Array (Kind of like a Private function)
int Graph_FindVerticePosition(struct Graph* graph, TYPEOFGRAPH value);

//Checks if Vertice exists in Graph
int Graph_DoesVerticeExist(struct Graph* graph, TYPEOFGRAPH vertice);

//Creates graph and sets all values to 0/NULL. You can pass in an array of vertices but you also have to pass in the length
struct Graph* Graph_Create(TYPEOFGRAPH vertices[], int len);

//Inserts Vertice. If the number of vertices has reached its maximum, 0 will be returned
int Graph_InsertVertice(struct Graph* graph, TYPEOFGRAPH vertice);

//Inserts edge between 2 vertices. If the function is unable to do so, 0 will be returned
int Graph_InsertEdge(struct Graph* graph, TYPEOFGRAPH node1, TYPEOFGRAPH node2);

//Checks if Edge exists
int Graph_IsThereEdge(struct Graph* graph,TYPEOFGRAPH node1, TYPEOFGRAPH node2);

//Returns pointer to linked list of all adjacent vertices to the passed in vertice
struct SLL_Node* Graph_AdjacentNodes(struct Graph* graph, TYPEOFGRAPH vertice);

//Returns Total Number of Vertices in Graph
int Graph_NumberOfVertices(struct Graph* graph);

//Returns Total Number of Edges in Graph
int Graph_NumberOfEdges(struct Graph* graph);

//Returns nth Node in Vertices array in Graph
TYPEOFGRAPH Graph_WhatIsNthNode(struct Graph* graph, int position);

//Frees Graph from memory
void Graph_DeleteGraph(struct Graph* graph);

//Deletes a Vertice from graph and all of its associated edges
void Graph_DeleteVertice(struct Graph* graph, TYPEOFGRAPH vertice);

//Deletes 1 edge, between 2 vertices passed. If the edge doesn't exist, nothing happens
void Graph_DeleteEdge(struct Graph* graph, TYPEOFGRAPH node1, TYPEOFGRAPH node2);

#endif