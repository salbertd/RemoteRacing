/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "racing_tasks.h"
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
#define SPARE_GPIO_0_Pin GPIO_PIN_13
#define SPARE_GPIO_0_GPIO_Port GPIOC
#define SPARE_GPIO_1_Pin GPIO_PIN_14
#define SPARE_GPIO_1_GPIO_Port GPIOC
#define SPARE_GPIO_2_Pin GPIO_PIN_15
#define SPARE_GPIO_2_GPIO_Port GPIOC
#define SPARE_GPIO_3_Pin GPIO_PIN_0
#define SPARE_GPIO_3_GPIO_Port GPIOF
#define GPS_1PPS_Pin GPIO_PIN_0
#define GPS_1PPS_GPIO_Port GPIOA
#define GPS_FORCE_ON_Pin GPIO_PIN_1
#define GPS_FORCE_ON_GPIO_Port GPIOA
#define GPS_RX_Pin GPIO_PIN_2
#define GPS_RX_GPIO_Port GPIOA
#define GPS_TX_Pin GPIO_PIN_3
#define GPS_TX_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_5
#define LCD_DC_GPIO_Port GPIOA
#define LCD_RD_Pin GPIO_PIN_7
#define LCD_RD_GPIO_Port GPIOA
#define LCD_WR_Pin GPIO_PIN_4
#define LCD_WR_GPIO_Port GPIOC
#define LCD_CCS_Pin GPIO_PIN_5
#define LCD_CCS_GPIO_Port GPIOC
#define LCD_YP_Pin GPIO_PIN_0
#define LCD_YP_GPIO_Port GPIOB
#define LCD_XM_Pin GPIO_PIN_1
#define LCD_XM_GPIO_Port GPIOB
#define LCD_YM_Pin GPIO_PIN_2
#define LCD_YM_GPIO_Port GPIOB
#define LCD_XP_Pin GPIO_PIN_10
#define LCD_XP_GPIO_Port GPIOB
#define LCD_8BIT_3_Pin GPIO_PIN_12
#define LCD_8BIT_3_GPIO_Port GPIOB
#define LCD_8BIT_7_Pin GPIO_PIN_13
#define LCD_8BIT_7_GPIO_Port GPIOB
#define LCD_8BIT_2_Pin GPIO_PIN_14
#define LCD_8BIT_2_GPIO_Port GPIOB
#define LCD_8BIT_6_Pin GPIO_PIN_15
#define LCD_8BIT_6_GPIO_Port GPIOB
#define LCD_8BIT_1_Pin GPIO_PIN_6
#define LCD_8BIT_1_GPIO_Port GPIOC
#define LCD_8BIT_5_Pin GPIO_PIN_7
#define LCD_8BIT_5_GPIO_Port GPIOC
#define LCD_8BIT_0_Pin GPIO_PIN_8
#define LCD_8BIT_0_GPIO_Port GPIOC
#define LCD_8BIT_4_Pin GPIO_PIN_9
#define LCD_8BIT_4_GPIO_Port GPIOC
#define BLE_RX_Pin GPIO_PIN_9
#define BLE_RX_GPIO_Port GPIOA
#define BLE_TX_Pin GPIO_PIN_10
#define BLE_TX_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_15
#define LED_GREEN_GPIO_Port GPIOA
#define LED_YELLOW_Pin GPIO_PIN_10
#define LED_YELLOW_GPIO_Port GPIOC
#define LED_RED_Pin GPIO_PIN_11
#define LED_RED_GPIO_Port GPIOC
#define IMU_INT2_Pin GPIO_PIN_5
#define IMU_INT2_GPIO_Port GPIOB
#define IMU_INT1_Pin GPIO_PIN_6
#define IMU_INT1_GPIO_Port GPIOB
#define IMU_SDA_Pin GPIO_PIN_7
#define IMU_SDA_GPIO_Port GPIOB
#define IMU_SCL_Pin GPIO_PIN_8
#define IMU_SCL_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
