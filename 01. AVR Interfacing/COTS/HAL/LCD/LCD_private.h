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
#define FOUR_BIT_MODE  0
#define EIGHT_BIT_MODE 1

#define LCD_ROW_FIRST  0
#define LCD_ROW_SECOND 1

/*  ---------------------------------------------------------------------------
                            PRIVATE Functions ProtoTypes:
    ---------------------------------------------------------------------------*/    
/**
 * _________________________________API(2)_________________________________
 * @brief  Sending Command to the LCD uC.
 * @fn     Pre-Build.
 * @note   (Static @fn => @file LCD_private.h)
 * @param  Copy_u8Command
 *         This parameter can be one of the following values:
 *     			@arg LCD_FUNCTION_SET_CMD
 *	            @arg LCD_DISPLAY_ON_OFF_CMD
 *	            @arg LCD_DISPLAY_CLEAR_CMD
 * @retval void.
 **/
static void LCD_voidSendCommand(u8 Copy_u8Command);

/**
 * _________________________________API(4)_________________________________
 * @brief  Send Enable Pulse On The {Control Enable Pin {EN}}
 * @fn     Post-Build.
 * @note   (Static @fn => @file LCD_private.h)
 * @param  void.
 * @retval void.
 **/
static void LCD_voidSendEnablePulse(void);




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
        -> NOTE: Cursor automatically moves to next cell automatically after each Data Send.    

    API(4): Send Enable Pulse Function.
        Step(1): On Control Enable Pin {EN} -> Send Enable Pulse {LOW, HIGH, LOW}.
                    @fn Using Set Pin Value Function.

    API(5): Clear Display.
        Step(1): Send CLEAR Command in the same order mentioned in DataSheet
            Initialization Illustration @page 13,14.
            @fn Using The Send Command Function == API(2).

    API(6):
        Steo(1): Store Each Digit As Array Element To Be Sent individually.
                NOTE: Store From LEFT To RIGHT.
        Step(2): Display Digite From Array Elements One By One
                NOTE: Send From RIGHT To LEFT {N to 0}
                @fn Using Send Data Function == API(3)

    API(7):
        Step(1): Loop The String Array Until: { Array[FinalElement]=='0' }.
        Step(2): Send Each Character Individually.
                @fn Using Send Data Function == API(3).

    API(8):
        Step(1): Take X and Y Positions coordinate as parameters.
        Ster(2): Calculate The Address Of Character On LCD.
                    Casting from {1 x 80} To {2 x 16}.
                    Store The Address in u8 variable.
        Step(3): Set The 7th Bit Of The Address Variable.
        Step(4): Send Address Variable As A Command.
                    @fn Using Send Command Function == API(2).

    API(9):
        Step(1): Calculate Pattern CGRAM Address = {PatternNumber x 8}. 
            NOTE: Only each u8 number fill 5-bits for 5 dots.
        Step(2): Set The 6th bit int the CGRAM Address Command.
        Step(3): Send The CGRAM Address Command to LDC
        Step(4): Loop The pu8CharacterArray[], And Send Data Byte By Byte.
        Step(5): Send The Command To Set Cursor On The XPos, YPos.
            Using LCD_voidGoToXY(X,Y) Function == API(8).
        Step(6): Display The Pattern from CGRAM on Display.
            Using LCD_voidSendData(PatternNumber) == API(3).


    ---------------------------------------------------------------------------
*/

#endif /* HAL_LCD_LCD_PRIVATE_ */