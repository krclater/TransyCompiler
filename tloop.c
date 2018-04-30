//tloop.c
//Kelsey Clater
//CS3024 Fall 2017
//
//
//tloop A = 1,10,2
//tloop A = -1, -10, -1
//tloop A = 10, 1, -1
//tloop A = 10, 1, 0
//tloop A = 

#include "tloop.h"

//tloop
//precondition: currentLine contains LOOP in the first four characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tloop (char* currentLine, SymbolTable* st, FILE* objFile) {
  int offsetIndex = 4, varLineCount = 0, successfulLoop = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  successfulLoop = checkRestOfLoopLine(currentLine, &varLineCount, currentLineVar, offsetIndex, st);
  if (successfulLoop == BOOL_FALSE) {
    eFlag = BOOL_TRUE;
  }
  writeLoopObjCode(currentLine, currentLineVar, &varLineCount, st, objFile);
}

//checkRestOfLoopLine
//precondition: currentLine contains LOOP in the first four characters
//postcondition: currentLineVar holds all viable var names found on currentLine, varLineCount holds number of vars found, if an error was found, return 1, else return 0
int checkRestOfLoopLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* st) {
  char currentChar, tempVar[VAR_NAME_MAX];
  int i = 0, incrimentVarFlag = BOOL_FALSE; 
  currentChar = currentLine[offsetIndex];

  if(!(isalpha(currentChar))) {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  /* check first id */
  while (currentChar!='\0' && currentChar!='=') {
    tempVar[i] = currentChar;
    i++;
    offsetIndex++;
    currentChar = currentLine[offsetIndex];
  }
  tempVar[i] = '\0';
  i = 0;

  if (currentChar != '=') {
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
  
  offsetIndex++;
  currentChar = currentLine[offsetIndex]; //skip equal sign

 /* check second id */
  i = 0;
  while (currentChar !=',' && currentChar !='\0') {
    tempVar[i] = currentChar;
    i++;
    offsetIndex++;
    currentChar = currentLine[offsetIndex];
  }

  tempVar[i] = '\0';
  i = 0;

  if(currentChar != ',') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  
  if (isalpha(tempVar[0])) {
    if (isVar(tempVar)) {
      if(lookup(st, tempVar) < 0) {
        insertInto(st, tempVar, DOUBLE_VAR_SIZE); //INSERTING VAR
      }
      strcpy(currentLineVar[*varLineCount], tempVar);
      (*varLineCount)++;
    }
    else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE; //temp is not var -> error
    }
  }
  else {
    if(isdigit(tempVar[0]) || tempVar[0] == '-') {
	    if (isInt(tempVar, 10)) {
  	    if(lookup(st, tempVar) < 0) {
  	      insertInto(st, tempVar,  CONSTANT_VAR_SIZE); //INSERTING CONSTANT
  	    }
  	    strcpy(currentLineVar[*varLineCount], tempVar);
  	    (*varLineCount)++;
  	  }
    
    	else {
    	  errorHandler(INVAL_ID);
    	  return BOOL_FALSE; //temp is not an int
    	}
    }
    else {
    	errorHandler(INVAL_ID);
    	return BOOL_FALSE; //temp is not a valid ID
    }
  }
  
  offsetIndex++;
  currentChar = currentLine[offsetIndex]; //skip comma

  /* check third id */
  i = 0;
  while (currentChar !=',' && currentChar !='\0') {
    tempVar[i] = currentChar;
    i++;
    offsetIndex++;
    currentChar = currentLine[offsetIndex];
  }

  tempVar[i] = '\0';
  i = 0;

  if(currentChar == ',') {
    incrimentVarFlag = BOOL_TRUE;
  }

  if (isalpha(tempVar[0])) {
    if (isVar(tempVar)) {
      if(lookup(st, tempVar) < 0) {
        insertInto(st, tempVar, DOUBLE_VAR_SIZE); //INSERTING VAR
      }
      strcpy(currentLineVar[*varLineCount], tempVar);
      (*varLineCount)++;
    }
    else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE; //temp is not var -> error
    }
  }
  else {
    if(isdigit(tempVar[0]) || tempVar[0] == '-') {
	    if (isInt(tempVar, 10)) {
  	    if(lookup(st, tempVar) < 0) {
  	      insertInto(st, tempVar,  CONSTANT_VAR_SIZE); //INSERTING CONSTANT
  	    }
  	    strcpy(currentLineVar[*varLineCount], tempVar);
  	    (*varLineCount)++;
  	  }
    
    	else {
    	  errorHandler(INVAL_ID);
    	  return BOOL_FALSE; //temp is not an int
    	}
    }
    else {
    	errorHandler(INVAL_ID);
    	return BOOL_FALSE; //temp is not a valid ID
    }
  }

  /* if incrimentVarFlag == TRUE, check 4th id */
  if (incrimentVarFlag == BOOL_TRUE) {
    i = 0;
    offsetIndex++;
    currentChar = currentLine[offsetIndex]; //skip comma
    while (currentChar != ',' && currentChar !='\0') {
      tempVar[i] = currentChar;
      i++;
      offsetIndex++;
      currentChar = currentLine[offsetIndex];
    }
    tempVar[i] = '\0';
    i = 0;

    if(currentChar != '\0') {
      errorHandler(INVAL_SYNTAX);
      return BOOL_FALSE;
    }

    if (isalpha(tempVar[i])) {
      if (isVar(tempVar)) {
        if(lookup(st, tempVar) < 0) {
          insertInto(st, tempVar, DOUBLE_VAR_SIZE); //INSERTING VAR
        }
        strcpy(currentLineVar[*varLineCount], tempVar);
        (*varLineCount)++;
      }
      else {
        errorHandler(INVAL_ID);
        return BOOL_FALSE; //temp is not var -> error
      }
    }
	  else {
	    if(isdigit(tempVar[0]) || tempVar[0] == '-') {
		    if (isInt(tempVar, 10)) {
	  	    if(lookup(st, tempVar) < 0) {
	  	      insertInto(st, tempVar,  CONSTANT_VAR_SIZE); //INSERTING CONSTANT
	  	    }
	  	    strcpy(currentLineVar[*varLineCount], tempVar);
	  	    (*varLineCount)++;
	  	  }
	    
	    	else {
	    	  errorHandler(INVAL_ID);
	    	  return BOOL_FALSE; //temp is not an int
	    	}
	    }
	    else {
	    	errorHandler(INVAL_ID);
	    	return BOOL_FALSE; //temp is not a valid ID
	    }
	  }
	}
  return BOOL_TRUE;
}

//writeLoopObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeLoopObjCode(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* st, FILE* objFile) {
  fprintf(objFile, "%d ", LOOP);
  int i = 0;
  for (i=0; i<*varLineCount; ++i) {
    int currentVarMem = lookup(st, currentLineVar[i]);
    fprintf(objFile, "%d ", currentVarMem);
  }
  fprintf(objFile, "\n");
}
