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

/*  ----------------------------------------------
                Header Guard File:
    ---------------------------------------------- */
#ifndef HAL_LCD_LCD_INTERFACE_
#define HAL_LCD_LCD_INTERFACE_

/*  ----------------------------------------------
                Definitions:
    ---------------------------------------------- */
// Clear The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
#define COMMAND 0
#define DATA    0
// Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
#define WRITE   0
#define READ    1

/*  ---------------------------------------------------------------------------
                            Functions ProtoTypes:
    ---------------------------------------------------------------------------*/
/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1): LCD_voidInit(void).                                 @file: ( @interface.h )
 *      API(2): LCD_voidSendCommand(Copy_u8Command).                @file: ( Static-> @private.h)
 *      API(3): LCD_voidSendData(Copy_u8Data).                      @file: ( @interface.h )
 *      API(4): LCD_voidSendEnablePulse(void).                      @file: ( Static-> @private.h)
 *      API(5): LCD_VoidClearDisplay(void).                         @file: ( @interface.h )
 *      API(6): LCD_voidSendNumber(Copy_u32InputNumber).            @file: ( @interface.h )
 *      API(7): LCD_voidSendString(Copy_pu8InputStringArray).       @file: ( @interface.h )
 *      API(8): LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos).           @file: ( @interface.h )
 *      API(9): LCD_voidSendCustomCharacter(Copy_pu8CharacterArray, 
 *                                          Copy_u8PatternNumber,
 *                                          Copy_u8XPosition,
 *                                          Copy_u8YPosition).
 * _______________________________________________
 **/


#endif /* HAL_LCD_LCD_INTERFACE_ */
