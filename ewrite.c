//FILE: ewrite.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "ewrite.h"

//ewrite
//PRE:
//POST:
void ewrite(ObjectPtr objPtr, CorePtr corePtr) {
  int j = 1;
  double temp;
  while(getObj(objPtr,pc,j) != SENTINEL_OBJ) {
    temp = getRVal(corePtr, getObj(objPtr,pc,j));
    printf("%lf ",temp);
    ++j;
  }
	printf("\n");
}
