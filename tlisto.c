//tlisto.c
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#include "tlisto.h"

//tlisto
//precondition: currentLine contains LISTO in the first five characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tlisto (char* currentLine, FILE* objFile) {
  int offsetIndex = 5;
  if (strlen(currentLine) != 5) {
    printf("\n\t%d ERROR: UNRECOGNIZED LISTO COMMAND\n", srcLnNum);
    eFlag = BOOL_TRUE;
  }
  writeListoObjCode(objFile);
}

//writeListoObjCode
//precondition:
//postcondition: objFile holds the corresponding object code for currentLine
void writeListoObjCode(FILE* objFile) {
  fprintf(objFile, "%d\n", LISTO);
}
