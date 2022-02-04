#include <REGX52.H>

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

#define DS1302_SECOND 0X80
#define DS1302_MINUTE 0X82
#define DS1302_HOUR   0X84
#define DS1302_DATE   0X86
#define DS1302_MONTH  0X88
#define DS1302_DAY    0X8A
#define DS1302_YEAR   0X8C
#define DS1302_WP     0X8E

unsigned char DS1302_Time[]={22,2,4,13,46,30,5};


void DS1302_Init()
{
    DS1302_CE=0;
    DS1302_SCLK=0;
}

void DS1302_WriteByte(unsigned char Command,unsigned char Data)
{
    unsigned char i;
    DS1302_CE=1;
    for(i=0;i<8;i++)
    {        
        DS1302_IO=Command&(0x01<<i);
        DS1302_SCLK=1;
        DS1302_SCLK=0;
    }
    for(i=0;i<8;i++)
    {        
        DS1302_IO=Data&(0x01<<i);
        DS1302_SCLK=1;
        DS1302_SCLK=0;
    }
    DS1302_CE=0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i;
    unsigned char Data=0x00;
    Command|=0x01;
    DS1302_CE=1;
    for(i=0;i<8;i++)
    {        
        DS1302_IO=Command&(0x01<<i);
        DS1302_SCLK=0;
        DS1302_SCLK=1;
    }
    for(i=0;i<8;i++)
    {        
        DS1302_SCLK=1;
        DS1302_SCLK=0;
        if (DS1302_IO) {Data|=(0x01<<i);}//(SCLK=0之后，数据已经在IO口上)
    }
    DS1302_CE=0;
    DS1302_IO=0;
    return Data;
}

void DS1302_SetTime()
{
    DS1302_WriteByte(DS1302_WP,0X00);
    DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
    DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
    DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
    DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
    DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
    DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
    DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
    DS1302_WriteByte(DS1302_WP,0X80);
}

void DS1302_ReadTime()
{
    unsigned char Temp;
    Temp=DS1302_ReadByte(DS1302_YEAR);
    DS1302_Time[0]=Temp/16*10+Temp%16;    
    Temp=DS1302_ReadByte(DS1302_MONTH);
    DS1302_Time[1]=Temp/16*10+Temp%16;
    Temp=DS1302_ReadByte(DS1302_DATE);
    DS1302_Time[2]=Temp/16*10+Temp%16;    
    Temp=DS1302_ReadByte(DS1302_HOUR);
    DS1302_Time[3]=Temp/16*10+Temp%16;    
    Temp=DS1302_ReadByte(DS1302_MINUTE);
    DS1302_Time[4]=Temp/16*10+Temp%16;    
    Temp=DS1302_ReadByte(DS1302_SECOND);
    DS1302_Time[5]=Temp/16*10+Temp%16;    
    Temp=DS1302_ReadByte(DS1302_DAY);
    DS1302_Time[6]=Temp/16*10+Temp%16;    
}