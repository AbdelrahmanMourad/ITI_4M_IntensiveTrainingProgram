
/*	--------------------------------------------------------------------------------
	Session (4) Assignement (1):
	----------------------------

		Write a C program that ask the user to enter two numbers and print their summation
			, this program should never ends until the user close the window

	--------------------------------------------------------------------------------
*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/

#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Function ProtoTypes.
	---------------------------------------------------------------------------*/
// API(1):
void summation(void);

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/
void main(void)
{
	while (1)
	{
		summation();
	}
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/
// API(1):
void summation(void)
{
	// Declare All Variables.
	int n1, n2, sum;
	// Take n1, n2 Inputs From User.
	printf("\nPlease enter first number:	");
	scanf("%d", &n1);
	printf("Please enter second number:	");
	scanf("%d", &n2);
	// Calculations.
	sum = n1 + n2;
	// Output.
	printf("Summation = %d\n", sum);
}