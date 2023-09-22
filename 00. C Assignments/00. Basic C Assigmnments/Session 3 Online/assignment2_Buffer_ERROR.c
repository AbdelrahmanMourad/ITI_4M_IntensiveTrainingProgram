/*	Search .. Buffer Errors! */


/*	--------------------------------------------------------------------------------
	Session (3) Assignment (2):
	---------------------------

		Write a C code that ask the user to enter his ID
			, if the ID is valid it will ask the user to enter his password
			, if the password is correct the program will print the user name
			, if the password is incorrect the program will print Incorrect Password.

			In case of not existing ID
				, the program will print Incorrect ID

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
	//

	//	Right ID
	int id1 = 1234;
	//	entered ID
	int id2;

	//	Right Password
	int pass1 = 1234;
	//	entered Password
	int pass2;

	//	Scan ID from user
	printf("\nEnter ID:	\n");
	scanf(" %d\n", &id2);

	// check if id is correct
	if (id2 == id1)
	{
		printf("\nEnter Password:	");
		scanf(" %d\n", &pass2);

		//	Check if Password is correct
		if (pass2 == pass1)
		{
			printf("Logged In\n");
		}
		else
		{
			printf("Incorrect Password\n");
		}
	}
	else
	{
		printf("Incorrect ID\n");
	}
}
