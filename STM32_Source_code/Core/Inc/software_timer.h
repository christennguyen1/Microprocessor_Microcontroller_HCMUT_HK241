/*
 * software_timer.h
 *
 *  Created on: Nov 14, 2024
 *      Author: vinhn
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];


void setTimer0(int index, int duration);
void timer_run();

#endif /* SRC_SOFTWARE_TIMER_H_ */
