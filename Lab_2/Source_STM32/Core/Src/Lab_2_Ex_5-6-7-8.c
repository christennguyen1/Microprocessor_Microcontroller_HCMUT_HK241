/*
 * Lab_2_Ex_4.c
 *
 *  Created on: Sep 24, 2024
 *      Author: vinhn
 */



#include <Lab_2_Ex_5-6-7-8.h>
#include "constant.h"
#include "stm32f1xx_hal.h"


int hour = 15, minute = 8, second = 50;
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

void init_exercise5(){
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_0_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_1_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_2_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_3_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_4_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_5_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_6_EX1_Pin);
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
//	HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
	HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
	GPIOB->ODR = arr[led_buffer[0]];
}

void displayClock(){
	switch(counter){
		case 4:
			GPIOB->ODR = arr[led_buffer[0]];
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			GPIOB->ODR = arr[led_buffer[1]];
			HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			GPIOB->ODR = arr[led_buffer[2]];
			HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			GPIOB->ODR = arr[led_buffer[3]];
			HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
			break;
	}
	counter--;
	if(counter <= 0){
		counter = 4;
	}
}


void updateClockBuffer(){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
	displayClock();
}


void updateLed(){
	updateClockBuffer();
}


void exercise5_run(){
	second++;
	 if (second >= 60){
		 second = 0;
		 minute++;
	 }

	 if(minute >= 60){
		 minute = 0;
		 hour++;
	 }

	 if(hour >= 24){
		 hour = 0;
	 }
	 HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
}
