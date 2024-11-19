/*
 * global.h
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include"main.h"
#include"software_timer.h"
#include"button.h"

#define INIT_LED 0
#define INIT_BUTTON 0
#define NUM_BUTTONS 3

#define AUTO_RED1 1
#define AUTO_GREEN1 2
#define AUTO_AMBER1 3

#define AUTO_RED2 5
#define AUTO_GREEN2 6
#define AUTO_AMBER2 7

#define MODE1 11
#define MODE2 12
#define MODE3 13
#define MODE4 14

extern int status0;
extern int status1;
extern int status2;
extern int status3;
extern int status4;

extern int TIME_RED;
extern int TIME_YELLOW;
extern int TIME_GREEN;
extern int TIME_BLINK;

extern int time_mid;
extern int time_lane1;
extern int time_lane2;

uint16_t BUTTON[NUM_BUTTONS];

#endif /* INC_GLOBAL_H_ */
