//FILE: elwrite.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "elwrite.h"

void elwrite(ObjectPtr objPtr, LiteralPtr litPtr) {
  int j = getObj(objPtr,pc,1);
  char temp[LINE_CHAR_MAX];
  getLit(litPtr, j, temp);
  printf("%s",temp);
}
