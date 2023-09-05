/*****************************************
* 	Author: 			Abdelrahman Mourad
*	Creatuin Date:		16 MAR, 2023
*	Verion:				v1.0
*	Compiler:			GNU GCC
*******************************************/

#include <stdio.h>
#include "STD_TYPES.h"		
#include "Queue.h"


u8 Queue_u8Arr[QUEUE_SIZE]  = {0};         //  Not necessary to assign zero to save memory
s8 Queue_s8Front   = -1;           //  Global
s8 Queue_s8Rear    = -1;          //   Global

void Queue_voidEnQueue(u8 Copy_u8UserData)
{
    //  Check If the queue is full
    if (Queue_s8Rear >= (QUEUE_SIZE -1))      // Can make function would be better
    {
        printf("Queue IS Full\n");
        return;
    }
    else                                // msh hatfre2 bs for readability
    {
        if(Queue_s8Front == -1)
        {
            Queue_s8Front = 0;
        }
        Queue_s8Rear++;
        Queue_u8Arr[Queue_s8Rear] = Copy_u8UserData;
    }
}

u8   Queue_u8DeQueue(void)
{
    u8 Local_u8ReturnedValue;
    // Check if Queue is empty?
    if(Queue_s8Front == 1)              // Logical error you fixs
    {
        printf("Queue Is Empty\n");
        // return;
    }
    else            // Empty else is better practice than return (MISRA)
    {
        Local_u8ReturnedValue = Queue_u8Arr[Queue_s8Front];
        Queue_s8Front++;
    }

}

u8   Queue_u8Peak(void)
{
    // Check if Queue is empty?
    if(Queue_s8Front == 1)
    {
        printf("Queue Is Empty\n");
        // return;
    }
    else
    {
        return Queue_u8Arr[Queue_s8Front];
    }
}
 



