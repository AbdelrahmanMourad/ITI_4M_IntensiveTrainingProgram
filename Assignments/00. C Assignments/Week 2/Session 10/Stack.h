/*****************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		15 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
*******************************************/
 
 #ifndef STACK_H
 #define STACK_H
 
 #include"STD_TYPES.h"

 #define    STACK_SIZE  5       // Set the stack size
 #define    TRUE        1       // Text Replacement
 #define    FALSE       0       // Text Replacement
 
 //	Function Prototypes:
 // --------------------

void    Stack_voidPush  (u8 Copy_u8UserData);
u8      Stack_u8Pop     (void);
s8      Stack_s8Top     (void);
u8      Stack_u8IsEmpty (void);
u8      Stack_u8IsFull  (void);
 
 #endif