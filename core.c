//FILE: core.c
//Kelsey Clater
//CS3024
//Fall 2017

#include "core.h"


//loadCore
//precondition: coreFile is a file of .core type
//postcondition: the core file is filled with the contents of the core file, with the index of coreArray corresponding to the line of the core file, returns 0 if coreFile is empty
int loadCore(CorePtr ptr, FILE* coreFile) {
  int i;
  char currentLn[LINE_CHAR_MAX];
  for(i=0;i<CORE_ARRAY_MAX;i++) {
    strcpy(currentLn,"");
    char currentCh = getc(coreFile);
    if(currentCh == EOF) { //CHECK FOR EMPTY FILE
      printf("\nERROR: CORE FILE IS EMPTY\n");
      return BOOL_FALSE;
    }
    int j = 0;
    while(currentCh != '\n') {
      currentLn[j] = currentCh;
      currentCh = getc(coreFile);
      ++j;
    }
    currentLn[j] = '\0';
    strcpy((*ptr)[i], currentLn);
  }
}


//printCore
//PRE:
//POST: prints coreArray to the screen
void printCore(CorePtr ptr) {
  int i = 0, j = 0;
  
  printf("\n\tBEGIN CORE PRINT:");
  for(i = 0; i<CORE_ARRAY_MAX; i++) {
    printf("\n\t\t%d: %s", i, (*ptr)[i]);
  }
  printf("\n\tEND CORE PRINT\n");
}

//printCoreArrayRange
//PRE:
//POST: prints coreArray to the screen within the specified range
int printCoreRange(CorePtr ptr, int start, int stop) {
	if(start+stop > MEM_MAX) {
		printf("\n\tERROR: INVALID RANGE\n");
		return BOOL_FALSE;
	}
	if(start > stop) {
		printf("\n\tERROR: INVALID RANGE\n");
		return BOOL_FALSE;
	}
  int i;
  double dumpVal;
  printf("\n\tBEGIN CORE PRINT:");
  for(i = start; i<=stop; i++) {
    printf("\n\t\t%d: ", i);
    dumpVal = getRVal(ptr, i);
    printf("%lf", dumpVal);
  }
  printf("\n\tEND CORE PRINT\n");
	return BOOL_TRUE;
}

//getRVal
//PRE:
//POST:
double getRVal(CorePtr ptr, int i){
  char* endptr;
  if(strcmp((*ptr)[i],UNDEF) == 0 && zFlag == BOOL_TRUE) {
    return 0;
  }
  else {
    return strtod((*ptr)[i],&endptr);
  }
}

//insertRVal
//PRE:
//POST:
int insertRVal(CorePtr ptr, int i, double rValDbl) {
	if(i >= 1000) {
		printf("\n\tERROR: ATTEMPTING TO EXCEED THE RANGE OF CORE MEMORY\n");
		eFlag = BOOL_TRUE;
		return BOOL_FALSE;
	}
  char rValStr[LINE_CHAR_MAX];
  sprintf(rValStr, "%lf", rValDbl);
  strcpy((*ptr)[i], rValStr);
	return BOOL_TRUE;
}

//checkCompilation
//precondition:
//postcondition: returns the value of the last element of core which holds a 1 if compilation was successful and a 0 if compilation failed
int checkCompilation(CorePtr ptr) {
  char* endptr;
  return strtod(*ptr[CORE_ARRAY_MAX-1],&endptr);
}

