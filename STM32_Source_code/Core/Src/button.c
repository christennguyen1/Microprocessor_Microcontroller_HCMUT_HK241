/*
 * button_1.c
 *
 *  Created on: Sep 21, 2024
 *      Author: vinhn
 */

//trong proteus nho them tro keo voi button.

#include "button.h"


int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTONS] = {200};
int button1_pressed[NUM_BUTTONS] = {0};
int button1_long_pressed[NUM_BUTTONS] = {0};
int button1_flag[NUM_BUTTONS] = {0};


int isButton1Pressed(int index){
	if(index >= NUM_BUTTONS) return 0;
	if(button1_flag[index] == 1){
		button1_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(int index){
	if( index >= NUM_BUTTONS ) return 0;
	if(button1_long_pressed[index] == 1){
		button1_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	button1_flag[index] = 1;
}

void getKeyInput(){
	for( int i = 0 ; i < NUM_BUTTONS ; i++)
	{
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		// Add your key
		if(i == 3){
			KeyReg2[i] = HAL_GPIO_ReadPin(GPIOC, BUTTON[i]);
		}
		else{
			KeyReg2[i] = HAL_GPIO_ReadPin(GPIOB, BUTTON[i]);
		}


		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		    if (KeyReg2[i] != KeyReg3[i]){
		      KeyReg3[i] = KeyReg2[i];

		      if (KeyReg2[i] == PRESSED_STATE){
		    	  TimeOutForKeyPress[i] = 200;
		    	  subKeyProcess(i);
		      }

		    }else{
		        TimeOutForKeyPress[i] --;
		        if (TimeOutForKeyPress[i] == 0){
		        	TimeOutForKeyPress[i] = 200;
		        	if (KeyReg2[i] == PRESSED_STATE){
		        		subKeyProcess(i);
		        	}
		        }
		    }
		}
	}
}

