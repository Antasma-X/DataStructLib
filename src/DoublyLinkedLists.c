#include <stdlib.h>
#include <stdio.h>

// Doubly Linked List
struct DLL_Node {
    struct DLL_Node* prev;
    int data;
    struct DLL_Node* next;
};

//Traverses List and performs function of peogammer's choice on the value in the node. The function must have void return type, and take void* and integer(the integer in the list being traversed). You also pass in a void * variable that will passed into the function
void DLL_ListTraversal(struct DLL_Node* head, void (*func)(void*, int), void* var){

    while (head->next != NULL){
        func(var,head->data);
        head=head->next;
    }
}

//Returns Value at nth Node
int DLL_GetValue(struct DLL_Node* head, int position){

    for (int i=0;i<position-1;i++){
        head=head->next;
    }

    return head -> data;
}

//Returns Address of nth Node
struct DLL_Node* DLL_GetAddress(struct DLL_Node* head, int position){
    if(position==-1){
        while(head->next!=NULL){
            head=head->next;
        }

    }else if (position==1){
        
    } else{
    for(int i=0;i<position-1;i++){
        head=head->next;
    }

    }
    return head;
}

// Returns Position of Value passed in. If Value isn't found, 0 is returned
int DLL_FindValue(struct DLL_Node* head,int value){
    int i=0;
    while (head != NULL){
        i++;
        if(head->data==value){
            return i;
        }
        head=head->next;
    }
    return 0;
}

//Returns Pointer to First Node from any point in list
struct DLL_Node* DLL_FindHead(struct DLL_Node* node){

    while(node -> prev != NULL){
        node=node -> prev;
    }
    return node;
}

//Returns Pointer to Last Node from any point in list
struct DLL_Node* DLL_FindTail(struct DLL_Node* node){

    while (node->next != NULL){
        node = node -> next;
    }
    return node;
}

//Deletes Node of programmer's choice. Pass in the position to choose. To delete last node, pass in -1
struct DLL_Node* DLL_DeleteNode(struct DLL_Node* head, int position){
    struct DLL_Node* temp;
    if (position==-1){
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    else if (position == 1){
        temp= head -> next;
        free(head);
        temp -> prev= NULL;
        head=temp;
    }
    else {
        struct DLL_Node* current = head;
        for(int i = 0; i<position -2;i++){
            current=current -> next;
        }
        temp=current->next -> next;
        free(current -> next);
        temp -> prev = current;
        current -> next = temp;
    }
    
    return head;
}

//Recursively frees list from memory
void DLL_DeleteList(struct DLL_Node* head){
    if (head==NULL){
        return;
    }
    if (head->next!=NULL){
        DLL_DeleteList(head->next);
    }
    free(head);
}

//Inserts Node at a Position of Programmer's choice. Indexing starts at 1. You can pass in -1 to insert node at the end
struct DLL_Node* DLL_Insert(struct DLL_Node* head, int data, int position){
    struct DLL_Node* newNode = (struct DLL_Node*) malloc(sizeof(struct DLL_Node));
    if (newNode == NULL) return NULL;
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;

    if (head == NULL){
        head = newNode;
    }
    else if (position == -1){
        struct DLL_Node* current = head;
        while(current -> next != NULL){
            current=current -> next;
        }
        current -> next= newNode;
        newNode -> prev = current;
    }
    else if (position == 1){
        newNode ->next = head;
        newNode-> prev = NULL;
        head = newNode;

    }
    else{
        struct DLL_Node* current = head;
        for(int i=0;i<position-2;i++){
            current=current->next;
        }
        struct DLL_Node* temp = current->next;

        current->next=newNode;
        newNode -> prev = current;
        newNode->next=temp;
        temp -> prev = newNode;
    }
    return head;
}

//Returns List Length
int DLL_GetListLen(struct DLL_Node* head){
    int i=0;
    while (head->next != NULL){
        head=head -> next;
        i++;
    }
    return ++i;
}

//Checks if list is Empty
int DLL_isListEmpty(struct DLL_Node* head){
    if (head==NULL) return 1;
    return 0;
}

//Prints a string of progrmmer's choice and then the list to output stream
void DLL_PrintList(struct DLL_Node* head, const char* string, FILE* destination){
    fprintf(destination,"%s",string);    
    while (head != NULL){
        fprintf(destination,"%d ",head->data);
        head=head->next;
    }
    fprintf(destination,"\n");
}

//Prints a string of progrmmer's choice and then the list in reverse order to output stream
void DLL_ReversePrintList(struct DLL_Node* head, const char* string, FILE* destination){
    head= DLL_FindTail(head);

    fprintf(destination,"%s",string);    
    while (head != NULL){
        fprintf(destination,"%d ",head->data);
        head=head->prev;
    }
    fprintf(destination,"\n");
}
