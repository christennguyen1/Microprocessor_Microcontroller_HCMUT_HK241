/*
 * software_timer.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Phuc
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];


void setTimer0(int index, int duration);
void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
