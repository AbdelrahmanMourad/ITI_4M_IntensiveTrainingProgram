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

/*  ----------------------------------------------
                Header Guard File:
    ---------------------------------------------- */
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/*  ----------------------------------------------
                MACROS:
    ---------------------------------------------- */
// All Ports.
#define SEG7_PORT_A     DIO_PORTA
#define SEG7_PORT_B     DIO_PORTB
#define SEG7_PORT_C     DIO_PORTC
#define SEG7_PORT_D     DIO_PORTD

// Numbers For 7-Segment.
#define SEG7_NUMBER_0   0
#define SEG7_NUMBER_1   1
#define SEG7_NUMBER_2   2
#define SEG7_NUMBER_3   3
#define SEG7_NUMBER_4   4
#define SEG7_NUMBER_5   5
#define SEG7_NUMBER_6   6
#define SEG7_NUMBER_7   7
#define SEG7_NUMBER_8   8
#define SEG7_NUMBER_9   9

// For Register Direction.
#define ALL_OUTPUT      0xFF    //0b11111111


/*  ---------------------------------------------------------------------------
                            Functions ProtoTypes:
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
void SEG7_voidInit(u8 Copy_u8Seg7Port);

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
void SEG7_voidPrintNumber(u8 Copy_u8Seg7Port, u8 Copy_NumberToPrint);

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
void SEG7_voidCountDown_s(u8 Copy_u8Seg7Port, u8 Copy_CountTime);

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
void SEG7_voidCountUp_s(u8 Copy_u8Seg7Port, u8 Copy_CountTime);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */