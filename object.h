//FILE: object.h
//KELSEY CLATER
//CS3024
//FALL 2017

#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "ehelper.h"

/*
*** TYPE DEFS
*/

typedef int Object[LINE_MAX][LINE_CHAR_MAX];

typedef Object* ObjectPtr;

/*
*** GLOBALS
*/

extern Flag sFlag;

/*
*** FN PROTOTYPES
*/

int loadObj(ObjectPtr ptr, FILE* objFile);

void getObjLn(FILE** objFile, char currentCh, char* currentLn);

void parseObjLn(ObjectPtr ptr, char* currentLn, int* o);

void printObjArray(ObjectPtr ptr);

int endObj(ObjectPtr ptr, int i);

int retCmd(ObjectPtr ptr, int i);

int getObj(ObjectPtr ptr, int i, int j);

void checkLoopend(ObjectPtr ptr, int* next);

#endif
