#include <stdio.h>

	// Session -5- Lab -3-
	//
	/*
		
	*/
	//

void Add(int*x,int*y);
	
void main(void)
{
	int n1,n2;
	printf("Please Enter Value 1:\n");
	scanf("%d",&n1);
	printf("Please Enter Value 2:\n");
	scanf("%d",&n2);
	Add(&n1,&n2);
	//Sub(&n1,&n2);
	//
}

void Add(int*x,int*y)
{
	int add = *x+*y;
	printf("Result = %d",add);
}