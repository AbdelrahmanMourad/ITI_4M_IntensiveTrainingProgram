/*	--------------------------------------------------------------------------------
	Session (4) Assignement (3):
	----------------------------

		Write a c program that draw a pyramid of stars 
	        with height entered by the user

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
	int i, j, rows, k = 0;  
    
	printf (" Enter a number to define the rows: \n");  
    scanf ("%d", &rows);   
      
    for ( i =1; i <= rows; i++)  
    {  
		//	Make spaces on left
        for ( j = 1; j <= rows - i; j++)  
        {  
            printf ("  ");   
        }  
    
		//	Use for loop where k is less than equal to (2 * i -1)  
        for ( k = 1; k <= ( 2 * i - 1); k++)  
        {  
            printf ("* "); // print the Star  
        }  
		
		//	New line
        printf ("\n");  
    }  
}