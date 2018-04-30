//FILE:tif.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TIF_H
#define TIF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tif
//precondition: currentLine contains IF in the first two characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tif(char* currentLine, SymbolTable* st, SymbolTable *llt, FILE* objFile);

//checkRestOfIfLine
//precondition: currentLine contains IF in the first two characters, offset index contains the initial index for which to begin parsing currentLine, op contains 0
//postcodition: if no errors were found, returns 1, varLineCount contains the number of valid ids found and currentLineVar contains all valid ids found, returns 0 otherwise
int checkRestOfIfLine(char* currentLine, SymbolTable* st, SymbolTable *llt, int offsetIndex, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX]);

//writeIfObjCode
//precondition: varLineCount contains the number of valid ids found on currentLin, currentLine var contains all valid ids found
//postcondition: the corresponding obj code for currentLine is written to objFile
void writeIfObjCode (SymbolTable* st, SymbolTable* llt, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX], FILE* objFile);

#endif
