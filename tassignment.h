//tassignment.h
//Kelsey Clater
//CS3024 
//Fall 2017
//
//
//

#ifndef TASSIGNMENT_H
#define TASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.h"
#include "helper.h"
#include "constants.h"
#include "transducer.h"

//extern
extern Flag eFlag;
extern int srcLnNum;

//FNS

int tassignment(char* currentLine, SymbolTable* st, FILE* objFile);

int checkAssignment(char* currentLine, SymbolTable* st, int* o, int* szPCL, char (*postfixCurrentLine)[VAR_NAME_MAX], Transducer* trdc);

int trdcPass(TransducerPtr trdcPtr, char (*cLParse)[VAR_NAME_MAX], int szCLP);

int aPass2(char (*cLParse)[VAR_NAME_MAX], int szCLP);

int aId1(char fc);

int aId(char fc);

int aEql_Opn_Ocb(char fc, int len);

int aCb(char fc);

int aCpn(char fc);

int aOp(char fc, int len);

int getInptFlg(char fc, int len);

int aPass1(SymbolTable* st, char* currentLine, int* o, char (*cLParse)[VAR_NAME_MAX], int* szCLP);

void writeAssignmentObjCode(SymbolTable* st, int* szPCL, char (*postfixCurrentLine)[VAR_NAME_MAX], FILE* objFile);

int getAssignmentOpObjCode(char* op);

int getAssignmentId(SymbolTable* st, char* currentLine, int* o, char* validId);

int getAssignmentOp(char* currentLine, int* offset, char* validOp);

int isAssignmentOp(char op);

#endif
