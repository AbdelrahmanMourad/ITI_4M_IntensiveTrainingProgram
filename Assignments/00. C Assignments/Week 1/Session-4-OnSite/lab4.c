#include <stdio.h>

void main(void)
{
	// Session -4- Lab -4-
	//
	/*	write a c code to take 4 numbers from the user
		,and print the summation of these numbers 
		, Using {array} and arithmetic operator {+=}
		
		if inputs {10,20,30,40} --> we expect sum = 100		*/
	//
	
	int n[4];				//	Declare empty array.
	
	//	Declare and initialize variable to store summation inside. 
	// {sum = zero} to avoid garbage values
	int sum = 0;			
	
	//	assign input values from the user into array.
	printf("\nplease enter the 4 numbers:  \n");
	scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]);
	
	//	Summation operation.
	sum+=n[0];
	sum+=n[1];
	sum+=n[2];
	sum+=n[3];
	
	//	Display summation output to user.
	printf("\nSum = %d\n",sum);
}