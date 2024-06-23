#ifndef DOUBLYLINKEDLISTS_H
#define DOUBLYLINKEDLISTS_H

#include <stdlib.h>
#include <stdio.h>

// Doubly Linked List
struct DLL_Node {
    struct DLL_Node* prev;
    int data;
    struct DLL_Node* next;
};

//Traverses List and performs function of peogammer's choice on the value in the node. The function must have void return type, and take void* and integer(the integer in the list being traversed). You also pass in a void * variable that will passed into the function
void DLL_ListTraversal(struct DLL_Node* head, void (*func)(void*, int), void* var);

//Returns Value at nth Node
int DLL_GetValue(struct DLL_Node* head, int position);

//Returns Address of nth Node
struct DLL_Node* DLL_GetAddress(struct DLL_Node* head, int position);

// Returns Position of Value passed in. If Value isn't found, 0 is returned
int DLL_FindValue(struct DLL_Node* head,int value);

//Returns Pointer to First Node from any point in list
struct DLL_Node* DLL_FindHead(struct DLL_Node* node);

//Returns Pointer to Last Node from any point in list
struct DLL_Node* DLL_FindTail(struct DLL_Node* node);

//Deletes Node of programmer's choice. Pass in the position to choose. To delete last node, pass in -1
struct DLL_Node* DLL_DeleteNode(struct DLL_Node* head, int position);

//Recursively frees list from memory
void DLL_DeleteList(struct DLL_Node* head);

//Inserts Node at a Position of Programmer's choice. Indexing starts at 1. You can pass in -1 to insert node at the end
struct DLL_Node* DLL_Insert(struct DLL_Node* head, int data, int position);

//Returns List Length
int DLL_GetListLen(struct DLL_Node* head);

//Checks if list is Empty
int DLL_isListEmpty(struct DLL_Node* head);

//Prints a string of progrmmer's choice and then the list to output stream
void DLL_PrintList(struct DLL_Node* head, const char* string, FILE* destination);

//Prints a string of progrmmer's choice and then the list in reverse order to output stream
void DLL_ReversePrintList(struct DLL_Node* head, const char* string, FILE* destination);

#endif