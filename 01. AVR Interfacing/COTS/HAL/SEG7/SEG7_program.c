/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	24 Sep, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32    (8-Bit Architecture)
 * Processor:		AVR         (8-Bit Architecture)
 * Layer:			MCAL
 * Driver:          SEG7        (7-Segment)
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  24 Sep, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
 */

/*  ---------------------------------------------------------------------------
							Included Libraries:
	---------------------------------------------------------------------------*/
/*Library Inclusions*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*Lower Layer Inclusions*/
#include "../../MCAL/DIO/DIO_interface.h"
/*Self Layer Inclusions*/

/*Self Files Inclusions*/
#include "SEG7_interface.h"
#include "SEG7_private.h"
#include "SEG7_config.h"

/*  ---------------------------------------------------------------------------
							Functions Implementation:
	---------------------------------------------------------------------------*/

/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1).
 *      	Init. Function.
 *      API(2).
 * 			Print A Number.
 *      API(3).
 * 			Count Down In Seconds.
 *      API(4).
 * 			Count Up In Seconds.
 * _______________________________________________
 **/

/**
 * _________________________________API(1)_________________________________
 * @brief  Initialize 7-Segment Function Sets All Port Pins As Output.
 * @note   None.
 * @param  Copy_u8Seg7Port
 *         This parameter can be one of the following values:
 *     			@arg	SEG7_PORT_A	|| 	DIO_PORTA
 *	            @arg	SEG7_PORT_B	|| 	DIO_PORTB
 *	            @arg	SEG7_PORT_C	|| 	DIO_PORTC
 *				@arg	SEG7_PORT_D	|| 	DIO_PORTD
 * @retval None.
 **/
void SEG7_voidInit(u8 Copy_u8Seg7Port)
{
	switch (Copy_u8Seg7Port)
	{
	case SEG7_PORT_A:
		DIO_voidSetPortDirectionAll(SEG7_PORT_A);
		break;
	case SEG7_PORT_B:
		DIO_voidSetPortDirectionAll(SEG7_PORT_B);
		break;
	case SEG7_PORT_C:
		DIO_voidSetPortDirectionAll(SEG7_PORT_C);
		break;
	case SEG7_PORT_D:
		DIO_voidSetPortDirectionAll(SEG7_PORT_D);
		break;
	}
}

/**
 * _________________________________API(2)_________________________________
 * @brief  Set The Value Of Each OUTPUT Pin Of The Digital GPIO Ports To Be LOW or HIGH.
 * @note   None.
 * @param  Copy_u8Seg7Port
 *         This parameter can be one of the following values:
 *     			@arg	SEG7_PORT_A	|| 	DIO_PORTA
 *	            @arg	SEG7_PORT_B	|| 	DIO_PORTB
 *	            @arg	SEG7_PORT_C	|| 	DIO_PORTC
 *				@arg	SEG7_PORT_D	|| 	DIO_PORTD
 * @param	Copy_NumberToPrint
 * 			This Parameter can be one of the following Values:
 *				@arg 	SEG7_NUMBER_0 .. SEG7_NUMBER_9
 * @retval None.
 **/
void SEG7_voidPrintNumber(u8 Copy_u8Seg7Port, u8 Copy_NumberToPrint)
{
	switch (Copy_u8NumberToPrint)
	{
	case SEG7_NUMBER_0:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_0);
		break;
	case SEG7_NUMBER_1:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_1);
		break;
	case SEG7_NUMBER_2:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_2);
		break;
	case SEG7_NUMBER_3:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_3);
		break;
	case SEG7_NUMBER_4:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_4);
		break;
	case SEG7_NUMBER_5:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_5);
		break;
	case SEG7_NUMBER_6:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_6);
		break;
	case SEG7_NUMBER_7:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_7);
		break;
	case SEG7_NUMBER_8:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_8);
		break;
	case SEG7_NUMBER_9:
		DIO_voidSetPortSpecificValue(Copy_u8Seg7Port, SEG7_NUMBER_9);
		break;
	}
}

/**
 * _________________________________API(3)_________________________________
 * @brief  Print Count-Down From "Count-Time" To "Zero" With Delay 1 Sec:
 * @note   None.
 * @param  Copy_u8Seg7Port
 *         This parameter can be one of the following values:
 *     			@arg	SEG7_PORT_A	|| 	DIO_PORTA
 *	            @arg	SEG7_PORT_B	|| 	DIO_PORTB
 *	            @arg	SEG7_PORT_C	|| 	DIO_PORTC
 *				@arg	SEG7_PORT_D	|| 	DIO_PORTD
 * @param	Copy_CountTime
 * 			This Parameter can be one of the following Values:
 *				@arg 	Any {int} Number Of Seconds.
 * @retval  None
 **/
void SEG7_voidCountDown_s(u8 Copy_u8Seg7Port, u8 Copy_CountTime)
{
	s8 Local_s8LoopCounter = Copy_CountTime;
	for (Local_s8LoopCounter; Local_s8LoopCounter >= 0; Local_s8LoopCounter--)
	{
		SEG7_voidPrintNumber(Copy_u8Seg7Port, Local_s8LoopCounter);
		_delay_ms(1000);
	}
}

/**
 * _________________________________API(4)_________________________________
 * @brief  Print Count-UP From "Zero" to "Count-Time" With Delay 1 Sec:
 * @note   None.
 * @param  Copy_u8Seg7Port
 *         This parameter can be one of the following values:
 *     			@arg	SEG7_PORT_A	|| 	DIO_PORTA
 *	            @arg	SEG7_PORT_B	|| 	DIO_PORTB
 *	            @arg	SEG7_PORT_C	|| 	DIO_PORTC
 *				@arg	SEG7_PORT_D	|| 	DIO_PORTD
 * @param	Copy_CountTime
 * 			This Parameter can be one of the following Values:
 *				@arg 	Any {int} Number Of Seconds.
 * @retval  None
 **/
void SEG7_voidCountDown_s(u8 Copy_u8Seg7Port, u8 Copy_CountTime)
{
	s8 Local_s8LoopCounter = 0;
	for (Local_s8LoopCounter; Local_s8LoopCounter <= Copy_CountTime; Local_s8LoopCounter++)
	{
		SEG7_voidPrintNumber(Copy_u8Seg7Port, Local_s8LoopCounter);
		_delay_ms(1000);
	}
}