//FILE: eread.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EREAD_H
#define EREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"

//GLOBALS
extern int pc;

/*
*** FN PROTOTYPES
*/

void eread(ObjectPtr objPtr, CorePtr corePtr);

#endif
