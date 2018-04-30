//tgoto.c
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#include "tgoto.h"

//tgoto
//precondition: currentLine contains GOTO in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tgoto (char* currentLine, SymbolTable *llt, FILE* objFile) {
  int offsetIndex = 4, successfulGoto = 0, varLineCount = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  successfulGoto = checkRestOfGotoLine(currentLine, currentLineVar, &varLineCount, offsetIndex, llt);
  if (successfulGoto == BOOL_FALSE) { //an error has already been found
	eFlag = BOOL_TRUE;
  }
  writeGotoObjCode(currentLine, currentLineVar, &varLineCount, llt, objFile);
}

//chestRestOfGotoLine
//precondition: currentLine contains GOTO in the first four characters
//postcondition: currentLineVar holds all viable line labels names found on currentLine, varLineCount holds 0 or 1, if an error was found, return 1, else return 0
int checkRestOfGotoLine(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, int offsetIndex, SymbolTable* llt) {
  char currentChar;
  int i = 0;
  char tempVar[VAR_NAME_MAX];
  currentChar = currentLine[offsetIndex];

  while(currentChar != '\0') { 
  //get linelabel
    tempVar[i] = currentChar;
    i++;
    currentChar = currentLine[++offsetIndex];
  }
  tempVar[i] = '\0';

  if(lookup(llt, tempVar) < 0) { 
  //check if linelabel is in llt
		printf("\n%d ERROR: UNIDENTIFIED LINE LABEL\n", srcLnNum);
    return BOOL_FALSE;
  }
  strcpy(currentLineVar[*varLineCount], tempVar);
  (*varLineCount)++;

  return BOOL_TRUE;
}

//writeGotoObjectCode
//precondition: currentLineVar contains the name of all viable line label names found on currentLine, varLineCount holds 0 or 1
//postcondition: objFile holds the corresponding object code for currentLine
void writeGotoObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* llt, FILE* objFile) {
  fprintf(objFile, "%d ", GOTO);
  int lnLblObjLn = lookup(llt, currentLineVar[0]);
  fprintf(objFile, "%d\n", lnLblObjLn);
}
