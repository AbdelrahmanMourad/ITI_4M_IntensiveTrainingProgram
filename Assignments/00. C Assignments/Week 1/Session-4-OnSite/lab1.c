#include <stdio.h>

void main(void)
{
	// Session -4- Lab -1-
	//
	/*  ---------------------------------------------
		Q) What is the expected value of this program:
		---------------------------------------------
			a)	10						//	Our compiler is smart enough to assume x = 5 = "CONST"
			b)	0
			c)	garbage value
			d)	error					//	C-99 Stanard, should be arr[Const]					*/
	//
	
	int x = 5;
	char arr[x];
	arr[0]=10;
	printf("\n%d\n",arr[0]);
}