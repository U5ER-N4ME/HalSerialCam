/**
  ******************************************************************************
  * @file           : test.c
  * @brief          : File for test only, will not be compiled in release
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "test.h"

/**
  * @brief Debug output to UART. 
  * @param str string to output. 
  */
void debug(void* str)
{
  HAL_UART_Transmit(&huart4, str, strlen(str), 1000);
}

/**
  * @brief Send hello world phrase to specific UART port. 
  * @param huart UART handle. 
  */
/*
void Test_UART(UART_HandleTypeDef *huart)
{
  HAL_UART_Transmit(&(*huart), Test_Str_HelloWorld, strlen(Test_Str_HelloWorld), 1000);
}
*/

/**
  * @brief Basic test on OV5640 connectivity. It powers up the module, check ID 
  *        and reset it. 
  *        By passing this test, OV5640 is connected with a working I2C bus. 
  */
HAL_StatusTypeDef Test_OV5640(void)
{
  OV5640_PwrSet(true);

  if (OV5640_CheckID(OV5640_ID) != HAL_OK)
  {
    debug("Camera ID check failure\n");
    return HAL_ERROR;
  }
  else
  {
    if (OV5640_SWReset() != HAL_OK)
    {
      debug("Camera swrst failure\n");
      return HAL_ERROR;
    }
    
  }

  debug("Camera OK! \n");

  return HAL_OK;
}
