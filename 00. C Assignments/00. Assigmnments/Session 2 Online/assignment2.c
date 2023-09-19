

/*
	---------------------------
	Session (2) Assignment (2):
	---------------------------

		Draw A 6 Steps Pyramid

*/

/*  ---------------------------------------------------------------------------
							Include Library:
	---------------------------------------------------------------------------*/

#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Function Prototypes:
	---------------------------------------------------------------------------*/

// API(1):
void DrawPyramid(int n);
// API(2):
void DrawHalfPyramid(int n);

/*  ---------------------------------------------------------------------------
							Driving Code:
	---------------------------------------------------------------------------*/

void main(void)
{
	// Using Function.
	DrawPyramid(7);

	// Manually.
	// Write a code that can draw this pyramid
	printf("     *\n");
	printf("    ***\n");
	printf("   *****\n");
	printf("  *******\n");
	printf(" *********\n");
	printf("***********\n");
}

/*  ---------------------------------------------------------------------------
							Function Implementation:
	---------------------------------------------------------------------------*/

// API(1):
void DrawPyramid(int n)
{
	for (int i = 1; i <= n; i++)
	{
		// Print Spaces Horizontally.
		for (int j = n - i; j >= 0; j--)
		{
			printf(" ");
		}

		// Print Stars Horizontally.
		for (int k = 1; k <= i; k++)
		{
			if (k == 1)
			{
				// The Pyramid Head
				printf("*");
			}
			else
			{
				// The Pyramid Body Right and Left
				printf("**");
			}
		}

		// Move Vertically To Next Floor.
		printf("\n");
	}

	printf("\n");
}

// API(2):
void DrawHalfPyramid(int n)
{
	for (int i = 1; i <= n; i++)
	{
		// Print Spaces Horizontally.
		for (int j = n - i; j >= 0; j--)
		{
			printf(" ");
		}

		// Print Stars Horizontally.
		for (int k = 1; k <= i; k++)
		{
			printf("*");
		}

		// Move Vertically To Next Floor.
		printf("\n");
	}

	printf("\n");
}