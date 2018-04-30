//FILE: constants.h
//Kelsey Clater
//CS3024
//Fall 2017
//
//	contains all constants for compiler.c
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
***  general
*/
#define INIT 					0
#define	BOOL_TRUE			1
#define	BOOL_FALSE		0

/*
***  program specific
*/
#define OBJ_CODE_STR_SZ_MX		5 //"1000" can be represented by 4 bytes
#define OBJ_CODE_INT_SZ_MX		2 // 1000 can be represented by 2 bytes
#define LINE_MAX							5000
#define MEM_MAX								1000
#define CORE_ARRAY_MAX				1001
#define VAR_NAME_MAX					128
#define FILE_NAME_MAX					64
#define LINE_CHAR_MAX					256
#define LINE_VAR_MAX 					7
#define	DOUBLE_VAR_SIZE				1
#define CONSTANT_VAR_SIZE			1
#define LINE_LBL_SIZE					1
#define DBL_STR_MAX						20
#define UNDEF 								"0.123456789" //undefined string
#define UNDEF_DBL							0.123456789
#define STCK_ITM_MAX					50
#define LSTCK_ITM_MAX					7
#define EMPTY_LSTACK					-1
#define SENTINEL_OBJ					-1996
#define SENTINEL_LIT					"UNDEFINED"
#define CLS_LN_NUM						50


/*
*** tassignment constants
*/
#define ID1		0
#define ID		1
#define E			2
#define	OB		3
#define	CB		4
#define	OPN		5
#define CPN		6
#define OOP		7

/*
*** transducer constants
*/

#define TRDC_COL						10
#define TRDC_ROW						7
#define TRDC_COL_SIZE				7
#define TRDC_ROW_SIZE				10
#define TRDC_FN_NAME_MAX		2

//column constants (input)
#define ID_C			0
#define EQ_C			1
#define PLS_C			2
#define MNS_C			2
#define MLT_C			3
#define DIV_C			3
#define OPARAN_C	4
#define CPARAN_C	5
#define EXP_C			6
#define OBRAKT_C	7
#define CBRAKT_C	8
#define EOF_C			9

//row constants (top of s2)
#define NULL_R			0
#define EQ_R				1
#define PLS_R				2
#define MNS_R				2
#define MLT_R				3
#define DIV_R				3
#define OPARAN_R		4
#define OBRAKT_R		5
#define EXP_R				6

//function contstants
#define S1_CODE 		1
#define S2_CODE			2
#define U1_CODE			3
#define U2_CODE			4
#define U3_CODE			5
#define U4_CODE			6
#define ER_CODE			7


/*
***  command handler codes
*/
#define	DIM					0
#define READ				1
#define WRITE				2
#define STOP				3
	
#define CDUMP				5
#define LISTO				6
#define NOP					7
#define GOTO				8

#define IFA					10
#define	AREAD				11
#define AWRITE			12
#define SUBP				13
#define LOOP				14
#define LOOPEND			15
#define LREAD				16
#define LWRITE			17
#define IF					18
#define CLS					19
#define ASSIGNMENT	20

/*
*** operation object code
*/
#define LESS_THN					-1
#define LESS_THN_EQL_TO		-2
#define EQL_TO						-3
#define GRTR_THN					-4
#define GRTR_THN_EQL_TO		-5
#define NOT_EQL_TO				-6

#define SIN			-10
#define COS			-11
#define EXP			-12
#define ABS			-13
#define ALG			-14
#define ALN			-15
#define LOG			-16
#define SQR			-17

#define A_EQL			-1
#define A_OBRAKT	-2
#define A_EXP			-3
#define A_MLT			-4
#define A_DIV			-5
#define	A_PLS			-6
#define A_MNS			-7


/*
***  error handler codes
*/
#define UNIDENTIFIED_CMD	4
#define MISSING_ID				5
#define INVAL_ID					6
#define TOO_MANY_ID				7
#define INVAL_SYNTAX			8
#define UNIDENTIFIED_ID		9

#endif


