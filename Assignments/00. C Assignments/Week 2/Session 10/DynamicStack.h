/*****************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		16 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
*******************************************/
/*Version contrl:*/
/*****************************************
 * Version      Date            Author              Description
 * V1.0         16 Mar, 2023    Abdelrahman Mourad  initial Creation
 * V1.1         23 APR. 2023    Ahmed               Fix Push Bug
 ******************************************/

 #ifndef DYNAMIC_STACK_H                // Header Guard File Part -1-
 #define DYNAMIC_STACK_H                // Header Guard File Part -2-
// #include:
 #include"STD_TYPES.h"
// #define
 #define    TRUE        1                   // Text Replacement
 #define    FALSE       0                   // Text Replacement
 

void DynamicStack_voidPush(u8 Copy_u8UserData);
u8   DynamicStack_u8Pop(void);
u8   DynamicStack_u8Top(void);

#endif





