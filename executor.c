//FILE: executor.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//  DRIVER FOR EXECUTOR: GIVEN VALID ".obj",".core", AND ".literal" FILES, EXECUTOR WILL EXECUTE THE ".obj" FILE
//
//  ALL COMMANDS WITH THE EXCEPTION OF ASSIGNMENT ARE WORKING
//  CORE IS NOT LOADING CORRECTLY, ADT IS UNDER CONSTRUCTION
//
//

#include "executor.h"

int main (int argc, char**argv) {

  //ADT DEC
  Core core;
  Range range;
  Object obj;
  Literal lit;
  LStack lstack;

  //VARIBALE DECLARATIONS
  char objFileNm[FILE_NAME_MAX], coreFileNm[FILE_NAME_MAX], litFileNm[FILE_NAME_MAX];
  FILE *objFile, *coreFile, *litFile;
  int next;

  //INIT
  if(!initE(&range, &argc, argv, objFileNm, coreFileNm, litFileNm, &objFile, &coreFile, &litFile, &core, &obj, &lit, &lstack)) {
    eFlag = BOOL_TRUE;
    prntTerminateMsg();
    return 0;
  }
  
  //MAIN BODY
  pc = 0;
  next = pc + 1;
  int cmdFlag = retCmd(&obj, pc);
  while (cmdFlag != SENTINEL_OBJ && eFlag == BOOL_FALSE && sFlag == BOOL_FALSE) {
    switch(cmdFlag){
      case DIM:
        edim(&obj, &core, &range);
        break;
      case READ:
        eread(&obj, &core);
        break;
      case WRITE:
				ewrite(&obj,&core);
				break;
      case STOP:
				estop();
				break;
      case CDUMP:
				ecdump(&obj, &core);
				break;
      case LISTO:
				elisto(&obj);
				break;
      case NOP:
				enop();
				break;
      case GOTO:
				egoto(&obj, &next);	
				break;
      case IFA:
				eifa(&obj, &core, &next);
				break;
      case AREAD:
				earead(&obj, &core, &range);
				break;
      case AWRITE:
				eawrite(&obj, &core, &range);
				break;
      case SUBP:
				esubp(&obj,&core);
				break;
      case LOOPEND: 
				eloopend(&obj, &core, &lstack, &next);
				break;
      case LOOP:
				eloop(&obj, &core, &lstack, &next);
				break;
      case LREAD:
				elread(&obj, &lit);
				break;
      case LWRITE:
				elwrite(&obj, &lit);
				break;
      case IF:
				eif(&obj, &core, &next);
				break;
      case CLS:
				ecls();
				break;
      case ASSIGNMENT:
				eassignment(&obj, &core, &range);
				break;
      case SENTINEL_OBJ:
        break;
      default:
        break;
    }
    pc = next;
    next = pc+1;
    cmdFlag = retCmd(&obj, pc);
  }
  
  //FINAL
  //check for stop
  if(sFlag != BOOL_TRUE && eFlag == BOOL_FALSE) {
    printf("\n\tERROR: MISSING TERMINATING COMMAND\n");
    eFlag = BOOL_TRUE;
  }
  //close files
  fclose(objFile);
  fclose(coreFile);
  fclose(litFile);
  prntTerminateMsg();
  return 0;
}

/*
*** FUNCTION DEFS
*/

//initE
//PRE:
//POST:
int initE (RangePtr rangePtr, int* argc, char* argv[], char* objFileNm, char* coreFileNm, char* litFileNm, FILE** objFile, FILE** coreFile, FILE** litFile,
CorePtr corePtr, ObjectPtr objPtr, LiteralPtr litPtr, LStackPtr lstackPtr) {
  initFlags();
  initRange(rangePtr);
  initLStack(lstackPtr);
  if (!handleECmdLn(argc, argv, objFileNm)) {
    return BOOL_FALSE;
  }
  if(!openEFiles(objFileNm, coreFileNm, litFileNm, objFile, coreFile, litFile)) {
    return BOOL_FALSE;
  }
  if(!loadCore(corePtr, *coreFile)) {
    return BOOL_FALSE;
  }
  if(!checkCompilation) {
    printf("\n\tERROR: CANNOT EXECUTE FILE THAT FAILED TO COMPILE\n");
    return BOOL_FALSE;
  }
  if(!loadObj(objPtr, *objFile)) {
    return BOOL_FALSE;
  }
  if(!loadLit(litPtr, *litFile)) {
    return BOOL_FALSE;
  }
}


//initFlags
//PRE: all flags are created
//POST: all command flags, and other flags are set to 0
void initFlags(void) {
  rFlag = BOOL_FALSE;
  xFlag = BOOL_FALSE;
  xFlag = BOOL_FALSE;
  eFlag = BOOL_FALSE;
  sFlag = BOOL_FALSE;
}

//handleECmdLn
//PRE:
//POST: parses the command line for flags and file names, if no filetype was found, .obj will be appended, if no filename was found, inputFileName will default to "test1.obj"
int handleECmdLn(int* argc, char* argv[], char* inputFileName){
  
  //FLAG HANDLER
  char c;
  while(--(*argc) > 0 && (*++argv)[0] == '-') {
    while(c = *++argv[0]) {
      switch(c) {
        case 'r':
          rFlag = BOOL_TRUE;
          break;
        case 'x':
          xFlag = BOOL_TRUE;
          break;
        case 'z':
          zFlag = BOOL_TRUE;
          break;
        default:
          printf("\n\tERROR: UNRECOGNIZED FLAG\n");
	  return BOOL_FALSE;	
      }
    }
  }

  //HANDLE REMIAINING CMD LN INPUT
  char tempFileName[FILE_NAME_MAX];

  if (*argc == 1) {  //INPUT FOUND ON CDM LN
    strcpy(tempFileName, argv[0]);
    if (!handleEInputFileName(tempFileName, inputFileName)) {
      return BOOL_FALSE;
    } 
  }
  
  if (*argc == 0) {  //NO REMAINING CMD LN INPUT
    strcpy(inputFileName,"test1.obj"); 
  }
  
  return BOOL_TRUE;
}

//prntTerminateMsg
//PRE:
//POST: if eFlag is true, a success message is printed, else is not success message is printed
void prntTerminateMsg(void) {
  if(eFlag == BOOL_FALSE) {
    printf("\n\t\t*EXECUTION WAS SUCCESSFUL*\n");
  }
  else {
    printf("\n\t\t*EXECUTION WAS NOT SUCCESSFUL*\n");	
  }
}
