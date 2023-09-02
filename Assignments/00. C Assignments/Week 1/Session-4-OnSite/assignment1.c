#include <stdio.h>

//	Session -4-	Assignment -1-
//
/*	Write a C program that ask the user to enter two 
	numbers and print their summation, 
	this program should never ends until 
	the user close the window				*/
//
void summation(void);

void main(void)
{	
	while(1)
	{
		summation();
	}
}

void summation(void)
{
	int n1,n2,sum;
	printf("\nPlease enter first number:	");
	scanf("%d",&n1);
	printf("Please enter second number:	");
	scanf("%d",&n2);
	sum = n1 + n2;
	printf("Summation = %d\n",sum);	
}