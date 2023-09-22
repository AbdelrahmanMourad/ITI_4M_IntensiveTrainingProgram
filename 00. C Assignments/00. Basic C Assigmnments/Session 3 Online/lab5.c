
/*	--------------------------------------------------------------------------------
	Session (3) Lab (5):
	--------------------

		Write a C code that ask the user to enter his ID, then program will print his name

	--------------------------------------------------------------------------------*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/

#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/

void main(void)
{
	int id;

	printf("Please enter your ID:  ");
	scanf("%d", &id);
	printf("\n");

	switch (id)
	{
	case 1234:
		printf("Welcome Ahmed");
		break;

	case 5678:
		printf("Welcome Youssef");
		break;

	case 1145:
		printf("Welcome Mina");
		break;

	default:
		printf("Wrong ID");
		break;
	}
}