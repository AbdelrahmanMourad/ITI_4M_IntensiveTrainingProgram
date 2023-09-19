
/*
	--------------------
	Session (1) Lab (3):
	--------------------

		Write a c-code to prin the following:
			Name: <yourName>
			Age: <yourAge>
			Univ: <yourUniv>

*/

/*  ---------------------------------------------------------------------------
							Functions Implementation:
	---------------------------------------------------------------------------*/
#include <stdio.h>

/*  ---------------------------------------------------------------------------
							Driving Code
	---------------------------------------------------------------------------*/

void main(void)
{

	char Name[] = "Abdelrahman Mourad";
	char Age = 26;
	char Univ[] = "IAET";

	printf("\nName: <Mourad>\nAge: <26>\nUniv: <IAET>\n");

	printf("\nName: <%s>\nAge: <%d>\nUniv: <%s>\n", Name, Age, Univ);
}