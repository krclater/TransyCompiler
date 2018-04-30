//FILE:tcdump.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//
//cdump(id1,id2); id1 and id2 can be either a var or int >= 0

#include "tcdump.h"

//tcdump
//precondition:the first 5 chars of currentLine contain the command "CDUMP"
//postcondition:if an error was found, eFlag is true and an error message was printed to the screen
void tcdump(char* currentLine, SymbolTable* st, FILE* objFile) {
  int offsetIndex = 5, varLineCount = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if(!checkRestOfCdumpLine(currentLine, st, offsetIndex, &varLineCount, currentLineVar)) {
    eFlag=BOOL_TRUE;
  }
  writeCdumpObjCode(currentLine, st, objFile, &varLineCount, currentLineVar);
}


//checkRestOfCdumpLine
//precondition: currentLine holds CDUMP in first 5 chars, 
//postcondition: varLineCount holds 2, currentLineVar holds the names of the valid ids found, returns 1 if no errors were found, returns 0 otherwise
int checkRestOfCdumpLine(char* currentLine, SymbolTable* st, int offsetIndex, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX]) {
  char currentChar = currentLine[offsetIndex], tempID[VAR_NAME_MAX], delims[]=",";
  int i = 0;
  if (!isalpha(currentChar) && !isdigit(currentChar)) {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }

  for (i = 0; i <= strlen(delims); i++) {
    if (i != 0) {
      offsetIndex++;  //skip delim[i]
      currentChar = currentLine[offsetIndex];
    }
    if(isalpha(currentChar)) {
      if(getVar(currentLine, &offsetIndex, delims[i], tempID)) {
        if (currentLine[offsetIndex] != delims[i]) {
          errorHandler(INVAL_SYNTAX);
          return BOOL_FALSE;
        }
        if(lookup(st, tempID) < 0) {
          insertInto(st, tempID, DOUBLE_VAR_SIZE); //INSERTING VAR
        }
        strcpy(currentLineVar[*varLineCount], tempID);
        (*varLineCount)++;
      }
      else {
        errorHandler(INVAL_ID);
        return BOOL_FALSE; //temp is not var -> error
      }
    }
    else {
      if (isdigit(currentChar)) {
        if(getInt(currentLine, &offsetIndex, delims[i], tempID)) {
          if (currentLine[offsetIndex] != delims[i]) {
            errorHandler(INVAL_SYNTAX);
            return BOOL_FALSE;
          }
          if(lookup(st, tempID) < 0) {
            insertInto(st, tempID, DOUBLE_VAR_SIZE); //INSERTING CONSTANT
          }
          strcpy(currentLineVar[*varLineCount], tempID);
          (*varLineCount)++;
        }
        else {
          errorHandler(INVAL_ID);
          return BOOL_FALSE; //temp is not var -> error
        }
      }
      else {
        errorHandler(INVAL_ID);
        return BOOL_FALSE; //temp is not var -> error
      }
    }
  }
  if(currentLine[offsetIndex] != '\0') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  return BOOL_TRUE;
}


//writeCdumpObjCode
//precondition: the first 5 chars of currentLine contain the command "CDUMP"
//postcondition: the appropriate object code for currentLine is written in objFile
void writeCdumpObjCode(char* currentLine, SymbolTable* st, FILE* objFile, int* varLineCount, char(*currentLineVar)[VAR_NAME_MAX]) {
  int i, currentVarMem;
  fprintf(objFile, "%d ",CDUMP);
  for(i=0; i < (*varLineCount); i++) {
    currentVarMem = lookup(st,currentLineVar[i]);
    fprintf(objFile, "%d ",currentVarMem);
  }
  fprintf(objFile, "\n");
  
}
