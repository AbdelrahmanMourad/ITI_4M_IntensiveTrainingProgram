
/*	--------------------------------------------------------------------------------
	Session (3) Assignment (1):
	---------------------------
		Write a C code that ask the user to enter 10 values and save them in an array using a for loop.
		Then print the minimum and the maximum of the values.

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
	int array[10];
	array[0] = 0;
	int max = 0;
	int min = 0;

	for (int i = 0; i <= 9; i++)
	{
		//	scan number at a time
		printf("Please enter the %d-index number:\n", i);
		scanf("%d", &array[i]);

		//	compare:
		if (array[i] > max)
		{
			max = array[i];
		}
		else if (array[i] < min)
		{
			min = array[i];
		}
	}

	printf("Max number = %d \nmin mumber = %d", max, min);
}