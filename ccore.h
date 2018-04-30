//FILE: ccore.c
//Kelsey Clater
//CS3024
//Fall 2017

#ifndef CCORE_H
#define CCORE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "helper.h"

/*typedefs*/
typedef char Core[CORE_ARRAY_MAX][DBL_STR_MAX];

//global variable
extern Core core;
extern Flag eFlag;

/*fn prototypes*/
//initCore
//precondition:
//postcondition:
void initCore(void);

//insertIntoCore
//precondition:
//postcondition:
void insertIntoCore(int index, char* strValue);

//fprintfCore
//precondition:
//postcondition:
void saveCore(FILE* coreFile);

//setLastCore
//precondition:
//postcondition:
void setLastCore(void);

#endif

