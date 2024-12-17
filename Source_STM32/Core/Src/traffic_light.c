/*
 * traffic_light.c
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */


#include"traffic_light.h"


void traffic_light1(int status1){
	switch(status1){
			case INIT_LED:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
				break;

			case AUTO_RED1:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
				break;

			case AUTO_AMBER1:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
				break;

			case AUTO_GREEN1:
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
				break;

			default:
				break;
		}
}


void traffic_light2(int status2){
	switch(status2){
			case INIT_LED:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
				break;

			case AUTO_RED2:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
				break;

			case AUTO_AMBER2:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
				break;

			case AUTO_GREEN2:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
				break;

			default:
				break;
		}
}



void fsm_automatic_traffic_light(){
	if(status0 == MODE1){
		switch(status1){
				case INIT_LED:
					status1 = AUTO_RED1;
					counter_1 = TIME_RED / 1000;
					traffic_light1(status1);
					break;

				case AUTO_RED1:
					counter_1 --;
					if(counter_1 <= 0){
						status1 = AUTO_GREEN1;
						counter_1 = TIME_GREEN / 1000;
						traffic_light1(status1);
					}
					break;

				case AUTO_AMBER1:
					counter_1 --;
					if(counter_1 <= 0){
						status1 = AUTO_RED1;
						counter_1 = TIME_RED / 1000;
						traffic_light1(status1);
					}
					break;

				case AUTO_GREEN1:
					counter_1 --;
					if(counter_1 <= 0){
						status1 = AUTO_AMBER1;
						counter_1 = TIME_YELLOW / 1000;
						traffic_light1(status1);
					}
					break;

				default:
					break;
		}

		switch(status2){
				case INIT_LED:
						status2 = AUTO_GREEN2;
						counter_2 = TIME_GREEN / 1000;
						traffic_light2(status2);
					break;

				case AUTO_RED2:
					counter_2 --;
					if(counter_2 <= 0){
						status2 = AUTO_GREEN2;
						counter_2 = TIME_GREEN / 1000;
						traffic_light2(status2);
					}

					break;

				case AUTO_AMBER2:
					counter_2 --;
					if(counter_2 <= 0){
						status2 = AUTO_RED2;
						counter_2 = TIME_RED / 1000;
						traffic_light2(status2);
					}
					break;

				case AUTO_GREEN2:
					counter_2 --;
					if(counter_2 <= 0){
						status2 = AUTO_AMBER2;
						counter_2 = TIME_YELLOW / 1000;
						traffic_light2(status2);
					}

					break;

				default:
					break;
			}
	}
}

void updateLed(){
	updateClockBuffer(counter_1, counter_2);
}
