//FILE: literal.h
//KELSEY CLATER
//CS3024
//FALL 2017

#ifndef LITERAL_H
#define LITERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

/*
*** TYPE DEFS
*/


typedef char Literal[LINE_MAX][LINE_CHAR_MAX];

typedef Literal* LiteralPtr;

/*
*** FN PROTOTYPES
*/

int loadLit(LiteralPtr ptr, FILE* litFile);

//getLit
//PRE:
//POST:
void getLit(LiteralPtr ptr, int i, char* tempLit);

void parseLitEsc(char* c);

//insertLit
//PRE:
//POST:
void insertLit(LiteralPtr ptr, int i, char* tempLit);

void printLit(LiteralPtr ptr);

int getLitColSize(LiteralPtr ptr);

#endif
