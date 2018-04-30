//FILE: elread.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef ELREAD_H
#define ELREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"
#include "literal.h"

//GLOBALS
extern int pc;

void elread(ObjectPtr objPtr, LiteralPtr litPtr);

#endif
