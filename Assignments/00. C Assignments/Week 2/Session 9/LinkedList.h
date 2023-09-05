/*****************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		14 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
 *******************************************/
 #ifndef Linked_List_H
 #define Linked_List_H
 //
 #include"STD_TYPES.h"
 // 
 //	Function Prototypes:
 // --------------------
 // 1
 void LinkedList_voidInsertNodeAtTail(u8 UserData);
 //2
 void LinkedList_voidInsertNodeAtHead(u8 UserData);
 // 3
 void LinkedList_voidInserNodeAtSpecificIndex (u8 UserDate);
 // 4
 void LinkedList_voidDeleteNode(u8 Data);
 // 5 
 void LinkedList_voidSearchForData(u8 UserDate);
 // 6
 void LinkedList_voidTraverse(void);
 //
 
 #endif