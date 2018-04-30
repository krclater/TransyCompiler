//tread.c
//Kelsey Clater
//CS3024 Fall 2017
//
// Implementation of tread command
//

#include "tread.h"

//tread
//precondition: currentLine contains READ in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tread(char* currentLine, SymbolTable* st, FILE* objFile) {
  int offsetIndex = 4, varLineCount = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if(!checkRestOfLine(currentLine, currentLineVar, &varLineCount, offsetIndex, st)) {
    eFlag = BOOL_TRUE;
  }
  writeReadObjCode(currentLine, currentLineVar, &varLineCount, st, objFile);
}

//writeReadObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeReadObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, FILE* objFile) {
	fprintf(objFile, "%d ", READ);
	int i;
	for (i=0; i<*varLineCount; ++i) {
		int currentVarMem = lookup(st, currentLineVar[i]);
		fprintf(objFile, "%d ", currentVarMem);
	}
	fprintf(objFile, "\n");
}
