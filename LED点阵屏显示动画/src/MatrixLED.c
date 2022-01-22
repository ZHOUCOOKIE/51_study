#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;
#define MATRIX_LED_PORT P0

/**
 * @brief 74HC595д��һ���ֽ�
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
 * @brief ��������ʼ��
 * 
 */
void MatrixLED_Init()
{
    SCK=0;
    RCK=0;
}

/**
 * @brief LED��������ʾһ������
 * 
 * @param Column Ҫѡ����У���Χ��0~7��0�������
 * @param Data ѡ������ʾ�����ݣ���λ���ϣ�1Ϊ����0Ϊ��
 */
void MatrixLED_showCoulumn(unsigned char Column,unsigned char Data)
{
    _74HC595_WriteByte(Data);
    MATRIX_LED_PORT=~(0x80>>Column);
    Delay(1);
    MATRIX_LED_PORT=0XFF;
}