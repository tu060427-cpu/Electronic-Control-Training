#include "I2C.h"
#include "MPU6050.h"



void MPU6050_writebyte_full(uint8_t byte,uint8_t address)//指定地址写
{
    I2C_Start();
    I2C_Byte(0xD0);
    I2C_WaitAck();
    I2C_Byte(address);
    I2C_WaitAck();
    I2C_Byte(byte);
    I2C_WaitAck();
    I2C_Stop();
}




uint8_t MPU6050_readbyte_full(uint8_t address)//指定地址读
{
    uint8_t temp;
    I2C_Start();
    I2C_Byte(0xD0);
    I2C_WaitAck();
    I2C_Byte(address);
    I2C_WaitAck();

    I2C_Start();
    I2C_Byte(0xD0 | 0x01);
    I2C_WaitAck();
    temp = I2C_readbyte();
    I2C_Ack_no();
    I2C_Stop();
    return temp;
}




void MPU6050_Getdata(uint16_t *AX,uint16_t *AY,uint16_t *AZ,uint16_t *GX,uint16_t *GY,uint16_t *GZ)
{
    uint8_t data_h;
    uint8_t data_l;
    data_h = MPU6050_readbyte_full(0x3B);
    data_l = MPU6050_readbyte_full(0x3C);
    *AX = (data_h << 8) | data_l;

    data_h = MPU6050_readbyte_full(0x3D);
    data_l = MPU6050_readbyte_full(0x3E);
    *AY = (data_h << 8) | data_l;

    data_h = MPU6050_readbyte_full(0x3F);
    data_l = MPU6050_readbyte_full(0x40);
    *AZ = (data_h << 8) | data_l;

    data_h = MPU6050_readbyte_full(0x43);
    data_l = MPU6050_readbyte_full(0x44);
    *GX = (data_h << 8) | data_l;

    data_h = MPU6050_readbyte_full(0x45);
    data_l = MPU6050_readbyte_full(0x46);
    *GY = (data_h << 8) | data_l;

    data_h = MPU6050_readbyte_full(0x47);
    data_l = MPU6050_readbyte_full(0x48);
    *GZ = (data_h << 8) | data_l;

}