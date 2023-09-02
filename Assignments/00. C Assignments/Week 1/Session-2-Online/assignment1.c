#include <stdio.h>

void main(void)
{
	//	Session -2- Assignment -1- "Search"
	/*	Search for the mathematical processes 
		------ EXCUTION PRIORITY ------
		then estimate output and detect the 
			   actual output 	*/
	
	// -----------	
	// Example(1):
	// -----------
	
	float y1 = 3*4/2-5+4;
	/* 	----------
		Estimation:
		----------
		all from left to right:						y1 = 3 *4 /2 -5 +4;
		1- (parentheses) 							y1 = 3 *4 /2 -5 +4;
		2- Multiplication"*",Division"/"
			,Remainder"%" from left to right		y1 = 12   /2 -5 +4;
													y1 = 	   6 -5 +4;
		3- Addition"+",Subtraction"-"
			from left to right						y1 = 		1   +4;
													y1 = 5;					*/
	printf("Estimated Y1 = 5\n");
	// 	Actual:
	printf("Y1 = %f\n",y1);
	
	
	// -----------	
	// Example(2):
	// -----------
	
	float y2 = 3*4/2-5+4-(6*8)/6;
	/* 	----------
		Estimation:
		----------
		all from left to right:						y2 = 3 *4 /2 -5 +4 -(6*8)/6;
		1- (parentheses) 							y2 = 3 *4 /2 -5 +4 -  48 /6;
		2- Multiplication"*",Division"/"
			,Remainder"%" from left to right		y2 = 12   /2 -5 +4 	     -8;
													y2 = 	   6 -5 +4	     -8;
		3- Addition"+",Subtraction"-"
			from left to right						y2 = 	1       +4	     -8;
													y2 = 	         5	     -8;
													y2 = -3;						*/
	printf("Estimated Y2 = -3\n");
	// Actual:
	printf("Y2 = %f\n",y2);
}