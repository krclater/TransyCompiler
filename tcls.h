//FILE:tcls.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TCLS_H
#define TCLS_H

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

//tcls
//precondition:the first 3 chars of currentLine contain the command "CLS"
//postcondition:if an error was found, errorFlag is true and an error message was printed to the screen
void tcls(char* currentLine,  FILE* objFile);

//writeClsObjCode
//precondition:
//postcondition: the appropriate object code for CLS is written to .obj file 
void writeClsObjCode(FILE* objFile);

#endif
