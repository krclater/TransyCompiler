//FILE: eassignment.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EASSIGNMENT_H
#define EASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "constants.h"
#include "object.h"
#include "core.h"
#include "range.h"
#include "astack.h"

//GLOBALS
extern Flag eFlag, rFlag;
extern int pc;

//FNS
void eassignment(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr);

int aeql(CorePtr corePtr, AStackPtr astackPtr);

int aobrakt(CorePtr corePtr, RangePtr rangePtr, AStackPtr astackPtr);

void aexp_mlt_div_pls_mns(CorePtr corePtr, AStackPtr astackPtr, int opCode);

#endif
