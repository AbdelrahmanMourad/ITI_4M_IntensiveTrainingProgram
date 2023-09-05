/*****************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		15 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
*******************************************/

/*  ---------------------------------------------------------------------------------
Documentation:
--------------
Implementation of stack data structure using Linked List.
Using a linked list means that we are going to store the information 
in the form of nodes following the rules of the stack. 
The stack rule says that insertion and deletion should take place at the same end, 
i.e., Last In, First Out(LIFO).       
---------------------------------------------------------------------------------   */

 #ifndef STACKDSLINKEDLIST_H                // Header Guard File Part -1-
 #define STACKDSLINKEDLIST_H                // Header Guard File Part -2-
 
 // #include:
 #include"STD_TYPES.h"

// #define
 #define    TRUE        1                   // Text Replacement
 #define    FALSE       0                   // Text Replacement
 




//  ----------------------------------------------------------------------  //
//	Function Prototypes:
//  --------------------
//
void    StackDSLinlkedList_voidPush  (u8 Copy_u8UserData);
u8      StackDSLinlkedList_u8Pop     (void);
s8      StackDSLinlkedList_s8Top     (void);





/* 
u8      Stack_u8IsEmpty (void);
u8      Stack_u8IsFull  (void); 
*/
 


//  ----------------------------------------------------------------------  // 

 #endif                            // Header Guard File Part -3-


























 
// Declare and Reserve a new node pointer to struct using "DynamicMemtoryAllocation" in heap {malloc}, at sizeof the structure {Node}
struct Node * NewNode = (struct Node *) malloc(sizeof(struct Node));								// Assign to "pointer to struct"
//	---------------------------------------------------------------------------------------------------------------------------------
//	-											 Illustation 																		-
//	-											-------------																		-
//  -	struct Node * NewNode 						 	= (struct Node *) 							malloc(sizeof(struct Node)		-
// 	-	Pointer {* NewNode} to structure {struct Node} 	= {Casting the void output of malloc}		malloc in heap					-
//	---------------------------------------------------------------------------------------------------------------------------------
//	Notes:																															-
//	------																															-
// 			1-	Declare and Reserve a new node pointer to structure {NewNode}														-
// 			2-	malloc return void pointer (Address), we cast to pointer to struct inside()											-
// 			3-	then assign to pointer NewNode																						-
// 			4-	Note NewNode pointer is in stack(local), as long as program ends it ends also										-
// 			5-	malloc stored in heap not deleted like stack																		-
//	---------------------------------------------------------------------------------------------------------------------------------











