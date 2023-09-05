/******************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		14 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
 *******************************************/ 
 //
 #include <stdio.h>
 #include "Queue.h"
 #include "STD_TYPES.h"			// using u8/u16
 
void main(void)
{
	u8 Local_u8ReturnedValue;
	Queue_voidEnQueue(3);
	Queue_voidEnQueue(6);
	Queue_voidEnQueue(9);
	//	logical Error (more than the size)
	//	Easy to solve
	Queue_voidEnQueue(12);
	Queue_voidEnQueue(15);
	//	ok
	Local_u8ReturnedValue = Queue_u8DeQueue();
	Local_u8ReturnedValue = Queue_u8DeQueue();
	Local_u8ReturnedValue = Queue_u8DeQueue();
	Local_u8ReturnedValue = Queue_u8DeQueue();
	//	logical Error (more than the size)
	//	Easy to solve
	Local_u8ReturnedValue = Queue_u8DeQueue();
	Local_u8ReturnedValue = Queue_u8DeQueue();

	//	Logical error (EnQueue,DeQueue,EnQueue,Dequeue) more than size
	//	Pretty Hard to solve
	//	Search for : Circular Queue <--------------- Programiz

}