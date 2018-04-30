//File: compiler.c
//Kelsey Clater
//CS3024
//Fall 2017
//
//	Driver for transy compiler
//	Upon successful comilation of a .transy file, the appropriate .obj file will be created
//
//

#include "compiler.h"

int main (int argc, char**argv) //char** array of an array of characters (array of strings)
{

	//ADT DEC
  SymbolTable st, llt, lt;

	//VAR DEC
  char currentChar, inputFileNm[FILE_NAME_MAX], noBlnksFileNm[FILE_NAME_MAX], objFileNm[FILE_NAME_MAX], litFileNm[FILE_NAME_MAX], coreFileNm[FILE_NAME_MAX];
  FILE *inputFile, *noBlnksFile, *objFile, *litFile, *coreFile;
  int objIndex = 0, commandFlag, i, objLnSrcLn[LINE_MAX];

	//INIT
  if (!initC(&argc, argv, inputFileNm, noBlnksFileNm, objFileNm, coreFileNm, litFileNm,  &inputFile, &noBlnksFile, &objFile, &coreFile, &litFile, &st, &llt, &lt)) {
		return 0;
	}
  initCore();

	//FILL .NOBLANKS FILE
  noblanks(inputFile, noBlnksFile, objLnSrcLn, &llt);
  rewind(noBlnksFile);

	//retrieve one line from noBlanksFile 
  while((currentChar = getc(noBlnksFile)) != EOF) {
    char currentLine[LINE_CHAR_MAX];
    i = 0;
    while (currentChar!='\n') {
      currentLine[i] = currentChar;
      ++i;
      currentChar = getc(noBlnksFile);
    }
    currentLine[i] = '\0';
    srcLnNum = getSrcLnNum(objLnSrcLn, objIndex);
    ++objIndex;
    
  	//check for commands on currentLine
    commandFlag = checkForCommand(currentLine);
    switch(commandFlag){
      case DIM:
				printf("\n=====> currentLine: %s\n",currentLine);
        tdim(currentLine, &st, objFile);
        break;
      case READ:
        printf("\n=====> currentLine: %s\n",currentLine);
        tread(currentLine, &st, objFile);
        break;
      case WRITE:
				printf("\n=====> currentLine: %s\n",currentLine);
				twrite(currentLine, &st, objFile);
				break;
      case STOP:
				printf("\n=====> currentLine: %s\n",currentLine);
				tstop(currentLine, objFile);
				break;
      case CDUMP:
				printf("\n=====> currentLine: %s\n",currentLine);
				tcdump(currentLine, &st, objFile);
				break;
      case LISTO:
				printf("\n=====> currentLine: %s\n",currentLine);
				tlisto(currentLine, objFile);
				break;
      case NOP:
				printf("\n=====> currentLine: %s\n",currentLine);
				tnop(currentLine, objFile);
				break;
      case GOTO:
				printf("\n=====> currentLine: %s\n",currentLine);
				tgoto(currentLine, &llt, objFile);
				break;
      case IFA:
				printf("\n=====> currentLine: %s\n",currentLine);
				tifa(currentLine, &st, &llt, objFile);
				break;
      case AREAD:
				printf("\n=====> currentLine: %s\n",currentLine);
				taread(currentLine, &st, objFile);
				break;
      case AWRITE:
				printf("\n=====> currentLine: %s\n",currentLine);
				tawrite(currentLine, &st, objFile);
				break;
      case SUBP:
				printf("\n=====> currentLine: %s\n",currentLine);
				tsubp(currentLine, &st, objFile);
				break;
      case LOOPEND:
				printf("\n=====> currentLine: %s\n",currentLine);
				tloopend(currentLine, objFile);
				break;
      case LOOP:
				printf("\n=====> currentLine: %s\n",currentLine);
				tloop(currentLine, &st, objFile);
				break;
      case LREAD:
				printf("\n=====> currentLine: %s\n",currentLine);
				tlread(currentLine, &lt, objFile, litFile);
				break;
      case LWRITE:
				printf("\n=====> currentLine: %s\n",currentLine);
				tlwrite(currentLine, &lt, objFile, litFile);
				break;
      case IF:
				printf("\n=====> currentLine: %s\n",currentLine);
				tif(currentLine, &st, &llt, objFile);
				break;
      case CLS:
				printf("\n=====> currentLine: %s\n",currentLine);
				tcls(currentLine, objFile);
				break;
      case ASSIGNMENT:
				printf("\n=====> currentLine: %s\n",currentLine);
				tassignment(currentLine, &st, objFile);
				break;
      default:
				printf("\n=====> currentLine: %s\n",currentLine);
        eFlag=BOOL_TRUE;
        errorHandler(UNIDENTIFIED_CMD);
        break;
    }
  }

  terminateC(objFileNm, noBlnksFileNm, &inputFile, &noBlnksFile, &objFile, &coreFile, &litFile);

  return 0;
}

/*
*** Functions
*/

//terminateC
//PRE:
//POST:
void terminateC(char* objFileNm, char* noBlnksFileNm, FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile) {
  int removeFile = 1;

  if (eFlag == BOOL_TRUE) { //if there WERE errors, keep .noblanks file, delete .obj file, unless the o flag is true
    if (oFlag != BOOL_TRUE) {
      removeFile = remove(objFileNm); //needs sources
      if (removeFile != 0) {
        printf("\n\tERROR: UNABLE TO REMOVE THE \".obj\" OUTPUT FILE\n");
      }
    }
  }
  else { //successful compilation, keep .obj file, delete .noblanks file, unless the n flag is true
    if (nFlag == BOOL_TRUE) {
      removeFile = remove(noBlnksFileNm);
      if (removeFile != 0) {
        printf("\n\tERROR: UNABLE TO REMOVE THE \".noblanks\" OUTPUT FILE\n");
      }
    }
  }

  setLastCore();
  saveCore(*coreFile);

  closeCFiles(inputFile, noBlnksFile, objFile, coreFile, litFile);
  prntTerminateMsg();

	if(xFlag == BOOL_TRUE && eFlag == BOOL_FALSE) {
		char eCmdLn[] = "./executor ";
		strcat(eCmdLn, objFileNm);
		system(eCmdLn);
	}
}

//prntTerminateMsg
//PRE:
//POST:
void prntTerminateMsg(void) {
  if(eFlag == BOOL_FALSE) {
    printf("\n\t\t*COMPILATION WAS SUCCESSFUL*\n");
  }
  else {
    printf("\n\t\t*COMPILATION WAS NOT SUCCESSFUL*\n");
  }
}

//initC
//PRE:
//POST:
int initC(int* argc, char* argv[], char* inputFileNm, char* noBlnksFileNm, char* objFileNm, char* coreFileNm, char* litFileNm, FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile, SymbolTable* st, SymbolTable* llt, SymbolTable* lt) {
  initFlags();
  if(!handleCCmdLn(argc, argv, inputFileNm)) {
    return BOOL_FALSE;
  }
  if(!openCFiles(inputFileNm, noBlnksFileNm, objFileNm, coreFileNm, litFileNm, inputFile, noBlnksFile, objFile, coreFile, litFile)) {
    return BOOL_FALSE;
  }
  initSTs(st, llt, lt);
}

//initFlags
//PRE:
//POST:
void initFlags(void) {
  oFlag = BOOL_FALSE;
  nFlag = BOOL_FALSE;
  eFlag = BOOL_FALSE;
	xFlag = BOOL_FALSE;
}

//initSTs
//PRE:
//POST:
void initSTs(SymbolTable* st, SymbolTable* llt, SymbolTable* lt) {
  initSymbolTable(st);
  initSymbolTable(llt);
  initSymbolTable(lt);
}

//handleCCmdLn
//PRE:
//POST:
int handleCCmdLn(int* argc, char* argv[], char* inputFileNm) {
  
  //FLAG HANDLER
  char c;
  while(--(*argc) > 0 && (*++argv)[0] == '-') {
    while(c = *++argv[0]) {
      switch(c) {
        case 'n':
          nFlag = BOOL_TRUE;
          break;
        case 'o':
          oFlag = BOOL_TRUE;
          break;
				case 'x':
					xFlag = BOOL_TRUE;
					break;
        default:
          printf("\n\tERROR: UNRECOGNIZED FLAG\n");
	  return BOOL_FALSE;	
      }
    }
  }

  //HANDLE REMIAINING CMD LN INPUT
  char tempFileNm[FILE_NAME_MAX];

  if (*argc == 1) {
    strcpy(tempFileNm, argv[0]);
    if(!handleCInputFileName(tempFileNm, inputFileNm)) {
      return BOOL_FALSE;
    }
  }
  if (*argc == 0) {  //NO REMAINING CMD LN INPUT
    strcpy(inputFileNm,"test1.transy"); 
  }
  
  return BOOL_TRUE;
}

//checkForCommand
//precondition: currentLine contains a (string) line from the noBlanksFile
//postCondition: returns a unique int depending on the command found in the first several characters of currentLine, returns -1 if no recognizable command was found
int checkForCommand(char* currentLine) {
  if ((strstr(currentLine,"=") != NULL) && (strstr(currentLine,",") == NULL) && (strncmp(currentLine,"LWRITE\"", 7) != 0) && (strncmp(currentLine, "IF(", 3) != 0)) {
    return ASSIGNMENT;
  }
  if (strncmp(currentLine,"DIM",3) == 0) {
    return DIM;
  }
  if (strncmp(currentLine,"READ",4) == 0) {
    return READ;
  }
  if (strncmp(currentLine,"WRITE",5) == 0) {
      return WRITE;
  }
  if (strncmp(currentLine,"STOP",4) == 0) {
    return STOP;
  }
  if (strncmp(currentLine,"CDUMP",5) == 0) {
    return CDUMP;
  }
  if (strncmp(currentLine,"LISTO",5) == 0) {
    return LISTO;
  }
  if (strncmp(currentLine,"NOP",3) == 0) {
    return NOP;
  }
  if (strncmp(currentLine,"GOTO",4) == 0) {
    return GOTO;
  }
  if (strncmp(currentLine,"IFA",3) == 0) {
    return IFA;
  } //CHECK FOR IF AFTER CHECK FOR IFA

  if (strncmp(currentLine,"AREAD",5) == 0) {
    return AREAD;
  }
  if (strncmp(currentLine,"AWRITE",6) == 0) {
    return AWRITE;
  }
  if (strncmp(currentLine,"SUBP",4) == 0) {
    return SUBP;
  }
  if (strncmp(currentLine,"LOOP-END",8) == 0) {
    return LOOPEND;
  }
  if (strncmp(currentLine,"LOOP",4) == 0) {
    return LOOP; //CHECK FOR LOOP AFTER CHECK FOR LOOPEND
  }
  if (strncmp(currentLine,"LREAD",5) == 0) {
    return LREAD;
  }
  if (strncmp(currentLine,"LWRITE",6) == 0) {
    return LWRITE;
  }
  if (strncmp(currentLine,"IF",2) == 0) {
    return IF;
  }
  if (strncmp(currentLine,"CLS",3) == 0) {
    return CLS;
  }
	
  return -1;
}

