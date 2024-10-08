/*
 * Lab_2_Ex_4.c
 *
 *  Created on: Sep 24, 2024
 *      Author: vinhn
 */



#include "Lab_2_Ex_4.h"
#include "constant.h"
#include "stm32f1xx_hal.h"


void init_exercise4(){
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_0_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_1_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_2_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_3_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_4_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_5_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_6_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
}


void exercise4_run(){
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	switch(counter){
		case 4:
			GPIOB->ODR = arr[1];
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED1_Pin, 0);
			break;
		case 3:
			GPIOB->ODR = arr[2];
			HAL_GPIO_WritePin(GPIOA, LED1_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED2_Pin, 0);
			break;
		case 2:
			GPIOB->ODR = arr[3];
			HAL_GPIO_WritePin(GPIOA, LED2_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED3_Pin, 0);
			break;
		case 1:
			GPIOB->ODR = arr[0];
			HAL_GPIO_WritePin(GPIOA, LED3_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, 0);
			break;
	}
	counter--;
	if(counter <= 0){
		counter = 4;
	}


}
