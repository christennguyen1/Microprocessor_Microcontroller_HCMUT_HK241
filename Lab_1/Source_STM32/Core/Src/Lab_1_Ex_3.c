/*
 * Lab_1_Ex_3.c
 *
 *  Created on: Sep 9, 2024
 *      Author: vinhn
 */


#include "Lab_1_Ex_3.h"
#include "stm32f1xx_hal.h"

int counter_3_1 = 10;
int counter_3_2 = 5;

void init_exercise3(){
	HAL_GPIO_TogglePin(GPIOB, LED_RED_EX3_1_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_YELLOW_EX3_1_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_GREEN_EX3_1_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_RED_EX3_2_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_YELLOW_EX3_2_Pin);
	HAL_GPIO_TogglePin(GPIOB, LED_GREEN_EX3_2_Pin);
}



void exercise3_run(){

	switch (counter_3_1){
		case 10:
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX3_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX3_2_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX3_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_EX3_2_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_EX3_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX3_2_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}


	switch (counter_3_2){
		case 10:
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX3_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX3_1_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX3_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_EX3_1_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_EX3_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX3_1_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}

	counter_3_1--;
	if(counter_3_1 <= 0){
		counter_3_1 = 10;
	}

	counter_3_2--;
	if(counter_3_2 <= 0){
		counter_3_2 = 10;
	}
}
