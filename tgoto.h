//tgoto.h
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#ifndef TGOTO_H
#define TGOTO_H

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

//tgoto
//precondition: currentLine contains GOTO in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tgoto (char* currentLine, SymbolTable* llt, FILE* objFile);

//chestRestOfGotoLine
//precondition: currentLine contains GOTO in the first four characters
//postcondition: currentLineVar holds all viable line labels names found on currentLine, varLineCount holds 0 or 1, if an error was found, return 1, else return 0
int checkRestOfGotoLine(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, int offsetIndex, SymbolTable* llt);

//writeGotoObjectCode
//precondition: currentLineVar contains the name of all viable line label names found on currentLine, varLineCount holds 0 or 1
//postcondition: objFile holds the corresponding object code for currentLine
void writeGotoObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* llt, FILE* objFile);

#endif
