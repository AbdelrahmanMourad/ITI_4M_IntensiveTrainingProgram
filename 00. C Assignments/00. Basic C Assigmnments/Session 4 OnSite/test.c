#include <stdio.h>

//	Function Prototype:
int SCAN1 (void);
int SCAN (void);
int ADD (int n1, int n2);
int SUBTRACT (int n1, int n2);
int MULTIPLY (int n1, int n2);
int DIVIDE (int n1, int n2);
int AND (int n1, int n2);
int OR (int n1, int n2);
int NOT (int n);
int XOR (int n1, int n2);
int REMINDER (int n1, int n2);
int INCREMENT (int n);
int DECREMENT (int n);


// Driver Code:
void main(void)
{
	int operand;
	//	Ask for operation type:
	printf("\nWelcome to the calcularot program\n\n");
	printf("Please Enter the operation you need:\n");
	printf(" \"  +,-,*,/,AND,OR,NOT,XOR,%,++,-- \"");
	scanf("%d",&operand);
	
	//	Switch to the appropriate operation:
	int arr[2];
	switch(operand)
	{
		case('+'):
			arr[0] = SCAN();
			arr[1] = SCAN();
			ADD(arr[0],arr[1]);
			break;
		default:
			printf("Wrong answer, Please try again!\n");
			break;
	}	
	
}



//	Function Implementation:
int SCAN1 (void);
int SCAN (void);
{
	printf("\nPlease enter a numbers: 	");
	scanf("%d\n",&input);
	return input;
}

int ADD (int n1, int n2);
{
	R = n1 + n2;
	printf("result = %d",R);
	return R;
}

int SUBTRACT (int n1, int n2);
int MULTIPLY (int n1, int n2);
int DIVIDE (int n1, int n2);
int AND (int n1, int n2);
int OR (int n1, int n2);
int NOT (int n);
int XOR (int n1, int n2);
int REMINDER (int n1, int n2);
int INCREMENT (int n);
int DECREMENT (int n);
