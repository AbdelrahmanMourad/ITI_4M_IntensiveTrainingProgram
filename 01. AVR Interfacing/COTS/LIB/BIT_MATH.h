/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	08 Sep, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32/STM32F4   (8/32-Bit Architecture)
 * Processor:		AVR/ARM-M4         (8/32-Bit Architecture)
 * Layer:			LIB
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  09 Sep, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
*/
#ifndef BIT_MATH_H
#define BIT_MATH_H

/******** Functions Like Macro To Manipulate Over Specific Bit ************/
#define SET_BIT(REG_NAME, BIT_NUM)                  (REG_NAME |= (1 << BIT_NUM))
#define CLR_BIT(REG_NAME, BIT_NUM)                  (REG_NAME &= (~(1 << BIT_NUM)))
#define GET_BIT(REG_NAME, BIT_NUM)                  ((REG_NAME >> BIT_NUM) & 0x01)
#define TOG_BIT(REG_NAME, BIT_NUM)                  (REG_NAME ^= (1 << BIT_NUM))

/******** Functions Like Macro To Manipulate Over Specific Register *******/
#define SET_REG_SPECIFIC_VALUE(REG_NAME, VALUE)     (REG_NAME = VALUE)
#define SET_REG(REG_NAME)                           (REG_NAME = 0xFF)
#define GET_REG(REG_NAME)                           (REG_NAME)
#define CLR_REG(REG_NAME)                           (REG_NAME = 0x00)

#endif
