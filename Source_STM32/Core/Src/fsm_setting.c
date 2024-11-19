/*
 * fsm_setting.c
 *
 *  Created on: Oct 25, 2024
 *      Author: vinhn
 */


// tinhs toan thoi gian trong nay
#include "fsm_setting.h"

void counter_7segmen2(){
	if(status0 == MODE1){
		switch(status3){
				case INIT_LED:
						time_lane1 = TIME_RED / 1000;
						status3 = AUTO_RED1;
						clearAll();
					break;

				case AUTO_RED1:
						time_lane1--;
						if (time_lane1 <= 0){
							time_lane1 = TIME_GREEN / 1000;
							status3 = AUTO_GREEN1;
						}
					break;

				case AUTO_AMBER1:
						time_lane1--;
						if (time_lane1 <= 0){
							time_lane1 = TIME_RED / 1000;
							status3 = AUTO_RED1;
						}
					break;

				case AUTO_GREEN1:
						time_lane1--;
						if (time_lane1 <= 0){
							time_lane1 = TIME_YELLOW / 1000;
							status3 = AUTO_AMBER1;
						}
					break;

				default:
					break;
		}

		switch(status4){
			case INIT_LED:
					time_lane2 = TIME_GREEN / 1000;
					status4 = AUTO_GREEN2;
					clearAll();
				break;

			case AUTO_RED2:
					time_lane2--;
					if (time_lane2 <= 0){
						time_lane2 = TIME_GREEN / 1000;
						status4 = AUTO_GREEN2;
					}
				break;

			case AUTO_AMBER2:
					time_lane2--;
					if (time_lane2 <= 0){
						time_lane2 = TIME_RED / 1000;
						status4 = AUTO_RED2;
					}
				break;

			case AUTO_GREEN2:
					time_lane2--;
					if (time_lane2 <= 0){
						time_lane2 = TIME_YELLOW / 1000;
						status4 = AUTO_AMBER2;
					}
				break;

			default:
				break;
		}
	}

}


void fsm_automatic_run_segmen(){
	if(timer_flag[3] == 1){
		counter_7segmen2();
		setTimer0(3, 1000);
	}
}

void updateLed(){
	if(timer_flag[2] == 1){
		updateClockBuffer(time_lane1, time_lane2);
		setTimer0(2, TIME_BLINK);
	}
}

