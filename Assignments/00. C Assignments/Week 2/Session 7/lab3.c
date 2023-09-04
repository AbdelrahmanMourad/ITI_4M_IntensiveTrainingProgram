#include <stdio.h>
#include "STD_TYPES.h"

//	Session -7-	Lab	-3-	-		 "challenge"
//
/*		structure
		object
		print function
		send object to print function by reference
		print id and grade using pointer
		PASS BY REFERENCE
*/
//


/*
struct student
{
	u8 id;
	u
}*/
///// structure name is OPTIONAL when using typedef

typedef struct 		// struct definition
{
	u8 id;
	u16 grade;
}zozo;

void _print (zozo *Nabil);		// function prototype


//	Code Driver:
//	------------
void main(void)
{
	zozo Basel;
	Basel.id = 100;
	Basel.grade = 600;
	
	_print(&Basel);
	
}

void _print (zozo *Nabil)		// function implementation
{
	printf("id = %d\n",Nabil->id);
	printf("id = %d\n",Nabil->grade);
}



