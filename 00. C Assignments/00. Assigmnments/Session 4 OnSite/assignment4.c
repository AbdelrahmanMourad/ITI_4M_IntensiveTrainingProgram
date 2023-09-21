#include <stdio.h>
/*	--------------------------------------------------------------------------------
	Session (4) Assignement (4):
	----------------------------

	Write a C program the implement 2 function:
		1- Function to get the maximum of 4 values
		2- Function to get the minimum of 4 values
	The program will ask the user first to enter the 4 values,
	then print the maximum number and minimum number of them.
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
int Max(int arr[], int length);
// API(2):
int Min(int arr[], int length);

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/
#define ARRAY_LENGTH 4

void main(void)
{
	//	Container
	int arr[ARRAY_LENGTH]; // Container for the 4 Values.
	int max, min;		   // Results
	int i;				   // Counter

	//	Scan The numbers.
	for (i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("Please enter (%d) number:\n", i + 1);
		scanf("%d", &arr[i]);
	}

	// Maximum.
	max = Max(arr, 4);
	printf("\nThe maximum number = %d	\n", max);

	// Minimum.
	min = Min(arr, 4);
	printf("\nThe mainimum number = %d	\n", min);
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/
// API(1):
int Max(int arr[], int length) //	{int arr[]}..is array, {n}..is the number of its elements
{
	int i;
	int max = arr[0];
	for (i = 1; i <= length - 1; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}
// API(2):
int Min(int arr[], int length) //	{int arr[]}..is array, {n}..is the number of its elements
{
	int i;
	int min = arr[0];
	for (i = 1; i <= length - 1; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}