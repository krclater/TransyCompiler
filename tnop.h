//FILE: tnop.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TNOP_H
#define TNOP_H

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

//tnop
//precondition: currentLine contains NOP in the first three characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tnop (char* currentLine, FILE* objFile);

//writeNopObjCode
//precondition:
//postcondition: objFile holds the corresponding object code for currentLine
void writeNopObjCode(FILE* objFile);

#endif
