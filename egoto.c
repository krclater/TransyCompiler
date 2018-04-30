//FILE: egoto.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "egoto.h"


//egoto
//PRE:
//POST:
void egoto(ObjectPtr objPtr, int* next) {
  *next = getObj(objPtr, pc, 1);
}
