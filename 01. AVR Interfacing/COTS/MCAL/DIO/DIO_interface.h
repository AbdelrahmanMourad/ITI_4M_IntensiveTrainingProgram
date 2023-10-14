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

// For Register Direction.
#define ALL_INPUT   0x00
#define ALL_OUTPUT  0xFF

// For Output Registers Values.
#define ALL_LOW     0x00
#define ALL_HIGH    0xFF



/*  ---------------------------------------------------------------------------
                            Functions ProtoTypes:
    ---------------------------------------------------------------------------*/
/**
 * _______________________________________________
 *  @tableofcontents:
 *      Pin Direction Configuration API Set:
 *          API(1).
 *      Pin Value Configuration API Set:
 *          API(2).
 *          API(3).
 *          API(4).
 *      Port Specific Config API Set:
 *          API(5).
 *          API(6).
 *      Port General Set APIs:
 *          API(7).
 *          API(8).
 * _______________________________________________
 **/

/**
 * _________________________________API(1)_________________________________
 * @brief  Set The Direction Of Each Pin Of The Digital GPIO Ports To Be INPUT or OUTPUT.
 * @note   None.
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @param	Copy_u8PinNumber
 * 			This Parameter can be one of the following Values:
 *				@arg DIO_PIN0 .. DIO_PIN7
 * @param	Copy_u8PinDirection
 * 			This Parameter can be one of the following Values:
 * 				@arg INPUT
 * 				@arg OUTPUT
 * @retval None.
 **/
void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection);

/**
 * _________________________________API(2)_________________________________
 * @brief  Set The Value Of Each OUTPUT Pin Of The Digital GPIO Ports To Be LOW or HIGH.
 * @note   None.
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @param	Copy_u8PinNumber
 * 			This Parameter can be one of the following Values:
 *				@arg DIO_PIN0 .. DIO_PIN7
 * @param	Copy_u8PinState
 * 			This Parameter can be one of the following Values:
 * 				@arg LOW    ||  NO_PULLUP
 * 				@arg HIGH   ||  PULLUP
 * @retval None.
 **/
void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState);

/**
 * _________________________________API(3)_________________________________
 * @brief  Get The Value Of Each Input Pin Of The Digital GPIO Ports To Be INPUT or OUTPUT.
 * @note   None.
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @param	Copy_u8PinNumber
 * 			This Parameter can be one of the following Values:
 *				@arg DIO_PIN0 .. DIO_PIN7
 * @retval  *Copy_pu8ReturnValue , Pass By Reference..
 *          This parameter can be one of the following values:
 *              @arg 0  ||  INPUT_LOW
 *              @arg 1  ||  INPUT_HIGH
 **/
void DIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 *Copy_pu8ReturnedValue);

/**
 * _________________________________API(4)_________________________________
 * @brief  Toggle The Value Of Each Pin Of The Digital GPIO Ports. (Reverse).
 * @note   None.
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @param	Copy_u8PinNumber
 * 			This Parameter can be one of the following Values:
 *				@arg DIO_PIN0 .. DIO_PIN7
 * @retval None.
 **/
void DIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

/**
 * _________________________________API(5)_________________________________
 * @brief  Set The Direction Of Each Pin Of The Digital GPIO Ports 
 *              , With Specific Configuration all At Once To The Whole Port Register
 *              , To Be INPUT or OUTPUT.
 * @note   None.
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @param	Copy_u8PinSpecificDirection
 * 			This Parameter can be ANY_NUMBER_BETWEEN {0, 255} in binary as follows:
 * 				@arg 0b00000000 .. 0b11111111
 * @retval None.
 **/
void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection);
/**
 * _________________________________API(6)_________________________________
 * @brief  Set The Value Of Each Output Of The Digital GPIO Ports 
 *              , With Specific Configuration all At Once To The Whole Port Register
 *              , To Be LOW or HIGH.
 * @note   Prefereble to be used with all port pins set to output to avoid errors.
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @param	Copy_u8PinSpecificValue
 * 			This Parameter can be ANY_NUMBER_BETWEEN {0, 255} in binary as follows:
 * 				@arg 0b00000000 .. 0b11111111
 * @retval None.
 **/
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8SpecificValue);
/**
_________________________________API(7)_________________________________
 * @brief  Set The Direction Of ALL Port Register Of The Digital GPIO Ports 
                , To Be INPUT or OUTPUT.
 * @note   The Function Set All Register Pins to 0 or 1 ,i.e:
 * 				ALL_INPUT    ||  0x00    ||  0b00000000
 * 				ALL_OUTPUT   ||  0xFF    ||  0x11111111
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @retval None.
 **/
void DIO_voidSetPortDirectionAll(u8 Copy_u8PortName);

/**
_________________________________API(8)_________________________________
 * @brief  Set The Values Of ALL Output Port Register Of The Digital GPIO Ports 
 *              , To Be INPUT or OUTPUT.
 * @note   Prefereble to be used with all port pins set to output to avoid errors.
 *         The Function Set All Register Pins to 0 or 1 ,i.e:
 * 				ALL_LOW    ||  0x00    ||  0b00000000
 * 				ALL_HIGH   ||  0xFF    ||  0x11111111
 * @param  Copy_u8PortName
 *         This parameter can be one of the following values:
 *     			@arg DIO_PORTA
 *	            @arg DIO_PORTB
 *	            @arg DIO_PORTC
 *				@arg DIO_PORTD
 * @retval None.
 **/
void DIO_voidSetPortValueAll(u8 Copy_u8PortName);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */