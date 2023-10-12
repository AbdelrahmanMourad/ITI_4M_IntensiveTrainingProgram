/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	12 Oct, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32    (8-Bit Architecture)
 * Processor:		AVR         (8-Bit Architecture)
 * Layer:			HAL
 * Driver:          LCD         (LMB161A Model)
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  12 Oct, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
 */

/*  ---------------------------------------------------------------------------
							Included Libraries:
	---------------------------------------------------------------------------*/
/*Library Inclusions*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*Lower Layer Inclusions*/
#include "../../MCAL/DIO/DIO_interface.h"
/*Self Layer Inclusions*/
/*Self Files Inclusions*/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

/*  ---------------------------------------------------------------------------
							Functions Implementation:
	---------------------------------------------------------------------------*/

/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1): LCD_voidInit(void).
 *      API(2): LCD_voidSendCommand(Copy_u8Command).    =>  (Static..@private.h)
 *      API(3): LCD_voidSendData(Copy_u8Data).
 *      API(4): LCD_voidSendPulse(void).
 *      API(5): LCD_VoidClearDisplay(void).
 *      API(6): LCD_voidSendNumber(Copy_u32InputNumber).
 *      API(7): LCD_voidSendString(Copy_pu8InputStringArray).
 *      API(8): LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos).
 *      API(9): LCD_voidSendCustomCharacter(Copy_pu8CharacterArray,
 *                                          Copy_u8PatternNumber,
 *                                          Copy_u8XPosition,
 *                                          Copy_u8YPosition).
 * _______________________________________________
 **/
