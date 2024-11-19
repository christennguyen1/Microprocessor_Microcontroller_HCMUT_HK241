/*
 * display7Segment.h
 *
 *  Created on: Oct 21, 2024
 *      Author: vinhn
 */

#ifndef INC_DISPLAY7SEGMENT_H_
#define INC_DISPLAY7SEGMENT_H_

#include"global.h"
#include "i2c-lcd.h"
#include "stdio.h"

void updateClockBuffer(int lane_1, int lane_2);
void clearAll();


#endif /* INC_DISPLAY7SEGMENT_H_ */
