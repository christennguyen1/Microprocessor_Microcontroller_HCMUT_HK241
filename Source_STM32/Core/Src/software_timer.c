/*
 * software_timer.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Phuc
 */

#include "software_timer.h"

int timer_flag[10];
int timer_counter[10];
int TIMER_DEVICE = 10;

void setTimer0(int index, int duration) {
	timer_counter[index] = duration / TIMER_DEVICE;
	timer_flag[index] = 0;
}

void timer_run() {
	if (timer_counter[0] > 0) {
		timer_counter[0]--;
		if (timer_counter[0] <= 0) {
			timer_flag[0] = 1;
		}
	}

	if (timer_counter[1] > 0) {
		timer_counter[1]--;
		if (timer_counter[1] <= 0) {
			timer_flag[1] = 1;
		}
	}

	if (timer_counter[2] > 0) {
		timer_counter[2]--;
		if (timer_counter[2] <= 0) {
			timer_flag[2] = 1;
		}
	}

	if (timer_counter[3] > 0) {
		timer_counter[3]--;
		if (timer_counter[3] <= 0) {
			timer_flag[3] = 1;
		}
	}
}
