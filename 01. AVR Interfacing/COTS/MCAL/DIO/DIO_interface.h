/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	22 Sep, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32    (8-Bit Architecture)
 * Processor:		AVR         (8-Bit Architecture)
 * Layer:			MCAL
 * Driver:          DIO         (Digital Input/Output)
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  22 Sep, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
*/

/*  ----------------------------------------------
                Header Guard File:
    ---------------------------------------------- */
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/*  ----------------------------------------------
                Definitions:
    ---------------------------------------------- */
// All Ports.
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

// All Pins.
#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7

// For DDRxn.
#define INPUT       0
#define OUTPUT      1

// For PORTxn.
#define LOW         0
#define HIGH        1

// For PORTxn.
#define NO_PULLUP   0
#define PULLUP      1

/*  ---------------------------------------------------------------------------
							Functions ProtoTypes:
	---------------------------------------------------------------------------*/
// Pin Direction Configuration APIs:
void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection);  // API(1).
// Pin Value Configuration APIs:
void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState);          // API(2).
void DIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 *Copy_pu8ReturnedValue);   // API(3).
void DIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);                           // API(4).
// Port Specific Config APIs:
void DIO_SetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection);             // API(5).
void DIO_SetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8SpecificValue);                     // API(6).
// Port General Set APIs:
void DIO_voidSetPortDirectionAll(u8 Copy_u8PortName, u8 Copy_u8PortDirectionAll);               // API(7).
void DIO_voidSetPortAllValueAll(u8 Copy_u8PortName, u8 Copy_u8PortValueAll);                    // API(8).


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */