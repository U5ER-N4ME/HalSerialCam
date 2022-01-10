/**
  ******************************************************************************
  * @file           : ov5640.h
  * @brief          : Camera OV5640
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __OV5640_H
#define __OV5640_H

/* Includes ------------------------------------------------------------------*/
#include "ov5640reg.h"
#include "i2c.h"

/* Private define ------------------------------------------------------------*/
#define OV5640_HI2C                       hi2c1
#define OV5640_I2C_ADDR                   0x78
#define OV5640_I2C_TIMEOUT                1000

#define OV5640_ID                         0x5640

/* Private macro -------------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
HAL_StatusTypeDef OV5640_Write(uint16_t addr, uint8_t value);
HAL_StatusTypeDef OV5640_Read(uint16_t addr, uint8_t* value);
HAL_StatusTypeDef OV5640_PwrSet(bool state);
HAL_StatusTypeDef OV5640_SWReset(void);
HAL_StatusTypeDef OV5640_CheckID(uint16_t idExpected);

#endif /* __OV5640_H */