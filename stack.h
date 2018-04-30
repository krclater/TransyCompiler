//stack.h
//Kelsey Clater
//CS3024 
//Fall 2017
//
//
//

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"

typedef struct {
  int count;
  char stackItem[LINE_CHAR_MAX][VAR_NAME_MAX];
}Stack;

//initStack
//pre: 
//post: stack.count will equal 0
void initStack(Stack* stack);

//getStackCount
//pre:
//post: will return stack.count
int getStackCount(Stack* stack);

//getTopStack
//pre:
//post:
void getTopStack(Stack *stack, char* topStack);

//copyStackToArray
//pre:
//post:
void copyStackToArray(Stack *stack, char (*array)[VAR_NAME_MAX]);

//pushStack
//pre:
//post: will return 1 if pushItem was successfully pushed onto stack, else will return 0
int pushStack(Stack* stack, char* pushItem);

//popStack
//pre:
//post: will return 1 if an item was successfully popped off stack, popItem holds the item that was popped off, else will return 0
int popStack(Stack* stack, char* popItem);

//printStack
int printStack(Stack* stack);

#endif
