//FILE: astack.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "astack.h"

//ASTACK
void initAStack(AStack* stack) {
  (*stack).count = INIT;
}

int getLAtackCount(AStack* stack){ 
  return (*stack).count;
}

int pushAStack(AStack* stack, double pushItem, char type){ 
	  if ((*stack).count < LSTCK_ITM_MAX) {
    (*stack).stackItem[(*stack).count].val = pushItem;
    (*stack).stackItem[(*stack).count].type = type;
    (*stack).count++;
    return BOOL_TRUE;
  }
  else {
    return BOOL_FALSE;
  }
}


int popAStack(AStack* stack, double* popItem, char* type){ 
  if ((*stack).count > 0) {
    *popItem = (*stack).stackItem[(*stack).count - 1].val;
    *type = (*stack).stackItem[(*stack).count - 1].type;
    (*stack).count--;
    return BOOL_TRUE;
  }
  else {
    return BOOL_FALSE;
  }
}


void printAStack(AStack* stack){ 
  int i;
  printf("\n\t\tPrinting Stack\n");
  for(i = 0; i < (*stack).count; i++) {
    printf("\n\tStack Element %d: %lf, %c\n", i, (*stack).stackItem[i].val, (*stack).stackItem[i].type);
  }
  printf("\n\t\tDone Printing Stack\n");
}
