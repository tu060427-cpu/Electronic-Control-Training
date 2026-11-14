#include "main.h"
#include <stdint.h>

#define SCL_H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET)
#define SCL_L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET)
#define SDA_H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET)
#define SDA_L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET)

#define SDA_READ HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)


void I2C_Delay(void)
{
    uint32_t i = 10;
    while(i--);
}

void I2C_Start(void)
{
    SDA_H;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
    SDA_L;
    I2C_Delay();
    SCL_L;
    I2C_Delay();
}

void I2C_Stop(void)
{
    SDA_L;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
    SDA_H;
    I2C_Delay();
}

void I2C_Ack_no(void)//读取非应答
{
    SDA_H;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
    SCL_L;
    I2C_Delay();
}

void I2C_Ack_yes(void)//读取应答
{
    SDA_L;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
    SCL_L;
    I2C_Delay();
}


uint8_t I2C_WaitAck(void)//发送应答
{
    uint8_t temp = 0;
    SDA_H;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
    temp = SDA_READ;
    I2C_Delay();
    SCL_L;
    I2C_Delay();
    return temp;
}


void I2C_Byte(uint8_t byte)//发送一个字节
{
    uint8_t i;
    for(i = 0;i < 8;i++)
    {
        if(byte & (0x80 >> i))
        {
            SDA_H;
        }
        else
        {
            SDA_L;
        }
        SCL_H;
        I2C_Delay();
        SCL_L;
        I2C_Delay();
    }
}


uint8_t I2C_readbyte(void)//读取一个字节
{
    uint8_t i;
    uint8_t temp = 0;
    SDA_H;
    I2C_Delay();
    for(i = 0;i < 8;i++)
    {
        SCL_H;
        I2C_Delay();
        if(SDA_READ == 1)
        {
            temp = temp | 0x80 >> i;
        }
        SCL_L;
        I2C_Delay();
    }
    return temp;
}




