/******************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		14 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
 *******************************************/ 
 //
 #include <stdio.h>
 #include "Stack.h"
 #include "STD_TYPES.h"			// using u8/u16
 

//  ============================================================================    //
//  Create structure of {Node}:
//  ---------------------------
struct Node {                                 //    Structure {Node} declaration
int data;                                     //    {data}      variable member contains "value stored"
struct Node *PtrToNextNode;                        //    {*NextNode} pointer  member contains "next node address"
};
//  ----------------------------------------------------------------------------    //


// Create 1st object (Our Head) ,Call it {top} point to NULL for now
struct Node * top = NULL;

struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = 10;


//  ============================================================================    //
//  Functions Implementation:
//  ------------------------

void    StackDSLinlkedList_voidPush  (u8 Copy_u8UserData)
{
	//  Create a new node using dynamic memory allocation and assign value to the node.
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = 10;
        newNode->PtrToNextNode = NULL;
        
		StackArray[++TOP] = Copy_u8UserData;
	
}

//            ------------------------------------------------------                  //
u8      StackDSLinlkedList_u8Pop     (void)
{

}

//            ------------------------------------------------------                  //
s8      StackDSLinlkedList_s8Top     (void)
{

}

//  ============================================================================    //