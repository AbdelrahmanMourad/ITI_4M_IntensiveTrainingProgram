#include <stdio.h>
#include <stdlib.h>			//	Just for generating random numbers automatically.
#include <time.h>			//	Just for generating random numbers automatically.
	
	//
	// Session -5- Assignment -2-
	//
	/* 	Write C code that manage a small school. 
		The school has 3 classes each class contains 10 students. 
		Define three arrays for the three classes each one with a length of 10. 
		Save a random numbers in all array elements to indicate the students grade. 
		
		The program will calculate and display the following statistics: 
		1- Number of passed students 
		2- Number of Failed students 
		3- Highest grade 
		4- Lowest grade 
		5- Average grade Knowing that the total grade is 
			from 100 and the minimum passing grade is 50..		*/
	//
	
void main(void)
{
	// school has 3 classes, 10 students each:
	int class1[10], class2[10], class3[10];
	
	//	Random student grades from 0 to 100:
	//	-----------------------------------
	int upper = 100;	
	int lower = 0;

    srand(time(0));		//	Just for generating random numbers automatically.
		
	int passCount = 0;	//	1- Number of passed students:
	int failCount = 0;	//	2- Number of Failed students 
	int high = 0;		//	3- Highest grade 
	int low = 100;		//	4- Lowest grade 
	int avgPass = 0;	//	5- Average grade from 100 to 50
	int sumPass = 0;	// 		avgPass = sumPass/passCount;
	
	for (int i = 0 ; i <= 9 ; i++)
	{	
		class1[i] = (rand() % (upper - lower + 1)) + lower;
		class2[i] = (rand() % (upper - lower + 1)) + lower;
		class3[i] = (rand() % (upper - lower + 1)) + lower;
		
		//	Print just to check random values:	
			printf("class1[Student: %d] = %d\n",i,class1[i]);
			printf("class2[Student: %d] = %d\n",i,class2[i]);
			printf("class3[Student: %d] = %d\n\n",i,class3[i]);
			
		//	1- Number of passed students:
		if (class1[i] >= 50)	
		{	
			passCount++;	
			sumPass+= class1[i];
		}
		if (class2[i] >= 50)	
		{	
			passCount++;
			sumPass+= class1[i];
		}
		if (class3[i] >= 50)	
		{	
			passCount++;
			sumPass+= class1[i];
		}
		
		//	2- Number of Failed students:
		if (class1[i] <= 50)	{	failCount++;	}
		if (class2[i] <= 50)	{	failCount++;	}
		if (class3[i] <= 50)	{	failCount++;	}
		
		//	3- Highest grade: 
		if (class1[i] >= high)	{	high = class1[i];	}
		if (class2[i] >= high)	{	high = class2[i];	}
		if (class3[i] >= high)	{	high = class3[i];	}
		
		//	4- Lowest grade:
		if (class1[i] <= low)	{	low = class1[i];	}
		if (class2[i] <= low)	{	low = class2[i];	}
		if (class3[i] <= low)	{	low = class3[i];	}
	}
	
	//	5- Average grade from 100 to 50:
	avgPass = sumPass/passCount;
	
	//	Statisitcs print:
	printf("\n\nNumber of passed students = %d\n",passCount);		//	1
	printf("Number of failed students 	  = %d\n",failCount);		//	2
	printf("Highest grade recorded	  	  = %d\n",high);			//	3
	printf("Lowest grade recorded     	  = %d\n",low);				//	4
	printf("Average degree of passing segment = %d\n",avgPass);		//	5
	
	//
		

}