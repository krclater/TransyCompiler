//tloop.h
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#ifndef TLOOP_H
#define TLOOP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tloop
//precondition: currentLine contains LOOP in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tloop(char* currentLine, SymbolTable* st, FILE* objFile);

//checkRestOfLoopLine
//precondition: currentLine contains LOOP in the first four characters
//postcondition: currentLineVar holds all viable var names found on currentLine, varLineCount holds number of vars found, if an error was found, return 1, else return 0
int checkRestOfLoopLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* st);

//writeLoopObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeLoopObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, FILE* objFile);

#endif
