#include "main.h"
#ifndef __I2C_H
#define __I2C_H
 
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Ack(void);
uint8_t I2C_WaitAck(void);
uint8_t I2C_readbyte(void);
void I2C_Byte(uint8_t byte);
uint8_t I2C_readbyte(void);
void I2C_writebyte_full(uint8_t byte);
uint8_t I2C_readbyte_full(void);


#endif
