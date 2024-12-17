/*
 * global.c
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#include"global.h"

int counter_1 = 0;
int counter_2 = 0;

int status0 = 0;
int status1 = 0;
int status2 = 0;
int status3 = 0;
int status4 = 0;

int TIME_RED = 5000;
int TIME_YELLOW = 2000;
int TIME_GREEN = 3000;
int TIME_BLINK = 250;

int time_mid = 0;
int time_lane1 = 0;
int time_lane2 = 0;

uint16_t BUTTON[NUM_BUTTONS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};
