#include <stdio.h>

//	Session -4- Assignment	-4-
//
/*	Write a C program the implement 2 function:
		1- Function to get the maximum of 4 values
		2- Function to get the minimum of 4 values
	The program will ask the user first to enter the 4 values, 
	then print the maximum number and minimum number of them.		*/
//

//	Prototype of functions:
//	-----------------------
int Max(int [], int n);		//	{int []}..is array, {n}..is the number of its elements
int Min(int [], int n);		//	{int []}..is array, {n}..is the number of its elements
//	void Max(int n1, int n2, int n3, int n4);
//	void Min(int n1, int n2, int n3, int n4);

//	Driver Code:
//	------------
void main(void)
{
	//	Container
	int arr[4];
	//	Counter
	int i;
	//	Scan 4 numbers
	for(i=0;i<=3;i++)
	{
		printf("Please enter (%d) number:\n",i+1);
		scanf("%d",&arr[i]);
	//	scanf("%d\n",&arr[i]);				\\ Wrong, Logical Error!
	}
	//Maximum
	int max = Max(arr, 4);
	printf("\nThe maximum number = %d	\n",max);
	//Minimum
	int min = Min(arr, 4);
	printf("\nThe mainimum number = %d	\n",min);
}

//	Functions Implementation:
//	------------------------
int Max(int arr[], int n)	//	{int arr[]}..is array, {n}..is the number of its elements
{	
	int i;
	int max = arr[0];
	for(i=1;i<=n-1;i++)
	{
		if (max<arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int Min(int arr[], int n)	//	{int arr[]}..is array, {n}..is the number of its elements
{
	int i;
	int min = arr[0];
	for(i=1;i<=n-1;i++)
	{
		if (min>arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}