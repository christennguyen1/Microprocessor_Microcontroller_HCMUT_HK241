
/*
 * fsm_manual.c
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#include"fsm_manual.h"

void fsm_manual_run(){
	switch(status0){
		case INIT_BUTTON:
			lcd_send_cmd (0x80);
			lcd_goto_XY(1,4);
			lcd_send_string("Hello guy");
			if(isButton1Pressed(0) == 1){
				  setTimer0(3, 1010);
				  setTimer0(2, 10);
				  setTimer0(1, 1010);
				  setTimer0(0, 1010);
				  status1 = INIT_LED;
				  status2 = INIT_LED;
				  status0 = MODE1;
				  status3 = INIT_LED;
				  status4 = INIT_LED;
				  time_lane1 = MODE1 % 10;
				  time_lane2 = 0;
				  clearAll();
			}

			break;
		case MODE1:
			updateLed();
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = MODE2;
				clearAll();
			}

			break;
		case MODE2:
			traffic_light1(AUTO_RED1);
			traffic_light2(AUTO_RED2);
			time_lane1 = MODE2 % 10;
			time_lane2 = time_mid;
			updateLed();
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = MODE3;
				clearAll();
			}

			//increase time value of red led
			if(isButton1Pressed(1) == 1){
				time_mid = time_mid + 1;
				if( time_mid >= 100 ){
					time_mid = 1;
					clearAll();
				}
			}

			//confirm time value of red led
			if(isButton1Pressed(2) == 1){
				TIME_RED = time_mid * 1000;
				time_mid = 1;
				clearAll();
			}
			break;
		case MODE3:
			traffic_light1(AUTO_AMBER1);
			traffic_light2(AUTO_AMBER2);
			time_lane1 = MODE3 % 10;
			time_lane2 = time_mid;
			updateLed();
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = MODE4;
				clearAll();
			}

			//increase time value of amber led
			if(isButton1Pressed(1) == 1){
				time_mid = time_mid + 1;
				if( time_mid >= 100 ){
					time_mid = 1;
					clearAll();
				}
			}

			//confirm time value of amber led
			if(isButton1Pressed(2) == 1){
				TIME_YELLOW = time_mid * 1000;
				time_mid = 1;
			}
			break;
		case MODE4:
			traffic_light1(AUTO_GREEN1);
			traffic_light2(AUTO_GREEN2);
			time_lane1 = MODE4 % 10;
			time_lane2 = time_mid;
			updateLed();
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = INIT_BUTTON;
				clearAll();
				lcd_send_cmd (0x02);
			}

			//increase time value of green led
			if(isButton1Pressed(1) == 1){
				time_mid = time_mid + 1;
				if( time_mid >= 100 ){
					time_mid = 1;
					clearAll();
				}
			}

			//confirm time value of green led
			if(isButton1Pressed(2) == 1){
				TIME_GREEN = time_mid * 1000;
				time_mid = 1;
				clearAll();
			}
			break;
		default:
			break;
	}
}



