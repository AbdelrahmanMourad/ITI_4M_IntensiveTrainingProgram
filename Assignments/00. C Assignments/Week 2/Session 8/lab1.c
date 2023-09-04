#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

//	Session -8-	Lab	-1-	
//
/*	Heap	
	*/
//

	
void main(void)
{	
	u8 inputBytes;	// lets all assume 4-bytes
	
	//	taking input:
	//	-------------
	printf("Please enter no. of bytes needed:\n");
	scanf("%d",&inputBytes);
	
	
	
	u8 * ptr = (u8 *) malloc(inputBytes);
	scanf("%d",ptr);
	scanf("%d",ptr++);
	printf("%d    %d",*ptr,*(ptr++));
	
	
	
}