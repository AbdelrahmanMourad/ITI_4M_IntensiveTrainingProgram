#include <stdio.h>

void main(void)
{	
	//	Session -3- Lab -4-
	/*
	Write a C code that ask the user to 
	enter his grade , print as in range..
	*/	
	int grade;
	printf("Please enter number:  ");
	scanf("%d",&grade);
	/*
	if(grade>=85)
		{
			printf("Your rating is Excellect");
		}
	else if(grade>=75)
		{
			printf("Your rating is Very Good");
		}
	else if(grade>=65)
		{
			printf("Your rating is Good");
		}
	else if(grade>=50)
		{
			printf("Your rating is Normal");
		}
	else
		{
			printf("Your rating is Failed");
		}
		*/
	// ------------------------
	// Using Logical Operators:
	// ------------------------
	if(		(grade>=0) && 
			(grade<=50))
		{
			printf("Your rating is Failed\n");
		}
	else if(	(grade>50) && (grade<=65))
		{
			printf("Your rating is Normal\n");
		}
	else if(	(grade>65) && (grade<=75))
		{
			printf("Your rating is Good\n");
		}
	else if(	(grade>75) && (grade<=85))
		{
			printf("Your rating is very Good\n");
		}
	else if(	(grade>85) && (grade<=100))
		{
			printf("Your rating is Excellent\n");
		}
	else
		{
			printf("Invalid number, please try again!\n");
		}
}