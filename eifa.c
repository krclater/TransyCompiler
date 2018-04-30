//FILE: eifa.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eifa.h"


//eifa
//PRE:
//POST:
void eifa(ObjectPtr objPtr, CorePtr corePtr, int* next) {
  int loc1 = getObj(objPtr, pc, 2), loc2 = getObj(objPtr, pc, 3), loc3 = getObj(objPtr, pc, 4);
  double rVal = getRVal(corePtr, getObj(objPtr, pc, 1));
  if(rVal < 0) {
    *next = loc1;
  }
  if (rVal == 0) {
    *next = loc2;
  }
  if (rVal > 0) {
    *next = loc3;
  }
}
