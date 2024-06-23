#ifndef SINGLYLINKEDLISTS_H
#define SINGLYLINKEDLISTS_H


#include <stdlib.h>
#include <stdio.h>

//Put whatever type of list you want here
#define TYPEOFLIST int

//Singly Linked List
struct SLL_Node{
    TYPEOFLIST data;
    struct SLL_Node* next;
};

//Creates new node
struct SLL_Node* SLL_CreateNewNode(TYPEOFLIST data);

//Traverses List and performs function of progammer's choice on the value in the node. The function must have void return type, and take void* and the data type of the list(the data will be the data from the list). You also pass in a void * variable that will passed into the function
void SLL_ListTraversal(struct SLL_Node* head, void (*func)(void*, TYPEOFLIST), void* var);

//Returns Value at nth Node
TYPEOFLIST SLL_GetValue(struct SLL_Node* head, int position);

//Returns Address of nth Node
struct SLL_Node* SLL_GetAddress(struct SLL_Node* head, int position);

// Returns Position of Value passed in. If Value isn't found, 0 is returned
int SLL_FindValue(struct SLL_Node* head,TYPEOFLIST value);

//Deletes Node of programmer's choice. Pass in the position to choose. To delete last node, pass in -1
struct SLL_Node* SLL_DeleteNode(struct SLL_Node* head, int position);

//Gets Length of List
int SLL_GetListLen(struct SLL_Node* head);

//Checks if List is Empty
int SLL_isListEmpty(struct SLL_Node* head);

// Iteratively Reverses List
struct SLL_Node* SLL_ReverseIterative(struct SLL_Node* head);

//Recursively Reverses List
struct SLL_Node* SLL_ReverseRecursive(struct SLL_Node* current);

//Recursively frees List from Memory
void SLL_DeleteList(struct SLL_Node* head);

//Inserts Node at a Position of Programmer's choice. Indexing starts at 1. You can pass in -1 to insert node at the end
struct SLL_Node* SLL_Insert(struct SLL_Node* head, TYPEOFLIST data, int position);

//Prints a string of progrmmer's choice and then the list in reverse order to output stream (Recursive)
void SLL_ReversePrintList(struct SLL_Node* head, const char* string,FILE* destination);

//Prints a string of progrmmer's choice and then the list to output stream (This will only work if TYPEOFLIST is int. I can support generics but I'd rather kms)
void SLL_PrintList(struct SLL_Node* head, const char* string, FILE* destination);

//Returns a pointer to an array of values in Linked List. To get size of array, use SLL_GetListLen() function on list
TYPEOFLIST* SLL_ConvertToArray(struct SLL_Node* head);

#endif