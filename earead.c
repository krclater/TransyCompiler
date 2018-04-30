//FILE: earead.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "earead.h"

void earead(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr) {
  int base = getObj(objPtr,pc,1), start = getRVal(corePtr, getObj(objPtr,pc,2)), end = getRVal(corePtr, getObj(objPtr,pc,3));
  if((rFlag == BOOL_TRUE) && (checkRange(rangePtr, base, end) == BOOL_FALSE)) {
    eFlag = BOOL_TRUE;
    printf("\n\tERROR: ATTEMPT TO READ OUT OF RANGE\n");
    return;
  }
  else {
    int j;
    double temp;
    for (j = start; j <= end; ++j) {
      int aPos = base + j;
      scanf("%lf",&temp);
      if(!insertRVal(corePtr, aPos, temp)) {
				return;
			}
    }
  }
}
