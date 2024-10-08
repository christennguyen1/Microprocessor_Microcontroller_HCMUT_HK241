/*
 * Lab_2_Ex_4.c
 *
 *  Created on: Sep 24, 2024
 *      Author: vinhn
 */



#include "Lab_2_Ex_9.h"
#include "constant.h"
#include "stm32f1xx_hal.h"


void init_exercise9(){
	HAL_GPIO_TogglePin(GPIOA, ENM0_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM1_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM2_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM3_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM4_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM5_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM6_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM7_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW0_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW1_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW2_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW3_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW4_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW5_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW6_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW7_Pin);
}


void display_col_9(int num){ //assign value for column
	HAL_GPIO_WritePin(GPIOA,ENM0_Pin,(num>>0)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM1_Pin,(num>>1)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM2_Pin,(num>>2)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM3_Pin,(num>>3)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM4_Pin,(num>>4)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM5_Pin,(num>>5)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM6_Pin,(num>>6)&0x01);
	HAL_GPIO_WritePin(GPIOA,ENM7_Pin,(num>>7)&0x01);
}


void display_row_9(int num){ //assign value for row
	HAL_GPIO_WritePin(GPIOB,ROW0_Pin,(num>>0)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW1_Pin,(num>>1)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW2_Pin,(num>>2)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW3_Pin,(num>>3)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW4_Pin,(num>>4)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW5_Pin,(num>>5)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW6_Pin,(num>>6)&0x01);
	HAL_GPIO_WritePin(GPIOB,ROW7_Pin,(num>>7)&0x01);
}


const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0xFF,0x03,0x01,0xCC,0xCC,0x01,0x03,0xFF};//value of buffer to display "A"
void updateLEDMatrix_9(int index){
	switch(index){
		case 0:
			display_row_9(matrix_buffer[index]);
			break;
		case 1:
			display_row_9(matrix_buffer[index]);
			break;
		case 2:
			display_row_9(matrix_buffer[index]);
			break;
		case 3:
			display_row_9(matrix_buffer[index]);
			break;
		case 4:
			display_row_9(matrix_buffer[index]);
			break;
		case 5:
			display_row_9(matrix_buffer[index]);
			break;
		case 6:
			display_row_9(matrix_buffer[index]);
			break;
		case 7:
			display_row_9(matrix_buffer[index]);
			break;
		default:
			break;
	}
}



void exercise9_run(){
	display_col_9(0xffff);
	updateLEDMatrix_9(index_led_matrix);
	display_col_9((0xff7f>>index_led_matrix));
	index_led_matrix++;
	if(index_led_matrix >= 8){
		index_led_matrix = 0;
	}
}
