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
					if(timer_flag[0] == 1){
						status1 = AUTO_RED1;
						setTimer0(0, TIME_RED);
					}
					break;

				case AUTO_RED1:
					traffic_light1(status1);
					if(timer_flag[0] == 1){
						status1 = AUTO_GREEN1;
						setTimer0(0, TIME_GREEN);
					}
					break;

				case AUTO_AMBER1:
					traffic_light1(status1);
					if(timer_flag[0] == 1){
						status1 = AUTO_RED1;
						setTimer0(0, TIME_RED);
					}
					break;

				case AUTO_GREEN1:
					traffic_light1(status1);
					if(timer_flag[0] == 1){
						status1 = AUTO_AMBER1;
						setTimer0(0, TIME_YELLOW);
					}
					break;

				default:
					break;
		}

		switch(status2){
				case INIT_LED:
					if(timer_flag[1] == 1){
						status2 = AUTO_GREEN2;
						setTimer0(1, TIME_GREEN);
					}
					break;

				case AUTO_RED2:
					traffic_light2(status2);
					if(timer_flag[1] == 1){
						status2 = AUTO_GREEN2;
						setTimer0(1, TIME_GREEN);
					}

					break;

				case AUTO_AMBER2:
					traffic_light2(status2);
					if(timer_flag[1] == 1){
						status2 = AUTO_RED2;
						setTimer0(1, TIME_RED);
					}

					break;

				case AUTO_GREEN2:
					traffic_light2(status2);
					if(timer_flag[1] == 1){
						status2 = AUTO_AMBER2;
						setTimer0(1, TIME_YELLOW);
					}

					break;

				default:
					break;
			}
	}
}
