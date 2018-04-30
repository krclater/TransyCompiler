//FILE: fileHandler.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//
//

#ifndef FILEHANDLER_C
#define FILEHANDLER_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

/*
*** Fn prototypes
*/

int isFileType(char* fileName, char* fileType);

int handleCInputFileName(char* tempFileName, char* inputFileName);

int handleEInputFileName(char* tempFileName, char* inputFileName);

void changeFileType (char* fileName, char* newType, char* newFileName);

int openCFiles(char* inputFileNm, char* noBlnksFileNm, char* objFileNm, char* coreFileNm, char* litFileNm, FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile);

void closeCFiles(FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile);

int openEFiles(char* objFileNm, char* coreFileNm, char* litFileNm, FILE** objFile, FILE** coreFile, FILE** litFile);

#endif
