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



/**
 *  _________________________________API(1)_________________________________
 *  @brief  Initialization Function of the LCD Modeule.
 *  @fn     Pre-Build.
 *  @note   None.
 *  @param  void.
 *  @retval void.
 **/
void LCD_voidInit(void);

/**
 * _________________________________API(3)_________________________________
 * @brief  Sending Data to the LCD uC.
 * @fn     Pre-Build.
 * @note   It automatically move one cell each time we send new data.
 * @param  Copy_u8Data
 *         This parameter can be one of the following values:
 *     			@arg LCD_FUNCTION_SET_CMD
 *	            @arg LCD_DISPLAY_ON_OFF_CMD
 *	            @arg LCD_DISPLAY_CLEAR_CMD
 * @retval None.
 **/
void LCD_voidSendData(u8 Copy_u8Data);

/**
 * _________________________________API(5)_________________________________
 * @brief  This API Clears All Display.
 * @fn     Post-Build.
 * @note   None.
 * @param  void
 * @retval void.
 **/
void LCD_voidClearDisplay(void);

/**
 *  _________________________________API(6)_________________________________
 *  @brief  This API Let you Send Multi Digit Number To Display on LCD.
 *  @fn     Post-Build.
 *  @note   None.
 *  @param  Copy_u32Number.
 *           This parameter can be any number between
 *              @arg    { 0 ... 4,294,967,295 }
 *  @retval void.
 **/
void LCD_voidSendNumber(u32 Copy_u32Number);

/**
 * _________________________________API(7)_________________________________
 * @brief  This API Let You Send String {Array of Char} to Display on the LCD.
 * @fn     Post-Build.
 * @note   None.
 * @param  Copy_pu8StringArray
 *          This parameter can be one of the following values:
 *     			@arg Any String array. -> {u8 String[]}
 * @retval void.
 **/
void LCD_voidSendString(u8 *Copy_pu8StringArray);

/**
 * _________________________________API(8)_________________________________
 * @brief  This API Let You Start Typing from Chosen Location on the LCD.
 * @fn     Post-Build.
 * @note   None.
 * @param  Copy_u8XPos
 *          This parameter can be one of the following values:
 *     			@arg 0 ... 1
 * @param  Copy_u8YPos
 *          This parameter can be one of the following values:
 *     			@arg 0 ... 16
 * @retval void.
 **/
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/**
 * _________________________________API(9)_________________________________
 * @brief  Send Custom Char Shape as array to be stored in the CGRAM
 *          ,In Specific Pattern Number
 *          , And Display on LCD In Specific X-Position and Y-Position.
 * @fn     Post-Build.
 * @note   None.
 * @param  Copy_pu8CharacterArray
 *           This parameter can be Any u8 Arra, Fill 1st 5-bits of the u8 numbers with the shape pattern.
 *              @arg  u8 CharacterArray[8] = []
 * @param  Copy_u8PatternNumber
 *           This parameter is the Address Of CGRAM to Store The Array Pattern inside {from 0x8 to 8x8}
 *           Each CGRAM is 5x8 dots represented as u8 array addresses
 *           Pattern addresses start from 0 to 63 addresses, each pattern takes 8 addresses {from 0x8 to 8x8}.
 *           This Parameter can be any number between:
 *              @arg  {0 ... 8}.
 * @param  Copy_u8XPos
 *          This parameter can be one of the following values:
 *     			@arg LCD_ROW_FIRST
 *     			@arg LCD_ROW_SECOND
 * @param  Copy_u8YPos
 *          This parameter can be any number between:
 *     			@arg {0 ... 16}.
 * @retval void.
 **/
void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray,
                                 u8 Copy_u8PatternNumber,
                                 u8 Copy_u8XPosition,
                                 u8 Copy_u8YPosition);

#endif /* HAL_LCD_LCD_INTERFACE_ */
