/*
 * Lab_2_Ex_3.c
 *
 *  Created on: Sep 24, 2024
 *      Author: vinhn
 */



#include "Lab_2_Ex_3.h"
#include "stm32f1xx_hal.h"

int counter_3 = 4;
int arr_3[10] = {
		0x81FF,  //0
		0xF3FF,  //1
		0x49FF,  //2
		0x61FF,  //3
		0x33FF,  //4
		0x25FF,  //5
		0x05FF,  //6
		0xF1FF,  //7
		0x01FF,  //8
		0x21FF,  //9
};


void init_exercise3(){
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_0_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_1_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_2_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_3_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_4_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_5_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_6_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
}


void exercise3_run(){
	switch(counter_3){
		case 4:
			GPIOB->ODR = arr_3[0];
			break;
		case 3:
			GPIOB->ODR = arr_3[1];
			break;
		case 2:
			GPIOB->ODR = arr_3[2];
			break;
		case 1:
			GPIOB->ODR = arr_3[3];
			break;
	}
	counter_3--;
	if(counter_3 <= 0){
		counter_3 = 4;
	}


}
