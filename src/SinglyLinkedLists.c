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
struct SLL_Node* SLL_CreateNewNode(TYPEOFLIST data){
    struct SLL_Node* newNode= (struct SLL_Node*) malloc(sizeof(struct SLL_Node));
    if (newNode == NULL) return NULL;
    newNode->data=data; 
    newNode-> next=NULL;
    return newNode;
}

//Traverses List and performs function of progammer's choice on the value in the node. The function must have void return type, and take void* and the data type of the list(the data will be the data from the list). You also pass in a void * variable that will passed into the function
void SLL_ListTraversal(struct SLL_Node* head, void (*func)(void*, TYPEOFLIST), void* var){

    while (head->next != NULL){
        func(var,head->data);
        head=head->next;
    }
}

//Returns Value at nth Node
TYPEOFLIST SLL_GetValue(struct SLL_Node* head, int position){

    for (int i=0;i<position-1;i++){
        head=head->next;
    }

    return head -> data;
}

//Returns Address of nth Node
struct SLL_Node* SLL_GetAddress(struct SLL_Node* head, int position){
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
int SLL_FindValue(struct SLL_Node* head,TYPEOFLIST value){
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

//Deletes Node of programmer's choice. Pass in the position to choose. To delete last node, pass in -1
struct SLL_Node* SLL_DeleteNode(struct SLL_Node* head, int position){
    struct SLL_Node* temp;
    if (position==-1){
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    else if (position ==1){
        temp=head->next;
        free(head);
        head=temp;
    }else {
        struct SLL_Node* current = head;
    for(int i=0;i<position-2;i++){
        current=current ->next;
    }
    temp=current->next->next;
    free(current->next);
    current->next=temp;
    
    }
    return head;
}

//Gets Length of List
int SLL_GetListLen(struct SLL_Node* head){
    int i=0;
    while (head != NULL){
        head=head -> next;
        i++;
    }
    return i;

}

//Checks if List is Empty
int SLL_isListEmpty(struct SLL_Node* head){
    if (head==NULL) return 1;
    return 0;
}

// Iteratively Reverses List
struct SLL_Node* SLL_ReverseIterative(struct SLL_Node* head){

    if(head==NULL){
        return head;
    }

    struct SLL_Node* prev = NULL;
    struct SLL_Node* current = head;
    struct SLL_Node* after = head->next;

    while(after !=NULL){
        current->next=prev;
        prev=current;
        current=after;
        after=current->next;
    }
    current->next=prev;
    return current;

}

//Recursively Reverses List
struct SLL_Node* SLL_ReverseRecursive(struct SLL_Node* current){

    struct SLL_Node* head;
    if (current->next==NULL){
        head=current;
        return head;
    }

    head=SLL_ReverseRecursive(current->next);
    struct SLL_Node* temp= current -> next;
    temp-> next=current;
    current -> next= NULL;
    return head;

}

//Recursively frees List from Memory
void SLL_DeleteList(struct SLL_Node* head){
    if (head==NULL){
        return;
    }
    if (head->next!=NULL){
        SLL_DeleteList(head->next);
    }
    free(head);
}

//Inserts Node at a Position of Programmer's choice. Indexing starts at 1. You can pass in -1 to insert node at the end
struct SLL_Node* SLL_Insert(struct SLL_Node* head, TYPEOFLIST data, int position){
    struct SLL_Node* newNode= SLL_CreateNewNode(data);

     if (head==NULL){
        head=newNode;
    }else if (position==-1){
        struct SLL_Node* current = head;
        while(current->next != NULL ){
            current=current-> next;
        }
        current->next= newNode;
    }else if (position==1){
        newNode -> next = head;
        head=newNode;
        return head;
    }else {
        struct SLL_Node* current = head;
        for(int i=0;i<position-2;i++){
            current=current->next;
        }
        struct SLL_Node* temp = current->next;
        current->next=newNode;
        newNode->next=temp;
    }
    return head;
   
}

//Recursively Prints List (This will only work if TYPEOFLIST is int. I can support generics but I'd rather kms)
void ReversePrintUtil(struct SLL_Node* head,FILE* destination){
    if (head==NULL) {
        return;
    }
    ReversePrintUtil(head->next,destination);
    fprintf(destination,"%d ",head->data);
}

//Prints a string of progrmmer's choice and then the list in reverse order to output stream (Recursive)
void SLL_ReversePrintList(struct SLL_Node* head, const char* string,FILE* destination){
    fprintf(destination,"%s",string);
    ReversePrintUtil(head,destination);
    fprintf(destination,"\n");

}

//Prints a string of progrmmer's choice and then the list to output stream (This will only work if TYPEOFLIST is int. I can support generics but I'd rather kms)
void SLL_PrintList(struct SLL_Node* head, const char* string, FILE* destination){
    fprintf(destination,"%s",string);
    while (head != NULL){
        fprintf(destination,"%d ",head->data);
        head=head->next;
    }
    fprintf(destination,"\n");
}

//Returns a pointer to an array of values in Linked List. To get size of array, use SLL_GetListLen() function on list
TYPEOFLIST* SLL_ConvertToArray(struct SLL_Node* head){
    unsigned int len = SLL_GetListLen(head);
    TYPEOFLIST* array = (TYPEOFLIST*) malloc(len*sizeof(TYPEOFLIST));

    for(int i = 0;i<len;i++){
        array[i]=SLL_GetValue(head,i+1);
    }
    return array;
}
