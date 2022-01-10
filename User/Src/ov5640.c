/**
  ******************************************************************************
  * @file           : ov5640.c
  * @brief          : Camera OV5640
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ov5640.h"

/**
  * @brief Write content to specific register address. 
  * @param addr destination register address. 
  * @param value value to be written. 
  */
HAL_StatusTypeDef OV5640_Write(uint16_t addr, uint8_t value)
{
  HAL_StatusTypeDef rtn; 
  rtn = HAL_I2C_Mem_Write(&OV5640_HI2C, OV5640_I2C_ADDR, 
                          addr, I2C_MEMADD_SIZE_16BIT, 
                          value, I2C_MEMADD_SIZE_8BIT, 
                          OV5640_I2C_TIMEOUT
                         );
  return rtn;
}

/**
  * @brief Read data from specific register address. 
  * @param addr source register address. 
  * @param value pointer. The internal address to store the value. 
  */
HAL_StatusTypeDef OV5640_Read(uint16_t addr, uint8_t* value)
{
  HAL_StatusTypeDef rtn;
  rtn = HAL_I2C_Mem_Read(&OV5640_HI2C, OV5640_I2C_ADDR, 
                         addr, I2C_MEMADD_SIZE_16BIT, 
                         value, I2C_MEMADD_SIZE_8BIT, 
                         OV5640_I2C_TIMEOUT
                        );
  return rtn;
}

/**
  * @brief Power on or off. 
  * @param state 'true' to switch on, and 'false' to switch off. 
  */
HAL_StatusTypeDef OV5640_PwrSet(bool state)
{
  // OV5640 active when CAMPWR is low
  switch (state)
  {
  case true:
    // enable reset
    HAL_GPIO_WritePin(CAMRST_GPIO_Port, CAMRST_Pin, GPIO_PIN_RESET); 
    HAL_Delay(20);
    // power up
    HAL_GPIO_WritePin(CAMPWR_GPIO_Port, CAMPWR_Pin, GPIO_PIN_RESET);
    HAL_Delay(20);
    // disable reset
    HAL_GPIO_WritePin(CAMRST_GPIO_Port, CAMRST_Pin, GPIO_PIN_SET);
    HAL_Delay(20);
    break;
  case false:
    HAL_GPIO_WritePin(CAMPWR_GPIO_Port, CAMPWR_Pin, GPIO_PIN_SET);
    HAL_Delay(20);
    break;
  default:
    break;
  }

  return HAL_OK;
}

/**
  * @brief Power on or off. 
  * @param state 'true' to switch on, and 'false' to switch off. 
  */
HAL_StatusTypeDef OV5640_CheckID(uint16_t idExpected)
{
  uint8_t idObtained[2];

  OV5640_Read(OV5640_REG_IDH, &idObtained[0]);
  OV5640_Read(OV5640_REG_IDL, &idObtained[1]);

  if ((idObtained[0]<<8) + idObtained[1] == idExpected)
  {
    return HAL_OK;
  }
  else
  {
    return HAL_ERROR; 
  }
}

/**
  * @brief OV5640 software reset. 
  */
HAL_StatusTypeDef OV5640_SWReset(void)
{
  HAL_StatusTypeDef rtn;
  rtn = OV5640_Write(OV5640_REG_SYSCTRL0, OV5640_REG_SYSCTRL0_RST);
  return rtn;
}

