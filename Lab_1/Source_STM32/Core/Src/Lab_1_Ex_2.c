/*
 * Lab_1_Ex_2.c
 *
 *  Created on: Sep 9, 2024
 *      Author: vinhn
 */


#include "Lab_1_Ex_2.h"
#include "stm32f1xx_hal.h"

int counter_2 = 10;

void init_exercise2(){
	HAL_GPIO_TogglePin(GPIOB, LED_RED_EX2_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_YELLOW_EX2_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_GREEN_EX2_Pin);
}


void exercise2_run(){
	switch (counter_2){
		case 10:
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX2_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_EX2_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_EX2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX2_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
	counter_2--;
	if(counter_2 <= 0){
		counter_2 = 10;
	}
}
