
/*	Search .. Buffer Errors! */

/*	--------------------------------------------------------------------------------
	Session (3) Assignment (1):
	---------------------------

		Write a C code that ask the user to enter 10 numbers
			, then ask him to enter another number to search on it in the 10 numbers
			, and print its location {index} in case it is found.

			In case the number is not found
				, it will print number no exist

	--------------------------------------------------------------------------------
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
char ArraySearchValue(char *Array, char Length, char Value, char *Location);
// API(3):
void ArrayPrint(char *Array, char Length);
// API(4):
void ArrayPrintReverse(char *Array, char Length);

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/

// Define Number Of Array Elements.
#define ARRAY_SIZE 10

void main(void)
{
	//___________________________________New Approach___________
	// Declare Array To Store Values Inside.
	char Array[ARRAY_SIZE]; // Array.
	char Number;			// Number To Look For.
	char Index;				// Location Of The Number If Found In The Array.
	char status;			// Search Status Exist {1} , Not Exist {0}.

	// Scan Array Values From User Input.
	ArrayScan(Array, ARRAY_SIZE);

	// Take Value to Search For From User Input.
	printf("Enter Value to Look For:\t");
	scanf("%d", Number);

	// Search Value In Array.
	status = ArraySearchValue(Array, ARRAY_SIZE, Number, &Index);

	// Print Restults.
	if (status == 1)
	{
		printf("The Value: (%d) exists at location: %d ", Number, Index);
	}
	else if (status == 0)
	{
		printf("Not Found \'Number NO Exist\'\n");
	}

	//___________________________________Old Approach___________

	// //	Delare 10- element array to store the input numbers inside
	// int arr[10];
	// //	Declare store we will search for
	// int searchValue;
	// //	Declare counter
	// int i;

	// //	Take 10 numbers from user
	// for (i = 1; i <= 10; i++)
	// {
	// 	printf("Enter Number %d:  ", i);
	// 	scanf("	%d\n", &arr[i]); ////	space to avoid buffer error! (It reads "enter key" as the operation.)	////
	// }

	// // Take Value to search in the array numbers
	// printf("Enter the value to search:  \n");
	// scanf("	%d", &searchValue); ////	space to avoid buffer error! (It reads "enter key" as the operation.)	////

	// //	Search the value
	// if (searchValue == arr[1])
	// {
	// 	printf("Value is exist at element number %d", arr[1]);
	// }
	// else if (searchValue == arr[2])
	// {
	// 	printf("Value is exist at element number %d", arr[2]);
	// }
	// else if (searchValue == arr[3])
	// {
	// 	printf("Value is exist at element number %d", arr[3]);
	// }
	// else if (searchValue == arr[4])
	// {
	// 	printf("Value is exist at element number %d", arr[4]);
	// }
	// else if (searchValue == arr[5])
	// {
	// 	printf("Value is exist at element number %d", arr[5]);
	// }
	// else if (searchValue == arr[6])
	// {
	// 	printf("Value is exist at element number %d", arr[6]);
	// }
	// else if (searchValue == arr[7])
	// {
	// 	printf("Value is exist at element number %d", arr[7]);
	// }
	// else if (searchValue == arr[8])
	// {
	// 	printf("Value is exist at element number %d", arr[8]);
	// }
	// else if (searchValue == arr[9])
	// {
	// 	printf("Value is exist at element number %d", arr[9]);
	// }
	// else if (searchValue == arr[10])
	// {
	// 	printf("Value is exist at element number %d", arr[10]);
	// }
	// else
	// {
	// 	printf("Number not exist");
	// }
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/

// API(1):
void ArrayScan(char *Array, char Length)
{
	for (char i = 0; i < Length; i++)
	{
		printf("Array[%d]:\t", i);
		scanf("%d", &Array[i]);
	}
}

// API(2):
char ArraySearchValue(char *Array, char Length, char Value, char *Location)
{
	char status = 0;

	for (char i = 0; i < Length; i++)
	{
		if (Array[i] == Value)
		{
			*Location = i;
			break;
		}
		else
		{
			// Do Nothing
		}
	}
	return status;
}

// API(3):
void ArrayPrint(char *Array, char Length)
{
	for (char i = 0; i < Length; i++)
	{
		printf("Array[%d]:\t%d\n", (i), Array[i]);
	}
}

// API(4):
void ArrayPrintReverse(char *Array, char Length)
{
	for (char i = Length - 1; i >= 0; i--)
	{
		printf("Array[%d]:\t%d\n", i, Array[i]);
	}
}
