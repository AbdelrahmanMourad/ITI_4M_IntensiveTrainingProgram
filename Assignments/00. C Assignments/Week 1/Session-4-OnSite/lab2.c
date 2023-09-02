#include <stdio.h>

void main(void)
{
	// Session -4- Lab -2-
	//
	/*	write c code that takes 4 numbers from the user
		,store them is array ,and print them in reverse		*/
	//
	
	// Declare 4-element array.
	int n[4];			
	
	//	Take inputs from the user:
	printf("\nplease enter the 4 numbers:  \n");
	scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]);
	
	//	Display back array elements to user in reverse:
	printf("\nyou entered : \n %d\t %d\t %d\t %d\n",n[3],n[2],n[1],n[0]);
}