//FILE: tifa.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TIFA_H
#define TIFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tifa
//precondition: currentLine contains IFA in the first three characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tifa(char* currentLine, SymbolTable* st, SymbolTable* llt, FILE* objFile);

//checkRestOfIfaLine
//precondition: currentLine contains IFA in the first three characters
//postcondition: currentLineVar holds all viable var names found on currentLine, varLineCount holds number of vars found, if an error was found, return 1, else return 0
int checkRestOfIfaLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* st, SymbolTable* llt);

//writeIfaObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeIfaObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, SymbolTable* llt, FILE* objFile);

#endif
