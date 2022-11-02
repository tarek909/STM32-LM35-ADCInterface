/*
 *  File Name: ADC.c
 *  Created on: May 15, 2022
 *  Description: Source file for ADC1 Driver for STM32
 *  Team Members: Muhammad Al-Barbary  Section:2  BN:10
 *  		 	  Tarek Mohamed		   Section:1  BN:45
 */

#include "stm32f4xx.h"
#include "gpio.h"
#include "ADC.h"

/*Initialize ADC with input parameters*/
void ADC_Init(ADCConfigType* ConfigParamPtr){
	/*Enable ADC1 Clock*/
	RCC->APB2ENR|=(1<<8);
	/*Set ADC Resolution*/
	ADC1->CR1=(ADC1->CR1 & ~((1<<24)|(1<<25))) | ((ConfigParamPtr->ADC_Resolution)<<24);
	/*Set Conversion Mode*/
	ADC1->CR2= (ADC1->CR2 & ~(1<<1)) | ((ConfigParamPtr->ADC_ConversionMode)<<1);

	if (USE_POLLING==1){ /*Polling Mode*/
		/*Disable ADC Interrupt*/
		ADC1->CR1 &= ~(1<<5);
	}
	else{ /*Interrupt Mode*/
		/*Enable ADC Interrupt*/
		NVIC->ISER[0]|=(1u<<(18));
		ADC1->CR1 |= (1<<5);
	}
}

/* 	Reads channel number (Pin number from PortA): 0,1...14,15
	Start Conversion of input Voltage */
void ADC_StartConv(unsigned char ChannelNum){
	/*Set PortA Pin(ChannelNum) as Analog with no pull-up or pull-down*/
	GPIO_Init(GPIOA,ChannelNum,3,0);
	/*Enable ADC*/
	ADC1->CR2 |= (1<<0);
	/*Set ChannelNum as first channel to be converted*/
	ADC1->SQR3= (ADC1->SQR3 & ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4))) | ((ChannelNum)<<0);
	/*Set total conversions=1*/
	ADC1->SQR1= (ADC1->SQR1 & ~((1<<20)|(1<<21)|(1<<22)|(1<<23))) | ((1)<<20);
	/*Start Conversion*/
	ADC1->CR2 |= (1<<30);
}


#if (USE_POLLING==1)
/*	Reads address to a Conversion State Variable
 *	If Conversion is not complete: Conversion State Variable = 0
 *	If conversion is complete: Conversion State Variable = 1
*/
void ADC_GetConversionState(unsigned char* ConversionStatePtr){
	/*check if conversion is complete by checking EOC bit in ADC_SR*/
	if (ADC1->SR & (1<<1))
		*ConversionStatePtr =1; /*Conversion Complete*/
	else
		*ConversionStatePtr =0; /*Conversion not Complete*/
}
#endif


/*	Reads address to an ADC Data Variable
 *	No valid ADC Value: return 1
 *	valid ADC Value: return 0 and write ADC Value to ADC Data Variable
*/
unsigned char ADC_ReadData(unsigned short int* DataPtr){
if (ADC1->SR & (1<<1)){ /*conversion complete*/
		*DataPtr= ADC1->DR; /*store ADC data into the dereference of DataPtr*/
		return 0; /*Success*/
	}
	return 1; /* Failure*/
}


