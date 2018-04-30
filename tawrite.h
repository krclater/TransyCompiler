//FILE: tawrite.h
//Kelsey Clater
//CS3024
//Fall 2017

#ifndef TAWRITE_H
#define TAWRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tawrite
//precondition: currentLine contains AWRITE in the first six characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tawrite(char* currentLine, SymbolTable* st, FILE* objFile);

//writeAwriteObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeAwriteObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, FILE* objFile);

#endif
