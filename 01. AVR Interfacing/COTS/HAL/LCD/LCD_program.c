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
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

/*  ---------------------------------------------------------------------------
                            Functions Implementation:
    ---------------------------------------------------------------------------*/

/**
 * _______________________________________________
 *  @tableofcontents:
 *      API(1): LCD_voidInit(void).                                 @file: ( @interface.h )
 *      API(2): LCD_voidSendCommand(Copy_u8Command).                @file: ( Static-> @private.h)
 *      API(3): LCD_voidSendData(Copy_u8Data).                      @file: ( @interface.h )
 *      API(4): LCD_voidSendEnablePulse(void).                      @file: ( Static-> @private.h)
 *      API(5): LCD_VoidClearDisplay(void).                         @file: ( @interface.h )
 *      API(6): LCD_voidSendNumber(Copy_u32InputNumber).            @file: ( @interface.h )
 *      API(7): LCD_voidSendString(Copy_pu8InputStringArray).       @file: ( @interface.h )
 *      API(8): LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos).           @file: ( @interface.h )
 *      API(9): LCD_voidSendCustomCharacter(Copy_pu8CharacterArray, 
 *                                          Copy_u8PatternNumber,
 *                                          Copy_u8XPosition,
 *                                          Copy_u8YPosition).
 * _______________________________________________
 **/

/**
 *  _________________________________API(1)_________________________________
 *  @brief  Initialization Function of the LCD Modeule.
 *  @fn     Pre-Build.
 *  @note   None.
 *  @param  void.
 *  @retval void.
 **/
void LCD_voidInit(void)
{
    #if LCD_INIT_MODE == EIGHT_BIT_MODE

        // Initialize Data Port Direction All As Outputs.
        DIO_voidSetPortSpecificDirection(LCD_DATA_PORT, LCD_ALL_OUTPUT);

        // Initialze Control Pins Direction All As outputs.
        DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_CTRL_PIN_RS, OUTPUT);
        DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_CTRL_PIN_RW, OUTPUT);
        DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_CTRL_PIN_EN, OUTPUT);

        // Wait For More Than 30 ms.
        _delay_ms(40);
        
        // Send Function Set Command.
        LCD_voidSendCommand(LCD_FUNCTION_SET_CMD);

        // Send Display On/Off Control Command.
        LCD_voidSendCommand(LCD_DISPLAY_ON_OFF_CMD);

        // Send Display Clear Command.
        LCD_voidSendCommand(LCD_DISPLAY_CLEAR_CMD);

    #elif LCD_INIT_MODE == FOUR_BIT_MODE
        // Not Implemented Yet.
    #else
        #error("LCD_INIT_MODE Configuration Error")
    #endif
}

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
static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    // __1__CONTROL_PINS__
    // Clear The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RS, COMMAND);
    // Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RW, WRITE);

    // __2__DATA/COMMAND_PINS__
    // Set The Command On The Data/Command Port
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    // __3__ENABLE__
    // Send Enable Pulse, On The Control Pin Enable {EN}.
    LCD_voidEnablePulse();
}


/**
 * _________________________________API(3)_________________________________
 * @brief  Sending Data to the LCD uC.
 * @fn     Pre-Build.
 * @note   It automatically move one cell each time we send new data.
 * @param  Copy_u8Data
 *         This parameter can be one of the following values:
 *     			@arg LCD_FUNCTION_SET_CMD
 *	            @arg LCD_DISPLAY_ON_OFF_CMD
 *	            @arg LCD_DISPLAY_CLEAR_CMD
 * @retval None.
 **/
void LCD_voidSendData(u8 Copy_u8Data)
{
#if LCD_INIT_MODE == EIGHT_BIT_MODE

    // __1__CONTROL_PINS__
    // Set The Control Pin {RS} To Send The Command ( RS -> 0: Command, 1: Data)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RS, DATA);
    // Clear The Control Pin {RW} To Write The Command (R/W -> 0: Write, 1: Read)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RW, WRITE);

    // __2__DATA/COMMAND_PINS__
    // Assign The Data On The Data/Command Port {Db0..Db7}.
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    // __3__ENABLE__ 
    // Send Enable Pulse, On The Control Pin Enable {EN}.
    LCD_voidEnablePulse();

#elif LCD_INIT_MODE == EIGHT_BIT_MODE
    // Code
#else
#error("LCD_INIT_MODE Configuration Error")
#endif
}


/**
 * _________________________________API(4)_________________________________
 * @brief  Send Enable Pulse On The {Control Enable Pin {EN}}
 * @fn     Post-Build.
 * @note   (Static @fn => @file LCD_private.h)
 * @param  void.
 * @retval void.
 **/
static void LCD_voidSendEnablePulse(void)
{
    /* Send Enable Pulse On The {Control Enable Pin {EN}} */

    // Low.
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_EN, LOW);
    // High For 2msec.
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_EN, HIGH);
    _delay_ms(2);
    // Low.
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_EN, LOW);
}


/**
 * _________________________________API(5)_________________________________
 * @brief  This API Clears All Display.
 * @fn     Post-Build.
 * @note   None.
 * @param  void
 * @retval void.
 **/
void LCD_voidClearDisplay(void)
{
    // Take The CLEAR COMMAND and Execute using the Function Send Command.
    LCD_voidSendCommand(LCD_DISPLAY_CLEAR_CMD);
}


/**
 *  _________________________________API(6)_________________________________
 *  @brief  This API Let you Send Multi Digit Number To Display on LCD.
 *  @fn     Post-Build.
 *  @note   None.
 *  @param  Copy_u32Number.
 *           This parameter can be any number between
 *              @arg    { 0 ... 4,294,967,295 }
 *  @retval void.
 **/
void LCD_voidSendNumber(u32 Copy_u32Number)
{
    // Array To Save Each Digit To Send Alone.
    u8 Local_u8ArrayNumber[10];
    // Loop Counter.
    s8 Local_s8LoopCounter = 0;

    while (Copy_u32Number != 0)
    {
        // Store Each Digit From Right-To-Left.
        Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;

        // Remove That Digit After Storing It.
        Copy_u32Number /= 10;

        // Increase Counter Until {N == 0}
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--; // To Cancel The Last {++}.

    while (Local_s8LoopCounter >= 0)
    {
        // Send Digit By Digit .. As Ascii of The Number { '0' + N }.
        LCD_voidSendData(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
        // Decrease Conunter Until {Counter < 0}
        Local_s8LoopCounter--;
    }
}


/**
 * _________________________________API(7)_________________________________
 * @brief  This API Let You Send String {Array of Char} to Display on the LCD.
 * @fn     Post-Build.
 * @note   None.
 * @param  Copy_pu8StringArray
 *          This parameter can be one of the following values:
 *     			@arg Any String array. -> {u8 String[]}
 * @retval void.
 **/
void LCD_voidSendString(u8 *Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter = 0;

    // Loop On The String till the null terminator.
    while (Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        // Send The Array Element To Display.
        LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
    // Note: It automatically move one cell each time we send new data.
}


/**
 * _________________________________API(8)_________________________________
 * @brief  This API Let You Start Typing from Chosen Location on the LCD.
 * @fn     Post-Build.
 * @note   None.
 * @param  Copy_u8XPos
 *          This parameter can be one of the following values:
 *     			@arg 0 ... 1
 * @param  Copy_u8YPos
 *          This parameter can be one of the following values:
 *     			@arg 0 ... 16
 * @retval void.
 **/
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8CharacterAddress = 0;

    // Calculate The Address Of The Character On LCD
    if (Copy_u8XPos == 0)
    {
        // @ x = 0 -> Address = Y-Position
        Local_u8CharacterAddress = Copy_u8YPos;
    }
    else if (Copy_u8XPos == 1)
    {
        // @ x = 1 -> Address = Y-Position + 0x40
        Local_u8CharacterAddress = Copy_u8YPos + 0x40;
    }
    else
    { 
        // Raise an error.
    }

    // Set The 7th bit in the address variable.
    SET_BIT(Local_u8CharacterAddress, 7);

    // Send the address variable as a command.
    LCD_voidSendCommand(Local_u8CharacterAddress);
}


/**
 * _________________________________API(9)_________________________________
 * @brief  Send Custom Char Shape as array to be stored in the CGRAM
 *          ,In Specific Pattern Number
 *          , And Display on LCD In Specific X-Position and Y-Position.
 * @fn     Post-Build.
 * @note   None.
 * @param  Copy_pu8CharacterArray
 *           This parameter can be Any u8 Arra, Fill 1st 5-bits of the u8 numbers with the shape pattern.
 *              @arg  u8 CharacterArray[8] = []
 * @param  Copy_u8PatternNumber
 *           This parameter is the Address Of CGRAM to Store The Array Pattern inside {from 0x8 to 8x8}
 *           Each CGRAM is 5x8 dots represented as u8 array addresses
 *           Pattern addresses start from 0 to 63 addresses, each pattern takes 8 addresses {from 0x8 to 8x8}.
 *           This Parameter can be any number between:
 *              @arg  {0 ... 8}.
 * @param  Copy_u8XPos
 *          This parameter can be one of the following values:
 *     			@arg LCD_ROW_FIRST
 *     			@arg LCD_ROW_SECOND
 * @param  Copy_u8YPos
 *          This parameter can be any number between:
 *     			@arg {0 ... 16}.
 * @retval void.
 **/
void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray,
                                 u8 Copy_u8PatternNumber,
                                 u8 Copy_u8XPosition,
                                 u8 Copy_u8YPosition)
{
    // Loop Counter.
    u8 Local_u8LoopCounter;

    // Address Of CGRAM to Store The Array Pattern inside {Addresses from 0*8 to 8*8}
    u8 Local_u8CGRAMAddress = 0;

    // Calculate the CGRAM Address = {Pattern Number * 8}
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;

    // Set The 6th bit in the CGRAM Address Command
    SET_BIT(Local_u8CGRAMAddress, 6);

    // Send The CGRAM Address Command To The LCD
    LCD_voidSendCommand(Local_u8CGRAMAddress);

    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        // Send Byte From The Character Array
        LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }

    // Send The Command to Set The DDRAM Address
    LCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);

    // Display The Pattern From CGRAM
    LCD_voidSendData(Copy_u8PatternNumber);
}
