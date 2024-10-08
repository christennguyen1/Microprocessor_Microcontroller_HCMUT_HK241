/*
 * Lab_1_Ex_5.c
 *
 *  Created on: Sep 17, 2024
 *      Author: vinhn
 */

#include "Lab_1_Ex_5.h"
#include "stm32f1xx_hal.h"

int counter_5 = 5;

// status_led = 1 is red
// status_led = 2 is yellow
// status_led = 3 is green
int status_led = 1;


void init_exercise5(){
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_0_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_1_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_2_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_3_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_4_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_5_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_6_EX4_Pin);
}


void display7SEG(int count){

	switch(count % 10){
	   case 0:
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_SET);
	       break;
	  case 1:
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_SET);
		   break;
	  case 2:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	  case 3:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	  case 4:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	   case 5:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	   case 6:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	   case 7:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_SET);
	       break;
	   case 8:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	   case 9:
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
	       break;
	   default:
	       break;
  }
}


void trafficLight(int count){
	switch (count){
		case 1:
			HAL_GPIO_WritePin(GPIOB, LED_YELLOW_EX2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_EX2_Pin, GPIO_PIN_RESET);
			break;
		case 3:
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
}


void exercise5_run(){
	display7SEG(counter_5);
	trafficLight(status_led);
	counter_5 = counter_5 - 1;
	switch(status_led) {
		// Đèn xanh
		case 1:
			if(counter_5 <= 0){
				counter_5 = 3;
				status_led = 3;
			}
			break;
		// Đèn đỏ
		case 2:
			if(counter_5 <= 0){
				counter_5 = 5;
				status_led = 1;
			}
			break;
		// Đèn vàng
		case 3:
			if(counter_5 <= 0){
				counter_5 = 2;
				status_led = 2;
			}
			break;
	}
}

