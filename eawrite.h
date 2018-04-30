//FILE: eawrite.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EAWRITE_H
#define EAWRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"
#include "range.h"

//GLOBALS
extern Flag rFlag;
extern int pc;

void eawrite(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr);

#endif
