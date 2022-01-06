/**
  ******************************************************************************
  * @file           : test.h
  * @brief          : File for test only, will not be compiled in release
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* Private variables ---------------------------------------------------------*/
const uint8_t Test_Str_HelloWorld[] = "Hello World!\n";

/* Private function prototypes -----------------------------------------------*/
void Test_UART(UART_HandleTypeDef *huart);
