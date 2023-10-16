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
 * @brief  Initialize by Setting Columns and Rows Directions and Values
 * @note   N/A.
 * @param  void.
 * @retval void.
 **/
void KPD_voidInit(void)
{
    /*__ROWS__*/
    // Set Rows Pins Direction To Be Input.
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW0_PIN, INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW1_PIN, INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW2_PIN, INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW3_PIN, INPUT);
    // Set Rows Pins Value To Be  PulledUp (HIGH).
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW0_PIN, PULLUP);
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW1_PIN, PULLUP);
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW2_PIN, PULLUP);
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW3_PIN, PULLUP);

    /*__COLUMNS__*/
    // Set Columns Pins Direction To Be Output.
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, OUTPUT);
    // Set Columns Pins Value To Be HIGH.
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, HIGH);
}

/**
_________________________________API(2)_________________________________
 * @brief  Initialize by Setting Colemns and Rows Directions and Values
 * @note   N/A.
 * @param  void
 * @retval Local_u8PressedKey
 **/
u8 KPD_u8GetPressedKey(void)
{
    // KeyPad Values Layout Represented in 2D Array.
    static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COLUMNS_NUM] = KPD_ARR_VAL_LAYOUT;

    // Columns Pins, Represented in 1D Array.
    static u8 Local_u8KPDColumnsArray[KPD_COLUMNS_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};

    // Rows Pins, Represented in 1D Array.
    static u8 Local_u8KPDRowsArray[KPD_ROWS_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

    u8 Local_u8RowValue;                         // Container for row values to compare status each loop.
    u8 Local_u8ColumnsIterator;                  // Loop Counter for Columns.
    u8 Local_u8RowsIterator;                     // Loop Counter for Rows.
    u8 Local_u8PressedKey = KPD_NOT_PRESSED_VAL; // Value Of the Key Pressed (Will Return Finally To User).

    // Iterate On KPD Columns Array.
    for (Local_u8ColumnsIterator = 0; Local_u8ColumnsIterator < KPD_COLUMNS_NUM; Local_u8ColumnsIterator++)
    {
        // Activate A Column => { Activate (value == Ground) }.
        DIO_voidSetPinValue(KPD_COLUMNS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], LOW); // ****

        // Iterate On The KPD Rows Array.
        for (Local_u8RowsIterator = 0; Local_u8RowsIterator < KPD_ROWS_NUM; Local_u8RowsIterator++)
        {
            // Get The Row Value.
            Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);

            // Compare Value.
            if (Local_u8RowValue == LOW)
            {
                // Get The Pressed Key.
                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowsIterator][Local_u8ColumnsIterator];

                // Polling (busy wait) till the key is released.
                while (Local_u8RowValue == LOW)
                {
                    Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
                }

                // Return The Pressed Key.
                return Local_u8PressedKey;
            }
        }

        // Deactivate A Column => { Activate (value == VCC) }.
        DIO_voidSetPinValue(KPD_COLUMNS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], HIGH); // *****
    }
    
    // Return The Default Value.
    return Local_u8PressedKey;
}