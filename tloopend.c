//tloopend.c
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#include "tloopend.h"

//tloopend
//precondition: currentLine contains LOOP-END in the first eight characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tloopend (char* currentLine, FILE* objFile) {
  int offsetIndex = 8;
  if (strlen(currentLine) != 8) {
    printf("\n\t%d ERROR: UNRECOGNIZED LOOP-END COMMAND\n", srcLnNum);
    eFlag = BOOL_TRUE;
  }
  writeLoopendObjCode(objFile);
}

//writeLoopendObjCode
//precondition:
//postcondition: objFile holds the corresponding object code for currentLine
void writeLoopendObjCode(FILE* objFile) {
	fprintf(objFile, "%d\n", LOOPEND);
}
