//File: noblanks.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//	Removes all whitespace, comments, and line labels from input file and uppercases all characters with the exception of whatever falls in quotes. 
//	Fills outputFile with new content and stores line labels
//	


#include "noblanks.h"

//noblanks
//precondition: inputFile points to a .transy file, outputFile points to a .noblanks file
//postcondition: objLnSrcLn contains an array that relates the source file lines to corresponding object file lines, eFlag is set to true if an error was found, all line labels were removed and stored in llt, all comments, spaces, tabs, blanks lines were removed from the inputFile and result was stored in outputFile
void noblanks(FILE* inputFile, FILE* outputFile, int* objLnSrcLn, SymbolTable* llt)
{
  char currentChar, currentLine[LINE_CHAR_MAX], temp[LINE_CHAR_MAX];
  int i, objLn = 0, srcLn = -1, dimFlag = BOOL_TRUE;

  currentChar = getc(inputFile);
	
  while(currentChar != EOF) {
    i = 0;

    /* first remove all spaces, tabs and uppercase all chars with the exception of literals*/
    while ((currentChar != '\n') && (currentChar != EOF) && (currentChar != '\0')) {
      if (currentChar != '\t' && currentChar != ' ') {
        if (currentChar == '"') {
          currentLine[i++] = currentChar;
          currentChar = getc(inputFile);
          while(currentChar != '"' && currentChar != '\n') {
            currentLine[i++] = currentChar;
            currentChar = getc(inputFile);
          }
					if(currentChar == '\n') {

						break;
					}
          currentLine[i++] = currentChar;
        }
        else {
          currentLine[i++] = toupper(currentChar);
        }
      }
      currentChar = getc(inputFile);
    }
    currentLine[i] = '\0';
    srcLn++; //after each new line is read in from the input file, incriments srcLn
    i = 0;

    /* remove all comments and line labels, store line labels in llt */
    if (!((currentLine[i] == 'C') && (currentLine[i+1] == '*'))) { //skip lines that begin with "C*"
      if ((currentLine[i] != '/') && (currentLine[i+1] != '/')) { //skip lines that begin with "//"
        while(currentLine[i] != ':' && !(currentLine[i] == '/' && currentLine[i+1] == '/') && currentLine[i] != '\0') {
          if(currentLine[i] == '"') { //SKIP OVER LITERALS
            temp[i] = currentLine[i];
            ++i;
            while(currentLine[i] != '"' && currentLine[i] != '\0') { //SKIP LITERALS
              temp[i] = currentLine[i];
              ++i;
            }
						if (currentLine[i] == '\0') {
							break;
						}
          }		
          temp[i] = currentLine[i];
          ++i;
        }
        temp[i] ='\0';
				
        /* line label was found */
        if(currentLine[i] == ':') {
          if (isLnLbl(temp)) {
            if (lookup(llt,temp) < 0) {
              insertIntoLLT(llt, temp, objLn);
            }
            else {
              printf("\n\t%d ERROR: cannot use the same line label multiple times!\n", srcLn);
              eFlag = BOOL_TRUE;
              return;
            }
          }
          else {
            printf("\n\t%d ERROR: invalid line label identifier\n", srcLn);
            eFlag = BOOL_TRUE;
            return;
          }
          ++i; //skip colon

	  /*check dim flag */
	  if(strncmp(&currentLine[i],"DIM",3) == 0) {
	    if(dimFlag == BOOL_FALSE) {
	      printf("\n\t%d ERROR: all array declarations must be at the top of the file\n", srcLn);
	      eFlag = BOOL_TRUE;
	      return;
	    }
	  }
	  else {
	    dimFlag = BOOL_FALSE;
	  }

	  /*check if linelabel is on empty line*/
          if (currentLine[i] == '\0') {
            fprintf(outputFile,"NOP");
          }

	  /*dim flag is good, fprintf the rest of currentLine, or until I find a comment to file*/
          while (currentLine[i] != '\0' && !(currentLine[i] == '/' && currentLine[i+1] == '/')) {
            fprintf(outputFile, "%c", (currentLine[i++]));
          }
          fprintf(outputFile, "%c", '\n');
          objLnSrcLn[objLn] = srcLn;
          objLn++;
        }
        else {
          /* //comment was found */
          if (currentLine[i] == '/' && currentLine[i+1] == '/') { 
	    /* check dim flag */
	    if(strncmp(temp,"DIM",3) == 0) {
	      if(dimFlag == BOOL_FALSE) {
		printf("\n\t%d ERROR: all array declarations must be at the top of the file\n", srcLn);
		eFlag = BOOL_TRUE;
		return;
	      }
	    }
	    else {
	      dimFlag = BOOL_FALSE;
	    }
	    
	    /*dim flag is good, fprintf temp*/
	    i = 0;
	    while (i < strlen(temp)){
	      fprintf(outputFile, "%c", (temp[i++]));
	    }
	    fprintf(outputFile, "%c", '\n');
	    objLnSrcLn[objLn] = srcLn;
	    objLn++;
	  }
	  else {
            /* no line label, no comment, check for blank line */
	    if(strlen(temp)!= 0) {
	      /*no blank line, check dim flag*/	
	      if(strncmp(temp,"DIM",3) == 0) {
	        if(dimFlag == BOOL_FALSE) {
		  printf("\n\t%dERROR: all array declarations must be at the top of the file\n", srcLn);
		  eFlag = BOOL_TRUE;
		  return;
	        }
	      }
	      else {
	        dimFlag = BOOL_FALSE;
	      }

	      /*dim flag is good, fprintf temp*/
	      i = 0;
	      while (i < strlen(temp)){		
		fprintf(outputFile, "%c", (temp[i++]));
	      }
	      fprintf(outputFile, "%c", '\n');
	      objLnSrcLn[objLn] = srcLn;
	      objLn++;
	    }
	  }
	}	
      }
    }
    currentChar = getc(inputFile);
  }
  return;
}
