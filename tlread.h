//FILE: tlread.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TLREAD_H
#define TLREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"

//extern
extern Flag eFlag;

//tlread
//precondition: currentLine contains LREAD in the first five characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tlread (char* currentLine, SymbolTable* lt, FILE* objFile, FILE* litFile);

//checkRestOfLreadLine
//precondition: currentLine contains LREAD in the first five character, offsetIndex contains 5
//postcondition: currenLineVar contains a valid literal variable if found, lt contains the valid literal variable if found, a '\n' has been printed to the literal file if a valid literal variable was found 
int checkRestOfLreadLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* lt, FILE* litFile);

//writeLreadObjCode
//precondition: currentLineVar contains a valid literal variable if found, varLineCount contains 1
//postcondition: the corresponding object code for currentLine is written to the .obj file
void writeLreadObjCode(char(*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* lt, FILE* objFile);


#endif
