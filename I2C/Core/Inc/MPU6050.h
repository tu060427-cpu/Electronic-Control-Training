#include "main.h"
#ifndef __MPU6050_H
#define __MPU6050_H

void MPU6050_writebyte_full(uint8_t byte,uint8_t address);
uint8_t MPU6050_readbyte_full(uint8_t address);
void MPU6050_Getdata(uint16_t *AX,uint16_t *AY,uint16_t *AZ,uint16_t *GX,uint16_t *GY,uint16_t *GZ);

#endif
