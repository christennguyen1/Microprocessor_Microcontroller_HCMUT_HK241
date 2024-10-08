/*
 * Lab_1_Ex_4.c
 *
 *  Created on: Sep 10, 2024
 *      Author: vinhn
 */

#include "Lab_1_Ex_4.h"
#include "stm32f1xx_hal.h"


int counter_4 = 9;


void init_exercise4(){
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_0_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_1_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_2_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_3_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_4_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_5_EX4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEGMENT_6_EX4_Pin);
}


int arr[10] = {
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


void exercise4_run(){

	switch(counter_4){
	   case 0:
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_SET);
		   GPIOB->ODR = arr[0];
	       break;
	  case 1:
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_SET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
//		   HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_SET);
		  GPIOB->ODR = arr[1];
		   break;
	  case 2:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		  GPIOB->ODR = arr[2];
	       break;
	  case 3:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		  GPIOB->ODR = arr[3];
	       break;
	  case 4:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		  GPIOB->ODR = arr[4];
	       break;
	   case 5:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		   GPIOB->ODR = arr[5];
	       break;
	   case 6:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		   GPIOB->ODR = arr[6];
	       break;
	   case 7:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_SET);
		   GPIOB->ODR = arr[7];
	       break;
	   case 8:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		   GPIOB->ODR = arr[8];
	       break;
	   case 9:
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_0_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_1_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_2_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_3_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_4_EX4_Pin, GPIO_PIN_SET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_5_EX4_Pin, GPIO_PIN_RESET);
//	       HAL_GPIO_WritePin(GPIOB, SEGMENT_6_EX4_Pin, GPIO_PIN_RESET);
		   GPIOB->ODR = arr[9];
	       break;
	   default:
	       break;
  }

	counter_4--;
	if(counter_4 < 0){
		counter_4 = 9;
	}
}




