//FILE: ecdump.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "ecdump.h"

void ecdump(ObjectPtr objPtr, CorePtr corePtr) {
  int start = getRVal(corePtr, getObj(objPtr,pc,1));
  int end = getRVal(corePtr, getObj(objPtr,pc,2));
  if(!printCoreRange(corePtr, start, end)) {
		eFlag = BOOL_TRUE;
		printf("\nERROR: CDUMP FAILED\n");
	}
}
