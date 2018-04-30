//FILE: eif.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eif.h"

void eif(ObjectPtr objPtr, CorePtr corePtr, int* next) {
  int lVal1 = getObj(objPtr, pc, 1), lVal2 = getObj(objPtr, pc, 2), op = getObj(objPtr, pc, 3), loc = getObj(objPtr, pc, 4);
  double rVal1 = getRVal(corePtr, lVal1), rVal2 = getRVal(corePtr, lVal2);

  switch(op) {
    case LESS_THN:
      if (rVal1 < rVal2) {
        *next = loc;
      }
      break;
    case LESS_THN_EQL_TO:
      if (rVal1 <= rVal2) {
        *next = loc;
      }
      break;
    case EQL_TO:
      if (rVal1 == rVal2) {
        *next = loc;
      }
      break;
    case GRTR_THN:
      if (rVal1 > rVal2) {
        *next = loc;
      }
      break;
    case GRTR_THN_EQL_TO:
      if (rVal1 >= rVal2) {
        *next = loc;
      }
      break;
    case NOT_EQL_TO:
      if (rVal1 != rVal2) {
        *next = loc;
      }
      break;
  }
}
