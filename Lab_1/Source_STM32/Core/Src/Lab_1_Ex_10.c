/*
 * Lab_1_Ex_10.c
 *
 *  Created on: Sep 17, 2024
 *      Author: vinhn
 */


#include "Lab_1_Ex_10.h"
#include "stm32f1xx_hal.h"

int counter_s = 0;
int counter_m = 55;
int counter_h = 0;


void clearAllClock(){
		HAL_GPIO_WritePin(GPIOA, LED_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_8_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_9_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_10_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_11_Pin, GPIO_PIN_SET);
}

void setNumberOnClock(int num) {
	switch( num ){
		case 0:
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin, GPIO_PIN_RESET);
				break;
		case 1:
				HAL_GPIO_WritePin(GPIOA, LED_1_Pin, GPIO_PIN_RESET);
				break;
		case 2:
				HAL_GPIO_WritePin(GPIOA, LED_2_Pin, GPIO_PIN_RESET);
				break;
		case 3:
				HAL_GPIO_WritePin(GPIOA, LED_3_Pin, GPIO_PIN_RESET);
				break;
		case 4:
				HAL_GPIO_WritePin(GPIOA, LED_4_Pin, GPIO_PIN_RESET);
				break;
		case 5:
				HAL_GPIO_WritePin(GPIOA, LED_5_Pin, GPIO_PIN_RESET);
				break;
		case 6:
				HAL_GPIO_WritePin(GPIOA, LED_6_Pin, GPIO_PIN_RESET);
				break;
		case 7:
				HAL_GPIO_WritePin(GPIOA, LED_7_Pin, GPIO_PIN_RESET);
				break;
		case 8:
				HAL_GPIO_WritePin(GPIOA, LED_8_Pin, GPIO_PIN_RESET);
				break;
		case 9:
				HAL_GPIO_WritePin(GPIOA, LED_9_Pin, GPIO_PIN_RESET);
				break;
		case 10:
				HAL_GPIO_WritePin(GPIOA, LED_10_Pin, GPIO_PIN_RESET);
				break;
		case 11:
				HAL_GPIO_WritePin(GPIOA, LED_11_Pin, GPIO_PIN_RESET);
				break;
	}
}


void clearNumberOnClock(int num)
{
	switch(num)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOA, LED_0_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, LED_1_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, LED_2_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, LED_3_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, LED_4_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, LED_5_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, LED_6_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, LED_7_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA, LED_8_Pin, GPIO_PIN_SET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA, LED_9_Pin, GPIO_PIN_SET);
			break;
		case 10:
			HAL_GPIO_WritePin(GPIOA, LED_10_Pin, GPIO_PIN_SET);
			break;
		case 11:
			HAL_GPIO_WritePin(GPIOA, LED_11_Pin, GPIO_PIN_SET);
			break;
	}
}


void init_exercise10(){
	clearAllClock();
}


void exercise10_run(){

	if( counter_h >= 12 ){
		counter_h = 0;
		clearNumberOnClock(11);
	}

	if( counter_m >= 60 ){
		counter_m = 0;

		if( counter_h != 0 )
		{
			if( (counter_h - 1) != counter_m && (counter_h - 1) != counter_s)
			clearNumberOnClock(counter_h - 1);
		}

	}
//
	if( counter_s >= 60 ){
		counter_s = 0;

		if( counter_m % 5 == 0 ){
			if( (counter_m / 5 - 1) != counter_h && (counter_m / 5 - 1) != counter_s)
			{
				clearNumberOnClock(counter_m / 5 - 1);
			}
		}
	}
//
	if( counter_s % 5 == 0 ){
		if( counter_s == 0 )
		{
			if((counter_m / 5) != 11 && counter_h != 11)
			{
			  	clearNumberOnClock(11);
			}
		}
		else
		{
			if( ((counter_m / 5) != (counter_s / 5 - 1)) && (counter_h != (counter_s / 5 - 1)) )
			{
				clearNumberOnClock(counter_s / 5 - 1);
			}
		}
	}

	setNumberOnClock(counter_s / 5);
	setNumberOnClock(counter_m / 5);
	setNumberOnClock(counter_h);


//	clearAllClock();
//	setNumberOnClock(counter_s/5);
//	setNumberOnClock(counter_m/5);
//	setNumberOnClock(counter_h);

	counter_s++;

	if( counter_s >= 60 ){
//			counter_s = 0;
		  	counter_m++;
	}

	if( counter_m >= 60 ){
//			counter_m = 0;
		  	counter_h++;

	}

//	if( counter_h >= 12 ){
//		  	counter_h = 0;
//	}

}
