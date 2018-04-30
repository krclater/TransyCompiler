//FILE:tcls.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tcls.h"

//tcls
//precondition:the first 3 chars of currentLine contain the command "CLS"
//postcondition:if an error was found, eFlag is true and an error message was printed to the screen
void tcls(char* currentLine, FILE* objFile) {
  if (strlen(currentLine) != 3) {
    printf("\n\t%d ERROR: UNRECOGNIZED CLS COMMAND\n", srcLnNum);
    eFlag = BOOL_TRUE;
  }
  writeClsObjCode(objFile);
}

//writeClsObjCode
//precondition:
//postcondition: the appropriate object code for currentLine is written in objFile
void writeClsObjCode(FILE* objFile) {
  fprintf(objFile, "%d\n", CLS);
}

