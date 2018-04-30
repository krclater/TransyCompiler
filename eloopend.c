//FILE: eloopend.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eloopend.h"

void eloopend(ObjectPtr objPtr, CorePtr corePtr, LStackPtr lstackPtr, int* next) {
  int loop = popLStack(lstackPtr);
  if (loop < 0) {
    eFlag = BOOL_TRUE;
    printf("\n\tERROR: MISSING LOOP\n");
  }

  int indexLVal = getObj(objPtr, loop, 1), stopLVal = getObj(objPtr, loop, 3), incLVal = getObj(objPtr, loop, 4);
  double index = getRVal(corePtr, indexLVal), stop = getRVal(corePtr, stopLVal), inc = getRVal(corePtr, incLVal);

  if(!incIndex(corePtr, indexLVal, index, inc)) {
		return;
	}
  if(checkIndex(corePtr, indexLVal, stop, inc)) {
    if(!pushLStack(lstackPtr, loop)) {
			eFlag = BOOL_TRUE;
      printf("\n\tERROR: A MAXIMUM OF 7 LOOPS CAN BE NESTED\n");
			return;
		}
    *next = loop;
  }
}


//incIndex
//PRE:
//POST:
int incIndex(CorePtr corePtr, int indexLVal, double index, double inc) {
  index = index + inc;
  if(!insertRVal(corePtr, indexLVal, index)) {
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}
