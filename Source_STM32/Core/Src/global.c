/*
 * global.c
 *
 *  Created on: Dec 3, 2024
 *      Author: vinhn
 */


#include "global.h"

uint8_t cmdBuffer[CMD_CONTENT_MAX_LENGTH];
uint8_t buffer_flag = 0;
uint8_t cmd_content_index = 0;
uint8_t tempValue = 0;

enum UART_STATE 	uartState = UART_IDLE;
enum CMD_STATE		cmdState = CMD_IDLE;
enum ERROR_STATE	errState = ERROR_IDLE;


uint8_t flagForOK = 0;

int waitTimerCounter = 0;
int waitTimer_flag = 0;

int isRST = 0;
int isOK = 0;
