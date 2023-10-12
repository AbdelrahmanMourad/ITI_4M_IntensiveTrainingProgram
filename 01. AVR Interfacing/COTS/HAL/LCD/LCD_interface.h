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
// // All Ports.
// #define DIO_PORTA   0
// #define DIO_PORTB   1
// #define DIO_PORTC   2
// #define DIO_PORTD   3

// // All Pins.
// #define DIO_PIN0    0
// #define DIO_PIN1    1
// #define DIO_PIN2    2
// #define DIO_PIN3    3
// #define DIO_PIN4    4
// #define DIO_PIN5    5
// #define DIO_PIN6    6
// #define DIO_PIN7    7

/*  ---------------------------------------------------------------------------
                            Functions ProtoTypes:
    ---------------------------------------------------------------------------*/
/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1): LCD_voidInit(void).
 *      API(2): LCD_voidSendCommand(Copy_u8Command).        -->     (Static..@private.h)
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

/**
 * _________________________________API(2)_________________________________
 * @brief  Initialization Function of the LCD Modeule.
 * @note   None.
 * @param  void.
 * @retval None.
 **/
void LCD_voidInit(void);

/**
 * _________________________________API(2)_________________________________
 * @brief   Sending Commant to the LCD uC.
 * @note    None.
 * @param   Copy_u8Command
 *          This parameter can be one of the following values:
 *     			@arg LCD_FUNCTION_SET_CMD
 *	            @arg LCD_DISPLAY_ON_OFF_CMD
 *	            @arg LCD_DISPLAY_CLEAR_CMD
 * @retval None.
 **/
static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif /* HAL_LCD_LCD_INTERFACE_ */
