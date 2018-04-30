//FILE: eloopend.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef ELOOPEND_H
#define ELOOPEND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"
#include "eloopHelper.h"

//GLOBALS
extern int pc;

void eloopend(ObjectPtr objPtr, CorePtr corePtr, LStackPtr lstackPtr, int* next);

int incIndex(CorePtr corePtr, int indexLVal, double index, double inc);

#endif
