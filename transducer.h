//transducer.h
//Kelsey Clater
//CS3024 Fall 2017
//
//
//

#ifndef TRANSDUCER_H
#define TRANSDUCER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"
#include "stack.h"

typedef struct {
  int element[TRDC_ROW][TRDC_COL];
  Stack s1;
  Stack s2;
}Transducer;

typedef Transducer* TransducerPtr;

/*Transducer_Default = {{S1_CODE, S2_CODE, ER_CODE, ER_CODE, ER_CODE, ER_CODE, ER_CODE, S2_CODE, ER_CODE, ER_CODE, S1_CODE, ER_CODE, S2_CODE, S2_CODE, S2_CODE, ER_CODE,
  S2_CODE, S2_CODE, ER_CODE, U3_CODE, S1_CODE, ER_CODE, U1_CODE, S2_CODE, S2_CODE, U2_CODE, S2_CODE, S2_CODE, U4_CODE, U3_CODE,S1_CODE,ER_CODE, U1_CODE, U1_CODE,
  S2_CODE, U2_CODE, S2_CODE, S2_CODE, U4_CODE, U3_CODE, S1_CODE, ER_CODE, S2_CODE, S2_CODE, S2_CODE, U2_CODE, S2_CODE, S2_CODE, ER_CODE, ER_CODE, S1_CODE, ER_CODE,
  S2_CODE, S2_CODE, S2_CODE, ER_CODE, S2_CODE, S2_CODE, U4_CODE, ER_CODE, S1_CODE, ER_CODE, U1_CODE, U1_CODE, S2_CODE, U2_CODE, U2_CODE, S2_CODE, U4_CODE, U3_CODE}};
*/

//initTransducer
//pre: passes in a transducer
//post: fills the transducer with strings containing function names
void initTransducer(Transducer* trdc);

//getTransducerFn
//pre: a transducer and an input are passed in, it should have been validated before being passed in
//post: based on the input and the top of S2, a fn name is looked up in the transducer array and the corresponding constant is returned
int getTrdcFn (Transducer* trdc, int columnIndex, int rowIndex);

//getColumnIndex
//pre:
//post:
int getColumnIndex(char* input, int opFlag);

//getRowIndex
//pre:
//post:
int getRowIndex(Transducer* trdc);

//S1
//pre: takes a stack and an item to be pushed onto the stack
//post: the stack will never overflow
void S1(Stack* s1, char* item);

//S2
//pre: takes a stack and an item to be pushed onto the stack 
//post: the item has been pushed onto the stack
void S2(Stack* s2, char* item);

//U1
//pre: two stacks and an input are passed in
//post: an item are popped off of s2 and pushed onto s1, input is pushed onto s2
void U1(Stack* s1, Stack* s2, char* input);

//U3
//pre: two stacks and an input are passed in
//post: items are popped off of s2 and pushed onto s1 until s2 is empty
void U2(Stack* s1, Stack* s2);

//U3
//pre: two stacks and an input are passed in
//post: items are popped off of s2 and pushed onto s1 until s2 is empty
void U3(Stack* s1, Stack* s2, char* input);

//U4
//pre: two stacks are passed in
//post: itemps are popped off of s2 and pushed onto s1 until the top of s2 is an open bracket, an open bracket is pushed onto s1
void U4(Stack* s1, Stack* s2);

//handleInput
//pre: temp holds an input for the transducer trdc
//post: based on the input and the top of s2, the appropriate function is called to handle the input, if an error was found, return 0, else return 1
int handleInput(Transducer* trdc, char* temp, int opFlag);

//getPostfix
//pre:
//post:	
void getPostfix(Transducer *trdc, char (*postFix)[VAR_NAME_MAX]);

#endif
