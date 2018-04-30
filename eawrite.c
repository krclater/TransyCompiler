//FILE: eawrite.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eawrite.h"

void eawrite(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr) {
 int base = getObj(objPtr,pc,1), start = getRVal(corePtr, getObj(objPtr,pc,2)), end = getRVal(corePtr,getObj(objPtr,pc,3));
  if((rFlag == BOOL_TRUE) && (checkRange(rangePtr, base, end) == BOOL_FALSE)) {
    eFlag = BOOL_TRUE;
    printf("\n\tERROR: ATTEMPT TO WRITE OUT OF RANGE\n");
    return;
  }
  else {
    int j;
    double temp;
    for (j = start; j <= end; ++j) {
      int aPos = base + j;
      temp = getRVal(corePtr, aPos);
      printf("%lf\n",temp);
    }
  }
}
