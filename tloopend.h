//tloopend.h
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#ifndef TLOOPEND_H
#define TLOOPEND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//GLOBALS
extern Flag eFlag;
extern int srcLnNum;

//tloopend
//precondition: currentLine contains LOOP-END in the first eight characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tloopend (char* currentLine, FILE* objFile);

//writeLoopendObjCode
//precondition:
//postcondition: objFile holds the corresponding object code for currentLine
void writeLoopendObjCode(FILE* objFile);

#endif
