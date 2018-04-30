//FILE: egoto.h
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#ifndef EGOTO_H
#define EGOTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "object.h"

//GLOBALS
extern int pc;

void egoto(ObjectPtr obj, int* next);

#endif
