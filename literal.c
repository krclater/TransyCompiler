//FILE: literal.c
//KELSEY CLATER
//CS3024
//FALL 2017

#include "literal.h"

//loadLit
//PRE:
//POST:
int loadLit(LiteralPtr ptr, FILE* litFile) {
  int i = 0;
  char currentLn[LINE_CHAR_MAX];
  char currentCh = getc(litFile);
  if(currentCh == EOF) { //CHECK FOR EMPTY FILE
    printf("\n\tWARNING: \".literal\" FILE IS EMPTY\n");
    return BOOL_TRUE;
  }
  while(currentCh != EOF) {
    strcpy(currentLn,"");
    int j = 0;
    if(currentCh == '\n') {
      strcpy(currentLn,SENTINEL_LIT);
    }
    else {
      while(currentCh != '\n') {
        currentLn[j] = currentCh;
        currentCh = getc(litFile);
        ++j;
      }
      currentLn[j] = '\0';
    }
    strcpy((*ptr)[i], currentLn);
    ++i;
    currentCh = getc(litFile);
  }
}

//getLit
//PRE:
//POST:
void getLit(LiteralPtr ptr, int i, char* tempLit) {
  strcpy(tempLit, (*ptr)[i]);
  parseLitEsc(tempLit);
}

//parseLitEsc
//*see sources.txt, escape sequences for source
//PRE:
//POST:
void parseLitEsc(char* c) {
  char d[LINE_CHAR_MAX] = "";
  int i, j;
  for (i = 0, j = 0; c[i] != 0; ++i, ++j) {
    if (c[i] == '\\' && c[i+1] != 0) {
      switch(c[++i]) {
        case 'n':  d[j] = '\n'; break;
        case '\\': d[j] = '\\'; break;
        case 't': d[j] = '\t'; break;
        /* add the others you'd like to handle here */
        /* case 'a': ... */
        default:   d[j] = ' ';  break;
      }
    } 
    else {
      d[j] = c[i];
    }
    c[j] = 0;
  }
  strcpy(c,d);
}

//insertLit
//PRE:
//POST:
void insertLit(LiteralPtr ptr, int i, char* tempLit) {
  strcpy((*ptr)[i], tempLit);
}

//getLitColSize
//PRE:
//POST:
int getLitColSize(LiteralPtr ptr) {
  int i = 0, j = 0;
  char currentCh = (*ptr)[i][j];
  while (currentCh != '\0') {
    while(currentCh != '\0') {
      j++;
      currentCh = (*ptr)[i][j];
    }
    j = 0;
    i++;
    currentCh = (*ptr)[i][j];
  }
  return i;
}

//printLit
//PRE:
//POST:
void printLit(LiteralPtr ptr) {
  int i, litCol = getLitColSize(ptr);
  printf("\n\tBEGIN LITERAL PRINT:");
  for(i = 0; i< litCol; i++) {
    printf("\n\t\t\"%s\"", (*ptr)[i]);
  }
  printf("\n\tEND LITERAL PRINT\n");
}

