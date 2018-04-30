//FILE: fileHandler.c
//KELSEY CLATER
//CS3024
//FALL 2017
//
//
//

#include "fileHandler.h"

//isFileType
//PRE: fileName contains the name of a file, fileType contains a file type
//POST: returns 1 if the file type of fileName matches fileType, else returns 0 and prints an error msg
int isFileType(char* fileName, char* fileType) {
  if (strstr(fileName, fileType) != NULL) {
    return BOOL_TRUE;
  }
  printf("\n\tERROR: INVALID INPUT FILE TYPE\n");
  return BOOL_FALSE;
}

//handleCInputFileName
//PRE: tempFileName holds a string
//POST: returns 0 if file was of wrong type, returns 1 if av valid file name was found and inputFileName holds a valid file name
int handleCInputFileName(char* tempFileName, char* inputFileName) {
  char delim = '.', *charptr, transyFileType[] = ".transy";

  /*CHECK FOR FILE TYPE, IF NONE, APPEND, TRANSYFILETYPE*/
  charptr = strchr(tempFileName, delim);
  if (charptr != NULL) { 
    if (!isFileType(tempFileName, transyFileType)) { //INVAL FILE TYPE
      return BOOL_FALSE;
    }
    else { //VALID .TRANSY FILE TYPE
      strcpy(inputFileName,tempFileName);
    }
  }
  else { 
    strcpy(inputFileName,strcat(tempFileName,transyFileType));
  }
  return BOOL_TRUE;
}


//handleEInputFileName
//PRE: tempFileName holds a string
//POST: returns 0 if file was of wrong type, returns 1 if av valid file name was found and inputFileName holds a valid file name
int handleEInputFileName(char* tempFileName, char* inputFileName) {
  char delim = '.', *charptr, objFileType[] = ".obj";

  /*CHECK FOR FILE TYPE, IF NONE, APPEND, OBJFILETYPE*/
  charptr = strchr(tempFileName, delim);
  if (charptr != NULL) { 
    if (!isFileType(tempFileName, objFileType)) { //INVAL FILE TYPE
      return BOOL_FALSE;
    }
    else { //VALID .OBJ FILE TYPE
      strcpy(inputFileName,tempFileName);
    }
  }
  else { 
    strcpy(inputFileName,strcat(tempFileName,objFileType));
  }
  return BOOL_TRUE;
}



//changFileType
//PRE: fileName contains the old file name, newType contains the desired file type
//POST	: newFileName contains the old fileName with the new file type concatenated to the root of fileName
void changeFileType (char* fileName, char* newType, char* newFileName) {
  int i = 0;;
  char fileRoot[FILE_NAME_MAX];
  while (fileName[i] != '.') {
    fileRoot[i] = fileName[i];
    ++i;
  }
  fileRoot[i] = '\0';
  strcpy(newFileName, fileRoot);
  strcat(newFileName, newType);
}


//openCFiles
//PRE:
//POST:
int openCFiles(char* inputFileNm, char* noBlnksFileNm, char* objFileNm, char* coreFileNm, char* litFileNm, FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile) {
  char noBlnksFileType[]=".noblanks", objFileType[] = ".obj", coreFileType[] = ".core", litFileType[] = ".literal";
  
  *inputFile = fopen(inputFileNm,"r+");
  if (*inputFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN THE FILE: %s!\n", inputFileNm);
    return BOOL_FALSE;
  }
	
  changeFileType(inputFileNm, noBlnksFileType, noBlnksFileNm);
  *noBlnksFile = fopen(noBlnksFileNm,"w+");
  if (*noBlnksFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".noblanks\" FILE!\n");
    return BOOL_FALSE;
  }
	
  changeFileType(inputFileNm, objFileType, objFileNm);
  *objFile = fopen(objFileNm, "w+");
  if (*objFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".obj\" FILE!\n");
    return BOOL_FALSE;
  }

  changeFileType(inputFileNm, litFileType, litFileNm);
  *litFile = fopen(litFileNm, "w+");
  if(*litFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".literal\" FILE!\n");
    return BOOL_FALSE;
  }

  changeFileType(inputFileNm, coreFileType, coreFileNm);
  *coreFile = fopen(coreFileNm, "w+");
  if(*coreFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".core\" FILE!\n");
    return 0;
  }
}


//closeCFiles
//PRE:
//POST:
void closeCFiles(FILE** inputFile, FILE** noBlnksFile, FILE** objFile, FILE** coreFile, FILE** litFile) {
  fclose(*inputFile);
  fclose(*noBlnksFile);
  fclose(*objFile);
  fclose(*coreFile);
  fclose(*litFile);
}


//openEFiles
//PRE: objFileNm contains file name for the function to try to open
//POST: if a file does not open, fn returns 0 and an error message is printed, else returns 1 if all files open
int openEFiles(char* objFileNm, char* coreFileNm, char* litFileNm, FILE** objFile, FILE** coreFile, FILE** litFile) {
  char coreFileType[]=".core", litFileType[]=".literal";  

  *objFile = fopen(objFileNm, "r");
  if (*objFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".obj\" FILE!\n");
    return BOOL_FALSE;
  }

  changeFileType(objFileNm, coreFileType, coreFileNm);
  *coreFile = fopen(coreFileNm, "r");
  if(*coreFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".core\" FILE!\n");
    return BOOL_FALSE;
  }

  changeFileType(objFileNm, litFileType, litFileNm);
  *litFile = fopen(litFileNm, "r");
  if(*litFile == NULL) {
    printf("\n\tERROR: UNABLE TO OPEN \".literal\" FILE!\n");
    return BOOL_FALSE;
  }

  return BOOL_TRUE;
}
