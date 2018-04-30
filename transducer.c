//transducer.c
//Kelsey Clater
//CS3024 
//Fall 2017
//
//
//

#include "transducer.h"

//initTransducer
//pre: passes in a transducer
//post: fills the transducer with strings containing function names, initialized the stacks
void initTransducer (Transducer *trdc) {
 
  (*trdc).element[0][0] = S1_CODE;
  (*trdc).element[0][1] = S2_CODE;
  (*trdc).element[0][2] = ER_CODE;
  (*trdc).element[0][3] = ER_CODE;
  (*trdc).element[0][4] = ER_CODE;
  (*trdc).element[0][5] = ER_CODE;
  (*trdc).element[0][6] = ER_CODE;
  (*trdc).element[0][7] = S2_CODE;
  (*trdc).element[0][8] = ER_CODE;
  (*trdc).element[0][9] = ER_CODE;
  (*trdc).element[1][0] = S1_CODE;
  (*trdc).element[1][1] = ER_CODE;
  (*trdc).element[1][2] = S2_CODE;
  (*trdc).element[1][3] = S2_CODE;
  (*trdc).element[1][4] = S2_CODE;
  (*trdc).element[1][5] = ER_CODE;
  (*trdc).element[1][6] = S2_CODE;
  (*trdc).element[1][7] = S2_CODE;
  (*trdc).element[1][8] = ER_CODE;
  (*trdc).element[1][9] = U3_CODE;
  (*trdc).element[2][0] = S1_CODE;
  (*trdc).element[2][1] = ER_CODE;
  (*trdc).element[2][2] = U1_CODE;
  (*trdc).element[2][3] = S2_CODE;
  (*trdc).element[2][4] = S2_CODE;
  (*trdc).element[2][5] = U2_CODE;
  (*trdc).element[2][6] = S2_CODE;
  (*trdc).element[2][7] = S2_CODE;
  (*trdc).element[2][8] = U4_CODE;
  (*trdc).element[2][9] = U3_CODE;
  (*trdc).element[3][0] = S1_CODE;
  (*trdc).element[3][1] = ER_CODE;
  (*trdc).element[3][2] = U1_CODE;
  (*trdc).element[3][3] = U1_CODE;
  (*trdc).element[3][4] = S2_CODE;
  (*trdc).element[3][5] = U2_CODE;
  (*trdc).element[3][6] = S2_CODE;
  (*trdc).element[3][7] = S2_CODE;
  (*trdc).element[3][8] = U4_CODE;
  (*trdc).element[3][9] = U3_CODE;
  (*trdc).element[4][0] = S1_CODE;
  (*trdc).element[4][1] = ER_CODE;
  (*trdc).element[4][2] = S2_CODE;
  (*trdc).element[4][3] = S2_CODE;
  (*trdc).element[4][4] = S2_CODE;
  (*trdc).element[4][5] = U2_CODE;
  (*trdc).element[4][6] = S2_CODE;
  (*trdc).element[4][7] = S2_CODE;
  (*trdc).element[4][8] = ER_CODE;
  (*trdc).element[4][9] = ER_CODE;
  (*trdc).element[5][0] = S1_CODE;
  (*trdc).element[5][1] = ER_CODE;
  (*trdc).element[5][2] = S2_CODE;
  (*trdc).element[5][3] = S2_CODE;
  (*trdc).element[5][4] = S2_CODE;
  (*trdc).element[5][5] = ER_CODE;
  (*trdc).element[5][6] = S2_CODE;
  (*trdc).element[5][7] = S2_CODE;
  (*trdc).element[5][8] = U4_CODE;
  (*trdc).element[5][9] = ER_CODE;
  (*trdc).element[6][0] = S1_CODE;
  (*trdc).element[6][1] = ER_CODE;
  (*trdc).element[6][2] = U1_CODE;
  (*trdc).element[6][3] = U1_CODE;
  (*trdc).element[6][4] = S2_CODE;
  (*trdc).element[6][5] = U2_CODE;
  (*trdc).element[6][6] = S2_CODE;
  (*trdc).element[6][7] = S2_CODE;
  (*trdc).element[6][8] = U4_CODE;
  (*trdc).element[6][9] = U3_CODE;
  

  //initialize stacks
  initStack(&(*trdc).s1);
  initStack(&(*trdc).s2);
}

//getTransducerFn
//pre: a transducer and an input are passed in, it should have been validated before being passed in
//post: based on the input and the top of S2, a fn name is looked up in the transducer array and the corresponding constant is returned
int getTrdcFn (Transducer* trdc, int columnIndex, int rowIndex) {
  int code = (*trdc).element[rowIndex][columnIndex];
  //printf("\n\tinside getTrdcFn, col i: %d, row i: %d, fncode: %d\n", columnIndex, rowIndex, code);
  return code;
}

//getColumnIndex
//pre:
//post:
int getColumnIndex(char* input, int opFlag) {
  //printf("\n\tinside getColumnIndex, input: %s, opFlag: %d\n", input, opFlag);
  if(opFlag == BOOL_FALSE) { //input is an id
    return ID_C;
  }
  if(strcmp("=",input) == 0) {
    return EQ_C;
  }
  if(strcmp("+",input) == 0) {
    return PLS_C;
  }
  if(strcmp("-",input) == 0) {
    return MNS_C;
  }
  if(strcmp("*",input) == 0) {
    return MLT_C;
  }
  if(strcmp("/",input) == 0) {
    return DIV_C;
  }
  if(strcmp("(",input) == 0) {
    return OPARAN_C;
  }
  if(strcmp(")",input) == 0) {
    return CPARAN_C;
  }
  if(strcmp("^",input) == 0) {
    return EXP_C;
  }
  if(strcmp("[",input) == 0) {
    return OBRAKT_C;
  }
  if(strcmp("]",input) == 0) {
    return CBRAKT_C;
  }
  if(strcmp("\0",input) == 0) {
    return EOF_C;
  }
}

//getRowIndex
//pre:
//post:
int getRowIndex(Transducer* trdc) {
  char tops2[VAR_NAME_MAX];
  if(getStackCount(&(*trdc).s2) == 0) {
    return NULL_R;
  }
  getTopStack(&(*trdc).s2, tops2);
  if(strcmp("=",tops2) == 0) {
    return EQ_R;
  }
  if(strcmp("+",tops2) == 0) {
    return PLS_R;
  }
  if(strcmp("-",tops2) == 0) {
    return MNS_R;
  }
  if(strcmp("*",tops2) == 0) {
    return MLT_R;
  }
  if(strcmp("/",tops2) == 0) {
    return DIV_R;
  }
  if(strcmp("(",tops2) == 0) {
    return OPARAN_R;
  }
  if(strcmp("[",tops2) == 0) {
    return OBRAKT_R;
  }
  if(strcmp("^",tops2) == 0) {
    return EXP_R;
  }
}

//S1
//pre: takes a stack and an item to be pushed onto the stack
//post: the stack will never overflow
void S1(Stack* s1, char* item) {
  pushStack(s1, item);
}

//S2
//pre: takes a stack and an item to be pushed onto the stack 
//post: the item has been pushed onto the stack
void S2(Stack* s2, char* item) {
  pushStack(s2, item);
}

//U1
//pre: two stacks and an input are passed in
//post: an item are popped off of s2 and pushed onto s1, input is pushed onto s2
void U1(Stack* s1, Stack* s2, char* input) {
  char tops2[VAR_NAME_MAX];
  getTopStack(s2, tops2);
  popStack(s2, tops2);
  pushStack(s1, tops2);
  pushStack(s2, input);
}

//U2
//pre: two stacks and an input are passed in
//post: items are popped off of s2 and pushed onto s1 until the top of s2 is an open paran
void U2(Stack* s1, Stack* s2) {
  char tops2[VAR_NAME_MAX];
  getTopStack(s2, tops2);
  while (strcmp("(",tops2) != 0) {
    popStack(s2, tops2);
    pushStack(s1, tops2);
    strcpy(tops2,"");
    getTopStack(s2, tops2);
  }
  popStack(s2, tops2);
}

//U3
//pre: two stacks and an input are passed in
//post: items are popped off of s2 and pushed onto s1 until s2 is empty
void U3(Stack* s1, Stack* s2, char* input) {
  char tops2[VAR_NAME_MAX];
  getTopStack(s2, tops2);
  int flag = popStack(s2, tops2);
  while(flag != 0) {
    pushStack(s1, tops2);
    flag = popStack(s2, tops2);
  }
}

//U4
//pre: two stacks are passed in
//post: itemps are popped off of s2 and pushed onto s1 until the top of s2 is an open bracket, an open bracket is pushed onto s1
void U4(Stack* s1, Stack* s2) {
  char tops2[VAR_NAME_MAX];
  getTopStack(s2, tops2);
  while (strcmp("[",tops2) != 0) {
    popStack(s2, tops2);
    pushStack(s1, tops2);
    strcpy(tops2,"");
    getTopStack(s2, tops2);
  }
  popStack(s2, tops2);
  pushStack(s1, "[");
}

//handleInput
//pre: temp holds an input for the transducer trdc
//post: based on the input and the top of s2, the appropriate function is called to handle the input, if an error was found, return 0, else return 1
int handleInput(Transducer* trdc, char* temp, int opFlag) {
 	//printf("\ninside handleInput, input: %s\n", temp);
  int columnIndex = getColumnIndex(temp, opFlag), rowIndex = getRowIndex(trdc), retVal = BOOL_TRUE;
  char trdcFn[TRDC_FN_NAME_MAX];
  int trdcFnCode = getTrdcFn(trdc, columnIndex, rowIndex);
	//printf("trdcFnCode: %d\n", trdcFnCode);
  switch(trdcFnCode) {
    case S1_CODE:
      S1(&(*trdc).s1, temp);
      retVal = BOOL_TRUE;
      break;
    case S2_CODE:
      S2(&(*trdc).s2, temp);
      retVal = BOOL_TRUE;
      break;
    case U1_CODE:
      U1(&(*trdc).s1, &(*trdc).s2, temp);
      retVal = BOOL_TRUE;
      break;
    case U2_CODE:
      U2(&(*trdc).s1, &(*trdc).s2);
      retVal = BOOL_TRUE;
      break;
    case U3_CODE:
      U3(&(*trdc).s1, &(*trdc).s2, temp);
      retVal = BOOL_TRUE;
      break;
    case U4_CODE:
      U4(&(*trdc).s1, &(*trdc).s2);
      retVal = BOOL_TRUE;
      break;
    case ER_CODE:
      retVal = BOOL_FALSE;
      break;
    default: //error
      retVal = BOOL_FALSE;
      break;
  }
  //printf("\n---->stack 1\n");
  //printStack(&(*trdc).s1);
  //printf("\n---->stack 2\n");
  //printStack(&(*trdc).s2);
  return retVal;
}

//getPostfix
//pre:
//post:
void getPostfix(Transducer *trdc, char (*postFix)[VAR_NAME_MAX]) {
  copyStackToArray(&(*trdc).s1, postFix);
}
