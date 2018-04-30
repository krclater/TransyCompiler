//FILE: edim.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EDIM_H
#define EDIM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"
#include "range.h"

//GLOBALS
extern int pc;

void edim(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr);

#endif
