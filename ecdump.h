//FILE: ecdump.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef ECDUMP_H
#define ECDUMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"

//GLOBALS
extern Flag eFlag;
extern int pc;

void ecdump(ObjectPtr objPtr, CorePtr corePtr);

#endif
