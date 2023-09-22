
/*	--------------------------------------------------------------------------------
	Session (3) Assignment (3):
	---------------------------

		Write a code that will ask the user to enter 3 numbers
			, the program will print the maximum number of them.

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
	// Declatation
	int n1, n2, n3, max;

	//	Scan
	printf("Enter Number 1:		");
	scanf("%d", &n1);
	printf("Enter Number 2:		");
	scanf("%d", &n2);
	printf("Enter Number 3:		");
	scanf("%d", &n3);

	//	Check Maximum
	if (n1 > n2) // Compare n1&n2
	{
		max = n1;

		if (n1 > n3) // Compare n1&n3
		{
			// max = n1;
			printf("Maximum nuumber is	%d", max);
		}
		else
		{
			max = n3;
			printf("Maximum nuumber is	%d", max);
		}
	}
	else
	{
		max = n2;
		printf("Maximum nuumber is	%d", max);

		if (n2 > n3) // Compare n2&n3
		{
			// max = n2;
			printf("Maximum nuumber is	%d", max);
		}
		else
		{
			max = n3;
			printf("Maximum nuumber is	%d", max);
		}
	}
}
