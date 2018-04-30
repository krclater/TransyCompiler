//FILE: eloopHelper.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eloopHelper.h"

//checkIndex
//PRE:
//POST:
int checkIndex(CorePtr corePtr, int indexLVal, double stop, double inc) {
  double indexRVal = getRVal(corePtr, indexLVal);
  if (inc > 0) {
    if (indexRVal <= stop) {
      return BOOL_TRUE;
    }
  }
  if (inc < 0) {
    if (indexRVal >= stop) {
      return BOOL_TRUE;
    }
  }
  if (inc == 0) {
    if (indexRVal != stop) {
      return BOOL_TRUE;
    }
  }
  return BOOL_FALSE;
}
