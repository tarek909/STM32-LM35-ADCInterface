/*
 *  File Name: main.c
 *  Created on: May 15, 2022
 *  Description: main file to test ADC1 Driver for STM32 by reading analog voltage from LM35 Temperature sensor
 *  Team Members: Muhammad Al-Barbary  Section:2  BN:10
 *  		      Tarek Mohamed		   Section:1  BN:45
 */


#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "ADC.h"
#include "LCD.h"

/*Function Prototypes*/
/*ADC Manage only available in Polling mode*/
#if (USE_POLLING==1)
void ADC_Manage();
#endif
void DisplayTemperature();

/*Global Variables*/
unsigned short int ADC_Data;
int Temp;
#if (USE_POLLING==1) /*Polling Mode*/
	ADCConfigType ADC_ConfigStruct= {TwelveBits,Continuous,5};
#else /*Interrupt Mode*/
	ADCConfigType ADC_ConfigStruct= {TwelveBits,Single,5};
#endif


int main(void)
{
	for(int i=0; i<1000000;i++); /*Delay for Proteus to calculate output voltage from LM35 Temperature sensor*/
	LCD_Init(); /*Initialize LCD on pins defined in LCD header file*/
	ADC_Init(&ADC_ConfigStruct); /*Initialize ADC with globally defined parameters*/
	LCD_DisplayString("Temperature= "); /*Display String on lCD*/
	ADC_StartConv(5); /*Start conversion on channel 5 (PortA Pin5)*/

	/*Super Loop*/
	while(1)
	{
#if (USE_POLLING==1) /*Polling Mode*/
			ADC_Manage();
#endif
	}
	return 0;
}

void ADC_IRQHandler(void){ /*Interrupt for ADC*/
	if(!ADC_ReadData(&ADC_Data)) /*if there is a valid ADC Value write it to ADC_Data*/
	{
		DisplayTemperature(); /*Display Read Temperature*/
		//ADC_StartConv(5); /*Interrupt Continuous mode not working on Proteus so we Restart Single Conversion on ISR end*/
	}
}

#if (USE_POLLING==1) /*Polling Mode*/
void ADC_Manage(){
	unsigned char ADC_ConversionState; /*Variable to carry the conversion state*/
	ADC_GetConversionState(&ADC_ConversionState); /*Write conversion state to ADC_ConversionState*/
	if(ADC_ConversionState==1){ /*Conversion complete*/
		ADC_ReadData(&ADC_Data); /*Read ADC data*/
		DisplayTemperature(); /*Display ADC read Temperature*/
	}
}
#endif

/*Calculate current Temperature from current Voltage using Tref and Vref then display it on LCD*/
void DisplayTemperature(){
	Temp = (int)((ADC_Data/(LM35_MaxVolt * 4095.0f)) * ADC_ConfigStruct.ADC_ReferenceVoltage * LM35_MaxTemp); /*Current Temperature*/
	LCD_DisplayStringRowColumn(0,13,"   "); /*write empty spaces at row 0 column 13 (after "Temperature=") to clear previous value */
	LCD_MoveCursor(0,13); /*Move cursor again to row 0 column 13 to start writing after "Temperature=" */
	LCD_IntToStr(Temp); /*Display temperature value at row 0 column 13 (after "Temperature=")*/
	for(int i=0; i<1000000;i++); /*Short Delay*/
}
