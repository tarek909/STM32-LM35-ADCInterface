/*
 * gpio.h
 *
 *  Created on: Apr 30, 2022
 *      Author: moham
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

#include "stm32f4xx.h"

/* Initialize specified GPIO pin
 * arguments: Port,Pin,Direction,DefaultState
 * PORT: PORTA,PORTB...etc
 * Pin: 0,1,2...7
 * Direction: input:0 output:1 Analog:3
 * DefaultState: input pin: sets input type:  DefaultState=0: No Pull-UP or PULL-DOWN
 *                                            DefaultState=1: Pull-UP
 *                                            DefaultState=2: PULL-DOWN
 *
 *               output pin: sets output type:DefaultState=0: Push-Pull
 *                                            DefaultState=1: Open-Drain
 */
void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char defstate);

/* Set Output pins high or low
 * arguments: Port,Pin,State
 * PORT: PORTA,PORTB...etc
 * Pin: 0,1,2...7
 * State: LogicLow:0 , LogicHigh:1
 * Returns 1 for success, 0 for failure (pin is not output)
 *  */
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);

/* Reads input pin state
 * arguments: Port,Pin
 * PORT: PORTA,PORTB...etc
 * Pin: 0,1,2...7
 * Returns  1 for LogicHigh, 0 for LogicLow
 * Returns -1 for wrong pin address (pin is not input)
 *  */
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);

/* Sets output pin type
 * arguments: Port,Pin,PushPull_OpenDrain
 * PORT: PORTA,PORTB...etc
 * Pin: 0,1,2...7
 * PushPull_OpenDrain=0: Push-Pull
 * PushPull_OpenDrain=1: Open-Drain
 * returns 1 for success, 0 for failure (pin is not output)
 *  */
char GPIO_SetOutput(GPIO_TypeDef * GPIOx,char pin,char PP_OD);


/* Sets input pin type
 * arguments: Port,Pin,PullUp_PullDown
 * PORT: PORTA,PORTB...etc
 * Pin: 0,1,2...7
 * PullUp_PullDown=0: No Pull-UP or PULL-DOWN
 * PullUp_PullDown=1: Pull-UP
 * PullUp_PullDown=2: PULL-DOWN
 * returns 1 for success, 0 for failure (pin is not input)
 *  */
char GPIO_SetInput(GPIO_TypeDef * GPIOx,char pin,char PU_PD);

#endif /* INCLUDE_GPIO_H_ */
