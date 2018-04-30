//symbolTable.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//	Header file for symbol table
//

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"


/*
*** Type Defs
*/
typedef struct {
	int location;
	char varName[VAR_NAME_MAX];
} SymbolTableEntry;

typedef struct {
	SymbolTableEntry entry[MEM_MAX];
	int nextAvailableIndex;
	int nextAvailableMem;
} SymbolTable;

#include "ccore.h" //odd placement for proper linking purposes

/*
*** Functions
*/

//initSymbolTable
//precondition: st points to a SymbolTable
//postcondition: nextAvailableIndex and nextAvailableMem components of st equal 0
void initSymbolTable (SymbolTable* st);

//lookup
//precondition: st points to a SymbolTable, varName contains the name of a variable
//postcondition: if varName was found in st, the mem location of varName is returned, else -1 is returned
int lookup(SymbolTable* st, char* varName);

//insertInto
//precondition: st points to a SymbolTable, varName contains the name of a var, varSize contains that variables size
//postcondition: st now contains the variable with name varName and of size varSize
void insertInto(SymbolTable* st, char* varName, int varSize);

//insertIntoLLT
//precondition: llt points to a SymbolTable, varName contains the name of a line label, objLn contains the object file line that the line label was found on
//postcondition:llt contains the line label with name varName and the object file line number of objLn
void insertIntoLLT(SymbolTable* llt, char* varName, int objLn);

//insertIntoLT
//precondition: lt points to a SymbolTable, litVar contains a valid literal variable name
//postcondition:lt contains the litVar with the corresponding line in the litFile in which it corresponds to
void insertIntoLT(SymbolTable* lt, char* litVar);

//GLOBALS
//odd placement for linking purposes
extern Flag eFlag;
extern int srcLnNum;

#endif
