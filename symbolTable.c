//symbolTable.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//	Implementation of symbol table
//

#include "symbolTable.h"

//initSymbolTable
//postcondition:
//postcondition:
void initSymbolTable (SymbolTable *st) {
	(*st).nextAvailableIndex = INIT;
	(*st).nextAvailableMem = INIT;
}


//lookup
//precondition:
//postcondition:
int lookup(SymbolTable* st, char* varName) {
	int i;
        //printf("\ninside lookup, varName:%s\n",varName);
	for (i = 0; i < (*st).nextAvailableIndex; ++i) {
		if (strcmp(varName, (*st).entry[i].varName) == 0) {
			//printf("\nfound varName in index %d of ST, returning location %d\n", i, (*st).entry[i].location);
			return (*st).entry[i].location;
		}
	}
	return -1;
}

//insertInto
//precondition:
//postcondition:
void insertInto(SymbolTable* st, char* varName, int varSize) {
  if(isdigit(varName[0]) || varName[0] == '-') { //INSERTING CONSTANT INTO CORE
      insertIntoCore((*st).nextAvailableMem, varName);
  }
  strcpy((*st).entry[(*st).nextAvailableIndex].varName, varName);
  (*st).entry[(*st).nextAvailableIndex].location = (*st).nextAvailableMem;
  ((*st).nextAvailableIndex)++;
  if((((*st).nextAvailableMem) + varSize) >= 1000) {
    printf("\n\t%d ERROR: CORE MEMORY OVERLOAD, THE MAXIMUM MEMORY IS %d", srcLnNum, MEM_MAX);
		eFlag = BOOL_TRUE;
    return;
  }
  ((*st).nextAvailableMem) = ((*st).nextAvailableMem) + varSize;
}

//insertIntoLLT
//precondition:
//postcondition:
void insertIntoLLT(SymbolTable* llt, char* lnLblName, int objLn) {
  strcpy((*llt).entry[(*llt).nextAvailableIndex].varName, lnLblName);
  (*llt).entry[(*llt).nextAvailableIndex].location = objLn;
  ((*llt).nextAvailableIndex)++;
}

//insertIntoLT
//precondition:
//poscondition:
void insertIntoLT(SymbolTable* lt, char* litVar) {
  strcpy((*lt).entry[(*lt).nextAvailableIndex].varName, litVar);
  (*lt).entry[(*lt).nextAvailableIndex].location = (*lt).nextAvailableIndex;
  ((*lt).nextAvailableIndex)++;
}
