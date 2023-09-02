#include <stdio.h>

void main(void)
{	
	//	Session -3- Lab -3-
	/*
	Write a C code that ask the user to 
	enter a number and check if it is 
	Even or Odd
	*/	
	int userInupt;
	printf("please enter a number:  ");
	scanf("%d",&userInput);
	if ( (userInput%2) ==0)
	{
	printf("\nThis is an EVEN number");
	}
	else
	{
	printf("\nThis is an ODD number");
	}
}