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
 *      API(1): LCD_voidInit(void).
 *      API(2): LCD_voidSendCommand(Copy_u8Command).    =>  (Static..@private.h)
 *      API(3): LCD_voidSendData(Copy_u8Data).
 *      API(4): LCD_voidSendPulse(void).
 *      API(5): LCD_VoidClearDisplay(void).
 *      API(6): LCD_voidSendNumber(Copy_u32InputNumber).
 *      API(7): LCD_voidSendString(Copy_pu8InputStringArray).
 *      API(8): LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos).
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
    // Wait For More Than 30 ms
    _delay_ms(40);
    /*Send Function Set Command*/
    LCD_voidSendCommand(FUNCTION_SET_CMD);
    /*Send Display On/Off Control Command*/
    LCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
    /*Send Display Clear Command*/
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);

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
 * @note   None.
 * @param  Copy_u8Command
 *         This parameter can be one of the following values:
 *     			@arg LCD_FUNCTION_SET_CMD
 *	            @arg LCD_DISPLAY_ON_OFF_CMD
 *	            @arg LCD_DISPLAY_CLEAR_CMD
 * @retval void.
 **/
static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    // ----------------------
    // Control Pins {RS,R/W}:
    // ----------------------
    // Clear The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RS, COMMAND);
    // Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RW, WRITE);

    // ---------------------
    // Data Pins {Db0..Db7}:
    // ---------------------
    // Set The Command On The Data/Command Port
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    // ------------------------
    // Control Enable Pin {EN}:
    // ------------------------
    LCD_voidEnablePulse();
}

/**
 * _________________________________API(3)_________________________________
 * @brief  Sending Data to the LCD uC.
 * @fn     Pre-Build.
 * @note   None.
 * @param  Copy_u8Data
 *         This parameter can be one of the following values:
 *     			@arg LCD_FUNCTION_SET_CMD
 *	            @arg LCD_DISPLAY_ON_OFF_CMD
 *	            @arg LCD_DISPLAY_CLEAR_CMD
 * @retval None.
 **/
void LCD_voidSendData(u8 Copy_u8Data)
{
    // ----------------------
    // Control Pins {RS,R/W}:
    // ----------------------
    // Set The RS Pin To Send The Command ( RS -> 0: Command, 1: Data)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RS, DATA);
    // Clear The RW Pin To Write The Command (R/W -> 0: Write, 1: Read)
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_PIN_RW, WRITE);

    // ---------------------
    // Data Pins {Db0..Db7}:
    // ---------------------
    // Set The Command On The Data/Command Port
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    // ------------------------
    // Control Enable Pin {EN}:
    // ------------------------
    /*Send Enable Pulse*/
    LCD_voidEnablePulse();
}

/**
 * _________________________________API(4)_________________________________
 * @brief  Send Enable Pulse On The {Control Enable Pin {EN}}
 * @fn     Post-Build.
 * @note   None.
 * @param  void
 * @retval void.
 **/
static void LCD_voidSendEnablePulse(void)
{
    /* Send Enable Pulse On The {Control Enable Pin {EN}} */

    // Low.
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    // High For 2msec.
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    // Low.
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

/**
 * _________________________________API(5)_________________________________
 * @brief
 * @fn     Post-Build.
 * @note   None.
 * @param  void
 * @retval void.
 **/
void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);
}

/**
 * _________________________________API(6)_________________________________
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
    /*Calculate The Address Of The Character On LCD*/
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
        // Raise an error
    }
    /*Set The 7th bit in the address variable*/
    SET_BIT(Local_u8CharacterAddress, 7);
    /*Send the address variable as a command*/
    LCD_voidSendCommand(Local_u8CharacterAddress);
}

/**
 * _________________________________API(7)_________________________________
 * @brief
 * @fn     Post-Build.
 * @note   None.
 * @param  void
 * @retval void.
 **/
void LCD_voidSendString(u8 *Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter = 0;
    /*Loop On The String till the null terminator*/
    while (Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        /*Send The Array Element*/
        LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
}
/**
 *  _________________________________API(8)_________________________________
 *  @brief
 *  @fn     Post-Build.
 *  @note   None.
 *  @param  void
 *  @retval void.
 **/
void LCD_voidSendNumber(u32 Copy_u32Number)
{
    u8 Local_u8ArrayNumber[10];
    s8 Local_s8LoopCounter = 0;
    while (Copy_u32Number != 0)
    {
        Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--; // To Cancel The Last {++}.

    while (Local_s8LoopCounter >= 0)
    {
        LCD_voidSendData(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }
}

/**
 * _________________________________API(9)_________________________________
 * @brief
 * @fn     Post-Build.
 * @note   None.
 * @param  void
 * @retval void.
 **/
void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray,
                                 u8 Copy_u8PatternNumber,
                                 u8 Copy_u8XPosition,
                                 u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter;
    u8 Local_u8CGRAMAddress = 0;
    /*Calculate the CGRAM Address = Pattern Number * 8*/
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
    /*Set The 6th bit in the CGRAM Address Command*/
    SET_BIT(Local_u8CGRAMAddress, 6);
    /*Send The CGRAM Address Command To The LCD*/
    LCD_voidSendCommand(Local_u8CGRAMAddress);
    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        /*Send Byte From The Character Array*/
        LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }
    /*Send The Command to Set The DDRAM Address*/
    LCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);
    /*Display The Pattern From CGRAM*/
    LCD_voidSendData(Copy_u8PatternNumber);
}
