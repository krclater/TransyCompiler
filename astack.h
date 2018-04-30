//astack.h
//Kelsey Clater
//CS3024
//FALL 2017
//
//

#ifndef ASTACK_H
#define ASTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"


//TYPES DEFS AND STRUCT DEFS
typedef struct {
  double val;
  char type;
}AStackItem;

typedef struct {
  int count;
  AStackItem stackItem[LSTCK_ITM_MAX];
}AStack;

typedef AStack* AStackPtr;

//FNS
void initAStack(AStack* stack);

int getLAtackCount(AStack* stack);

int getTopAStack(AStack* stack);

int pushAStack(AStack* stack, double pushItem, char type);

int popAStack(AStack* stack, double* popItem, char* type);

void printAStack(AStack* stack);


#endif
