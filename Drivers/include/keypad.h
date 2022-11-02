/*
 * keypad.h
 *
 *  Created on: May 10, 2022
 *      Author: Muhammad Al-Barbary
 */

#ifndef INCLUDE_KEYPAD_H_
#define INCLUDE_KEYPAD_H_

#define KeypadPort GPIOA

/*Initialize Keypad pins*/
void KeyPad_INIT(void);

/*get current pressed key and store in "currentvalue" variable */
void KeyPad_MANAGE(void);

/*returns last stored pressed key from "currentvalue" variable */
char KeyPad_GET_VALUE(void);


/*check if a button is pressed
 * Returns
 * Press: 1
 * No Press: 0
 * */
char KeypadCallouts_KeyPressNotificaton(void);

#endif /* INCLUDE_KEYPAD_H_ */
