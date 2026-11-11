#include "main.h"

#define SCL_H HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET)
#define SCL_L HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET)
#define SDA_H HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET)
#define SDA_L HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET)

#define SDA_READ HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)


void I2C_Start(void)
{
    SDA_H;
    SCL_H;
    SDA_L;
    SCL_L;
}

void I2C_Stop(void)
{
    SDA_L;
    SCL_H;
    SDA_H;
}

void I2C_Ack(void)//读取应答
{
    SDA_H;
    SCL_H;
    SCL_L;
}


uint8_t I2C_WaitAck(void)//发送应答
{
    uint8_t temp = 0;
    SDA_H;
    SCL_H;
    temp = SDA_READ;
    SCL_L;
    return temp;
}


void I2C_Byte(uint8_t byte)//发送一个字节
{
    uint8_t i;
    for(i = 0;i < 8;i++)
    {
        if(((byte << i) & 0x80) == 1)
        {
            SDA_H;
        }
        else
        {
            SDA_L;
        }
        SCL_H;
        SCL_L;
    }
}


uint8_t I2C_readbyte(void)//读取一个字节
{
    uint8_t i;
    uint8_t temp = 0;
    SDA_H;
    for(i = 0;i < 8;i++)
    {
        SCL_H;
        if(SDA_READ == 1)
        {
            temp = temp | 0x80 >> i;
        }
        SCL_L;
    }
    return temp;
}

void I2C_writebyte_full(uint8_t byte)//完整发送
{
    I2C_Start();
    I2C_Byte(byte);
    I2C_WaitAck();
    I2C_Stop();
}


uint8_t I2C_readbyte_full(void)//完整读取
{
    uint8_t temp;
    I2C_Start();
    temp = I2C_readbyte();
    I2C_Ack();
    I2C_Stop();
    return temp;
}
