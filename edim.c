//FILE: edim.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "edim.h"

//edim
//PRE:
//POST:
void edim(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr) {
  int j = 1;
  while(getObj(objPtr,pc,j) != SENTINEL_OBJ) {
    int base = getObj(objPtr,pc,j);
    j++;
    int size = getObj(objPtr,pc,j);
    j++;
    storeDim(rangePtr, base, size);
  }
}
