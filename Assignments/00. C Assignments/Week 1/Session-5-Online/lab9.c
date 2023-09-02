#include <stdio.h>

	// Session -4- Lab -9-
	//
	/* write c code that takes 4 numbers from the user
		,Print them in reverse and sum 
		,Using user-defined function called ADD				*/
	//
	
//	Prototype:	
int ADD(int n1,int n2);

//	Main function:
void main(void)
{
	int _return = ADD(3,5);
	printf("\nAdd(3,5) = %d\n",_return);
}

//	Implementation:
int ADD (int n1, int n2)
{
	int sum = n1+n2;
	return sum;
}
