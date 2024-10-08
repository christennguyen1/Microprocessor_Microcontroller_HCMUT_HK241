/*
 * Lab_1_Ex_1.cpp
 *
 *  Created on: Sep 6, 2024
 *      Author: vinhn
 */
#include "Lab_1_Ex_1.h"
#include "stm32f1xx_hal.h"



void init_exercise1(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_EX1_Pin);
}


void exercise1_run(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_EX1_Pin);
}
