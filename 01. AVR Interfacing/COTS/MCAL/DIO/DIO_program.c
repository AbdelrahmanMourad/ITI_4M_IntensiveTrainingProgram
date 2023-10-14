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

/*  ---------------------------------------------------------------------------
							Included Libraries:
	---------------------------------------------------------------------------*/
/*Library Inclusions*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*Lower Layer Inclusions*/
/*Self Layer Inclusions*/
/*Self Files Inclusions*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*  ---------------------------------------------------------------------------
							Functions Implementation:
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
 * @brief  Set The Direction Of Each Pin Of The Digital GPIO Ports
 * 				, To Be INPUT or OUTPUT.
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
void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection)
{
	switch (Copy_u8PortName)
	{
	case (DIO_PORTA):
		switch (Copy_u8PinDirection)
		{
		case INPUT:
			CLR_BIT(DDRA, Copy_u8PinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRA, Copy_u8PinNumber);
			break;
		}
		break;
	case (DIO_PORTB):
		switch (Copy_u8PinDirection)
		{
		case INPUT:
			CLR_BIT(DDRB, Copy_u8PinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRB, Copy_u8PinNumber);
			break;
		}
		break;
	case (DIO_PORTC):
		switch (Copy_u8PinDirection)
		{
		case INPUT:
			CLR_BIT(DDRC, Copy_u8PinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRC, Copy_u8PinNumber);
			break;
		}
		break;
	case (DIO_PORTD):
		switch (Copy_u8PinDirection)
		{
		case INPUT:
			CLR_BIT(DDRD, Copy_u8PinNumber);
			break;
		case OUTPUT:
			SET_BIT(DDRD, Copy_u8PinNumber);
			break;
		}
		break;
	}
}

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
void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		switch (Copy_u8PinState)
		{
		case LOW:
			CLR_BIT(PORTA, Copy_u8PinNumber);
			break;
		case HIGH:
			SET_BIT(PORTA, Copy_u8PinNumber);
			break;
		}
		break;
	case DIO_PORTB:
		switch (Copy_u8PinState)
		{
		case LOW:
			CLR_BIT(PORTB, Copy_u8PinNumber);
			break;
		case HIGH:
			SET_BIT(PORTB, Copy_u8PinNumber);
			break;
		}
		break;
	case DIO_PORTC:
		switch (Copy_u8PinState)
		{
		case LOW:
			CLR_BIT(PORTC, Copy_u8PinNumber);
			break;
		case HIGH:
			SET_BIT(PORTC, Copy_u8PinNumber);
			break;
		}
		break;
	case DIO_PORTD:
		switch (Copy_u8PinState)
		{
		case LOW:
			CLR_BIT(PORTD, Copy_u8PinNumber);
			break;
		case HIGH:
			SET_BIT(PORTD, Copy_u8PinNumber);
			break;
		}
		break;
	}
}

/**
 * _________________________________API(3)_________________________________
 * @brief  Get The Value Of Each Input Pin Of The Digital GPIO Ports
 * 				, To Be INPUT or OUTPUT.
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
void DIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 *Copy_pu8ReturnedValue)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		*Copy_pu8ReturnedValue = GET_BIT(PINA, Copy_u8PinNumber);
		break;
	case DIO_PORTB:
		*Copy_pu8ReturnedValue = GET_BIT(PINB, Copy_u8PinNumber);
		break;
	case DIO_PORTC:
		*Copy_pu8ReturnedValue = GET_BIT(PINC, Copy_u8PinNumber);
		break;
	case DIO_PORTD:
		*Copy_pu8ReturnedValue = GET_BIT(PIND, Copy_u8PinNumber);
		break;
	}
}

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
void DIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA, Copy_u8PinNumber);
		break;
	case DIO_PORTB:
		TOG_BIT(PORTB, Copy_u8PinNumber);
		break;
	case DIO_PORTC:
		TOG_BIT(PORTC, Copy_u8PinNumber);
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD, Copy_u8PinNumber);
		break;
	}
}

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
 * 			This Parameter can be ANY NUMBER BETWEEN {0, 255} in binary as follows:
 * 				@arg 0b00000000 .. 0b11111111
 * @retval None.
 **/
void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		// DDRA = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(DDRA, Copy_u8SpecificDirection);
		break;
	case DIO_PORTB:
		// DDRB = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(DDRB, Copy_u8SpecificDirection);
		break;
	case DIO_PORTC:
		// DDRC = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(DDRC, Copy_u8SpecificDirection);
		break;
	case DIO_PORTD:
		// DDRD = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(DDRD, Copy_u8SpecificDirection);
		break;
	}
}

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
 * 			This Parameter can be ANY NUMBER BETWEEN {0, 255} in binary as follows:
 * 				@arg 0b00000000 .. 0b11111111
 * @retval None.
 **/
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8SpecificValue)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		// PORTA = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(PORTA, Copy_u8SpecificValue);
		break;
	case DIO_PORTB:
		// PORTB = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(PORTB, Copy_u8SpecificValue);
		break;
	case DIO_PORTC:
		// PORTC = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(PORTC, Copy_u8SpecificValue);
		break;
	case DIO_PORTD:
		// PORTD = Copy_u8SpecificDirection;
		SET_REG_SPECIFIC_VALUE(PORTD, Copy_u8SpecificValue);
		break;
	}
}

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
void DIO_voidSetPortDirectionAll(u8 Copy_u8PortName)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		SET_REG(DDRA);
		break;
	case DIO_PORTB:
		SET_REG(DDRB);
		break;
	case DIO_PORTC:
		SET_REG(DDRC);
		break;
	case DIO_PORTD:
		SET_REG(DDRD);
		break;
	}
}

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
void DIO_voidSetPortValueAll(u8 Copy_u8PortName)
{
	switch (Copy_u8PortName)
	{
	case DIO_PORTA:
		SET_REG(PORTA);
		break;
	case DIO_PORTB:
		SET_REG(PORTB);
		break;
	case DIO_PORTC:
		SET_REG(PORTC);
		break;
	case DIO_PORTD:
		SET_REG(PORTD);
		break;
	}
}
