//FILE: range.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "range.h"

//initRangeADT_Ptr
//PRE:
//POST:
void initRange(RangePtr ptr) {
  ptr->next = 0;
}

//storeDim
//PRE:
//POST:
void storeDim(RangePtr ptr, int base, int size) {
  (*ptr).allDimInfo[(*ptr).next].arrayBase = base;
  (*ptr).allDimInfo[(*ptr).next].arraySize = size;
  (*ptr).next++;
}

//lookupRange
//PRE:
//POST:
int lookupRange(RangePtr ptr, int base) {
  int i = 0;
  while (i < (*ptr).next) {
    if ((*ptr).allDimInfo[i].arrayBase == base) {
      return i;
    }
    ++i;
  }
  return -1;
}

//checkRange
//PRE:
//POST:
int checkRange(RangePtr ptr, int base, int end) {
  int i = lookupRange(ptr, base);
  if(base+end > (*ptr).allDimInfo[i].arraySize) {
    return BOOL_FALSE;
  }
  else {
    return BOOL_TRUE;
  }
}
