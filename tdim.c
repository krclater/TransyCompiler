//FILE: tdim.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
// dim a[size]

#include "tdim.h"

//tdim
//precondition: currentLine contains DIM in the first three characters
//postcondition: if an error was found, errorFlag is set to true, corresponding object code for currentLine is written to objFile
void tdim(char* currentLine, SymbolTable* st, FILE* objFile) {
  int offsetIndex = 3, varLineCount = 0;
  ArrayVarNameAndSize currentLineVar[LINE_VAR_MAX];
  if(!checkRestOfDimLine(currentLine, currentLineVar, &varLineCount, offsetIndex, st)) {
		printf("\n%d ERROR: DIM ERROR\n", srcLnNum);
  }
  writeDimObjectCode(currentLine, currentLineVar, &varLineCount, st, objFile);
}

//checkRestOfDimLine
//precondition: currentLine contains DIM in the first three characters
//postcondition: currentLineVar holds all viable var names and var sizes found on currentLine, varLineCount holds number of vars found, 
  //if an error was found, return 1, else return 0
int checkRestOfDimLine(char* currentLine, ArrayVarNameAndSize* currentLineVar, int* varLineCount, int offsetIndex, SymbolTable* st) { 
  char currentChar;
  int tempSize = 0, i = 0;	
  char tempArray[VAR_NAME_MAX], tempVar[VAR_NAME_MAX], tempSizeString[VAR_NAME_MAX];

    currentChar = currentLine[offsetIndex];

    if (!isalpha(currentChar)) {//if next char after dim != alpha -> error
      errorHandler(INVAL_SYNTAX);			
      return BOOL_FALSE;
    }

  while(offsetIndex < strlen(currentLine)) {

    if (!isalpha(currentChar)) {//if next char after comma is not alpha -> error
      errorHandler(INVAL_ID);			
      return BOOL_FALSE;
    }

    while(currentChar != ',' && currentChar != '\0') {	
      //save everything between (("DIM" and comma) || (comma and comma) || comma and endline) to temp
      tempArray[i]= currentChar;
      i++;
      currentChar = currentLine[++offsetIndex];
    }

    tempArray[i] = '\0';
    i = 0; //reset temp index
    //printf("\n\t==>temp: %s\n", tempArray);

    if(isArray(tempArray, tempVar, tempSizeString, &tempSize)) {

      if (!(addArrayVar(tempVar, tempSize, varLineCount, currentLineVar))) {
        return BOOL_FALSE;
      }

      if(lookup(st, tempVar) < 0) {
        insertInto(st, tempVar, tempSize);
      }

    }

		else {
			printf("\n%d ERROR: INVALID ARRAY\n", srcLnNum);
			return BOOL_FALSE;
		}
    
    if (currentChar != ',' && currentChar != '\0') {
      errorHandler(INVAL_SYNTAX);
      return BOOL_FALSE;
    }
    
    ++offsetIndex; //skip comma or null

    currentChar = currentLine[offsetIndex];
  
 }

  return BOOL_TRUE;

}

//isArray
//precondition: tempArray holds a potential array variable
//postCondition: tempVar holds the name of the array, tempSizeString holds the size of the array as chars, tempSize holds the size of the array as an int,
  //returns 1 if tempArray was valid format, else returns 0
int isArray(char* tempArray, char* tempVar, char* tempSizeString, int* tempSize) {
  int i = 0, j = 0;
  char currentChar;
  currentChar = tempArray[i];
  if (!isalpha(currentChar)) { //is this necessary?
    return BOOL_FALSE;
  }
  while (currentChar != '[' && currentChar != '\0'){
    tempVar[j++] = currentChar;
    currentChar = tempArray[++i];
  }
  tempVar[j] = '\0';

  if (!isVar(tempVar)) {
    errorHandler(INVAL_ID);
    return BOOL_FALSE;
  }
  if (currentChar != '[') {
    errorHandler(INVAL_SYNTAX);
    return BOOL_FALSE;
  }
  j = 0;
  currentChar = tempArray[++i]; //skip open bracket
  while(currentChar != ']' && currentChar != '\0') {
    tempSizeString[j++] = currentChar;
    currentChar = tempArray[++i];
  }
   tempSizeString[j] = '\0';

  *tempSize = atoi(tempSizeString); //string of digits to int

  if (!isValidArrayInt(*tempSize)) {
    return BOOL_FALSE;
  }

  if (currentChar != ']') {
    return BOOL_FALSE;
  }
  return BOOL_TRUE;
}

//isValidArrayInt
//precondition: tempSize contains an int
//postcondition: returns 1 if 0 < tempSize <= 1000, else returns 0
int isValidArrayInt(int tempSize) {
  if (tempSize == 0) {
    return BOOL_FALSE;
  }
  if (tempSize >= MEM_MAX) {
		eFlag =  BOOL_TRUE;
		printf("\n%d ERROR: CANNOT DECLARE AN ARRAY LARGER THAN THE MAXIMUM CORE SIZE\n", srcLnNum);
    return BOOL_FALSE;
  }
  return BOOL_TRUE;
}

//writeDimObjCode
//precondition: currentLineVar contains the name of all viable variables found on currentLine, varLineCount holds the number of viable vars on currentLine
//postcondition: objFile holds the corresponding object code for currentLine
void writeDimObjectCode(char* currentLine, ArrayVarNameAndSize* currentLineVar, int* varLineCount, SymbolTable* st, FILE* objFile) {
  fprintf(objFile, "%d ", DIM);
  int i;
  for (i=0; i<(*varLineCount); ++i) {
    int currentVarMem = lookup(st, currentLineVar[i].varName);
    fprintf(objFile, "%d ", currentVarMem);
    fprintf(objFile, "%d ", currentLineVar[i].varSize);
  }
  fprintf(objFile, "\n");
}
