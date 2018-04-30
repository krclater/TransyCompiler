//tstop.c
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#include "tstop.h"

//tstop
//precondition: currentLine contains STOP in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tstop (char* currentLine, FILE* objFile) {
  int offsetIndex = 4;
  if (strlen(currentLine) != 4) {
    printf("\n\t%d ERROR: UNRECOGNIZED STOP COMMAND\n", srcLnNum);
    eFlag = BOOL_TRUE;
  }
  writeStopObjCode(objFile);
}

//writeStopObjCode
//precondition:
//postcondition: objFile holds the corresponding object code for currentLine
void writeStopObjCode(FILE* objFile) {
	fprintf(objFile, "%d\n", STOP);
}
