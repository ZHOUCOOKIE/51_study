#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

unsigned char Animation[]={
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
    0xFF,0x10,0x10,0x10,0xFF,0x00,0x00,0x0F,
    0x15,0x15,0x09,0x00,0x00,0x7F,0x01,0x01,
    0x00,0x00,0x7F,0x01,0x01,0x00,0x00,0x0E,
    0x11,0x11,0x0E,0x00,0x7D,0x00,0x00,0x00,
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};

void main()
{
    unsigned char i,Offset=0,Count;
    void MatrixLED_Init();
    while(1)
    {
        for(i=0;i<8;i++)
        {
            MatrixLED_showCoulumn(i,Animation[i+Offset]);
        }
        Count++;
        if(Count>10)
        {
            Count=0;
            Offset++;
            if(Offset>40)
            {
                Offset=0;
            }
        }
    }
}