//FILE: range.h
//Kelsey Clater
//CS3024
//Fall 2017

#ifndef RANGE_H
#define RANGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

/*
*** TYPE DEFS
*/

typedef struct {
  int arrayBase;
  int arraySize;
} DimInfo;

typedef struct{
  DimInfo allDimInfo[MEM_MAX];
  int next;
} Range;

typedef Range* RangePtr;


/*
*** FN PROTOTYPES
*/

//initRangeADT_Ptr
//PRE:
//POST:
void initRange(RangePtr ptr);

//storeDim
//PRE:
//POST:
void storeDim(RangePtr ptr, int base, int size);

//lookupRange
//PRE:
//POST:
int lookupRange(RangePtr ptr, int base);

//checkRange
//PRE:
//POST:
int checkRange(RangePtr ptr, int base, int end);
 
#endif
