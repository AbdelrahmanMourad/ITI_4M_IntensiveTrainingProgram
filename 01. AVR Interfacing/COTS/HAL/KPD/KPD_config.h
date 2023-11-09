/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	16 Oct, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32    (8-Bit Architecture)
 * Processor:		AVR         (8-Bit Architecture)
 * Layer:			HAL
 * Driver:          KPD         (KeyPad 4x4)
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  16 Oct, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
 */

/*  ----------------------------------------------
                Header Guard File:
    ---------------------------------------------- */
#ifndef MCAL_KPD_KPD_CONFIG_H_
#define MCAL_KPD_KPD_CONFIG_H_

/*  ----------------------------------------------
                Configurations
    ---------------------------------------------- */
// Ports
#define KPD_ROWS_PORT       DIO_PORTD
#define KPD_COLUMNS_PORT    DIO_PORTD
// Rows Pins.   
#define KPD_ROW0_PIN        DIO_PIN0
#define KPD_ROW1_PIN        DIO_PIN1
#define KPD_ROW2_PIN        DIO_PIN2
#define KPD_ROW3_PIN        DIO_PIN3
// Columns Pins.    
#define KPD_COLUMN0_PIN     DIO_PIN4
#define KPD_COLUMN1_PIN     DIO_PIN5
#define KPD_COLUMN2_PIN     DIO_PIN6
#define KPD_COLUMN3_PIN     DIO_PIN7

// Set Value To Compare With.
#define KPD_NOT_PRESSED_VAL 255

// Number of Columns and Rows.
#define KPD_ROWS_NUM        4
#define KPD_COLUMNS_NUM     4

// KeyPad LayOut.
#define KPD_ARR_VAL_LAYOUT  { {'1', '2', '3', 'A'}\
                             ,{'4', '5', '6', 'B'}\
                             ,{'7', '8', '9', 'C'}\
                             ,{'*', '0', '#', 'D'} }


#endif /*MCAL_KPD_KPDCONFIG__H_*/
