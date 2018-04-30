//FILE: tnop.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tnop.h"

//tnop
//precondition: currentLine contains NOP in the first three characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tnop (char* currentLine, FILE* objFile) {
  int offsetIndex = 3;
  if (strlen(currentLine) != 3) {
    printf("\n\t%d ERROR: UNRECOGNIZED NOP COMMAND\n", srcLnNum);
    eFlag = BOOL_TRUE;
  }
  writeNopObjCode(objFile);
}

//writeNopObjCode
//precondition: 
//postcondition: objFile holds the corresponding object code for currentLine
void writeNopObjCode(FILE* objFile) {
  fprintf(objFile, "%d\n", NOP);
}
