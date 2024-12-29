///*
// * display7segment.c
// *
// *  Created on: Oct 21, 2024
// *      Author: vinhn
// */
//
#include"display7Segment.h"


int led_buffer[4] = {1, 2, 3, 4};
char res_str[10];


void updateClockBuffer(int lane_1, int lane_2){
	if(status0 != INIT_BUTTON){
		int tam_1 = lane_1;
		int tam_2 = lane_2;
		lcd_send_cmd (0x80);
		lcd_goto_XY(1,0);
		sprintf(res_str, "%d", tam_1);
		lcd_send_string(res_str);
		lcd_goto_XY(0,0);
		sprintf(res_str, "%d", tam_2);
		lcd_send_string(res_str);
	}

	if(status0 == MODE1){
//		lcd_init();
		lcd_clear_display();
		int tam_1 = lane_1;
		int tam_2 = lane_2;
		lcd_send_cmd (0x80);
		lcd_goto_XY(1,0);
		sprintf(res_str, "%d", tam_1);
		lcd_send_string(res_str);
		lcd_goto_XY(0,0);
		sprintf(res_str, "%d", tam_2);
		lcd_send_string(res_str);
	}
}


void clearAll(){
	lcd_clear_display();
	HAL_GPIO_WritePin(LED1_3_GPIO_Port, LED1_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_5_GPIO_Port, LED1_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_9_GPIO_Port, LED4_9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_8_GPIO_Port, LED4_8_Pin, GPIO_PIN_RESET);
}

