/*
 * button1.h
 *
 *  Created on: Nov 14, 2024
 *      Author: vinhn
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"


#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


void getKeyInput();
int isButton1Pressed();

#endif /* INC_BUTTON_H_ */
