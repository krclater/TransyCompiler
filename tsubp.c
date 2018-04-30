//FILE:tsubp.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tsubp.h"

//tsupb
//precondition: currentLine contains SUBP in the first four characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tsubp(char* currentLine, SymbolTable* st, FILE* objFile) {
  int offsetIndex = 4, varLineCount = 0, op = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if(!checkRestOfSubpLine(currentLine, st, offsetIndex, &varLineCount, &op, currentLineVar)) {
    eFlag = BOOL_TRUE;
  }
  writeSubpObjCode(st, &varLineCount, &op, currentLineVar, objFile);
}

//checkRestOfSubpLine
//precondition: currentLine contains SUBP in the first four characters, offset contains 4, op is 0
//postcondition: varLineCount contains the number of valid vars found, op contains the operation obj code of the operation found or op contains 0, returns 1 is no errors were found, else returns 0
int checkRestOfSubpLine(char* currentLine, SymbolTable* st, int offsetIndex, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX]) {
  char currentChar = currentLine[offsetIndex], temp[VAR_NAME_MAX], delims[] = "(,)";
  int i = 0;

  /*get operation id*/
  getOp(currentLine, &offsetIndex, delims[0], op);
  
  if(*op == 0) {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  if(currentLine[offsetIndex] != delims[0]){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  offsetIndex++; //skip delim[0]

  /*get ID 1: var */
  if(getVar(currentLine, &offsetIndex, delims[1], temp)) {
    strcpy(currentLineVar[(*varLineCount)], temp);
    (*varLineCount)++;
    if(lookup(st, temp) < 0) {
      insertInto(st, temp, DOUBLE_VAR_SIZE);
    }
  }
  else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE; //temp is not var -> error
  }

  if(currentLine[offsetIndex] != delims[1]){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  offsetIndex++; //skip delim[1]

  /*get ID 2: any ID*/
  if(getId(currentLine, &offsetIndex, delims[2], temp)) {
    strcpy(currentLineVar[(*varLineCount)], temp);
    (*varLineCount)++;
    if(lookup(st, temp) < 0) {
      insertInto(st, temp, DOUBLE_VAR_SIZE);
    }
  }
  else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE; //temp is not var -> error
  }

  if(currentLine[offsetIndex] != delims[2]){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  offsetIndex++; //skip delim[1]

  if(currentLine[offsetIndex] != '\0'){
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  return BOOL_TRUE;
}

//writeSubpObjCode
//precondition: varLineCount contains the number of valid IDs found on currentLine, currentLineVar contains all valid IDs found on currentLine, op contains the object code for the operation found on currentLine, if no valid operation was found, op contains 0
//postcondition: writes the corresponding object code to .obj file for currentLine
void writeSubpObjCode(SymbolTable* st, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX], FILE* objFile) {
  fprintf(objFile, "%d ",SUBP);
  fprintf(objFile, "%d ", *op);
  int i;
  for(i = 0; i< (*varLineCount); i++) {
    fprintf(objFile, "%d ", lookup(st, currentLineVar[i]));
  }
  fprintf(objFile, "\n");
}
