
/*
 * fsm_automatic.c
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#include"fsm_automatic.h"


void fsm_automatic_run(){
	fsm_automatic_traffic_light();
	fsm_automatic_run_segmen();
	updateLed();
}


