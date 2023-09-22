
/*
	--------------------
	Session (2) Lab (1):
	--------------------

		Ask user to enter 2 numbers, then print these numbers

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
	// Declaration
	int num1, num2;

	printf("\nThis program takes only integar numbers\n");

	// scaning 1st number
	printf("Please enter the 1st number\n");
	scanf("%d", &num1);

	// scaning 2nd number
	printf("Please enter the 2nd number\n");
	scanf("%d", &num2);

	// Printing
	printf("1st Number = %d \t,2nd Number = %d\n", num1, num2);
}