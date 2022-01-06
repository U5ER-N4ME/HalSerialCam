/**
  ******************************************************************************
  * @file           : test.c
  * @brief          : File for test only, will not be compiled in release
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "test.h"

/**
  * @brief Send hello world phrase to specific UART port. 
  * @param huart UART handle. 
  */
void Test_UART(UART_HandleTypeDef *huart)
{
  HAL_UART_Transmit(&(*huart), Test_Str_HelloWorld, strlen(Test_Str_HelloWorld), 1000);
}
