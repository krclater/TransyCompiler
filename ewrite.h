//FILE: ewrite.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EWRITE_H
#define EWRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "core.h"

//GLOBALS
extern int pc;

void ewrite(ObjectPtr objPtr, CorePtr corPtr);

#endif
