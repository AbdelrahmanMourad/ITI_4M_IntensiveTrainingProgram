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
#ifndef HAL_LCD_LCD_PRIVATE_
#define HAL_LCD_LCD_PRIVATE_

/*  ----------------------------------------------
                MCAROS
    ---------------------------------------------- */
#define LCD_ALL_OUTPUT 0xFF

/*  ----------------------------------------------
                Command Addresses
    ---------------------------------------------- */
#define LCD_FUNCTION_SET_CMD 0x38 // 0b00111000
#define LCD_DISPLAY_ON_OFF_CMD 0x0F
#define LCD_DISPLAY_CLEAR_CMD 0x01

/*  ----------------------------------------------
                INIT MODES
    ---------------------------------------------- */
#define EIGHT_BIT_MODE 1
#define FOUR_BIT_MODE 0

/*  ---------------------------------------------------------------------------
    Short Summary:
    ==============
    
    ---------------------------------------------------------------------------
*/

#endif /* HAL_LCD_LCD_PRIVATE_ */