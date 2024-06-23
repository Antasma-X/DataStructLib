#ifndef STACKS_H
#define STACKS_H

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
struct Stack* createStack(unsigned int lengthOfArray);

//Pushes Value into Stack. If Stack is full, realloc has to be used. So the return thpe is a pointer. If you're confident the stack won't overflow, you don't need to store the returned value
struct Stack* Push(struct Stack* stack, TYPEOFSTACK data);

//Checks if Stack is Empty
int Stack_isEmpty(struct Stack* stack);

//Returns Value at top of stack
TYPEOFSTACK Top(struct Stack* stack);

//Removes Value at top of stack and returns it
TYPEOFSTACK Pop(struct Stack* stack);

//Frees Stack
void deleteStack(struct Stack* stack);

//Checks if brackets is proper (type of stack has to be char)
int isBrackets(char brackets[]);

//Reverses string passed in. (Original String is Replaced)
char* reverseString(char* string);

#endif