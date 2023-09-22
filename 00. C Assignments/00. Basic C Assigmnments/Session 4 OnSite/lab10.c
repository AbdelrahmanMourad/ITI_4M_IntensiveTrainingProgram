
/*	--------------------------------------------------------------------------------
	Session (4) Lab (10):
	---------------------

		Make a Calculator:
			write c code that takes 2 numbers from the user
				,Takes the type of operation needed:	{+,-,*,/}
				,print the result
				,Using user-defined function
		-----
		Hint:
		-----
			-->{{	To get ascii address of operator use 'singleQuote' , Ex:'+'		}}<--

	--------------------------------------------------------------------------------
*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/

#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Function ProtoTypes.
	---------------------------------------------------------------------------*/
int add(int n1, int n2);	  // API(1):
int sub(int n1, int n2);	  // API(2):
int multiply(int n1, int n2); // API(3):
int division(int n1, int n2); // API(4):

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/
void main(void)
{
	//	Declare variable to take operation type from user.
	char operation;
	//	Declare 2 variables to take from the user.
	int n1, n2;
	//	Declare container for the result, equal zero to avoid any garbage.
	int Result = 0;

	// Taking 2 numbers from the user:
	printf("Please enter 2 numbers:\n");
	scanf("%d%d", &n1, &n2);

	// Taking operation type from the user:
	printf("Please enter operation: +,-,*,/ \n");
	scanf(" %c", &operation); // space to avoid buffer error! (It reads "enter key" as the operation.)

	// switching to appropriate function
	switch (operation)
	{
	case ('+'):
		Result = add(n1, n2);
		break;
	case ('-'):
		Result = sub(n1, n2);
		break;
	case ('*'):
		Result = multiply(n1, n2);
		break;
	case ('/'):
	{
		Result = division(n1, n2);
	}
	break;
	}

	// Print the result to user.
	printf("The result = %d\n", Result);
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/

// API(1):
int add(int n1, int n2)
{
	int sum = n1 + n2;
	return sum;
}

// API(2):
int sub(int n1, int n2)
{
	int _sub;
	if (n1 > n2)
	{
		_sub = n1 - n2;
	}
	else
	{
		_sub = n2 - n1;
	}

	return _sub;
}

// API(3):
int multiply(int n1, int n2)
{
	int multiply = n1 * n2;
	return multiply;
}

// API(4):
int division(int n1, int n2)
{
	int division;

	// if one of them equals zero
	if (n1 == 0)
	{
		printf("Warning, please enter non-Zero numbers\n");
		return 0;
	}
	if (n2 == 0)
	{
		printf("Warning, please enter non-Zero numbers\n");
		return 0;
	}

	// Normal process,	to avoid division of small over the big.
	if (n1 > n2)
	{
		division = n1 / n2;
	}
	else
	{
		division = n2 / n1;
	}
	return division;
}
