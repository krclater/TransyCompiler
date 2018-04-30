//FILE: eassignment.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//

#include "eassignment.h"

void eassignment(ObjectPtr objPtr, CorePtr corePtr, RangePtr rangePtr) {
	//ADT
	AStack astack;		

	//VARS
	int i = 0, obj = getObj(objPtr,pc,i);

	//INIT ADT
	initAStack(&astack);

	while(obj != SENTINEL_OBJ) {
		while(obj >= 0) {
	    pushAStack(&astack, getObj(objPtr,pc,i), 'l');
			++i;
			obj = getObj(objPtr,pc,i);
	  }
		switch (obj) {
			case A_EQL:
				if(!aeql(corePtr, &astack)) {
					printf("\n\tERROR: INVALID ACCESS TO MEMORY\n");
				}
				break;
			case A_OBRAKT:
				if(!aobrakt(corePtr, rangePtr, &astack)) {
  		  	eFlag = BOOL_TRUE;
  		  	printf("\n\tERROR: ATTEMPT TO READ OUT OF RANGE\n");
				}
				break;
			case A_EXP:
				aexp_mlt_div_pls_mns(corePtr, &astack, A_EXP);
				break;
			case A_MLT:
				aexp_mlt_div_pls_mns(corePtr, &astack, A_MLT);
				break;
			case A_DIV:
				aexp_mlt_div_pls_mns(corePtr, &astack, A_DIV);
				break;
			case A_PLS:
				aexp_mlt_div_pls_mns(corePtr, &astack, A_PLS);
				break;
			case A_MNS:
				aexp_mlt_div_pls_mns(corePtr, &astack, A_MNS);
				break;
		}
	if(eFlag == BOOL_TRUE) {
		break;
	}
	++i;
	obj = getObj(objPtr,pc,i);
	}

}

//A FNS
//ALWAYS APPLY THE OP: VAL2 OP VAL1 (A + B; A[B]; A^B)

//aeql
int aeql(CorePtr corePtr, AStackPtr astackPtr) {
	double val1, val2;
	char type1, type2;
  popAStack(astackPtr, &val1, &type1);
  popAStack(astackPtr, &val2, &type2);
  
	if(type1 == 'l') {
		val1 = getRVal(corePtr, val1);
	}
  if(!insertRVal(corePtr, (int)val2, val1)) {
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}

//aobrakt
int aobrakt(CorePtr corePtr, RangePtr rangePtr, AStackPtr astackPtr) {
	double val1, val2, fval;
	char type1, type2;
	popAStack(astackPtr, &val1, &type1);
  popAStack(astackPtr, &val2, &type2);

	if(type1 == 'l') {
		val1 = getRVal(corePtr, val1);
	}

	fval = val1 + val2;

	//CHECK RANGE
  if((rFlag == BOOL_TRUE) && (checkRange(rangePtr, val2, fval) == BOOL_FALSE)) {
    return BOOL_FALSE;
  }

	//RANGE OK
	pushAStack(astackPtr, fval, 'l');
	return BOOL_TRUE;
}

//aexp_mlt_div_pls_mns
void aexp_mlt_div_pls_mns(CorePtr corePtr, AStackPtr astackPtr, int opCode) {
	double val1, val2, fval;
	char type1, type2;
	popAStack(astackPtr, &val1, &type1);
  popAStack(astackPtr, &val2, &type2);
	
	if(type1 == 'l') {
		val1 = getRVal(corePtr, val1);
	}
	if(type2 == 'l') {
		val2 = getRVal(corePtr, val2);
	}

	switch(opCode){
		case A_EXP:
			fval = pow(val2,val1);
			break;
		case A_MLT:
			fval = val2*val1;
			break;
		case A_DIV:
			fval = val2/val1;
			break;
		case A_PLS:
			fval = val2+val1;
			break;
		case A_MNS:
			fval = val2-val1;
			break;
	}

	pushAStack(astackPtr, fval, 'r');
}



