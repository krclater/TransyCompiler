//FILE: tdim.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef TDIM_H
#define TDIM_H

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

//tdim
//precondition: currentLine contains DIM in the first three characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tdim(char* currentLine, SymbolTable* st, FILE* objFile);

//checkRestOfDimLine
//precondition: currentLine contains DIM in the first three characters
//postcondition: currentLineVar holds all viable var names and var sizes found on currentLine, varLineCount holds number of vars found, 
  //if an error was found, return 1, else return 0
int checkRestOfDimLine(char* currentLine, ArrayVarNameAndSize* currentLineVar, int* varLineCount, int offsetIndex, SymbolTable* st); 

//isArray
//precondition: tempArray holds a potential array variable
//postCondition: tempVar holds the name of the array, tempSizeString holds the size of the array as chars, tempSize holds the size of the array as an int,
  //returns 1 if tempArray was valid format, else returns 0
int isArray(char* tempArray, char* tempVar, char* tempSizeString, int* tempSize);

//isValidArrayInt
//precondition: tempSize contains an int
//postcondition: returns 1 if 0 < tempSize <= 1000, else returns 0
int isValidArrayInt(int tempSize);

//writeDimObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeDimObjectCode(char* currentLine, ArrayVarNameAndSize* currentLineVar, int* varLineCount, SymbolTable* st, FILE* objFile);

#endif
