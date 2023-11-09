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
#ifndef MCAL_KPD_KPD_INTERFACE_H_
#define MCAL_KPD_KPD_INTERFACE_H_

/*  ----------------------------------------------
                Definitions:
    ---------------------------------------------- */
// N/A

/*  ---------------------------------------------------------------------------
                            Functions ProtoTypes:
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
void KPD_voidInit(void);

/**
_________________________________API()_________________________________
 * @brief  Initialize by Setting Colemns and Rows Directions and Values
 * @note   N/A.
 * @param  void
 * @retval Local_u8PressedKey
 **/
u8 KPD_u8GetPressedKey(void);

#endif /*MCAL_KPD_KPD_INTERFACE_H_*/
