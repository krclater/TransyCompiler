//FILE: elread.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "elread.h"

void elread(ObjectPtr objPtr, LiteralPtr litPtr) {
  int j = getObj(objPtr,pc,1);
  char temp[LINE_CHAR_MAX];
  scanf("%s",temp);
  insertLit(litPtr, j, temp);
}
