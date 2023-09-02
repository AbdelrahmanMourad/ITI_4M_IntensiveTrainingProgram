#include <stdio.h>

void main(void)
{
	/*	Write a code that takes 2 numbers and print their 
		summation, subtraction, anding, oring, and Xoring	*/
	int n1, n2;
	printf("\nplease enter number a\n");		scanf("%d",&n1);
	printf("\nplease enter number b\n");		scanf("%d",&n2);
	
	// Operations:
	int sum  = n1+n2;
	int sub  = n1-n2;
	int _and = n1&n2;
	int _or  = n1|n2;
	int _xor = n1^n2;
	printf("\n");
	printf("Summation = %d\n",sum);
	printf("Subtraction = %d\n",sub);
	printf("Anding = %d\n",_and);
	printf("Oring = %d\n",_or);
	printf("Xoring = %d\n",_xor);
}