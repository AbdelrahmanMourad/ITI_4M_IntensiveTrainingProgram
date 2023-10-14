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
                Configurations
    ---------------------------------------------- */
/*  ----------------
    Options:
        DIO_PORTA
        DIO_PORTB
        DIO_PORTC
        DIO_PORTD
    ----------------*/
// Ports
#define LCD_DATA_PORT       DIO_PORTA
#define LCD_CTRL_PORT       DIO_PORTB
// Pins
#define LCD_CTRL_PIN_RS     DIO_PIN0
#define LCD_CTRL_PIN_RW     DIO_PIN1
#define LCD_CTRL_PIN_EN     DIO_PIN2

/*  ----------------
    Options:
        EIGHT_BIT_MODE
        FOUR_BIT_MODE
    ----------------*/
#define LCD_INIT_MODE EIGHT_BIT_MODE

#endif /* HAL_LCD_LCD_CONFIG_ */