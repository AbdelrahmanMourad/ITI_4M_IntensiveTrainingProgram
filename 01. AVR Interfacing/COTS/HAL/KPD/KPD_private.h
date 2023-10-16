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

/*  ----------------------------------------------
                Header Guard File:
    ---------------------------------------------- */
#ifndef MCAL_KPD_KPD_PRIVATE_H_
#define MCAL_KPD_KPD_PRIVATE_H_

#endif /*MCAL_KPD_KPDPRIVATE__H_*/

/*  ---------------------------------------------------------------------------
    Short Summary:
    ==============

        1.  We Set Direction as follows:
                Rows Input
                Cols Output
        
        2.  We Set Values as follows:
                Rows High.
                Cols High.
        
        3.  We Iterate Cols and Make Them LOW (GND) one by one.
                Iterate Rows with each Low Col.
                    If Key Pressed => Row = 0 (Changed).
                    If Not Pressed => Row = 1 (Default).
        
        4. When {Col:Low} and {Row:Low}.    
                =>  Then PressedKey = VALUE_LAYOUT_2D_ARRAY [ThisRow][ThisCol].

        5. Return The Value of PressedKey.

        6. If No Key Was Pressed Return Specific Number.
                #define KPD_NOT_PRESSED_VAL 255

    ---------------------------------------------------------------------------
*/