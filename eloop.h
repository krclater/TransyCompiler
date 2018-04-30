//FILE: eloop.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef ELOOP_H
#define ELOOP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"
#include "lstack.h"
#include "eloopHelper.h"

//GLOBALS
extern int pc;

void eloop(ObjectPtr objPtr, CorePtr corePtr, LStackPtr lstackPtr, int* next);

int exitLoop(ObjectPtr objPtr, int* next);

#endif
