
/*	--------------------------------------------------------------------------------
	Session (3) Lab (1):
	--------------------
		Use Sizeof() Operator.

	--------------------------------------------------------------------------------
*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/
#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/
void main(void)
{
	char *ptr1;
	int *ptr2;

	printf("The size of ptr1 = %d-byte\n", sizeof(ptr1)); //	const for this hardware
	printf("The size of ptr1 = %d-byte\n", sizeof(ptr2)); //	const for this hardware
}