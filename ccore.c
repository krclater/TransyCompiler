//FILE: ccore.c
//Kelsey Clater
//CS3024
//Fall 2017

#include "ccore.h"

//initCore
//precondition:
//postcondition:
void initCore(void) {
  int i;
  for(i = 0; i<CORE_ARRAY_MAX; i++){
    strcpy(core[i],UNDEF);
  }
}

//insertIntoCore
//precondition:
//postcondition:
void insertIntoCore(int index, char* strValue) {
  strcpy(core[index],strValue);
}

//saveCore
//precondition:
//postcondition:
void saveCore(FILE* coreFile) {
  int i;
  for(i = 0; i<CORE_ARRAY_MAX; i++){
    fprintf(coreFile,"%s\n",core[i]);
  }
}

//setLastCore
//precondition:
//postcondition:
void setLastCore(void) {
  char temp[DBL_STR_MAX];
  sprintf(temp,"%d",eFlag);
  strcpy(core[CORE_ARRAY_MAX-1],temp);
}


