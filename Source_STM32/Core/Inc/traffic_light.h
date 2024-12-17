/*
 * traffic_light.h
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"
#include "scheduler.h"
#include "display7Segment.h"

void traffic_light1();
void traffic_light2();
void fsm_automatic_traffic_light();
void updateLed();

#endif /* INC_TRAFFIC_LIGHT_H_ */
