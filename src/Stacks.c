#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Define what type of data you want
#define TYPEOFSTACK char

//Stack
struct Stack {
    int top;
    int length;
    TYPEOFSTACK data[];
};

//Creates a Stack and returns its value. You have to pass in the size of the stack. The size of the stack can change but it would be O(n)
struct Stack* createStack(unsigned int lengthOfArray){

    struct Stack* newStack= (struct Stack*) malloc(sizeof(struct Stack)+ (lengthOfArray * sizeof(TYPEOFSTACK)));
    if (newStack == NULL) return NULL;

    newStack -> length = lengthOfArray;
    newStack -> top = -1;
    return newStack;
}

//Pushes Value into Stack. If Stack is full, realloc has to be used. So the return thpe is a pointer. If you're confident the stack won't overflow, you don't need to store the returned value
struct Stack* Push(struct Stack* stack, TYPEOFSTACK data){

    //Reallocates memory if memory is full
    if ((stack->top) >= (stack->length)){
        struct Stack* newStack = (struct Stack*) realloc(stack, sizeof(struct Stack) + 2*(stack->length));

        if (newStack==NULL){
            printf("Overflow Error");
            return NULL;
        }
        else {
            stack = newStack;
        }
    }

    stack -> data[++(stack -> top)]=data;
    return stack;
}

//Checks if Stack is Empty
int Stack_isEmpty(struct Stack* stack){
    if (stack->top < 0){
        return 1;
    }
    return 0;
}

//Returns Value at top of stack
TYPEOFSTACK Top(struct Stack* stack){
    if (Stack_isEmpty(stack)){
        printf("Stack ks Empty \n");
        return 0;
    }
    return stack -> data[stack->top];
}

//Removes Value at top of stack and returns it
TYPEOFSTACK Pop(struct Stack* stack){
    if (Stack_isEmpty(stack)){
        printf("Stack is Empty \n");
        return 0;
    }

    (stack -> top)--;
    return stack ->data[(stack -> top)+1];
}

//Frees Stack
void deleteStack(struct Stack* stack){
    free(stack);
}

//Checks if brackets is proper (type of stack has to be char)
int isBrackets(char brackets[]){

    struct Stack* tempStack= createStack(strlen(brackets));
    for (int i =0;brackets[i] != '\0';i++){
        if (brackets[i]=='('){
        tempStack=Push(tempStack,'(');
        }
        else{
           if (Pop(tempStack) != '('){
           return 0;
           }
        }
    }

    if (Stack_isEmpty(tempStack)){
        deleteStack(tempStack);
        return 1;
    }
    
    deleteStack(tempStack);
    return 0;
}

//Reverses string passed in. (Original String is Replaced)
char* reverseString(char* string){
    struct Stack* tempStack = createStack(strlen(string));
    for(int i=0;string[i] != '\0';i++){
        tempStack = Push(tempStack,string[i]);
    }
    
    for(int i=0;i<strlen(string);i++){
        string[i]=Pop(tempStack);
    }

    free(tempStack);
    return string;
}




