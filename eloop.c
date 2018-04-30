//FILE: eloop.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eloop.h"

//eloop
//PRE:
//POST:
void eloop (ObjectPtr objPtr, CorePtr corePtr, LStackPtr lstackPtr, int* next) {
  int indexLVal = getObj(objPtr, pc, 1), startLVal = getObj(objPtr,pc,2), stopLVal = getObj(objPtr, pc, 3), incLVal = getObj(objPtr, pc, 4);
  double start = getRVal(corePtr, startLVal), stop = getRVal(corePtr, stopLVal), inc = getRVal(corePtr, incLVal);

  if(getLStackCount(lstackPtr) == 0 || getTopLStack(lstackPtr) != pc) { //CHECK IF FIRST TIME ENTERING LOOP
    if(!pushLStack(lstackPtr, pc)){
			eFlag = BOOL_TRUE;
      printf("\n\tERROR: A MAXIMUM OF 7 LOOPS CAN BE NESTED");
			return;
    }
    if(!insertRVal(corePtr, indexLVal, start)) {//INIT INDEX
			return;
		}
    if(!checkIndex(corePtr, indexLVal, stop, inc)) {
			popLStack(lstackPtr);
      if(!exitLoop(objPtr, next)) { //MISSING LOOP-END
        eFlag = BOOL_TRUE;
        printf("\n\tERROR: MISSING LOOP-END\n");
      }
    }
  }
} 


//exitLoop
//PRE:
//POST:
int exitLoop (ObjectPtr objPtr, int* next) {
  checkLoopend(objPtr, next);
  if(next >= 0) {
    return BOOL_TRUE;
  }
  else {
    return BOOL_FALSE;
  }
}

