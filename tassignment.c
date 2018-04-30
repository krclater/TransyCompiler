//tassignment.c
//Kelsey Clater
//CS3024 
//Fall 2017
//
//
//

//negative numbers must be handled as an entire id not a minus id

#include "tassignment.h"

//tassignment
//pre:
//post:
int tassignment(char* currentLine, SymbolTable* st, FILE* objFile) {
  int o = 0, szPCL = 0; //szPCL = size postfixCurrentLine
  char postfixCurrentLine[STCK_ITM_MAX][VAR_NAME_MAX];
  Transducer trdc;
  initTransducer(&trdc);
  if(!checkAssignment(currentLine, st, &o, &szPCL, postfixCurrentLine, &trdc)) {
		eFlag = BOOL_TRUE;
  }
  writeAssignmentObjCode(st, &szPCL, postfixCurrentLine, objFile);
}

//writeAssignmentObjCode
void writeAssignmentObjCode(SymbolTable* st, int* szPCL, char (*postfixCurrentLine)[VAR_NAME_MAX], FILE* objFile) {
  fprintf(objFile, "%d ", ASSIGNMENT);	
  int i;
  for(i = 0; i < (*szPCL); i++) {
    char currentChar = postfixCurrentLine[i][0];
    if(currentChar == '\0') {
      break;
    }
    if(isalpha(currentChar) || isdigit(currentChar) || (currentChar == '-' && strlen(postfixCurrentLine[i])>1)) {
      fprintf(objFile, "%d ",lookup(st,postfixCurrentLine[i]));
    }
    else {
      fprintf(objFile, "%d ",getAssignmentOpObjCode(postfixCurrentLine[i]));
    }
  }
  fprintf(objFile, "\n");
}

//getAssignmentOpObjCode
int getAssignmentOpObjCode(char* op) {
  if(strcmp("=",op) == 0) {
    return A_EQL;
  }
  if(strcmp("+",op) == 0) {
    return A_PLS;
  }
  if(strcmp("-",op) == 0) {
    return A_MNS;
  }
  if(strcmp("*",op) == 0) {
    return A_MLT;
  }
  if(strcmp("/",op) == 0) {
    return A_DIV;
  }
  if(strcmp("[",op) == 0) {
    return A_OBRAKT;
  }
  if(strcmp("^",op) == 0) {
    return A_EXP;
  }
}

//checkAssignment
int checkAssignment(char* currentLine, SymbolTable* st, int* o, int* szPCL, char (*postfixCurrentLine)[VAR_NAME_MAX], TransducerPtr trdcPtr) {
  int i = 0, opFlag = BOOL_FALSE, szCLP = 0; //szCLP = SIZE OF CURRENTLINEPARSE
  char cLParse[STCK_ITM_MAX*2][VAR_NAME_MAX]; //cc = CURRENTCHAR; cLParse = CURRENTLINEPARSE
  
	if(!aPass1(st, currentLine, o, cLParse, &szCLP)) {
		return BOOL_FALSE;
	}

  if(!aPass2(cLParse, szCLP)) {
		return BOOL_FALSE;
	} 

	if(!trdcPass(trdcPtr, cLParse, szCLP)) {
		return BOOL_FALSE;
	}

  getPostfix(trdcPtr, postfixCurrentLine);
	*szPCL = szCLP;
  return BOOL_TRUE;

}

//trdcPass
//PRE:
//POST:
int trdcPass(TransducerPtr trdcPtr, char (*cLParse)[VAR_NAME_MAX], int szCLP) {
	int i = 0, opFlg = BOOL_FALSE, len;
	char temp[VAR_NAME_MAX];
	
	while(i < szCLP) {
		strcpy(temp, cLParse[i]);
		len = strlen(temp);

		if(isalpha(temp[0]) || isdigit(temp[0]) || (temp[0] == '-' && len > 1)) {
			opFlg = BOOL_FALSE;
		}
		else {
			opFlg = BOOL_TRUE;
		}
		if(!handleInput(trdcPtr, temp, opFlg)) {
			printf("\n%d ERROR: INVALID ASSIGNMENT STATEMENT\n", srcLnNum);
			return BOOL_FALSE;
		}
		++i;
	}
}

//aPass2
//PRE:
//POST:checks that the elements in cLParse form a valid pattern of ids and operators
int aPass2(char (*cLParse)[VAR_NAME_MAX], int szCLP) {
	int i = 0, ret = BOOL_TRUE, len = 0, inptFlg, oPn = 0, cPn = 0, oB = 0, cB = 0;
	char fc = cLParse[0][0]; //fc = FIRST CHAR

	//CHECK FOR FIRST ID
	if(!isalpha(fc)) {
		printf("\n%d ERROR: THE FIRST ID MUST BE A VARIABLE\n", srcLnNum);
		return BOOL_FALSE;
	}
	inptFlg = ID1;
	++i;		
	
	while(i < szCLP && ret != BOOL_FALSE) {
		fc = cLParse[i][0];
		len = strlen(cLParse[i]);
		switch(inptFlg) {
			case ID1: //FIRST ID
				if(!aId1(fc)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING AN ID ON THE LEFT HAND SIDE OF ASSIGNMENT\n", srcLnNum);
					ret = BOOL_FALSE;
				}
				break;
			case ID: //NON-FIRST ID
				if(!aId(fc)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING AN ID\n", srcLnNum);
					ret = BOOL_FALSE;
				}
				break;
			case E: //EQUAL
				if(!aEql_Opn_Ocb(fc, len)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING AN EQUAL\n", srcLnNum);
					ret = BOOL_FALSE;
				}
				break;
			case OPN: //OPEN PAREN
				oPn++;
				if(!aEql_Opn_Ocb(fc, len)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING A OPEN PARENTHESES\n", srcLnNum);
					ret = BOOL_FALSE;
				}
				break;
			case CPN: //CLOS PAREN
				cPn++;
				if(!aCpn(fc)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING A CLOSE PARENTHESES\n", srcLnNum);
					ret=BOOL_FALSE;
				}
				break;
			case OB: //OPEN BRACKET
				oB++;
				if(!aEql_Opn_Ocb(fc, len)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING AN OPEN BRACKET\n", srcLnNum);
					ret=BOOL_FALSE;
				}
				break;
			case CB: //CLOSE BRACKET
				cB++;
				if(!aCb(fc)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING A CLOSED BRACKET\n", srcLnNum);
					ret=BOOL_FALSE;
				}
				break;
			case OOP: //OTHER OPERATION
				if(!aOp(fc, len)) {
					printf("\n%d ERROR: INVALID SYMBOL FOLLOWING AN OPERATION\n", srcLnNum);
					ret=BOOL_FALSE;
				}
				break;
			default:
				printf("\n%d ERROR: UNRECOGNIZED INPUT\n", srcLnNum);
				ret = BOOL_FALSE;
				break;
			
		}
		++i;
		inptFlg = getInptFlg(fc, len);
	}
	if (ret == BOOL_TRUE && oPn != cPn) {
		printf("\n%d ERROR: MISSING '(' or ')'\n", srcLnNum);
		return BOOL_FALSE;
	}
	if (ret == BOOL_TRUE && oB != cB) {
		printf("\n%d ERROR: MISSING '[' or ']'\n", srcLnNum);
		return BOOL_FALSE;
	}
	return ret;
}

//aId1
//PRE:
//POST:
int aId1(char fc) {
	if (fc != '=' && fc != '[') {
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}

//aId
//PRE:
//POST:
int aId(char fc) {
	if(fc != '[' && fc != ']' && fc != '+' && fc != '-' && fc != '*' && fc != '/'  && fc != '^' && fc != ')' && fc != '\0') {
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}

//aEql_Opn_Ocb
//PRE:
//POST:
int aEql_Opn_Ocb(char fc, int len) {
  if(!isalpha(fc) && !isdigit(fc) && !(fc == '-' && len > 1) && fc != '(') {
		if(fc == '\0') {
			printf("\n%d ERROR: CANNOT END AN ASSIGNMENT STATEMENT WITH A '=', '(', or '['\n", srcLnNum);
		}
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}

//aCb
//PRE:
//POST:
int aCb(char fc) {
	if(fc != ']' && fc != '+' && fc != '-' && fc != '*' && fc != '/'  && fc != '^' && fc != ')' && fc != '=' &&fc != '\0') {
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}


//aCpn
//PRE:
//POST:
int aCpn(char fc) {
	if(fc != ']' && fc != '+' && fc != '-' && fc != '*' && fc != '/'  && fc != '^' && fc != ')' && fc != '=' && fc != '\0') {
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}

//aOp
int aOp(char fc, int len) {
 if(fc != '(' && !isalpha(fc) && !isdigit(fc) && !(fc == '-' && len > 1)) {
		if(fc == '\0') {
			printf("\n%d ERROR: CANNOT END AN ASSIGNMENT STATEMENT WITH A '+'\n", srcLnNum);
		}
		return BOOL_FALSE;
	}
	return BOOL_TRUE;
}

//getInptFlg
//PRE:
//POST: based on first character and length of the string, fn tokenizes the current element of cLparse and sets inptFlg to the appropriate code
int getInptFlg(char fc, int len) {
	//printf("\ninside getInptFlg, fc: %c, len: %d\n", fc, len);
	int ret;
  if(isalpha(fc) || isdigit(fc) || (fc == '-' && len > 1)) {
		return ID; //IDENTIFIER
	}
	if(fc == '+' || fc == '-' || fc == '*' || fc == '/' || fc == '^') {
		return OOP; //OTHER OPERATION
	}
	switch(fc) {
		case '=':
			ret = E; //EQUAL
			break;
		case '[':
			ret = OB; //OPEN BRACKET
			break;
		case ']':
			ret = CB; //CLOSE BRACKET
			break;
		case '(':
			ret = OPN; //OPEN PARENTHESES
			break;
		case ')':
			ret = CPN; //CLOSE PARENTHESES
			break;
		default:
			ret = -1;
	}
	return ret;
}


//aPass1
//PRE:
//POST: returns TRUE if fn encounters no invalid IDs and Operators in currentLine, fills each elt of cLParse with a single id or op
int aPass1(SymbolTable* st, char* currentLine, int* o, char (*cLParse)[VAR_NAME_MAX], int* szCLP) {
	int i = 0, opFlag = BOOL_FALSE;	
	char cc = currentLine[(*o)], ccn = currentLine[(*o)+1], tempId[VAR_NAME_MAX], tempOp[2];

	while(cc != '\0') {
		if(isalpha(cc) || isdigit(cc) || (cc == '-' && isdigit(ccn) && opFlag == BOOL_TRUE)) { //CHECK FOR ID
			if(!getAssignmentId(st, currentLine, o, tempId)) {
				printf("\nID: %s\n", tempId);
				printf("\n%d ERROR: INVALID ID\n", srcLnNum);
				return BOOL_FALSE;
			}
			opFlag = BOOL_FALSE;
			strcpy(cLParse[i], tempId);
			++i;
	  }
		else {
			if(!getAssignmentOp(currentLine, o, tempOp)) {
				printf("\n%d ERROR: INVALID SYMBOL IN ASSIGNMENT STATEMENT\n", srcLnNum);
				return BOOL_FALSE;
			}
			if(strcmp(tempOp,"+") == 0|| strcmp(tempOp,"-") == 0 || strcmp(tempOp,"*") == 0 || strcmp(tempOp,"/") == 0 || strcmp(tempOp,"^") == 0) { 
				opFlag = BOOL_TRUE;
			}
			else {
				opFlag = BOOL_FALSE;
			}
			strcpy(cLParse[i], tempOp);
			++i;
		}
		cc = currentLine[(*o)];
		ccn = currentLine[(*o)+1];
	}
	//END OF LINE HAS BEEN REACHED
	strcpy(cLParse[i], &cc);
	++i;
	*szCLP = i;
}

//getAssignmentId
//precondition: offset contains the intial index with which to begin looking in currentLine
//postcondition: if a valid identifier was found, 1 is returned and the valid identifier is saved to validId and put in st, offset is now the index where the delimiter was found
int getAssignmentId(SymbolTable* st, char* currentLine, int* o, char* validId) {
  char cc = currentLine[*o], temp[VAR_NAME_MAX];
  int i = 0;

	if(cc == '-') { //NEGATIVE CONSTANT
		temp[i] = cc;
		i++;
		(*o)++;
	}

  cc = currentLine[*o];
	
  while(cc != '\0' && cc != '=' && cc != '+' && cc != '-' && cc != '*' && cc != '/' && cc != '(' && cc != ')' && cc != '^' && cc != '[' && cc !=  ']'  ) {
    temp[i] = cc;
    i++;
    (*o)++;
    cc = currentLine[*o];
  }
  temp[i] = '\0';
	
	if(!isID(temp)) {
		return BOOL_FALSE;
	}
	else {
		if(lookup(st, temp) < 0) {
			insertInto(st, temp, DOUBLE_VAR_SIZE);
		}
		strcpy(validId, temp);
		return BOOL_TRUE;
	}
}

//getAssignmentOp
int getAssignmentOp(char* currentLine, int* offset, char* validOp) {
  validOp[0] = currentLine[*offset];
  validOp[1] = '\0';
  if(isAssignmentOp(validOp[0])) {
    (*offset)++;
    return BOOL_TRUE;
  }
  return BOOL_FALSE;
}

//isAssignmentOp
int isAssignmentOp(char op) {
  if(op == '=' || op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '(' || op == ')' || op == '[' || op == ']') {
    return BOOL_TRUE;
  }
  return BOOL_FALSE;
}
