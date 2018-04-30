//FILE: tlwrite.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TLWRITE_H
#define TLWRITE_H

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

//tlwrite
//precondition: currentLine contains LWRITE in the first six characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tlwrite (char* currentLine, SymbolTable* lt, FILE* objFile, FILE* litFile);

//checkRestOfLwriteLine
//precondition: currentLine contains LWRITE in the first six chars, offsetIndex holds the val 6
//postcondition: currenLineVar contains a valid literal variable or literal string if found, lt contains the valid literal variable or literal string if found, a '\n' has been printed to the literal file if a valid literal variable was or the literal string has been printed to the literal file if found
int checkRestOfLwriteLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* lt, FILE* litFile);


//writeLwriteObjCod
//precondition: currentLineVar contains a valid literal variable if found or currentLineVar contains a valid literal string if found, varLineCount contains 1
//postcondition: the corresponding object code for currentLine is written to the .obj file
void writeLwriteObjCode(char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* lt, FILE* objFile);

#endif
