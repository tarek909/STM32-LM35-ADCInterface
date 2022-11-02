 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.h
 *
 * Description: Header file for LCD driver
 *
 * Author: Muhammad Al-Barbary
 *
 *******************************************************************************/
#ifndef LCD_H_
#define LCD_H_

 /*
  ******************************************************************************
								HOW TO USE
  *******************************************************************************
  LCD Model: LM041L or LM016L
  1. Set Port and Pins in definitions as connected, Connect Data pins alone in a port from pin 0 to pin7, don't use other pins in the same port
  2. Call LCD_Init() in main
  3. Call LCD_DisplayString("Any String") to display "Any String" in the current location
  4. Call LCD_IntToStr(Integer) to display a number
  5. Call LCD_DisplayStringRowColumn(Row Index,Column Index,"String") to display "String" in the specified location
  6. Call LCD_ClearScreen() to clear the screen
  7. Call LCD_MoveCursor(Row Number,Column Number) to set cursor to a specified location
*/

//Definitions

// Pins
#define LCD_RSPort                    GPIOA
#define LCD_RSPin                     1

#define LCD_RWPort                    GPIOA
#define LCD_RWPin                     2

#define LCD_EPort                     GPIOA
#define LCD_EPin                      3

#define LCD_DataPort                  GPIOB

// Commands
#define LCD_Clear                      0x01
#define LCD_Home                       0x02
#define LCD_EightBits                  0x38
#define LCD_FourBits                   0x28
#define LCD_CursorOff                  0x0C
#define LCD_CursorOn                   0x0E
#define LCD_SetCursor                  0x80



//Functions Prototypes

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_Init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_SendCommand(unsigned char command);



/*
 * Description :
 * Display the required character on the screen
 */
void LCD_DisplayCharacter(unsigned char data);



/*
 * Description :
 * Display the required string on the screen
 */
void LCD_DisplayString(const char *Str);



/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_MoveCursor(unsigned char row,unsigned char col);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_IntToStr(unsigned int data);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_DisplayStringRowColumn(unsigned char row,unsigned char col,const char *Str);




/*
 * Description :
 * Send the clear screen command
 */
void LCD_ClearScreen(void);

#endif /* LCD_H_ */
