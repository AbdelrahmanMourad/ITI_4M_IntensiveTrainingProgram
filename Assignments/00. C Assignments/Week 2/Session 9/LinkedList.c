/******************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		14 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
 *******************************************/ 
 //
 #include <stdio.h>
 #include <stdlib.h>			// maalloc,free
 #include "STD_TYPES.h"			// using u8/u16
 #include "LinkedList.h"
 //

 // Step -1- Create Structure {struct Node}, having two members (Data,PointerToNextNode)
 struct Node
 {
	 u8 Data;								//	member is variable Containing {Data} at this Node.
	 struct Node * PointerToNextNode;		//	member is Pointer to {Address} of the next Node.
 };
 

 //	Step -2- Create pointer {Head} to structure {Struct Node}, Then assign to adress {NULL}. "This is now first and only node in the LinkedList"
 struct Node * Head = NULL;
 

 //	------------------------------------------------------------------------------------------------
 //	Function Implementation:
 //	------------------------
 
 //	----------------
 //	Function ( 1 ):-
 //	----------------

 void LinkedList_voidInsertNodeAtTail(u8 UserData)				// Function Implementation
 {
	
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
	

	// Check if the linked list is empty or not? (// Head Pointer to the first Node created.)
	if(Head == NULL)
	{	
		// Head pointer points to the NewNode node
		Head = NewNode;
		
	}
	else	// head then point to something not null
	{
		// Last node in the linked list points to the created node
		// Search Last Node .. let point to new node .. Check last (NULL)
		struct Node * TempPtr;
		TempPtr = Head;

		//	Loop till rech the last node
		while(TempPtr->PointerToNextNode != NULL)
		{
			TempPtr = TempPtr->PointerToNextNode;		// Assignation.
		}
		
	// Last node 
	TempPtr->PointerToNextNode = NewNode;
	}

		NewNode -> Data = UserData;
		NewNode -> PointerToNextNode = NULL; 
 }


 //	----------------
 //	Function ( 2 ):-
 //	----------------
 void LinkedList_voidInsertNodeAtHead(u8 UserData)
 {

 }
 


 //	----------------
 //	Function ( 3 ):-
 //	----------------

 void LinkedList_voidInserNodeAtSpecificIndex (u8 UserDate)
 {

 }
 
 
 //	----------------
 //	Function ( 4 ):-
 //	----------------
 void LinkedList_voidDeleteNode(u8 Data)
 {
	struct Node * CurrentNode;				// Pointer {CurrentNode} to {struct Node}
	struct Node * PreviousNode;				// Pointer {PreviousNode} to {struct Node}
	//	Let both pointer point at 1st Node == Head

 }
 
 
 //	----------------
 //	Function ( 5 ):-
 //	----------------
 void LinkedList_voidSearchForData(u8 UserDate)
 {

 }
 
 

 //	----------------
 //	Function ( 6 ):-
 //	----------------
 void LinkedList_voidTraverse(void)
 {

 }
 