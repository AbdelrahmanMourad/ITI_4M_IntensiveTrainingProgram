#include <stdio.h>
	
	//
	// Session -5- Assignment -3-
	//
	/* 	Write a C code that define 3 int variables x, y and z 
		and 3 pointers to int p, q and r. Set x, y, z 
		to three distinct values. 
		Set p, q, r to the addresses of x, y, z respectively.

		a- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
		b- Print the message: Swapping pointers.
		c- Execute the swap code: r = p; p = q; q = r;
		d- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.		*/
	//
	
void main(void)
{
	//	declaration	
	int x,y,z;				// define variables
	int *p, *q, *r;			// define pointers
	
	// assumtions: (Set x,y,z to values)
	x = 10;		y = 20;		z = 30;
	
	//	set pointers to addresses:
	p = &x;			//	*p = 10
	q = &y;			//	*q = 20
	r = &z;			//	*r = 30
	
	//	a- print with labels the "values":
	printf("Value of x = %d\n",x);	//	10
	printf("Value of y = %d\n",y);	//	20
	printf("Value of z = %d\n",z);	//	30
	printf("Value of *p = %d\n",*p);	//	10
	printf("Value of *q = %d\n",*q);	//	20
	printf("Value of *r = %d\n",*r);	//	30
	
	//	b- print swapping pointer messege:
	printf("\nSwapping Pointers:\n\n");
	
	//	c- swap Code:
	r = p;			//	r = &x	//	*r = 10
	p = q;			//	p = &y	//	*p = 20
	q = r;			//	q = &x	//	*q = 10
	
	//	d- print with labels the "New values":
	printf("New Value of x = %d\n",x);		//	10
	printf("New Value of y = %d\n",y);		//	20
	printf("New Value of z = %d\n",z);		//	30
	printf("New Value of *p = %d\n",*p);	//	20
	printf("New Value of *q = %d\n",*q);	//	10
	printf("New Value of *r = %d\n",*r);	//	10

}