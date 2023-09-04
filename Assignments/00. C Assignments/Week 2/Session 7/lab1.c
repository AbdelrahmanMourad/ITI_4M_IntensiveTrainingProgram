#include <stdio.h>

//	Session -7-	Lab	-1-	
/*	WRite a c code that defines a structure for 
	employees that contains his:
		Salary, bonusm working hours, and id
	then ask the user to enter these data and print them 	*/
//

//	structure definition
	struct employee
	{
		int salary;
		int id;
		int bonus;
		int workingHour;
		
	};
	
	//	create alias for data type
	typedef struct employee emp;

	/*			--- Try 2nd method Here	---					*/
	
void main(void)
{	
	//	create object
	emp Ahmed;
	
	//	scan members:
	printf("Please enter the salary:\n");
	scanf("%d",&Ahmed.salary);
	printf("Please enter the WorkingHour:\n");
	scanf("%d",&Ahmed.workingHour);
	printf("Please enter the bonus:\n");
	scanf("%d",&Ahmed.bonus);
	printf("Please enter the id:\n");
	scanf("%d",&Ahmed.id);
	
	//	Print again:
	printf("\n\nYou Entered:\nAhmed\n,salary = %d\n,id = %d\n,workingHour = %d\n,bonus = %d\n",Ahmed.salary,Ahmed.id,Ahmed.workingHour,Ahmed.bonus);
	
	
}