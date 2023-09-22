/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Data:	08 Sep, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32
 * Layer:			MCAL
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  09 Sep, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
*/


/* Header Guard File */
#ifndef     STD_TYPES_H
#define     STD_TYPES_H

/* Our DataTypes */
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

typedef signed char     s8;
typedef signed short    s16;
typedef signed int      s32;

typedef  float 			f32;
typedef  double         f64;

/* Other Common DataTypes */
typedef unsigned char   uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;

typedef signed char 	sint8;
typedef signed short	sint16;
typedef signed int		sint32;

/* Expressions */
#define TRUE    1
#define FALSE   0

#define NULL    (void *)0

#endif  /*STD_TYPES_H*/

