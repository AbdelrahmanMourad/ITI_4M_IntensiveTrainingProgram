/*_____________________________________________________________________________
 * Author:			Abdelrahman Mourad
 * Creation Date:	12 Oct, 2023
 * Version:			v1.0
 * Compiler:		GNU GCC
 * Controller:		ATmega32    (8-Bit Architecture)
 * Processor:		AVR         (8-Bit Architecture)
 * Layer:			HAL
 * Driver:          LCD         (LMB161A Model)
 *  --------------------------------------------------------------------------
 * Version	  Date				Author					Description
 * v1.0		  12 Oct, 2023		Abdelrahman Mourad		Initial Creation
 * ____________________________________________________________________________
 */

/*  ----------------------------------------------
                Header Guard File:
    ---------------------------------------------- */
#ifndef HAL_LCD_LCD_PRIVATE_
#define HAL_LCD_LCD_PRIVATE_

/*  ----------------------------------------------
                MCAROS
    ---------------------------------------------- */
#define LCD_ALL_OUTPUT 0xFF

/*  ----------------------------------------------
                Command Data Addresses
    ---------------------------------------------- */
// 8-bit Mode.
#define LCD_FUNCTION_SET_CMD 0x38   // 0b00111000
#define LCD_DISPLAY_ON_OFF_CMD 0x0F // 0b00001111
#define LCD_DISPLAY_CLEAR_CMD 0x01  // 0b00000001
// 4-bit Mode.
#define LCD_FUNCTION_SET_CMD_P1 0b00100000   // 0b0010xxxx
#define LCD_FUNCTION_SET_CMD_P2 0b00100000   // 0b0010xxxx
#define LCD_FUNCTION_SET_CMD_P3 0b10000000   // 0b10xxxxxx
#define LCD_DISPLAY_ON_OFF_CMD_P1 0x00000000 // 0b0000xxxx
#define LCD_DISPLAY_ON_OFF_CMD_P2 0x11110000 // 0b1111xxxx
#define LCD_DISPLAY_CLEAR_CMD_P1 0b00000000  // 0b0000xxxx
#define LCD_DISPLAY_CLEAR_CMD_P2 0b00010000  // 0b0001xxxx

/*  ----------------------------------------------
                INIT MODES
    ---------------------------------------------- */
#define FOUR_BIT_MODE 0
#define EIGHT_BIT_MODE 1

/*  ---------------------------------------------------------------------------
    Short Summary:
    ==============

    LCD Module Consist of Three Memory Sections.
        1. DDRAM: Display Data RAM
        2. CGROM: Character Generator ROM.
        3. CGRAM: Character Generator RAM.

    API(1): Inintialization Function.
        Step(1): Set Control Pins {R/w,RS,EN} , And Data Pins {PD0..PD7}.
                    Direction All As Output.
        Step(2): Send Commands Of Initialization in the same order
                    mentioned in DataSheet Initialization Illustration @page 13,14.
                    @fn Using The Send Command Function == API(2).

    API(2): Send Command Function.
        Step(1): On Control Pins {R/w,RS} -> Configure as {Write->0}, {Command->0}.
                    @fn Using DIO Set Pin Value Function.
        Step(2): On Data Pins {PD0......PD7} -> Send Commands addresses as mentioned in Data Sheet @page 13,14.
                    Which is Sent As Parameter To This Function, To Set Values of Data Port With its Specific Value.
                    @fn Using The Set Port Specific Value Function.
        Step(3): On Control Enable Pin {EN} -> Send Enable Pulse {LOW, HIGH, LOW}.
                    @fn Using The Send Enable Pulse Function == API(4).

    API(3): Send Data Function.
        Step(1): On Control Pins {R/w,RS} -> Configure as {Write->0}, {Data->1}.
                    @fn Using DIO Set Pin Value Function.
        Step(2): On Data Pins {PD0......PD7} -> Send Data addresses as mentioned in Data Sheet @page 13,14.
                    Which is Sent As Parameter To This Function, To Set Values of Data Port With its Specific Value.
                    @fn Using The Set Port Specific Value Function.
        Step(3): On Control Enable Pin {EN} -> Send Enable Pulse {LOW, HIGH, LOW}.
                    @fn Using The Send Enable Pulse Function == API(4).

    API(4): Send Enable Pulse Function.
        Step(1): On Control Enable Pin {EN} -> Send Enable Pulse {LOW, HIGH, LOW}.
                    @fn Using Set Pin Value Function.

    API(5): Clear Display.
        Step(1): Send CLEAR Command in the same order mentioned in DataSheet
            Initialization Illustration @page 13,14.
            @fn Using The Send Command Function == API(2).

    API(6):
        Step(1): Take X and Y Positions coordinate as parameters.
        Ster(2): Calculate The Address Of Character On LCD.
                    Casting from {1 x 80} To {2 x 16}.
                    Store The Address in u8 variable.
        Step(3): Set The 7th Bit Of The Address Variable.

        Step(4): Send Address Variable As A Command.
                    @fn Using Send Command Function == API(2).

    API(7):

    API(8):

    API(9):


    ---------------------------------------------------------------------------
*/

#endif /* HAL_LCD_LCD_PRIVATE_ */