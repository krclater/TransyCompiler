//FILE: eifa.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EIFA_H
#define EIFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"

//GLOBALS
extern int pc;

void eifa(ObjectPtr objPtr, CorePtr corePtr, int* next);

#endif
