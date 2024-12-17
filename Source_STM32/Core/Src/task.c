/*
 * task.c
 *
 *  Created on: Nov 30, 2023
 *      Author: tuann
 */
#include "main.h"
#include "task.h"

void task0(){
	HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
}
void task1(){
	HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
}
void task2(){
	HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
}
void task3(){
	HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
}
void task4(){
	HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
}
