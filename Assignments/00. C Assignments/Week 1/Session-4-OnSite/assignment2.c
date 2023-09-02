#include <stdio.h>

//	Session -4- Assignment -2-
//
/*	Write a login program in C that ask the user to 
	enter his ID and his password, 
	if the ID is correct the system will ask the user to 
	enter his password up to 3 times, 
	if he enters the password right the systems welcomes him, 
	if the three times are incorrect, 
	the system print No more tries. 
	If the user ID is incorrect the system print 
	You are not registered								*/
//
/*	---------
	Database:
	---------
	-------------------------------------------------------
	User			ID				Password		Serial
	-------------------------------------------------------
	Ahmed			1234			7788			1
	Amr				5678			5566			2
	Wael			9870			1122			3		*/
//



//	Function Prototypes:
//	--------------------
int idcheck(int try,int exit);
int passcheck(int id,int exit);




//	Driver Code:
//	------------
void main(void)
{
	int try = 3;
	int exit=3;	

	int id = idcheck(try,exit);
		
	return;
} 



//	Functions Implementation:
//	-------------------------
int idcheck(int try, int exit)
{
	int id;
	while(try!=0)
	{
		printf("Enter your 4-digit ID:	\n");
		scanf("%d",&id);

		if (id == 1234)
		{
			printf("Hello Ahmed, Please Enter your password:");
			passcheck(id,exit);
			return 0;
			
		}
		else if(id== 5678)
		{
			printf("Hello Amr, Please Enter your password:");
			passcheck(id,exit);
			return 0;
		}
		else if (id == 9870)
		{
			
			printf("Hello Wael, Please Enter your password:");
			passcheck(id,exit);
			return 0;
		}
		else 
		{
			try--;
			printf("Wrong ID!\n");
		}
	}
	printf("You attempted 3 wrong logins, please wait 10 miutes before you try again!\n");

	
}

int passcheck(int id,int exit)
{
	int pass;
	while (exit!=0)
	{
		printf("\nInput the 4-digit password: \n");
		scanf("%d",&pass);	
	
		if (pass==7788)
		{
			printf("Correct password\n");
			return 0;
		}
		else if(pass==5566)
		{
			printf("Correct password\n");
			return 0;
		}
		else if(pass == 1122)
		{
			printf("Correct password\n");
			return 0;
		}
		else
		{
			printf("Wrong password, try another\n");
			exit--;
		}
		printf("\n");
	}
	return 0;
		
}



