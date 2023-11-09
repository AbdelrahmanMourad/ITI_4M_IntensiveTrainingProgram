/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	09 Nov, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32    (8-Bit Architecture)
 * Processor:		AVR         (8-Bit Architecture)
 * Layer:			HAL
 * Driver:          LED         (Light Emissive Diode - LED)
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  09 Nov, 2023		Abdelrahman Mourad		Initial Creation
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
#include "../../MCAL/DIO/DIO_interface.h"
/*Self Files Inclusions*/
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

/*  ---------------------------------------------------------------------------
                            Functions Implementation:
    ---------------------------------------------------------------------------*/

/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1): void LED_voidInit(LED_t* Ledobj);
 *      API(2): void LED_voidTurnOn(LED_t* Ledobj);
 *      API(3): void LED_voidTurnOff(LED_t* Ledobj);
 *      API(4): void LED_voidToggle(LED_t* Ledobj);
 * _______________________________________________
 **/

/**
 * _________________________________API(1)_________________________________
 * @brief  Initialize LED PORT PIN by setting Direction to OUTPUT.
 * @note   N/A.
 * @param  Ledobj
 *         This is {Object from LED_t struct} can be one of the following values:
 *     			@arg &LED1
 *                  @note     LED_t LED1 { DIO_PORTA , DIO_PIN0     };
 *                      OR:   LED_t LED1 {  .LED_PORT = DIO_PORTA,
 *                                          .LED_PIN  = DIO_PIN0    };
 * @retval void.
 **/
void LED_voidInit(LED_t *Ledobj)
{
    DIO_voidSetPinDirection(Ledobj->LED_PORT, Ledobj->LED_PIN, OUTPUT);
}

/**
 * _________________________________API(2)_________________________________
 * @brief  SET LED PORT PIN Value to HIGH, to turn it on.
 * @note   N/A.
 * @param  Ledobj
 *         This is {Object from LED_t struct} can be one of the following values:
 *     			@arg &LED1
 *                  @note     LED_t LED1 { DIO_PORTA , DIO_PIN0     };
 *                      OR:   LED_t LED1 {  .LED_PORT = DIO_PORTA,
 *                                          .LED_PIN  = DIO_PIN0    };
 * @retval void.
 **/
void LED_voidTurnOn(LED_t *Ledobj)
{
    DIO_voidSetPinValue(Ledobj->LED_PORT, Ledobj->LED_PIN, HIGH);
}

/**
 * _________________________________API(3)_________________________________
 * @brief  SET LED PORT PIN Value to LOW, to turn it off.
 * @note   N/A.
 * @param  Ledobj
 *         This is {Object from LED_t struct} can be one of the following values:
 *     			@arg &LED1
 *                  @note     LED_t LED1 { DIO_PORTA , DIO_PIN0     };
 *                      OR:   LED_t LED1 {  .LED_PORT = DIO_PORTA,
 *                                          .LED_PIN  = DIO_PIN0    };
 * @retval void.
 **/
void LED_voidTurnOff(LED_t *Ledobj)
{
    DIO_voidSetPinValue(Ledobj->LED_PORT, Ledobj->LED_PIN, LOW);
}

/**
 * _________________________________API(4)_________________________________
 * @brief  Reverse LED PORT PIN Value, To Toggle the LED Status.
 * @note   N/A.
 * @param  Ledobj
 *         This is {Object from LED_t struct} can be one of the following values:
 *     			@arg &LED1
 *                  @note     LED_t LED1 { DIO_PORTA , DIO_PIN0     };
 *                      OR:   LED_t LED1 {  .LED_PORT = DIO_PORTA,
 *                                          .LED_PIN  = DIO_PIN0    };
 * @retval void.
 **/
void LED_voidToggle(LED_t *Ledobj)
{
    DIO_voidTogPinValue(Ledobj->LED_PORT, Ledobj->LED_PIN);
}
