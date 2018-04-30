//tstop.h
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#ifndef TSTOP_H
#define TSTOP_H

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

//tstop
//precondition: currentLine contains STOP in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tstop (char* currentLine, FILE* objFile);

//writeStopObjCode
//precondition: 
//postcondition: objFile holds the corresponding object code for currentLine
void writeStopObjCode(FILE* objFile);

#endif
