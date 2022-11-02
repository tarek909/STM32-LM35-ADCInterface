/*
 *  File Name: ADC.h
 *  Created on: May 15, 2022
 *  Description: Header file for ADC1 Driver for STM32
 *  Team Members: Muhammad Al-Barbary  Section:2  BN:10
 *  		      Tarek Mohamed		   Section:1  BN:45
 */

#include "stm32f4xx.h"
#include "gpio.h"


/*USE_POLLING 0: Interrupt Mode
 *USE_POLLING 1: Polling Mode */
#define USE_POLLING 0

/*Definitions*/
#define LM35_MaxVolt 1.5
#define LM35_MaxTemp 150
typedef enum {TwelveBits,TenBits,EightBits,SixBits}ADC_ResolutionType;
typedef enum {Single,Continuous}ADC_ConversionModeType;
typedef struct {
	ADC_ResolutionType ADC_Resolution;
	ADC_ConversionModeType ADC_ConversionMode;
	double ADC_ReferenceVoltage;
}ADCConfigType;


/*Initialize ADC with input parameters*/
void ADC_Init(ADCConfigType* ConfigParamPtr);


/* 	Reads channel number (Pin number from PortA): 0,1...14,15
	Start Conversion of input Voltage */
void ADC_StartConv(unsigned char ChannelNum);

#if (USE_POLLING==1)
/*	Reads address to a Conversion State Variable
 *	If Conversion is not complete: Conversion State Variable = 0
 *	If conversion is complete: Conversion State Variable = 1
*/
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
#endif

/*	Reads address to an ADC Data Variable
 *	No valid ADC Value: return 1
 *	valid ADC Value: return 0 and write ADC Value to ADC Data Variable
*/
unsigned char ADC_ReadData(unsigned short int* DataPtr);
