//FILE:tcdump.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TCDUMP_H
#define TCDUMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tcdump
//precondition:the first 5 chars of currentLine contain the command "CDUMP"
//postcondition:if an error was found, errorFlag is true and an error message was printed to the screen
void tcdump(char* currentLine, SymbolTable* st, FILE* objFile);

//checkRestOfCdumpLine
//precondition: currentLine holds CDUMP in first 5 chars
//postcondition: varLineCount holds 2, currentLineVars holds the names of the valid ids found, returns 1 if no errors were found, returns 0 otherwise
int checkRestOfCdumpLine(char* currentLine, SymbolTable* st, int offsetIndex, int* varLineCount, char (*currentLineVars)[VAR_NAME_MAX]);

//writeCdumpObjCode
//precondition: the first 5 chars of currentLine contain the command "CDUMP"
//postcondition: the appropriate object code for currentLine is written in objFile
void writeCdumpObjCode(char* currentLine, SymbolTable* st, FILE* objFile, int* varLineCount, char(*currentLineVars)[VAR_NAME_MAX]);


#endif
