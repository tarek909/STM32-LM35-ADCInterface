 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.c
 *
 * Description: Source file for LCD driver
 *
 * Author: Muhammad Al-Barbary
 *
 *******************************************************************************/
#include "gpio.h"
#include "LCD.h"
#include <stdlib.h>

void LCD_Init(void){
	/*Set LCD_RSPin,LCD_RWPin,LCD_EPin and LCD_DataPort (Pins0-7) as output pins */
	GPIO_Init(LCD_RSPort,LCD_RSPin,1,0);
	GPIO_Init(LCD_RWPort,LCD_RWPin,1,0);
	GPIO_Init(LCD_EPort,LCD_EPin,1,0);
	for (int DataPortCounter=0;DataPortCounter<8;DataPortCounter++){
		GPIO_Init(LCD_DataPort,DataPortCounter,1,0);
	}
	LCD_SendCommand(LCD_EightBits);
	LCD_SendCommand(LCD_CursorOff);
	LCD_SendCommand(LCD_Clear);
}

void LCD_SendCommand(unsigned char command){
	GPIO_Write(LCD_RWPort,LCD_RWPin,0);
	GPIO_Write(LCD_RSPort,LCD_RSPin,0);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	GPIO_Write(LCD_EPort,LCD_EPin,1);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	for (int DataPortCounter=0;DataPortCounter<8;DataPortCounter++){
		GPIO_Write(LCD_DataPort,DataPortCounter,command & (1<<DataPortCounter));
	}
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	GPIO_Write(LCD_EPort,LCD_EPin,0);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
}

void LCD_DisplayCharacter(unsigned char data){
	GPIO_Write(LCD_RWPort,LCD_RWPin,0);
	GPIO_Write(LCD_RSPort,LCD_RSPin,1);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	GPIO_Write(LCD_EPort,LCD_EPin,1);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	for (int DataPortCounter=0;DataPortCounter<8;DataPortCounter++){
		GPIO_Write(LCD_DataPort,DataPortCounter,data & (1<<DataPortCounter));
	}
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
	GPIO_Write(LCD_EPort,LCD_EPin,0);
	for(int MiniDelay=0;MiniDelay<5000;MiniDelay++);
}

void LCD_DisplayString(const char *Str){
	unsigned char i=0;
	while( Str[i]!= '\0'){
		LCD_DisplayCharacter(Str[i]);
		i++;
	}
}

void LCD_MoveCursor(unsigned char row,unsigned char col){
	unsigned char LCD_address;
	switch(row)
		{
			case 0:
				LCD_address=col;
					break;
			case 1:
				LCD_address=col+0x40;
					break;
			case 2:
				LCD_address=col+0x10;
					break;
			case 3:
				LCD_address=col+0x50;
					break;
		}
	LCD_SendCommand(LCD_address | LCD_SetCursor);
}

void LCD_DisplayStringRowColumn(unsigned char row,unsigned char col,const char *Str)
{
	LCD_MoveCursor(row,col);
	LCD_DisplayString(Str);
}

void LCD_IntToStr(unsigned int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_DisplayString(buff); /* Display the string */
}

void LCD_ClearScreen(void){
	LCD_SendCommand(LCD_Clear);
}
