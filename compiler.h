//compiler.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//	Header for transy compiler
//


#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileHandler.h"
#include "ccore.h"
#include "noblanks.h"
#include "symbolTable.h"
#include "constants.h"
#include "helper.h"


#include "tdim.h"
#include "tread.h"
#include "twrite.h"
#include "tstop.h"

#include "tcdump.h"
#include "tlisto.h"
#include "tnop.h"
#include "tgoto.h"

#include "tifa.h"
#include "taread.h"
#include "tawrite.h"
#include "tsubp.h"
#include "tloopend.h"
#include "tloop.h"
#include "tlread.h"
#include "tlwrite.h"
#include "tif.h"
#include "tcls.h"
#include "tassignment.h"

/*
***GLOBAL VARIABLE DECLARATIONS
*/

Core core;

Flag oFlag, nFlag, xFlag, eFlag;

int srcLnNum;

/*
*** FN PROTOTYPES
*/

//terminateC
//PRE:
//POST:
void terminateC(char* objFileNm, char* noBlnksFileNm, FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile);

//prntTerminateMsg
//PRE:
//POST:
void prntTerminateMsg(void);

//initC
//PRE:
//POST:
int initC(int* argc, char* argv[], char* inputFileNm, char* noBlnksFileNm, char* objFileNm, char* coreFileNm, char* litFileNm, FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile, SymbolTable* st, SymbolTable* llt, SymbolTable* lt);

//initFlags
//PRE:
//POST:
void initFlags(void);

//initSTs
//PRE:
//POST:
void initSTs(SymbolTable* st, SymbolTable* llt, SymbolTable* lt);

//handleCCmdLn
//PRE:
//POST:
int handleCCmdLn(int* argc, char* argv[], char* inputFileNm);

//flagHandler
//precondition: passes in argc, argv, and pointers to flags
//postcondition: if a flag was found on the command line, the appropriate flag is set to true. If an unrecognized flag was entered, flagHandler returns false
int flagHandler(int* argc, char* argv[], int* nFlag, int* oFlag);

//checkForCommand
//precondition: currentLine contains a (string) line from the noBlanksFile
//postCondition: returns a unique int depending on the command found in the first several characters of currentLine, returns -1 if no recognizable command was found
int checkForCommand (char* currentLine);

//changFileType
//precondition: fileName contains the old file name, newType contains the desired file type
//postcondition: newFileName contains the old fileName with the new file type concatenated to the root of fileName
void changeFileType (char* fileName, char* newType, char* newFileName);

//isFileType
//precondition: fileName contains the name of a file, fileType contains a file type
//postcondition: returns 1 if the file type of fileName matches fileType
int isFileType(char* fileName, char* fileType);

#endif
