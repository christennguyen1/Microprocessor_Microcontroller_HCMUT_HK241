/*
 * display7segment.c
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#include"display7Segment.h"


int led_buffer[4] = {1, 2, 3, 4};

void displayClock(){
	switch(counter_led){
		case 4:
			GPIOB->ODR = arr[led_buffer[0]];
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			GPIOB->ODR = arr[led_buffer[1]];
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			GPIOB->ODR = arr[led_buffer[2]];
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			GPIOB->ODR = arr[led_buffer[3]];
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
			break;
	}
	counter_led--;
	if(counter_led <= 0){
		counter_led = 4;
	}
}


void updateClockBuffer(int lane_1, int lane_2){
	led_buffer[0] = lane_1 / 10;
	led_buffer[1] = lane_1 % 10;
	led_buffer[2] = lane_2 / 10;
	led_buffer[3] = lane_2 % 10;
	displayClock();
}


//void updateLed(int lane_1, int lane_2){
//	if(timer_flag[2] == 1){
//		updateClockBuffer(lane_1, lane_2);
//		setTimer0(2, TIME_BLINK);
//	}
//}

void clearAll(){
	GPIOB->ODR = 0xFFFF;
	HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin, GPIO_PIN_SET);
	counter_led = 4;
}

