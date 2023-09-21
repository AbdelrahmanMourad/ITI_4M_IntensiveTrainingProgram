

/*	--------------------------------------------------------------------------------
	Session (4) Lab (3):
	--------------------

		Q)	create array element, then desplay to user its ADDRESS

		----------
		Note that:
		----------
					address of first element in the array == &arr[0]
			,also:	address of first element in the array == arr
	--------------------------------------------------------------------------------
*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/
#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/
void main(void)
{
	int arr[1];
	printf("%p\n", &arr[0]); // "%p"=="Pointer"	,Format specifier.
	printf("%p\n", arr);	 //	&arr[0] == arr 	--> Both refer to address of first element in the array

}