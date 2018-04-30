//FILE: executor.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "ehelper.h"
#include "fileHandler.h"
#include "object.h"
#include "core.h"
#include "literal.h"
#include "range.h"
#include "lstack.h"
#include "astack.h"

#include "edim.h"
#include "eread.h"
#include "ewrite.h"
#include "estop.h"
#include "ecdump.h"
#include "elisto.h"
#include "enop.h"
#include "egoto.h"
#include "eifa.h"
#include "earead.h"
#include "eawrite.h"
#include "esubp.h"
#include "eloopend.h"
#include "eloop.h"
#include "elread.h"
#include "elwrite.h"
#include "eif.h"
#include "ecls.h"
#include "eassignment.h"

/*
***GLOBAL VARIABLES
*/

Flag rFlag, xFlag, zFlag, eFlag, sFlag;

int pc;

/*
*** FN PROTOTYPES
*/
int initE (RangePtr rangePtr, int* argc, char* argv[], char* objFileNm, char* coreFileNm, char* litFileNm, FILE** objFile, FILE** coreFile, FILE** litFile,
CorePtr corePtr, ObjectPtr objPtr, LiteralPtr litPtr, LStackPtr lstackPtr);

void initFlags(void);

int handleECmdLn(int* argc, char* argv[], char* inputFileName);

void prntTerminateMsg(void);


#endif
