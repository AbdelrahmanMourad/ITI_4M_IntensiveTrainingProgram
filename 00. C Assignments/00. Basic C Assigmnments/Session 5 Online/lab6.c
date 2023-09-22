/*	--------------------------------------------------------------------------------
	Session (3) Lab (6):
	--------------------
		write c code that takes 4 numbers from the user
			,print them in reverse and sum
			,Using {while loop}

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
	// declare array of 4 element size
	int n[4];
	// counter {i = zero} , {sum = zero} to avoid garbage values
	int i = 0; //	initial value
	int sum = 0;

	//	Get input values from user {From 0 --> 3}
	//	Make Summation operation inside the while loop
	while (i <= 3) //	Condition
	{
		printf("please enter the  number:  \n");
		scanf("%d", &n[i]);
		sum += n[i];
		i++; //	Update {Increment}
	}

	printf("\nYou Entered\n");

	//	Display output values to user {from 3 --> 0}{Reversed}
	i = 3;		   //	initial value
	while (i >= 0) //	Condition
	{
		printf("%d\n", n[i]);
		i--; //	Update {Decrement}
	}

	printf("Sum = %d\n", sum);
}