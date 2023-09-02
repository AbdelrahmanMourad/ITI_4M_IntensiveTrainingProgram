#include <stdio.h>

/*	Search .. Buffer Errors! */



void main(void)
{
	//	Session -3- Assignment -1-
	//
	/*	Write a C code that ask the user to enter 10 numbers
		,then ask him to enter another number to search on it 
		in the 10 numbers 
		,and print its location in case it is found. 
		In case the number is not found, 
		it will print number no exist*/
	//
	
	//	Delare 10- element array to store the input numbers inside
	int arr[10];
	//	Declare store we will search for
	int searchValue;
	//	Declare counter
	int i;
	
	//	Take 10 numbers from user
	for (i=1;i<=10;i++)
	{
		printf("Enter Number %d:  ",i);
		scanf("	%d\n",&arr[i]);							////	space to avoid buffer error! (It reads "enter key" as the operation.)	////
	}
	
	// Take Value to search in the array numbers
	printf("Enter the value to search:  \n");
	scanf("	%d",&searchValue);							////	space to avoid buffer error! (It reads "enter key" as the operation.)	////
	
	//	Search the value
	if(searchValue==arr[1])			{printf("Value is exist at element number %d",arr[1]);}
	else if(searchValue==arr[2])	{printf("Value is exist at element number %d",arr[2]);}
	else if(searchValue==arr[3])	{printf("Value is exist at element number %d",arr[3]);}
	else if(searchValue==arr[4])	{printf("Value is exist at element number %d",arr[4]);}
	else if(searchValue==arr[5])	{printf("Value is exist at element number %d",arr[5]);}
	else if(searchValue==arr[6])	{printf("Value is exist at element number %d",arr[6]);}
	else if(searchValue==arr[7])	{printf("Value is exist at element number %d",arr[7]);}
	else if(searchValue==arr[8])	{printf("Value is exist at element number %d",arr[8]);}
	else if(searchValue==arr[9])	{printf("Value is exist at element number %d",arr[9]);}
	else if(searchValue==arr[10])	{printf("Value is exist at element number %d",arr[10]);}
	else							{printf("Number not exist");}
	
	
	
	/*
	
	// WRONG approach --> Case(x) --> {x} must be integar number not variable!!!!!!!!!!!

	switch(searchValue)
	{
		case(array[1]):
			printf("Value is exist at element number %d",array[1]);
			break;
		case(array[2]):
			printf("Value is exist at element number %d",array[1]);
			break;	
		case(array[3]):
			printf("Value is exist at element number %d",array[1]);
			break;
		case(array[4]):
			printf("Value is exist at element number %d",array[1]);
			break;	
		case(array[5]):
			printf("Value is exist at element number %d",array[1]);
			break;
		case(array[6]):
			printf("Value is exist at element number %d",array[1]);
			break;	
		case(array[7]):
			printf("Value is exist at element number %d",array[1]);
			break;
		case(array[8]):
			printf("Value is exist at element number %d",array[1]);
			break;	
		case(array[9]):
			printf("Value is exist at element number %d",array[1]);
			break;
		case(array[10]):
			printf("Value is exist at element number %d",array[1]);
			break;	
		default
			printf("Number not exist");
	}		
	*/
}