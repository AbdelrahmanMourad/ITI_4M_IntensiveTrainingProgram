#include <stdio.h>

/*	--------------------------------------------------------------------------------
	Session (4) Assignement (5):
	----------------------------

		Write a C program to act as simple calculator
			, first it will ask the user to enter the operation ID
			, depending on the operation
			, the program will ask the user either to enter 1 operand or 2 operands
				and the program will execute the operation and print the result.

		Each operation should be implemented in a stand a long function.

	---------
	Database:
	---------

	-----------------------------------------------
	ID			Operation		Number of Operands
	-----------------------------------------------
	1			Add					2
	2			Subtract			2
	3			Multiply			2
	4			Divide				2
	5			And					2
	6			Or					2
	7			Not					1
	8			Xor					2
	9			reminder			2
	10			Increment			1
	11			Decrement			1
	-----------------------------------------------

	--------------------------------------------------------------------------------
*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/
#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Function ProtoTypes.
	---------------------------------------------------------------------------*/
void PrintWelcomeScreen(void);
int SCAN(void);
int ADD(int n1, int n2);
int SUBTRACT(int n1, int n2);
int MULTIPLY(int n1, int n2);
int DIVIDE(int n1, int n2);
int AND(int n1, int n2);
int OR(int n1, int n2);
int NOT(int n);
int XOR(int n1, int n2);
int REMAINDER(int n1, int n2);
int INCREMENT(int n);
int DECREMENT(int n);
void Calculator(char Operation, int *arr);

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/
void main(void)
{
	// Var. To Take The Type Of Operation From User.
	char operand;
	
	//	Welcoom User , And Ask for operation type:
	PrintWelcomeScreen();
	
	// Take The Operand From User Input.
	scanf("%s", &operand);

	// Array To Store 2 Data cells inside.
	int arr[2];

	// Initiate Calculator.
	Calculator(operand, arr);
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/
void PrintWelcomeScreen(void)
{
	printf("\nWelcome to the calcularot program\n\n");
	printf("PLease Enter the operation you need:\n");
	printf("   \"  +,-,*,/,&,|,!,XOR(^),%,Increment(i),Decrement(d) \"\n\n");
}

int SCAN(void)
{
	int input;
	printf("Please enter a numbers:\t");
	scanf("%d", &input);
	return input;
}

int ADD(int n1, int n2)
{
	int R = n1 + n2;
	printf("result = %d", R);
	return R;
}

int SUBTRACT(int n1, int n2)
{
	int R;
	if (n1 > n2)
	{
		R = n1 - n2;
	}
	else
	{
		R = n2 - n1;
	}

	printf("result = %d", R);
	return R;
}

int MULTIPLY(int n1, int n2)
{
	int R = n1 * n2;
	printf("result = %d", R);
	return R;
}

int DIVIDE(int n1, int n2)
{
	int r;
	(n1 > n2) ? (n1 / n2) : (n2 / n1);
	printf("result = %d", r);
	return r;
}

int AND(int n1, int n2)
{
	int R = n1 & n2;
	printf("result = %d", R);
	return R;
}

int OR(int n1, int n2)
{
	int R = n1 | n2;
	printf("result = %d", R);
	return R;
}

int NOT(int n)
{
	int R = !n;
	printf("result = %d", R);
	return R;
}

int XOR(int n1, int n2)
{
	int R = n1 ^ n2;
	printf("result = %d", R);
	return R;
}

int REMAINDER(int n1, int n2)
{
	int R;
	if (n1 > n2)
	{
		R = n1 % n2;
	}
	else
	{
		R = n2 % n1;
	}

	printf("result = %d", R);
	return R;
}

int INCREMENT(int n)
{
	n++;
	printf("result = %d", n);
	return n;
}

int DECREMENT(int n)
{
	n--;
	printf("result = %d", n);
	return n;
}

void Calculator(char Operation, int *arr)
{
	switch (Operation)
	{
	//	Addition
	case ('+'): // 'singleQuotes' for ascii value.
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		ADD(arr[0], arr[1]);
		break;
	}
	//	Subtraction
	case ('-'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		SUBTRACT(arr[0], arr[1]);
		break;
	}
	//	Multiplication
	case ('*'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		MULTIPLY(arr[0], arr[1]);
		break;
	}
	//	Division
	case ('/'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		DIVIDE(arr[0], arr[1]);
		break;
	}
	//	AND
	case ('&'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		AND(arr[0], arr[1]);
		break;
	}
	//	OR
	case ('|'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		OR(arr[0], arr[1]);
		break;
	}
	//	NOT
	case ('!'):
	{
		arr[0] = SCAN();
		NOT(arr[0]);
		break;
	}
	//	XOR
	case ('^'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		XOR(arr[0], arr[1]);
		break;
	}
	//	Remainder
	case ('%'):
	{
		arr[0] = SCAN();
		arr[1] = SCAN();
		REMAINDER(arr[0], arr[1]);
		break;
	}
	//	Increment
	case ('i'):
	{
		arr[0] = SCAN();
		INCREMENT(arr[0]);
		break;
	}
	//	Decrement
	case ('d'):
	{
		arr[0] = SCAN();
		DECREMENT(arr[0]);
		break;
	}
	//	Other
	default:
	{
		printf("\nWrong answer, Please try again!\n");
		break;
	}
	}
}