//FILE: esubp.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "esubp.h"

void esubp(ObjectPtr objPtr, CorePtr corePtr) {
  int op = getObj(objPtr,pc,1), xOp = getObj(objPtr,pc,2), yOp = getObj(objPtr,pc,3);
  double xVal, yVal = getRVal(corePtr, yOp);
  
  switch(op) {
  case SIN:
    insertRVal(corePtr, xOp, sin(yVal));
    break;
  case COS:
    insertRVal(corePtr, xOp, cos(yVal));
    break;
  case EXP:
    insertRVal(corePtr, xOp, exp(yVal));
    break;
  case ABS:
    insertRVal(corePtr, xOp, fabs(yVal));
    break;
  case ALG:
    insertRVal(corePtr, xOp, log2(yVal));
    break;
  case ALN:
    insertRVal(corePtr, xOp, log(yVal));
    break;
  case LOG:
    insertRVal(corePtr, xOp, log10(yVal));
    break;
  case SQR:
    insertRVal(corePtr, xOp, sqrt(yVal));
    break;
  }
}
