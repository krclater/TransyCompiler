//FILE: eread.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eread.h"

//eread
//PRE:
//POST:
void eread(ObjectPtr objPtr, CorePtr corePtr) {
  int j = 1;
  double temp;
  while(getObj(objPtr,pc,j) != SENTINEL_OBJ) {
    scanf("%lf",&temp);
    if(!insertRVal(corePtr, getObj(objPtr,pc,j), temp)) {
			return;
		}
    ++j; 
  }
}
