//file: noblanks.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//	Header file for noblanks.c
//

#ifndef NOBLANKS_H
#define NOBLANKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "helper.h"
#include "symbolTable.h"


//noblanks
//precondition: inputFile points to a .transy file, outputFile points to a .noblanks file
//postcondition: objLnSrcLn contains an array that relates the source file lines to corresponding object file lines, errorFlag is set to true if an error was found, all line labels were removed and stored in llt, all comments, spaces, tabs, blanks lines were removed from the inputFile and result was stored in outputFile
void noblanks(FILE* inputFile, FILE* outputFile, int* objLnSrcLn, SymbolTable* llt);

#endif
