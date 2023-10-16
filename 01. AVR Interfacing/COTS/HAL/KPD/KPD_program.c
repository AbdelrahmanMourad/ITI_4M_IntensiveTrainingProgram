/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	16 Ocr, 2023
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
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

/*  ---------------------------------------------------------------------------
                            Functions Implementation:
    ---------------------------------------------------------------------------*/

/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1): KPD_voidInit(void)
 *      API(2): KPD_u8GetPressedKey(void)
 * _______________________________________________
 **/

/**
_________________________________API(1)_________________________________
 * @brief  Initialize by Setting Colemns and Rows Directions and Values
 * @note   N/A.
 * @param  void.
 * @retval void.
 **/
void KPD_voidInit(void)
{
}

/**
_________________________________API()_________________________________
 * @brief  Initialize by Setting Colemns and Rows Directions and Values
 * @note   N/A.
 * @param  void
 * @retval Local_u8PressedKey
 **/
u8 KPD_u8GetPressedKey(void)
{
}