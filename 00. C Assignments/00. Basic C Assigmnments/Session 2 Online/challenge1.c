
/*
	---------------------------
	Session (2) Challenge (1):
	---------------------------

		For x = (	        5	)decimal
			  = (	0000 0101	)binary

			change the 4th bit from the right from 0 to 1
				, without changing any other bits.

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
	// Using Bitwise operators:
	// Use Bitwise OR
	int x = 5; 				// (0000   "0"  101)binary
	int y = 8; 				// (0000   "1"  000)binary
	x = x | y; 				// (0000   "1"  101)binary = (13)decimal
	
	// Print New Value.
	printf("The new value = %d", x);
}