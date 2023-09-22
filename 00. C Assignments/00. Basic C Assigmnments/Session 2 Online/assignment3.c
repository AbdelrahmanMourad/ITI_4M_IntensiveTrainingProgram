/*
	---------------------------
	Session (2) Assignment (3):
	---------------------------

		Write a code that scan 3 numbers from the user
			and print them in reversed order

		Input:
			Please Enter Number 1:	7
			Please Enter Number 2:	8
			Please Enter Number 3:	9
		Output:
			Number 3:	9
			Number 2:	8
			Number 1:	7

*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/

#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Function Prototypes:
	---------------------------------------------------------------------------*/

// API(1):
void ArrayScan(char *Array, char Length);
// API(2):
void ArrayPrint(char *Array, char Length);
// API(3):
void ArrayPrintReverse(char *Array, char Length);

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/

#define ARRAY_LENGTH 3

void main(void)
{
	//___________________________________New Approach___________
	// Declare Array To Store Data Inside.
	char Array[ARRAY_LENGTH];

	// Scan Array Data From User.
	ArrayScan(Array, ARRAY_LENGTH);

	// Print Array Reversed.
	ArrayPrintReverse(Array, ARRAY_LENGTH);

	//___________________________________Old Approach___________
	// // Declare 3 Variables.
	// int n1, n2, n3;

	// // Take Their Values From User Input.
	// printf("\nplease enter number 1:\t\n");
	// scanf("%d", &n1);
	// printf("\nplease enter number 2:\t\n");
	// scanf("%d", &n2);
	// printf("\nplease enter number 3:\t\n");
	// scanf("%d", &n3);

	// // Print The Values in Reverse Order.
	// printf("\n");
	// printf("The number 3: you entered: = %d\n", n3);
	// printf("The number 2: you entered: = %d\n", n2);
	// printf("The number 1: you entered: = %d\n", n1);
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/

// API(1):
void ArrayScan(char *Array, char Length)
{
	for (char i = 0; i < Length; i++)
	{
		printf("Please enter number %d:\t", (i + 1));
		scanf("%d", &Array[i]);
	}
}

// API(2):
void ArrayPrint(char *Array, char Length)
{
	for (char i = 0; i < Length; i++)
	{
		printf("Number %d:\t%d\n", (i + 1), Array[i]);
	}
}

// API(3):
void ArrayPrintReverse(char *Array, char Length)
{
	for (char i = Length - 1; i >= 0; i--)
	{
		printf("Number %d:\t%d\n", i, Array[i]);
	}
}