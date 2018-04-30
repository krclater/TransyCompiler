//FILE: tawrite.c
//Kelsey Clater
//CS3024
//Fall 2017

#include "tawrite.h"

//tawrite
//precondition: currentLine contains AWRITE in the first six characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tawrite (char* currentLine, SymbolTable* st, FILE* objFile) {
  int offsetIndex = 6, varLineCount = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if(!checkRestOfAreadAwriteLine(currentLine, &varLineCount, currentLineVar, offsetIndex, st)) {
    eFlag = BOOL_TRUE;
  }
  writeAwriteObjCode(currentLine, currentLineVar, &varLineCount, st, objFile);
}

//writeAwriteObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeAwriteObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, FILE* objFile) {
  fprintf(objFile, "%d ", AWRITE);
  int i = 0;
  for (i=0; i<*varLineCount; ++i) {
    int currentVarMem = lookup(st, currentLineVar[i]);
    fprintf(objFile, "%d ", currentVarMem);
  }
  fprintf(objFile, "\n");
}
