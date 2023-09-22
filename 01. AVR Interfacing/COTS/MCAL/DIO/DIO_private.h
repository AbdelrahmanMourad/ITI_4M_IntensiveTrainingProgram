/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Data:	08 Sep, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32
 * Layer:			MCAL
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  09 Sep, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
*/

/*  ----------------------------------------------
                Header Guard File
    ---------------------------------------------- */
#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/*  ----------------------------------------------
                Register Addresses
    ---------------------------------------------- */
#define PORTA   *((volatile u8*)(0x3B))
#define DDRA    *((volatile u8*)(0x3A))
#define PINA    *((volatile u8*)(0x39))

#define PORTB   *((volatile u8*)(0x38))
#define DDRB    *((volatile u8*)(0x37))
#define PINB    *((volatile u8*)(0x36))

#define PORTC   *((volatile u8*)(0x35))
#define DDRC    *((volatile u8*)(0x34))
#define PINC    *((volatile u8*)(0x33))

#define PORTD   *((volatile u8*)(0x32))
#define DDRD    *((volatile u8*)(0x31))
#define PIND    *((volatile u8*)(0x30))

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */

/*  ---------------------------------------------------------------------------
    Short Summary:
    ==============
        {DDRxn Register}
            , Selects the {Direction} of The Pin
            , if bit is written:
                Logic 1 ->  Configured OUTPUT Pin.
                Logic 0 ->  Configured INPUT Pin.

    --------------
    iF Output Pin:
    --------------
        {PORTxn Register}
            , if bit is written:
                Logic 1 ->  Pull-Up Resistor Is Activated.
                Logic 0 ->  Pull-Up Resistor Is Deativated, or Not Output Pin.
    
    -------------
    If Input Pin:
    -------------
        {PINxn Register}
            , Read Only Register To Read Inpupt Values From.
                Logic 1 ->  Input HIGH Received.
                Logic 0 ->  Input LOW Received.
        
    ---------------------------------------------------------------------------
*/