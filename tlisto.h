//tlisto.c
//Kelsey Clater
//CS3024 Fall 2017
//
//
//if(var op var) then linelbl

#ifndef TLISTO_H
#define TLISTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;
extern int srcLnNum;

//tlisto
//precondition: currentLine contains LISTO in the first five characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tlisto (char* currentLine, FILE* objFile);

//writeListoObjCode
//precondition: 
//postcondition: objFile holds the corresponding object code for currentLine
void writeListoObjCode(FILE* objFile);
 

#endif
