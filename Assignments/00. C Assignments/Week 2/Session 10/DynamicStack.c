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
#include <stdio.h>
#includ <stdlib.h>              // malloc library
#include "STD_TYPES.h"		
#include "DynamicStack.h"

struct Node
{
    u8 Data;
    struct Node * PointerToPreviousNode;
};

struct Node * TOP = NULL;

void DynamicStack_voidPush(u8 Copy_u8UserData)
{
    // Check later if the Heap is full <--------

    //Create New Node
    struct Node * NewNode = (struct Node *)malloc(sizeof(Struct Node));
    //Set the userData to the node's data
    NewNode -> Data = Copy_u8UserData;
    NewNode -> PointerToPreviousNode = TOP;
    //Set the TOP Point on the last Pushed Node
    TOP = NewNode;
}

u8   DynamicStack_u8Pop(void)
{
    //  Check whethe the stack is empty or not

    u8 Local_u8ReturnedValue;
    //Create and Declare Pointer to Node, static allcated
    struct Node * TempPtr;
    //  Set TempPtr To Point to what the head pointer Points
    TempPtr = TOP;
    //  Set TOP to point to the second Last Node
    TOP = TempPtr -> PointerToPreviousNode;
    //  Store The first Poped Data into variable
    Local_u8ReturnedValue = TempPtr->Data;
    //  Free the first POPed Node
    free(TempPtr);
    //  Return The POPed Data
    return Local_u8ReturnedValue;
}

u8   DynamicStack_u8Top(void)
{
    //  Check whethe the stack is empty or not
    retutn TOP->Data;
}
 



