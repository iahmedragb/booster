#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

//Compiler libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//User-defined macros
#define SIZE 20
#define TYPE uint8_t
//Structure of the stack
typedef struct{
    TYPE *item;
    int8_t top;
    uint8_t Size;
}STACK;
//Functions Prototypes
void init(STACK *ptr ,uint8_t );    //initialize the stacks by (allocating memory) and set (top = -1)
void push(STACK *ptr ,TYPE value);  //check if the stack is not overflow then push a value to the top of the stack then increment the top
TYPE pop(STACK *ptr);               //check if the stack is not underflow then pop a value from the top of the stack then decrement the top
void deallocate(STACK *);           //free the memory of the stack
TYPE* balancedParentheses(TYPE *);    //check for a balanced or non-balanced expression


#endif // MYSTACK_H_INCLUDED
