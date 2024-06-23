#ifndef QUEUES_H
#define QUEUES_H

#include "SinglyLinkedLists.h"
#include <stdlib.h>
#include <stdio.h>

#define TYPEOFLIST int
#define TYPEOFQUEUE TYPEOFLIST 


struct Queue{
    struct SLL_Node* head;
    struct SLL_Node* tail;
};

//Creates new Queue and returns pointer to queue
struct Queue* createQueue();

//Pushes value to end of queue
void Q_Push(struct Queue* queue, TYPEOFLIST data);

//Removes Value from front of queue and returns it
TYPEOFQUEUE Q_Pop(struct Queue* queue);

//Returns Value at front of queue
TYPEOFQUEUE Q_Front(struct Queue* queue);

//Checks if Queue is empty
int Q_IsEmpty(struct Queue* queue);

//Frees queue from memory
void Q_Delete(struct Queue* queue);

#endif