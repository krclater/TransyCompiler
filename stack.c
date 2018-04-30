//stack.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "stack.h"

//initStack
//pre: 
//post: stack.count will equal 0
void initStack(Stack* stack) {
  (*stack).count = INIT;
}

//getStackCount
//pre:
//post: will return stack.count
int getStackCount(Stack* stack) {
  return (*stack).count;
}

//getTopStack
//pre:
//post:
void getTopStack(Stack *stack, char* topStack) {
  strcpy(topStack,(*stack).stackItem[((*stack).count)-1]);
}

//copyStackToArray
void copyStackToArray(Stack *stack, char (*array)[VAR_NAME_MAX]) {
  int i;
  for(i = 0; i < (*stack).count; i++) {
    strcpy(array[i], (*stack).stackItem[i]);
  }
}

//pushStack
//pre:
//post: will return 1 if pushItem was successfully pushed onto stack, else will return 0
int pushStack(Stack* stack, char* pushItem) {
  if ((*stack).count < STCK_ITM_MAX) {
    strcpy((*stack).stackItem[(*stack).count], pushItem);
    (*stack).count++;
    return BOOL_TRUE;
  }
  else {
    return BOOL_FALSE;
  }
}

//popStack
//pre:
//post: will return 1 if an item was successfully popped off stack, popItem holds the item that was popped off, else will return 0
int popStack(Stack* stack, char* popItem){
  if ((*stack).count > 0) {
    strcpy(popItem, (*stack).stackItem[(*stack).count - 1]);
    (*stack).count--;
    return BOOL_TRUE;
  }
  else {
    return BOOL_FALSE;
  }
}

//printStack
//pre:
//post:
int printStack(Stack* stack) {
  int i;
  printf("\n\t\tPrinting Stack\n");
  for(i = 0; i < (*stack).count; i++) {
    printf("\n\tStack Element %d: %s\n", i, (*stack).stackItem[i]);
  }
  printf("\n\t\tDone Printing Stack\n");
}
