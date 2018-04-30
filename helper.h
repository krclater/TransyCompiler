//FILE: helper.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//
//

#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"

//global
extern int srcLnNum;

/*
*** Type definitions
*/

typedef struct {
	char varName[VAR_NAME_MAX];
	int varSize;
} ArrayVarNameAndSize;

typedef int Flag;

#include "symbolTable.h" //for proper linking purposes

/*
*** TREAD/TWRITE functions
*/

//checkRestOfLine
//precondition: currentLine contains READ or WRITE in the first serveral characters
//postcondition: currentLieVar contains all viable variables found on currentLine, varLineCount contains the number of viable variables
  //returns 1 if no errors were found, returns if errors were found
int checkRestOfLine(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, int offsetIndex, SymbolTable* st);

/*
*** TAREAD/TAWRITE Functions
*/

//checkRestOfAreadAwriteLine
//precondition: currentLine contains AREAD or AWRITE in the first serveral characters
//postcondition: currentLieVar contains all viable variables found on currentLine, varLineCount contains the number of viable variables
  //returns 1 if no errors were found, returns if errors were found
int checkRestOfAreadAwriteLine (char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* st);

/*
*** Other Functions
*/

//isID
//PRE:
//POST:
int isID(char* temp);

//addArrayVar
//precondition: varName holds a name of an array, varSize holds the array size
//postcondition: returns 0 if there werer less than 7 variables in currentLineVar and varName was not added to currentLineVar, else returns 1
int addArrayVar(char* varName, int varSize, int* index, ArrayVarNameAndSize* currentLineVar);

//isVar
//precondition: potentialVar contains a string
//postcondition: returns 1 if potentialVar contained a valid variable, else returns 0
int isVar(char* potentialVar);

//isLineLabel
//precondition: potentialLnLbl contains a string
//postcondition: returns 1 if potentialLnLbl contained a valid line label, else returns 0
int isLnLbl (char* potentialLnLbl);

//errorHandler
//precondition: errorCommand holds a constant that corresponds to an error type
//postcondition: a unique error message is printed
void errorHandler(int errorCommand);

//getSrcLnNum
//precondition: objIndex contains an object code line number
//postcondition: returns the source line number that corresponds to the object code line number
int getSrcLnNum(int* objLnSrcLn, int objIndex);

//getVar
//precondition:strlen of delims is 0 or 1, offset contains the intial index with which to look in currentLine
//postcondition: returns 1 if a valid var is found, validVar contains a valid variable if found
int getVar(char* currentLine, int* offset, char delim, char* validVar);

//getLnLbl
//precondition:strlen of delim is 0 or 1, offset contains the intial index with which to look in currentLine
//postcondition: returns 1 if a valid var is found, validVar contains a valid variable if found
int getLnLbl(char* currentLine, int* offset, char delim, char* validLnLbl);

//getInt
//precondition:strlen of delims is 0 or 1, offset contains the intial index with which to look in currentLine
//postcondition: returns 1 if a valid integer str is found, validInt contains a valid integer str if found
int getInt (char* currentLine, int* offset, char delim, char* validInt);

//isInt
//precondition: temp contains a potential string of digits, base contains the base in which the integer value of the string is in
//postcondition: returns 1 if temp contains a valid base ten integer, otherwise returns 0
int isInt (char* temp, int base);

//isFloat
//precondition: temp contains a potential float string, base contains the base in which the integer value of the string is in
//postcondition: returns 1 if temp contains a valid base ten integer, otherwise returns 0int isFloat(char* temp, int base) {
int isFloat (char* temp, int base);

//getOp
//precondition: offset contains the initial index for which to begin looking for an operation, delim contains a deliminater, *op contains 0
//postcondition: if a valid operation was found on the line starting at the offset to the delimiter, *op is set to the corresponding operation object code
void getOp(char* currentLine,  int* offset, char delim, int* op);

//isOp
//precondition: tempOp contains a potential operation
//postcondition: if a valid operation was found, the corresponding obj code for that op is returned, else 0 is returned
int isOp(char* tempOp);

//getId
//precondition:
//postcondition:
int getId(char* currentLine, int* offset, char delim, char* validId);

//getIfId1
//precondition: offset contains the intial index with which to begin looking in currentLine, *op is zero
//postcondition, *op holds the obj code of the operation found, if no valid operation was found, *op holds 0, validId contains a validId if found, returns 1 if no errors were found, otherwise returns 0
int getIfId1(char* currentLine, int* offset, int* op, char* validId);



#endif
