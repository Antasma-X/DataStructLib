#include "../includes/SinglyLinkedLists.h"
#include <stdlib.h>
#include <stdio.h>

#define TYPEOFLIST int
#define TYPEOFQUEUE TYPEOFLIST 


struct Queue{
    struct SLL_Node* head;
    struct SLL_Node* tail;
};

//Creates new Queue and returns pointer to queue
struct Queue* createQueue(){
    struct Queue* newQueue = (struct Queue*) malloc(sizeof(struct Queue));
    newQueue -> head = NULL;
    newQueue -> tail = NULL;
    return newQueue;
}

//Pushes value to end of queue
void Q_Push(struct Queue* queue, TYPEOFLIST data){
    struct SLL_Node* newNode= SLL_CreateNewNode(data);

    if (queue->head==NULL){
        queue->head=newNode;
        queue->tail=newNode;
    }
    else{
        queue->tail->next=newNode;
        queue->tail=newNode;
    }
}

//Removes Value from front of queue and returns it
TYPEOFQUEUE Q_Pop(struct Queue* queue){
    if(queue->head==NULL){
        printf("Queue is Empty \n");
        return 0;
    }

    TYPEOFQUEUE temp=queue -> head -> data;
    queue->head=SLL_DeleteNode(queue->head,1);
    return temp;
}

//Returns Value at front of queue
TYPEOFQUEUE Q_Front(struct Queue* queue){
    if(queue->head == NULL){
        printf("Queue is empty \n");
        return 0;
    }
    return queue->head->data;
}

//Checks if Queue is empty
int Q_IsEmpty(struct Queue* queue){
    if (queue->head==NULL){
        return 1;
    }
    return 0;
}

//Frees queue from memory
void Q_Delete(struct Queue* queue){

    SLL_DeleteList(queue->head);
    free(queue);

}


