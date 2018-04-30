//lstack.h
//Kelsey Clater
//CS3024 
//Fall 2017
//
//
//

#ifndef LSTACK_H
#define LSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"


//TYPEDEFS AND STRUCT DEFS
typedef struct {
  int count;
  int stackItem[LSTCK_ITM_MAX];
}LStack;

typedef LStack* LStackPtr;

//FNS
void initLStack(LStack* stack);

int getLStackCount(LStack* stack);

int getTopLStack(LStack* stack);

int pushLStack(LStack* stack, int pushItem);

int popLStack(LStack* stack);

void printLStack(LStack* stack);

#endif
