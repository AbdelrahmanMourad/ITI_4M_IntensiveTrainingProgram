#include <stdio.h>
#include "STD_TYPES.h"

//	Session -7-	Lab	-2-
/*	Make member of this struct
	,guess the size
	,find the size					
	if assuming word-size = 2-bytes		*/
//

struct employee
{	
	u8 id;				//	1-byte
	u16 salary;			//	2-byte
	u8 bonus;			//	1-byte
	u16 wh;				//	2-byte
						// 	Total = 6 bytes = 3 Locations in 2-wordsize memory
						//			8 bytes due to PADDING
};

struct employeeS2L		//	arranged small to large
{	
	u8 id;				//	1-byte
	u8 bonus;			//	1-byte
	u16 salary;			//	2-byte
	u16 wh;				//	2-byte
						// 	Total = 6 bytes = 3 Locations in 2-wordsize memory
						//		arranged manually // recommended to save memory without 		
};

struct employeeL2S		// 	arranged large to small
{	
	u16 salary;			//	2-byte
	u16 wh;				//	2-byte
	u8 id;				//	1-byte
	u8 bonus;			//	1-byte
	
						// 	Total = 6 bytes = 3 Locations in 2-wordsize memory
						//		
};

#pragma pack(1)
struct employee_Pragma
{	
	u8 id;				//	1-byte
	u16 salary;			//	2-byte
	u8 bonus;			//	1-byte
	u16 wh;				//	2-byte
						// 	Total = 6 bytes = 3 Locations in 2-wordsize memory
						//			6	as its arranged by {#pragma pack}
};


void main(void)
{
	struct employee Nahla;
	printf("the structure size = %d\n",sizeof(Nahla));
	
	struct employeeS2L Nahla2;
	printf("the structure size  (arranged small to larg) = %d\n",sizeof(Nahla2));
	
	struct employeeL2S Nahla3;
	printf("the structure size (arranged large to small) = %d\n",sizeof(Nahla3));
	
	struct employee_Pragma Nahla4;
	printf("the structure size (arranged using #pragma pack) = %d\n",sizeof(Nahla4));
}