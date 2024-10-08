/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_Pin GPIO_PIN_13
#define BUTTON_GPIO_Port GPIOC
#define ENM0_Pin GPIO_PIN_1
#define ENM0_GPIO_Port GPIOA
#define ENM1_Pin GPIO_PIN_2
#define ENM1_GPIO_Port GPIOA
#define ENM2_Pin GPIO_PIN_3
#define ENM2_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_4
#define DOT_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_7
#define LED2_GPIO_Port GPIOA
#define ROW0_Pin GPIO_PIN_0
#define ROW0_GPIO_Port GPIOB
#define ROW1_Pin GPIO_PIN_1
#define ROW1_GPIO_Port GPIOB
#define ROW2_Pin GPIO_PIN_2
#define ROW2_GPIO_Port GPIOB
#define SEGMENT_1_EX1_Pin GPIO_PIN_10
#define SEGMENT_1_EX1_GPIO_Port GPIOB
#define SEGMENT_2_EX1_Pin GPIO_PIN_11
#define SEGMENT_2_EX1_GPIO_Port GPIOB
#define SEGMENT_3_EX1_Pin GPIO_PIN_12
#define SEGMENT_3_EX1_GPIO_Port GPIOB
#define SEGMENT_4_EX1_Pin GPIO_PIN_13
#define SEGMENT_4_EX1_GPIO_Port GPIOB
#define SEGMENT_5_EX1_Pin GPIO_PIN_14
#define SEGMENT_5_EX1_GPIO_Port GPIOB
#define SEGMENT_6_EX1_Pin GPIO_PIN_15
#define SEGMENT_6_EX1_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_8
#define LED3_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_9
#define LED4_GPIO_Port GPIOA
#define ENM3_Pin GPIO_PIN_10
#define ENM3_GPIO_Port GPIOA
#define ENM4_Pin GPIO_PIN_11
#define ENM4_GPIO_Port GPIOA
#define ENM5_Pin GPIO_PIN_12
#define ENM5_GPIO_Port GPIOA
#define ENM6_Pin GPIO_PIN_13
#define ENM6_GPIO_Port GPIOA
#define ENM7_Pin GPIO_PIN_14
#define ENM7_GPIO_Port GPIOA
#define ROW3_Pin GPIO_PIN_3
#define ROW3_GPIO_Port GPIOB
#define ROW4_Pin GPIO_PIN_4
#define ROW4_GPIO_Port GPIOB
#define ROW5_Pin GPIO_PIN_5
#define ROW5_GPIO_Port GPIOB
#define ROW6_Pin GPIO_PIN_6
#define ROW6_GPIO_Port GPIOB
#define ROW7_Pin GPIO_PIN_7
#define ROW7_GPIO_Port GPIOB
#define SEGMENT_0_EX1_Pin GPIO_PIN_9
#define SEGMENT_0_EX1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
