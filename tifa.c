//FILE: tifa.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tifa.h"

//tifa
//precondition: currentLine contains IFA in the first three characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tifa(char* currentLine, SymbolTable* st, SymbolTable* llt, FILE* objFile) {
  int offsetIndex = 3, varLineCount = 0, successfulIfa = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  successfulIfa = checkRestOfIfaLine(currentLine, &varLineCount, currentLineVar, offsetIndex, st, llt);
  if(successfulIfa == BOOL_FALSE) {
    eFlag = BOOL_TRUE;
  }
  writeIfaObjCode(currentLine, currentLineVar, &varLineCount, st, llt, objFile);
}

//checkRestOfIfaLine
//precondition: currentLine contains IFA in the first three characters
//postcondition: currentLineVar holds all viable var names found on currentLine, varLineCount holds number of vars found, if an error was found, return 1, else return 0
int checkRestOfIfaLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* st, SymbolTable* llt) {
  char currentChar, tempVar[VAR_NAME_MAX];
  int i = 0; 
  currentChar = currentLine[offsetIndex];
  
  //printf("\n\tcurrentChar: %c\n", currentChar);
  if(currentChar != '(') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  ++offsetIndex;
  currentChar = currentLine[offsetIndex]; //skip open parentheses

  /* check id 1, can be any valid ID (var, pos int, neg int, pos float, neg float, 0) */

  while(currentChar != ')' && currentChar != '\0') {
    tempVar[i] = currentChar;
    ++i;
    ++offsetIndex;
    currentChar = currentLine[offsetIndex];
  }
  tempVar[i] = '\0';
  i = 0;

  if(currentChar != ')') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  if (isVar(tempVar)) {
    strcpy(currentLineVar[(*varLineCount)], tempVar);
    (*varLineCount)++;
    if(lookup(st, tempVar) < 0) {
      insertInto(st, tempVar, DOUBLE_VAR_SIZE);
    }
  }
  else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE; //temp is not var -> error
  }

  ++offsetIndex;
  currentChar = currentLine[offsetIndex]; //skip closing parantheses

  /* check id 2 */

  while(currentChar != ',' && currentChar != '\0') {
    tempVar[i] = currentChar;
    ++i;
    ++offsetIndex;
    currentChar = currentLine[offsetIndex];
  }
  tempVar[i] = '\0';
  i = 0;    
  
  if(currentChar != ','){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  if(lookup(llt, tempVar) < 0) { 
  //check if linelabel is in llt
    errorHandler(INVAL_ID);
    return BOOL_FALSE;
  }
  strcpy(currentLineVar[*varLineCount], tempVar);
  (*varLineCount)++;
  
  ++offsetIndex;
  currentChar = currentLine[offsetIndex]; //skip comma

  /* check id 3 */

  while(currentChar != ',' && currentChar != '\0') {
    tempVar[i] = currentChar;
    ++i;
    ++offsetIndex;
    currentChar = currentLine[offsetIndex];
  }
  tempVar[i] = '\0';
  i = 0;    
  
  if(currentChar != ','){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  if(lookup(llt, tempVar) < 0) { 
  //check if linelabel is in llt
    errorHandler(INVAL_ID);
    return BOOL_FALSE;
  }
  strcpy(currentLineVar[*varLineCount], tempVar);
  (*varLineCount)++;

  ++offsetIndex;
  currentChar = currentLine[offsetIndex]; //skip comma

  /* check id 4 */

  while(currentChar != ',' && currentChar != '\0') {
    tempVar[i] = currentChar;
    ++i;
    ++offsetIndex;
    currentChar = currentLine[offsetIndex];
  }
  tempVar[i] = '\0';
  i = 0;    
  
  if(currentChar != '\0'){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  if(lookup(llt, tempVar) < 0) { 
  //check if linelabel is in llt
    errorHandler(INVAL_ID);
    return BOOL_FALSE;
  }
  strcpy(currentLineVar[*varLineCount], tempVar);
  (*varLineCount)++;

  return BOOL_TRUE;
}


//writeIfaObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeIfaObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, SymbolTable* llt, FILE* objFile){
  fprintf(objFile, "%d ", IFA);
  int i = 0;
  if (*varLineCount > 0) {
    int currentVarMem = lookup(st, currentLineVar[i]);
    fprintf(objFile, "%d ", currentVarMem);
    if (*varLineCount > 1) {
      for (i = 1; i < *varLineCount; i++) {
        int currentVarMem = lookup(llt, currentLineVar[i]);
        fprintf(objFile, "%d ", currentVarMem);
      }
    }
  }
  fprintf(objFile, "\n");
  return;
}

