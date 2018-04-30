//FILE: tlwrite.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tlwrite.h"

//tlwrite
//precondition: currentLine contains LWRITE in the first six characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tlwrite (char* currentLine, SymbolTable* lt, FILE* objFile, FILE* litFile) {
  int offsetIndex = 6, varLineCount = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if (!checkRestOfLwriteLine(currentLine, &varLineCount, currentLineVar, offsetIndex, lt, litFile)) {
    eFlag = BOOL_TRUE;
  }
  writeLwriteObjCode(currentLineVar, &varLineCount, lt, objFile);
}

//checkRestOfLwriteLine
//precondition: currentLine contains LWRITE in the first six chars, offsetIndex holds the val 6
//postcondition: currenLineVar contains a valid literal variable or literal string if found, lt contains the valid literal variable or literal string if found, a '\n' has been printed to the literal file if a valid literal variable was or the literal string has been printed to the literal file if found
int checkRestOfLwriteLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* lt, FILE* litFile) {
  char currentChar = currentLine[offsetIndex], tempVar[VAR_NAME_MAX], tempLitVar[VAR_NAME_MAX], tempLitStr[VAR_NAME_MAX];
  int i = 0;

  if(currentChar != '$' && currentChar != '"') {
     errorHandler(INVAL_SYNTAX);
     return BOOL_FALSE;
  }

  //id is literal variable
  if(currentChar == '$') {
    strcpy(tempLitVar,"$");

    offsetIndex++; //skip $
    currentChar = currentLine[offsetIndex];

    while (currentChar != '\0') {
      tempVar[i] = currentChar;
      i++;
      offsetIndex++;
      currentChar = currentLine[offsetIndex];
    }
    tempVar[i]='\0';

    if(isVar(tempVar)) {
      //printf("\ntempVar: %s, tempLitVar: %s\n", tempVar, tempLitVar);
      strcat(tempLitVar,tempVar);
      if(lookup(lt, tempLitVar) < 0) {
				printf("\n\t%d ERROR: CANNOT LWRITE AN UNDEFINED LITERAL VARIABLE\n", srcLnNum);
				return BOOL_FALSE;
      }
      strcpy(currentLineVar[*varLineCount], tempLitVar);
      *varLineCount++;
    }

    else {
      errorHandler(INVAL_ID);
      return BOOL_FALSE;
    }
  }

  //id is literal string
  if(currentChar == '"') {
    offsetIndex++; //skip open quote
    currentChar = currentLine[offsetIndex];

    while(currentChar != '"' && currentChar != '\0') {
      tempLitStr[i] = currentChar;
      i++;
      offsetIndex++;
      currentChar = currentLine[offsetIndex];
    }
    tempLitStr[i] = '\0';
    
    if (currentChar != '"') {
      errorHandler(INVAL_SYNTAX);
      return BOOL_FALSE;
    }

    offsetIndex++; //skip close quote
    currentChar = currentLine[offsetIndex];

    if(currentChar != '\0') {
      errorHandler(INVAL_SYNTAX);
      return BOOL_FALSE;
    }
    
    strcpy(currentLineVar[*varLineCount], tempLitStr);
    *varLineCount++;

    //put tempLitStr into lt and literal file
    if(lookup(lt, tempLitStr) < 0) {
      //printf("inserting into literal table: %s", tempLitStr);
      insertIntoLT(lt, tempLitStr);
      fprintf(litFile, "%s\n", tempLitStr);
    } 
  }
}

//writeLwriteObjCod
//precondition: currentLineVar contains a valid literal variable if found or currentLineVar contains a valid literal string if found, varLineCount contains 1
//postcondition: the corresponding object code for currentLine is written to the .obj file
void writeLwriteObjCode(char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* lt, FILE* objFile) {
  int currentVarMem;
  fprintf(objFile, "%d ",LWRITE);
  currentVarMem = lookup(lt,currentLineVar[0]);
  fprintf(objFile, "%d\n",currentVarMem);
}
