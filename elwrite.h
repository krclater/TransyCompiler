//FILE: elwrite.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef ELWRITE_H
#define ELWRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "literal.h"

//GLOBALS
extern int pc;

void elwrite(ObjectPtr objPtr, LiteralPtr litPtr);

#endif
