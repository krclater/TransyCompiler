//FILE: helpFns.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//
//

#include "helper.h"

/*
==========================> TREAD/TWRITE functions ==========================>
*/

//checkRestOfLine
//precondition: currentLine contains READ or WRITE in the first serveral characters,
//postcondition: currentLieVar contains all viable variables found on currentLine, varLineCount contains the number of viable variables
  //returns 1 if no errors were found, returns if errors were found
int checkRestOfLine(char* currentLine, char (*currentLineVar)[VAR_NAME_MAX], int* varLineCount, int offsetIndex, SymbolTable* st) { 
	//pass in currentLineVar as array of pointers
	char currentChar;
	int i = 0;	
	char tempVar[VAR_NAME_MAX];
	while(offsetIndex < strlen(currentLine)) {
		if(*varLineCount >= 7) {
			printf("\n\t%d ERROR: A MAXIMUM OF 7 VARIABLES CAN BE READ OR WRITTEN AT ONE TIME\n", srcLnNum);
			return BOOL_FALSE;
		}
		currentChar = currentLine[offsetIndex];
		if (!isalpha(currentChar)) {
			errorHandler(INVAL_ID);			
			return BOOL_FALSE;
		}		
		while(currentChar != ',' && currentChar != '\0') {	
		//save everything between (("READ" and comma) || (comma and comma) || until an endline is reached) to temp
			tempVar[i++]= currentChar; 
			currentChar = currentLine[++offsetIndex];
			
		}
		tempVar[i] = '\0';
		i = 0; //reset temp index
		//printf("\n\t==>tempVar: %s\n", tempVar);	
		if(isVar(tempVar)){
		//if temp is var, save to array keeping track of the variables on currentLine, increase varLineCount after
			strcpy(currentLineVar[(*varLineCount)++], tempVar);
			if(lookup(st, tempVar) < 0)
				insertInto(st, tempVar, DOUBLE_VAR_SIZE);
		}
		else {
		//temp is not var -> error
			errorHandler(INVAL_ID);
			return BOOL_FALSE; 
		}
    ++offsetIndex;
	}
	if(currentChar != '\0') {
		errorHandler(INVAL_SYNTAX);
		return BOOL_FALSE;
	}		
	return BOOL_TRUE;
}

/*
==========================> TAREAD/TAWRITE Functions ==========================>
*/

//checkRestOfAreadAwriteLine
//precondition: currentLine contains AREAD or AWRITE in the first serveral characters
//postcondition: currentLieVar contains all viable variables found on currentLine, varLineCount contains the number of viable variables
  //returns 1 if no errors were found, returns if errors were found
int checkRestOfAreadAwriteLine (char* currentLine, int* varLineCount, char (*currentLineVar)[VAR_NAME_MAX], int offsetIndex, SymbolTable* st) {
  char currentChar, tempID[VAR_NAME_MAX], delims[] = ",,";
  int i = 0;
  currentChar = currentLine[offsetIndex];
	
  /* check first var */
  //first variable must be a prexisting variable in the st
      
  if (!isalpha(currentChar)) {
    errorHandler(INVAL_ID);			
    return BOOL_FALSE;
  }

  if(getVar(currentLine, &offsetIndex, delims[0], tempID)) {
    if(lookup(st, tempID) < 0) {
			printf("\n\t%d ERROR: THE VARIABLE, %s, MUST BE DEFINED BEFORE AREAD/AWRITE\n", srcLnNum, tempID);
      return BOOL_FALSE;
    }
    strcpy(currentLineVar[*varLineCount], tempID);
    (*varLineCount)++;
  }
  else {
    errorHandler(INVAL_ID);
    return BOOL_FALSE;
  }
  
  if(currentLine[offsetIndex] != delims[0]) {
    printf("\n\t%d ERROR: AREAD/AWRITE MUST CONTAIN 3 IDENTIFIERS\n", srcLnNum);
    return BOOL_FALSE;
  }

  offsetIndex++; //skip first comma
  currentChar = currentLine[offsetIndex];
 
  /* check second and third vars */
  //vars can be either a variable or a constant

  for (i = 1; i < strlen(delims)+1; i++) {
    if (i != 1) {
      offsetIndex++;  //skip delim[i]
      currentChar = currentLine[offsetIndex];
    }
    if(isalpha(currentChar)) {
      if(getVar(currentLine, &offsetIndex, delims[i], tempID)) {
        if (currentLine[offsetIndex] != delims[i]) {
          errorHandler(INVAL_SYNTAX);
          return BOOL_FALSE;
        }
        if(lookup(st, tempID) < 0) {
          insertInto(st, tempID, DOUBLE_VAR_SIZE); //INSERTING VAR
        }
        strcpy(currentLineVar[*varLineCount], tempID);
        (*varLineCount)++;
      }
      else {
        errorHandler(INVAL_ID);
        return BOOL_FALSE; //temp is not var -> error
      }
    }
    else {
      if (isdigit(currentChar)) {
        if(getInt(currentLine, &offsetIndex, delims[i], tempID)) {
          if (currentLine[offsetIndex] != delims[i]) {
            errorHandler(INVAL_SYNTAX);
            return BOOL_FALSE;
          }
          if(lookup(st, tempID) < 0) {
            insertInto(st, tempID, DOUBLE_VAR_SIZE); //INSERTING CONSTANT
          }
          strcpy(currentLineVar[*varLineCount], tempID);
          (*varLineCount)++;
        }
        else {
          errorHandler(INVAL_ID);
          return BOOL_FALSE; //temp is not var -> error
        }
      }
      else {
        errorHandler(INVAL_ID);
        return BOOL_FALSE; //temp is not var -> error
      }
    }
  }

  return BOOL_TRUE;
}


/*
==========================> Other Functions ==========================>
*/

//errorHandler
//precondition: errorCommand holds a constant that corresponds to an error type
//postcondition: a unique error message is printed
void errorHandler(int errorCommand) {
	switch(errorCommand){
		case UNIDENTIFIED_CMD:
			printf("\n\t%d ERROR: UNIDENTIFIED COMMAND\n", srcLnNum);
			break;
		case MISSING_ID:
			printf("\n\t%d ERROR: MISSING IDENTIFIER\n", srcLnNum);
			break;
		case INVAL_ID:
			printf("\n\t%d ERROR: INVALID IDENTIFIER\n", srcLnNum);
			break;
		case TOO_MANY_ID:
			printf("\n\t%d ERROR: TOO MANY IDENTIFIERS\n", srcLnNum);
			break;
		case INVAL_SYNTAX:
			printf("\n\t%d ERROR: INVALID SYNTAX\n", srcLnNum);
			break;
		case UNIDENTIFIED_ID:
			printf("\n\t%d ERROR: UNIDENTIFIED IDENTIFIER\n", srcLnNum);
			break;
	}
}

//getSrcLnNum
//precondition: objIndex contains an object code line number
//postcondition: returns the source line number that corresponds to the object code line number
int getSrcLnNum(int* objLnSrcLn, int objIndex) {
	return objLnSrcLn[objIndex];
}

//addArrayVar
//precondition: varName holds a name of an array, varSize holds the array size
//postcondition: returns 0 if there werer less than 7 variables in currentLineVar and varName was not added to currentLineVar, else returns 1
int addArrayVar(char* varName, int varSize, int *varLineCount, ArrayVarNameAndSize* varsOnCurrentLine) {
	if (!(*varLineCount < 7)) {
		printf("\n\t%d ERROR: A MAXIMUM OF 7 ARRAYS MAY BE DECALRED AT ONCE!\n", srcLnNum);		
		return BOOL_FALSE;
	}	
	strcpy(varsOnCurrentLine[(*varLineCount)].varName, varName);
	varsOnCurrentLine[(*varLineCount)].varSize = varSize;
	(*varLineCount)++;
	return BOOL_TRUE;
}

//isID
//PRE:
//POST:
int isID(char* temp) {
  int i = 0;
	if(isalpha(temp[0])) {
		return isVar(temp);
	}
	else {
		if(isdigit(temp[0])) { //TEMP CAN BE NON-NEG INT OR FLOAT
			if(!isInt(temp, 10)) { //NOT INT
				if(!isFloat(temp, 10)) { //NOT FLOAT
					return BOOL_FALSE;
				}
			}	
		}
		else {
			if(temp[0] == '-') { //TEMP CAN BE NEG INT OR FLOAT
				if(!isInt(&temp[1], 10)) { //NOT NEG INT
					if(!isFloat(&temp[1], 10)) { //NOT NEG FLOAT
						return BOOL_FALSE;
					}
				}	
			}
			else { //TEMP DOES NOT START WITH ALPHA, DIGIT, OR '-'
				return BOOL_FALSE;
			}
		}
	}
	return BOOL_TRUE;
}

//isVar
//precondition: potentialVar contains a string
//postcondition: returns 1 if potentialVar contained a valid variable, else returns 0
int isVar(char* potentialVar) {
	int i = 0;
	if(potentialVar[0] == '\0') {
		return BOOL_FALSE;
	}
	while (potentialVar[i] != '\0') {
		if (!(isalpha(potentialVar[i]) || isdigit(potentialVar[i]) || (potentialVar[i] == '_')))
			return BOOL_FALSE;
		++i;
	}
	return BOOL_TRUE;
}

//isLnLbl
//precondition: potentialLnLbl contains a string
//postcondition: returns 1 if potentialLnLbl contained a valid line label, else returns 0
int isLnLbl (char* potentialLnLbl) {
 int i = 0;
  while(potentialLnLbl[i] != '\0') {
    if (!(isalpha(potentialLnLbl[i]) || isdigit(potentialLnLbl[i]) || (potentialLnLbl[i] == '_'))) {
      return BOOL_FALSE;
    }
    ++i;
  }
  return BOOL_TRUE;
}

//isInt
//precondition: temp contains a potential string of digits, base contains the base in which the integer value of the string is in
//postcondition: returns 1 if temp contains a valid base ten integer, otherwise returns 0
int isInt (char* temp, int base) {
  char* end;
  strtol(temp, &end, base);
  if (end == temp) { //temps first char contained a non-digit char
    return BOOL_FALSE;
  }
  if (end != &temp[strlen(temp)]) { //end point at the last char in temp, if it doesn't temp wasn't entirely composed of digits
    return BOOL_FALSE;
  }
  return BOOL_TRUE;
}


//isFloat
//precondition: temp contains a potential float string, base contains the base in which the integer value of the string is in
//postcondition: returns 1 if temp contains a valid base ten integer, otherwise returns 0int isFloat(char* temp, int base) {
int isFloat (char* temp, int base) {
	if(temp[0] == '.') {
		return BOOL_FALSE;
	}
  char* end;
  strtof(temp, &end);
  if (end == temp) { //temps first char contained a non-digit char
    return BOOL_FALSE;
  }
  if (end != &temp[strlen(temp)]) { //end point at the last char in temp, if it doesn't temp wasn't entirely composed of digits
    return BOOL_FALSE;
  }
  return BOOL_TRUE;
}

//isOp
//precondition: tempOp contains a potential operation
//postcondition: if a valid operation was found, the corresponding obj code for that op is returned, else 0 is returned
int isOp(char* tempOp) {
  if(strncmp(tempOp,"<=",2) == 0) {
    return LESS_THN_EQL_TO;
  }

  if(strncmp(tempOp,">=",2) == 0) {
    return GRTR_THN_EQL_TO;
  }

  if(strncmp(tempOp,"!=",2) == 0) {
    return NOT_EQL_TO;
  }

  if(strncmp(tempOp,"<",1) == 0) {
    return LESS_THN;
  }

  if(strncmp(tempOp,">",1) == 0) {
    return GRTR_THN;
  }

  if(strncmp(tempOp,"=",1) == 0) {
    return EQL_TO;
  }

  if(strncmp(tempOp,"SIN",3) == 0) {
    return SIN;
  }

  if(strncmp(tempOp,"COS",3) == 0) {
    return COS;
  }

  if(strncmp(tempOp,"EXP",3) == 0) {
    return EXP;
  }

  if(strncmp(tempOp,"ABS",3) == 0) {
    return ABS;
  }
  
  if(strncmp(tempOp,"ALG",3) == 0) {
    return ALG;
  }

  if(strncmp(tempOp,"ALN",3) == 0) {
    return ALN;
  }

  if(strncmp(tempOp,"LOG",3) == 0) {
    return LOG;
  }

  if(strncmp(tempOp,"SQR",3) == 0){
    return SQR;
  }
  return BOOL_FALSE;
}

//getVar
//precondition:strlen of delim is 0 or 1, offset contains the intial index with which to look in currentLine
//postcondition: returns 1 if a valid var is found, validVar contains a valid variable if found
int getVar(char* currentLine, int* offset, char delim, char* validVar) {
  int i = 0;
  char currentChar = currentLine[*offset], temp[VAR_NAME_MAX];
  //printf("\n\t\tcurrentChar:%c, delimiter:%c\n",currentChar, delim);
  
  //no delimiter (aka '\0' is the only delimtier
  if(delim == '\0') {
    while(currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
    }
    temp[i] = '\0';
    
    if(isVar(temp)) {
      strcpy(validVar, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }

  //one delimiter
  else {
    while(currentChar != delim && currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
      //printf("\n\t\tcurrentChar:%c\n",currentChar);
    }
    temp[i] = '\0';
    
    if(isVar(temp)) {
      strcpy(validVar, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }  
}

//getLnLbl
//precondition:strlen of delim is 0 or 1, offset contains the intial index with which to look in currentLine
//postcondition: returns 1 if a valid var is found, validVar contains a valid variable if found
int getLnLbl(char* currentLine, int* offset, char delim, char* validLnLbl) {
  int i = 0;
  char currentChar = currentLine[*offset], temp[VAR_NAME_MAX];
  
  //no delimiter aka '\0' is the only delimtier
  if(delim == '\0') {
    while(currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
    }
    temp[i] = '\0';
    
    if(isLnLbl(temp)) {
      strcpy(validLnLbl, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }

  //one delimiter
  else {
    while(currentChar != delim && currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
      //printf("\n\t\tcurrentChar:%c\n",currentChar);
    }
    temp[i] = '\0';
    
    if(isLnLbl(temp)) {
      strcpy(validLnLbl, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }  
}

//getInt
//precondition:strlen of delim is 0 or 1, offset contains the intial index with which to look in currentLine
//postcondition: returns 1 if a valid integer str is found, validInt contains a valid integer str if found
int getInt (char* currentLine, int* offset, char delim, char* validInt) {
  int i = 0;
  char currentChar = currentLine[*offset], temp[VAR_NAME_MAX];
  char *end;
  //no delimiters (aka '\0' is the only delimiter)
  if(delim == '\0') {
    while(currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
    }
    temp[i] = '\0';
    
    if(isInt(temp, 10)) {
      strcpy(validInt, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }
  
  //one delimiter
  else {
    while(currentChar != delim && currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
    }
    temp[i] = '\0';
    
    if(isInt(temp, 10)) {
      strcpy(validInt, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }
}


//getOp
//precondition: offset contains the initial index for which to begin looking for an operation, delim contains a deliminater, *op contains 0
//postcondition: if a valid operation was found on the line starting at the offset to the delimiter, *op is set to the corresponding operation object code
void getOp(char* currentLine,  int* offset, char delim, int* op) {
  char currentChar = currentLine[*offset], tempOp[VAR_NAME_MAX];
  int i = 0;

  while(currentChar != delim && currentChar != '\0') {
    tempOp[i] = currentChar;
    i++;
    (*offset)++;
    currentChar = currentLine[*offset];
  }
  tempOp[i] = '\0';
  (*op) = isOp(tempOp);
}

//getId
//precondition: offset contains the intial index with which to begin looking in currentLine, delim contains a delimiter or '\0'
//postcondition: if a valid identifier was found, 1 is returned and the valid identifier is saved to validId, offset is now the index where the delimiter was found
int getId(char* currentLine, int* offset, char delim, char* validId) {
  char currentChar = currentLine[*offset], temp[VAR_NAME_MAX];
  int i = 0;
  //no delimiters (aka '\0' is the only delimiter)
  if(delim == '\0') {
    while(currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
    }
    temp[i] = '\0';
  }
  else {
    while(currentChar != delim && currentChar != '\0') {
      temp[i] = currentChar;
      i++;
      (*offset)++;
      currentChar = currentLine[*offset];
      //printf("\n\t\tcurrentChar:%c\n",currentChar);
    }
    temp[i] = '\0';
  }

	return isID(temp);
}

//getIfId1
//precondition: offset contains the intial index with which to begin looking in currentLine, *op is zero
//postcondition, *op holds the obj code of the operation found, if no valid operation was found, *op holds 0, validId contains a validId if found, returns 1 if no errors were found, otherwise returns 0
int getIfId1(char* currentLine, int* offset, int* op, char* validId) {
  char temp[VAR_NAME_MAX], tempOp[2], currentChar = currentLine[*offset];
  int i = 0;

  //read into temp until an op is found
  while(currentChar != '<' && currentChar != '=' && currentChar != '>' && currentChar != '!' && currentChar != '\0') {
    temp[i] = currentChar;
    i++;
    (*offset)++;
    currentChar = currentLine[*offset];
    //printf("\n\t\tcurrentChar:%c\n",currentChar);
  }
  temp[i] = '\0';
  
  /*handle temp*/
  //check for invalid id
  if (temp[0] != '-' && !isalpha(temp[0]) && !isdigit(temp[0]) && !(strchr(temp,'.') == NULL)){
    return BOOL_FALSE;
  }


  if(temp[0] == '-' && strchr(temp,'.') == NULL) { //neg int
    if(isInt(&temp[1], 10)) {
      strcpy(validId, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }  
  }

  if(temp[0] == '-' && !(strchr(temp,'.') == NULL)) { //neg float
    if(isFloat(&temp[1], 10)) {
      strcpy(validId, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }  
  }

  if(isdigit(temp[0]) && strchr(temp,'.') == NULL) { //int
    if(isInt(temp, 10)) {
      strcpy(validId, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }

  if(isdigit(temp[0]) && !(strchr(temp,'.') == NULL)) { //float
    if(isFloat(temp, 10)) {
      strcpy(validId, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }

  if(isalpha(temp[0])) { //var
    if(isVar(temp)) {
      strcpy(validId, temp);
      return BOOL_TRUE;
    }
    else {
      return BOOL_FALSE;
    }
  }
}
