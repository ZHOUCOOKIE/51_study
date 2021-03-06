#include <REGX52.H>
#include "Delay.h"
sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;
#define MATRIX_LED_PORT P0

/**
 * @brief 74HC595写入一个字节
 * 
 * @param Byte 
 */
void _74HC595_WriteByte(unsigned char Byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        SER=Byte&(0x80>>i);
        SCK=1;
        SCK=0;
    }
    RCK=1;
    RCK=0;
}

/**
 * @brief LED点阵屏显示一列数据
 * 
 * @param Column 要选择的列，范围：0~7，0在最左边
 * @param Data 选择列显示的数据，高位在上，1为亮，0为灭
 */
void MatrixLED_showCoulumn(unsigned char Column,unsigned char Data)
{
    _74HC595_WriteByte(Data);
    MATRIX_LED_PORT=~(0x80>>Column);
    Delay(1);
    MATRIX_LED_PORT=0XFF;
}

void main()
{
    SCK=0;
    RCK=0;

    while(1)
    {
    MatrixLED_showCoulumn(0,0x3C);
    MatrixLED_showCoulumn(1,0x42);
    MatrixLED_showCoulumn(2,0xA9);
    MatrixLED_showCoulumn(3,0x85);
    MatrixLED_showCoulumn(4,0x85);
    MatrixLED_showCoulumn(5,0xA9);
    MatrixLED_showCoulumn(6,0x42);
    MatrixLED_showCoulumn(7,0x3C);
    }
}