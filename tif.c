//FILE:tif.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tif.h"

//tif
//precondition: currentLine contains IF in the first two characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tif(char* currentLine, SymbolTable* st, SymbolTable *llt, FILE* objFile) {
  int offsetIndex = 2, varLineCount = 0, op = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if(!checkRestOfIfLine(currentLine, st, llt, offsetIndex, &varLineCount, &op, currentLineVar)) {
    eFlag = BOOL_TRUE;
  }
  writeIfObjCode(st, llt, &varLineCount, &op, currentLineVar, objFile);
}

//checkRestOfIfLine
//precondition: currentLine contains IF in the first two characters, offset index contains the initial index for which to begin parsing currentLine, op contains 0
//postcodition: if no errors were found, returns 1, varLineCount contains the number of valid ids found and currentLineVar contains all valid ids found, returns 0 otherwise
int checkRestOfIfLine(char* currentLine, SymbolTable* st, SymbolTable *llt, int offsetIndex, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX]) {
  char currentChar = currentLine[offsetIndex], temp[VAR_NAME_MAX], tempOp[VAR_NAME_MAX], delims[] = "()", empty[] = "", then[]="THEN";
  int i = 0;

  if(currentLine[offsetIndex] != '(') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  offsetIndex++; //skip '('

  /* check id1: can be any id */
  if(getIfId1(currentLine, &offsetIndex, op, temp)) 
  {
    if (currentLine[offsetIndex] == '\0') {
      return BOOL_FALSE;
    }

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


  /* check which op was found */
  //one char op
  if(currentLine[offsetIndex] == '=' || (currentLine[offsetIndex] == '>' && currentLine[(offsetIndex)+1] != '=') || (currentLine[offsetIndex] == '<' 
  && currentLine[(offsetIndex)+1] != '=')) {
    //printf("\ninsdie one char op\n");
    strncpy(tempOp, &currentLine[offsetIndex], 1);
    *op = isOp(tempOp);
    offsetIndex++;
    if((*op) == 0) {
      return BOOL_FALSE;
    }
  }
  else 
  { //two char op
    if((currentLine[offsetIndex] == '!' && currentLine[offsetIndex+1] == '=') || (currentLine[offsetIndex] == '<' && currentLine[(offsetIndex)+1] == '=') || (currentLine[(offsetIndex)] == '>' 
    && currentLine[(offsetIndex)+1] == '='))
    {
      //printf("\ninsdie two char op\n");
      strncpy(tempOp, &currentLine[offsetIndex], 2);
      *op = isOp(tempOp);
      offsetIndex = offsetIndex + 2;
      if((*op) == 0) {
        return BOOL_FALSE;
      }
    }
  }
  strcpy(temp,empty); //reset temp

  /*check id2: can be any id*/
  if(getId(currentLine, &offsetIndex, delims[1], temp)) {
    if(currentLine[offsetIndex] != delims[1]){
      errorHandler(INVAL_SYNTAX);
      return BOOL_FALSE;
    }
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
  offsetIndex++; //skip delimiter

  if(strncmp(&currentLine[offsetIndex],then,4) != 0) {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  offsetIndex = offsetIndex + strlen(then); //skip "then"

  /*get id3: line label*/
 if(getLnLbl(currentLine, &offsetIndex, delims[2], temp)) {
    if(currentLine[offsetIndex] != delims[2]){
      errorHandler(INVAL_SYNTAX);
      return BOOL_FALSE;
    }
    strcpy(currentLineVar[(*varLineCount)], temp);
    (*varLineCount)++;
    if((lookup(llt, temp)) < 0) {
      errorHandler(INVAL_ID);
      return BOOL_FALSE;
    }
  }
  else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE; //temp is not var -> error
  }

  return BOOL_TRUE;
}

//writeIfObjCode
//precondition: varLineCount contains the number of valid ids found on currentLin, currentLine var contains all valid ids found
//postcondition: the corresponding obj code for currentLine is written to objFile
void writeIfObjCode (SymbolTable* st, SymbolTable* llt, int* varLineCount, int* op, char (*currentLineVar)[VAR_NAME_MAX], FILE* objFile) {
  int i = 0;
  fprintf(objFile, "%d ", IF);
  while (i <= (*varLineCount)) {
    if(i == 0){
      fprintf(objFile, "%d ", lookup(st, currentLineVar[0]));
    }
    if(i == 1){
      fprintf(objFile, "%d ", lookup(st, currentLineVar[1]));
    }
    if(i == 2) {
      fprintf(objFile, "%d ", *op);
    }
    if(i == 3){
      fprintf(objFile, "%d ", lookup(llt, currentLineVar[2]));
    }
    ++i;
  }
  fprintf(objFile, "\n");
}

