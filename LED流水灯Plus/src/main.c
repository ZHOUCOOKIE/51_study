#include <REG52.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
    while(xms)
    {
    i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
    xms--;
    }
}

int main()
{
    while(1)
    {
        P2=0XFE;//1111 1110
    Delay1ms(100);
    P2=0XFD;
    Delay1ms(100);
    P2=0XFB;
    Delay1ms(100);
    P2=0XF7;
    Delay1ms(100);
    P2=0XEF;
    Delay1ms(100);
    P2=0XDF;
    Delay1ms(100);
    P2=0XBF;
    Delay1ms(100);
    P2=0X7F;
    Delay1ms(100);
    }
}
