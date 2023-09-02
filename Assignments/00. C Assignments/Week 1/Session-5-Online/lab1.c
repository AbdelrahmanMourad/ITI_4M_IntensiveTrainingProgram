#include <stdio.h>

void main(void)
{
	// Session -5- Lab -1-
	//
	/*	Write a c code defines an int variable initialized with 10
		,then print it,	then define a pointer that points to that int......
		
		*/
	//
	
	int x = 10;
	printf("X before change is:	%d\n",x);
	int *ptr;
	ptr = &x;
	*ptr = 20;
	printf("X after change is:	%d\n",x);

}