//FILE:tsubp.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TSUBP_H
#define TSUBP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tsupb
//precondition: currentLine contains SUBP in the first four characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tsubp(char* currentLine, SymbolTable* st, FILE* objFile);

//checkRestOfSubpLine
//precondition: currentLine contains SUBP in the first four characters, offset contains 4, op is 0
//postcondition: varLineCount contains the number of valid vars found, op contains the operation obj code of the operation found or op contains 0, returns 1 is no errors were found, else returns 0
int checkRestOfSubpLine(char* currentLine, SymbolTable* st, int offsetIndex, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX]);

//writeSubpObjCode
//precondition: varLineCount contains the number of valid IDs found on currentLine, currentLineVar contains all valid IDs found on currentLine, op contains the object code for the operation found on currentLine, if no valid operation was found, op contains 0
//postcondition: writes the corresponding object code to .obj file for currentLine
void writeSubpObjCode(SymbolTable* st, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX], FILE* objFile);

#endif
