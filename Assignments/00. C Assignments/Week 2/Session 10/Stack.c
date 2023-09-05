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
 //#include "LIB/STD_TYPES.h"	// using u8/u16
 //#include "LinkedList.h"
 // #include <stdlib.h>			// maalloc,free functions.



/*	Array size should be determined by user:
	Without opening the C-file.				 */
u8 StackArray[STACK_SIZE] = {0};

s8 TOP = -1;



 void Stack_voidPush(u8 Copy_u8UserData)
 {
	if(Stack_u8IsFull() == 1)
	{
		printf("Stack is full\n");
		return;
	}
	else
	{
		/*	TOP++;
			StackArray[TOP] = Copy_u8UserData;	*/		
		StackArray[++TOP] = Copy_u8UserData;
	}

 }

u8 Stack_u8Pop(void)
{
	if(Stack_u8IsEmpty() == TRUE)
	{
		printf("Stack is Empty\n");
		return;
	}
	else
	{
		/*	u8 ReturenedValue = StackArray[Top];
			TOP--
			return ReturenedValue;	*/
		return StackArray[TOP--];
	}
}

s8 Stack_s8Top(void)
{
	if(Stack_u8IsEmpty() == TRUE)
	{
		printf("Stack is empty\n");
		return;
	}
	else
	{
		return TOP;		// Index(TOP) = no. of elements-1
	}
}

u8 Stack_u8IsEmpty(void)
{
	u8 Status;				//	MISRA To avoid multiple return.
	if(TOP == -1)
	{
		// don't print as it will appear twice when calling push or pull
		Status = TRUE;			// True
	}
	else
	{
		Status = FALSE;			// False
	}
	return Status;

	/*	//Can replace all the above, But debatedly not recommended:
		return (TOP == -1) ? TRUE : FALSE;		//	Tertnary Operator	
		// Try not to use it very often						*/
}

u8 Stack_u8IsFull(void)
{
	u8 Status;				//	MISRA To avoid multiple return.
	if(TOP == (STACK_SIZE-1))
	{
		// don't print as it will appear twice when calling push or pull
		Status = TRUE;			// True
	}
	else
	{
		Status = FALSE;			// False
	}
	return Status;
	
}
