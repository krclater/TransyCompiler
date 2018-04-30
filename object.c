//FILE: object.c
//KELSEY CLATER
//CS3024
//FALL 2017

#include "object.h"

//loadObj
//PRE:
//POST: loads each line into an element of objArray, returns 0 if objFile is empty
int loadObj(ObjectPtr ptr, FILE* objFile) {
  int i, o = 0;
  char currentCh = getc(objFile);
  if(currentCh == EOF) { //CHECK FOR EMPTY FILE
    printf("\n\tERROR: OBJECT FILE IS EMPTY\n");
    return BOOL_FALSE;
  }
  while(currentCh != EOF) {
    char currentLn[LINE_CHAR_MAX];
    int j = 0;
    while(currentCh != '\n' && currentCh != EOF) {
      currentLn[j] = currentCh;
      currentCh = getc(objFile);
      ++j;
    }
    currentLn[j] = '\0';
    parseObjLn(ptr, currentLn, &o);
    currentCh = getc(objFile);
  }
  (*ptr)[o][0] = SENTINEL_OBJ;
}

//getObjLn
//PRE:
//POST:
void getObjLn(FILE** objFile, char currentCh, char* currentLn) {
  int j = 0;
  while(currentCh != '\n') {
    currentLn[j] = currentCh;
    currentCh = getc(*objFile);
    ++j;
  }
  currentLn[j] = '\0';
}

//parseObjLn
//PRE:
//POST:
void parseObjLn(ObjectPtr ptr, char* currentLn, int* o) {
  int i = 0, j = 0, tempIntElt;
  char currentCh, tempStrElt[OBJ_CODE_STR_SZ_MX], *endPtr;

  tempIntElt = (int)strtol(currentLn, &endPtr, 10);
  while(currentLn != endPtr) {
    (*ptr)[*o][j] = tempIntElt;
    j++;
    currentLn = endPtr;
    tempIntElt = (int)strtol(currentLn, &endPtr, 10);
  }
  (*ptr)[*o][j] = SENTINEL_OBJ;
  (*o)++;
}

//printObjArray
//PRE:
//POST:
void printObjArray(ObjectPtr ptr) {
  printf("\n\tBEGIN OBJ PRINT:");
  int i = 0, j = 0;
  while((*ptr)[i][j] != SENTINEL_OBJ) {
    printf("\n\t\t %d: ", i);
    while((*ptr)[i][j] != SENTINEL_OBJ) {
      printf("%d ", (*ptr)[i][j]);
      ++j;
    }
    j = 0;
    i++;
  }
  printf("\n\tEND OBJ PRINT\n");
}

//endObj
//PRE:
//POST:
int endObj(ObjectPtr ptr, int i) {
  if((*ptr)[i][0] != SENTINEL_OBJ) {
    return BOOL_FALSE;
  }
  else {
    return BOOL_TRUE;
  }
}

//retCmd
//PRE:
//POST:
int retCmd(ObjectPtr ptr, int i) {
  return (*ptr)[i][0];
}

//getObj
//PRE:
//POST:
int getObj(ObjectPtr ptr, int i, int j) {
  return (*ptr)[i][j];
}

//checkLoopend
//PRE:
//POST:
void checkLoopend(ObjectPtr ptr, int* next) {
  int numLoop = 1, numLoopend = 0;
  while (numLoop != numLoopend) {
    if ((*ptr)[*next][0] == LOOPEND) {
			numLoopend++;
    }
    if ((*ptr)[*next][0] == LOOP) {
			numLoop++;
    }
    if ((*ptr)[*next][0] == SENTINEL_OBJ) {
			*next = SENTINEL_OBJ;			
			break;
    }
    (*next)++;
  }
}	
