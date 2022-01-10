/**
  ******************************************************************************
  * @file           : test.h
  * @brief          : File for test only, will not be compiled in release
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TEST_H
#define __TEST_H

/* Includes ------------------------------------------------------------------*/
#include "usart.h"
#include "ov5640.h"

/* Private variables ---------------------------------------------------------*/
//const uint8_t Test_Str_HelloWorld[] = "Hello World!\n";

/* Private function prototypes -----------------------------------------------*/
void debug(void*);
// void Test_UART(UART_HandleTypeDef *huart);
HAL_StatusTypeDef Test_OV5640(void);

#endif /* __TEST_H */