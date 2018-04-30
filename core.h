//FILE: core.h
//Kelsey Clater
//CS3024
//Fall 2017

#ifndef CORE_H
#define CORE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "ehelper.h"

/*typedefs*/
typedef char Core[CORE_ARRAY_MAX][DBL_STR_MAX];

typedef Core* CorePtr;

//global variables
extern Flag zFlag, eFlag;
extern int pc;

/*fn prototypes*/

//loadCore
//precondition: is passed in a file of .core type
//postcondition: the core file is filled with the contents of the core file, with the index of coreArray corresponding to the line of the core file, returns 0 if coreFile is empty 
int loadCore(CorePtr ptr, FILE* coreFile);

//printCore
//PRE:
//POST: prints coreArray to the screen
void printCore(CorePtr ptr);

//printCoreRange
//PRE:
//POST: prints coreArray to the screen within the specified range
int printCoreRange(CorePtr ptr, int start, int stop);

//getRVal
//PRE:
//POST:
double getRVal(CorePtr ptr, int i);

//insertRVal
//PRE:
//POST:
int insertRVal(CorePtr ptr, int i, double rValDbl);

//checkCompilation
//precondition:
//postcondition: returns the value of the last element of core which holds a 1 if compilation was successful and a 0 if compilation failed
int checkCompilation(CorePtr ptr);

#endif

