#include <stdio.h>

void main(void)
{
	char x = 5;
	//	Postfix
	/*
	printf("%d\n",x++);	//	5
	printf("%d",x);		//	6
	*/
	
	// Prefix
	printf("%d\n",++x);	//	6
	printf("%d",x);		//	6
}