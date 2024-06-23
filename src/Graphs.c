#include <stdlib.h>
#include <stdio.h>
#include "../includes/SinglyLinkedLists.h"

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
int Graph_FindVerticePosition(struct Graph* graph, TYPEOFGRAPH value){
    int i =0;
    while(graph->vertices[i] != value){
        i++;
    }
    return i;
}

//Checks if Vertice exists in Graph
int Graph_DoesVerticeExist(struct Graph* graph, TYPEOFGRAPH vertice){

    for(int i=0;i<NUMBEROFVERTICES ;i++){
        
        if (graph->vertices[i] == vertice){
            return 1;
        }
    }
    return 0;
}

//Creates graph and sets all values to 0/NULL. You can pass in an array of vertices but you also have to pass in the length
struct Graph* Graph_Create(TYPEOFGRAPH vertices[], int len){

    struct Graph* graph= (struct Graph*) malloc(sizeof(struct Graph));
    if (graph ==NULL) return NULL;
    int i=0;
    while(i<len){
        graph->vertices[i]=vertices[i];
        i++;
    }
    
    while(i<NUMBEROFVERTICES){
       graph->vertices[i]=0; 
       i++;
    }

    for(int i =0;i<NUMBEROFVERTICES;i++){
        graph->edges[i] = NULL;
    }
    return graph;
}

//Inserts Vertice. If the number of vertices has reached its maximum, 0 will be returned
int Graph_InsertVertice(struct Graph* graph, TYPEOFGRAPH vertice){
    int i= 0;
    while(graph->vertices[i] != 0 ){
        i++;
        if (i==NUMBEROFVERTICES-1){
            return 0;
        }
    }
    graph->vertices[i]=vertice;
    return 1;   
}

//Inserts edge between 2 vertices. If the function is unable to do so, 0 will be returned
int Graph_InsertEdge(struct Graph* graph, TYPEOFGRAPH node1, TYPEOFGRAPH node2){

    if(!(Graph_DoesVerticeExist(graph, node1) && Graph_DoesVerticeExist(graph,node2) ) ){
        return 0;
    }
    int address[2]={Graph_FindVerticePosition(graph,node1),Graph_FindVerticePosition(graph,node2)};

    graph->edges[address[0]] = SLL_Insert(graph->edges[address[0]],address[1],-1);
    graph->edges[address[1]] = SLL_Insert(graph->edges[address[1]],address[0],-1);
    return 1;
}

//Checks if Edge exists
int Graph_IsThereEdge(struct Graph* graph,TYPEOFGRAPH node1, TYPEOFGRAPH node2){

    if(!(Graph_DoesVerticeExist(graph, node1) && Graph_DoesVerticeExist(graph,node2) ) ){
        return 0;
    }

    int address[2]={Graph_FindVerticePosition(graph,node1),Graph_FindVerticePosition(graph,node2)}; 


    if(SLL_FindValue(graph->edges[address[0]],address[1])){
        return 1;
    }
    else{
        return 0;
    }
}

//Returns pointer to linked list of all adjacent vertices to the passed in vertice
struct SLL_Node* Graph_AdjacentNodes(struct Graph* graph, TYPEOFGRAPH vertice){
    if(!(Graph_DoesVerticeExist(graph, vertice)) ){
        return NULL;
    }

    int verticePosition = Graph_FindVerticePosition(graph,vertice);
    return graph->edges[verticePosition];

}

//Returns Total Number of Vertices in Graph
int Graph_NumberOfVertices(struct Graph* graph){
    int i= 0;
    int j =0;

    while(i < NUMBEROFVERTICES ){     
        if (graph->vertices[i] != 0){
            j++;
        }
        i++;
    }
    return j;
}

//Returns Total Number of Edges in Graph
int Graph_NumberOfEdges(struct Graph* graph){
    
    int n = 0;
    for(int i=0;i<NUMBEROFVERTICES;i++){
        n+=SLL_GetListLen(graph->edges[i]);
    }
    return n/2;
}

//Returns nth Node in Vertices array in Graph
TYPEOFGRAPH Graph_WhatIsNthNode(struct Graph* graph, int position){
    if(position>=NUMBEROFVERTICES){
        return 0;
    }
    return graph->vertices[position];
}

//Frees Graph from memory
void Graph_DeleteGraph(struct Graph* graph){

    for(int i=0;i<NUMBEROFVERTICES;i++){
        SLL_DeleteList(graph->edges[i]);
    }
    free(graph);
}

//Deletes a Vertice from graph and all of its associated edges
void Graph_DeleteVertice(struct Graph* graph, TYPEOFGRAPH vertice){
    if(!Graph_DoesVerticeExist(graph,vertice)){
        return;
    }
    
    int position = Graph_FindVerticePosition(graph,vertice);
    struct SLL_Node* listOfEdges = graph->edges[position];

    int n = SLL_GetListLen(listOfEdges);
    for(int i = 0;i<n;i++){
        //LHS: First we go to the array of edge lists and get the value of the ith node in the Vertice list to be deleted
        //RHS: Then we delete the position value from the ith list
        graph->edges[SLL_GetValue(listOfEdges,i+1)]=SLL_DeleteNode(graph->edges[SLL_GetValue(listOfEdges,i+1)],SLL_FindValue(graph->edges[SLL_GetValue(listOfEdges,i+1)],position));
    }
    SLL_DeleteList(listOfEdges);
    graph->edges[position] = NULL;
    graph->vertices[position]=0;
}


//Deletes 1 edge, between 2 vertices passed. If the edge doesn't exist, nothing happens
void Graph_DeleteEdge(struct Graph* graph, TYPEOFGRAPH node1, TYPEOFGRAPH node2){

    if(!Graph_IsThereEdge(graph,node1,node2)){
        return;
    }
    int address[2]={Graph_FindVerticePosition(graph,node1),Graph_FindVerticePosition(graph,node2)}; 

    graph->edges[address[0]]=SLL_DeleteNode(graph->edges[address[0]],SLL_FindValue(graph->edges[address[0]],address[1]));
    graph->edges[address[1]]=SLL_DeleteNode(graph->edges[address[1]],SLL_FindValue(graph->edges[address[1]],address[0]));
}
