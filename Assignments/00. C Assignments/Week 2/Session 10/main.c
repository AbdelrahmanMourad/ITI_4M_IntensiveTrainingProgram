#include <stdio.h>
#include <stdlib.h>              // malloc library
#include "STD_TYPES.h"		
#include "DynamicStack.h"

void main(void)
{
	u8 Local_u8PrintedValue;

	DynamicStack_voidPush(2);
	DynamicStack_voidPush(3);
	DynamicStack_voidPush(6);

	Local_u8PrintedValue = DynamicStack_u8POP();
	printf("%d\n",Local_u8PrintedValue);
	Local_u8PrintedValue = DynamicStack_u8POP();
	printf("%d\n",Local_u8PrintedValue);
}