#include <stdio.h>

void main(void)
{
	// Session -4- Lab -5-
	//
	/*	write c code that takes 4 numbers from the user
		,print them in reverse and sum 
		,Using {for loops}									*/
	//
	
	// declare array of 4 element size
	int n[4];			
	// {i} is counter, {sum = zero} to avoid garbage values
	int i,sum=0;		
	
	//	Get input values from user {From 0 --> 3}
	//	Make Summation operation inside the for loop
	for (i=0;i<=3;i++)
		{
			printf("please enter the  number:  \n");
			scanf("%d",&n[i]);
			sum+=n[i];
		}
	
	printf("You Entered\n");
	
	//	Display output values to user {From 3 --> 0}{Reversed}
	for (i=3;i>=0;i--)
		{
			printf("%d\n",n[i]);
		}	
		
	printf("\nSum = %d\n",sum);

}