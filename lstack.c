//FILE: lstack.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "lstack.h"

//initLStack
//PRE:
//POST:
void initLStack(LStack* stack) {
  (*stack).count = INIT;
}

//getLStackCount
//PRE:
//POST:
int getLStackCount(LStack* stack) {
  return (*stack).count;
}

//getTopLStack
//PRE:
//POST:
int getTopLStack(LStack* stack) {
  if (getLStackCount(stack) == 0) {
    return EMPTY_LSTACK;
  }
  return (*stack).stackItem[((*stack).count)-1];
}

//pushLStack
//PRE:
//POST:
int pushLStack(LStack* stack, int pushItem) {
  if ((*stack).count < LSTCK_ITM_MAX) {
    (*stack).stackItem[(*stack).count] = pushItem;
    (*stack).count++;
    return BOOL_TRUE;
  }
  else {
    return BOOL_FALSE;
  }
}


//popLStack
//PRE:
//POST:
int popLStack(LStack* stack) {
  int popItem;
  if ((*stack).count > 0) {
    popItem = (*stack).stackItem[(*stack).count - 1];
    (*stack).count--;
    return popItem;
  }
  else {
    return -1;
  }
}

//printLStack
//pre:
//post:
void printLStack(LStack* stack) {
  int i;
  printf("\n\t\tPrinting Stack\n");
  for(i = 0; i < (*stack).count; i++) {
    printf("\n\tStack Element %d: %d\n", i, (*stack).stackItem[i]);
  }
  printf("\n\t\tDone Printing Stack\n");
}
