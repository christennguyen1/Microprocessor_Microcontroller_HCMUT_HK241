
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
			clearAll();
			if(isButton1Pressed(0) == 1){
				status0 = MODE1;
				status1 = INIT_LED;
				status2 = INIT_LED;
				clearAll();
				SCH_Init();
				SCH_Add_Task(fsm_automatic_run_traffic, 0, 100);
				SCH_Add_Task(fsm_automatic_run_time, 0, 25);
			}

			break;
		case MODE1:
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = MODE2;
				clearAll();
				SCH_Init();
				SCH_Add_Task(fsm_automatic_run_time, 0, 25);
				counter_1 = MODE2 % 10;
				counter_2 = time_mid;
			}

			break;
		case MODE2:
			traffic_light1(AUTO_RED1);
			traffic_light2(AUTO_RED2);
			counter_2 = time_mid;
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = MODE3;
				clearAll();
				SCH_Init();
				SCH_Add_Task(fsm_automatic_run_time, 0, 25);
				counter_1 = MODE3 % 10;
				counter_2 = time_mid;
			}

			//increase time value of red led
			if(isButton1Pressed(1) == 1){
				time_mid = time_mid + 1;
				if( time_mid >= 100 ){
					time_mid = 1;
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
			counter_2 = time_mid;
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = MODE4;
				clearAll();
				SCH_Init();
				SCH_Add_Task(fsm_automatic_run_time, 0, 25);
				counter_1 = MODE4 % 10;
				counter_2 = time_mid;
			}

			//increase time value of amber led
			if(isButton1Pressed(1) == 1){
				time_mid = time_mid + 1;
				if( time_mid >= 100 ){
					time_mid = 1;
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
			counter_2 = time_mid;
			if(isButton1Pressed(0) == 1){
				time_mid = 1;
				status0 = INIT_BUTTON;
			}

			//increase time value of green led
			if(isButton1Pressed(1) == 1){
				time_mid = time_mid + 1;
				if( time_mid >= 100 ){
					time_mid = 1;
				}
			}

			//confirm time value of green led
			if(isButton1Pressed(2) == 1){
				TIME_GREEN = time_mid * 1000;
				time_mid = 1;
			}
			break;
		default:
			break;
	}
}



