
/*
	---------------------------
	Session (2) Challenge (2):
	---------------------------

		For x = (	        5	)decimal
			  = (	0000 0101	)binary

			Find if the 3d bit from the right is equal to 0 or 1.

*/

/*  ---------------------------------------------------------------------------
							Library Included
---------------------------------------------------------------------------*/
#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Driving Code
	---------------------------------------------------------------------------*/

void main(void)
{
	// Using Bitwise operators: {right shift}:

	int x = 5;					// (0000 0 "1" 01)binary
	x = x >> 2; 				// (0000 000  "1")binary

	if (x = 1)
	{
		printf("The target bit value = 1\n");
	}
	else
	{
		printf("The target bit value = 0\n");
	}
}