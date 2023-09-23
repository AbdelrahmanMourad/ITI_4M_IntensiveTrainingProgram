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

/*Self Files Inclusions*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*  ---------------------------------------------------------------------------
							Functions Implementation:
	---------------------------------------------------------------------------*/

//___________________________________API_SET(1)__________________________________
// Pin Direction Configuration APIs:
// API(1).
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

//___________________________________API_SET(2)__________________________________
// Pin Value Configuration APIs:
// API(2).
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

// API(3).
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
	case DIO_PORTB:
		*Copy_pu8ReturnedValue = GET_BIT(PINC, Copy_u8PinNumber);
		break;
	case DIO_PORTD:
		*Copy_pu8ReturnedValue = GET_BIT(PIND, Copy_u8PinNumber);
		break;
	}
}

// API(4).
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
	case DIO_PORTB:
		TOG_BIT(PORTC, Copy_u8PinNumber);
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD, Copy_u8PinNumber);
		break;
	}
}
//___________________________________API_SET(3)__________________________________
// Port Specific Config APIs:
// API(5).
void DIO_SetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection)
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

// API(6).
void DIO_SetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8SpecificValue)
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

//___________________________________API_SET(4)__________________________________
// Port General Set APIs:
// API(7).
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

// API(8).
void DIO_voidSetPortAllValueAll(u8 Copy_u8PortName)
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

//___________________________________API_SET(5)__________________________________
