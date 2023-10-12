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
#ifndef HAL_LCD_LCD_CONFIG_
#define HAL_LCD_LCD_CONFIG_


/*  ----------------------------------------------
                MODE Selection
    ---------------------------------------------- */
/*  --------
    Options:
        EIGHT_BIT_MODE
        FOUR_BIT_MODE
    --------    */
#define LCD_INIT_MODE   EIGHT_BIT_MODE







#endif /* HAL_LCD_LCD_CONFIG_ */