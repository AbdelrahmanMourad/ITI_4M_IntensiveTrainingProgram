
/*	--------------------------------------------------------------------------------
	Session (4) Lab (7):
	--------------------

			write c code that takes 4 numbers from the user
				,print them in reverse and sum
				,Using {do..while loops}
	--------------------------------------------------------------------------------
*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/
#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Function ProtoTypes.
	---------------------------------------------------------------------------*/

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/

void main(void)
{
	//	Declare 4 element array
	int n[4];
	//	Initialize counter start from {zero}{Initial value}
	int i = 0;
	//	Initialize {sum=zero} to avid garbage ,and store result inside
	int sum = 0;

	//	Take input values from the user {from 0 to 3}
	do //	different from while as it excute once before start checking condition.
	{
		printf("please enter the  number:  \n");
		scanf("%d", &n[i]);
		sum += n[i];
		i++;
	} while (i <= 3);

	printf("\nYou Entered\n");

	//	Display output values to user {from 3 to 0}{Reversed}
	i = 3; // Initial value
	//	Loop
	do
	{
		printf("%d\n", n[i]);
		i--;
	} while (i >= 0);

	//	Dispay the summation
	printf("\nSum = %d\n", sum);
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/
