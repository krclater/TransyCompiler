//FILE: tlread.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "tlread.h"

//tlread
//precondition: currentLine contains LREAD in the first five characters
//postcondition: if an error was found, eFlag is set to true, corresponding object code for currentLine is written to objFile
void tlread (char* currentLine, SymbolTable* lt, FILE* objFile, FILE* litFile) {
  int offsetIndex = 5, varLineCount = 0;
  char currentLineVar[LINE_VAR_MAX][VAR_NAME_MAX];
  if (!checkRestOfLreadLine(currentLine, &varLineCount, currentLineVar, offsetIndex, lt, litFile)) {
    eFlag = BOOL_TRUE;
  }
  writeLreadObjCode(currentLineVar, &varLineCount, lt, objFile);
}

//checkRestOfLreadLine
//precondition: currentLine contains LREAD in the first five character, offsetIndex contains 5
//postcondition: currenLineVar contains a valid literal variable if found, lt contains the valid literal variable if found, a '\n' has been printed to the literal file if a valid literal variable was found 
int checkRestOfLreadLine(char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* lt, FILE* litFile) {
  char currentChar= currentLine[offsetIndex], tempVar[VAR_NAME_MAX], tempLitVar[VAR_NAME_MAX];
  int i=0;
  strcpy(tempLitVar,"$");
  
  if (currentChar!='$') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;  
  }

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
    strcat(tempLitVar,tempVar);
    if(lookup(lt, tempLitVar) < 0) {
      insertIntoLT(lt, tempLitVar);
      fprintf(litFile, "\n");
    }
    strcpy(currentLineVar[*varLineCount], tempLitVar);
    *varLineCount++;
  }

  else {
    errorHandler(INVAL_ID);
    return BOOL_FALSE;
  }

}

//writeLreadObjCode
//precondition: currentLineVar contains a valid literal variable if found, varLineCount contains 1
//postcondition: the corresponding object code for currentLine is written to the .obj file
void writeLreadObjCode(char(*currentLineVar)[VAR_NAME_MAX], int* varLineCount, SymbolTable* lt, FILE* objFile) {
  int currentVarMem;
  fprintf(objFile, "%d ",LREAD);
  currentVarMem = lookup(lt,currentLineVar[0]);
  fprintf(objFile, "%d\n",currentVarMem);
}
