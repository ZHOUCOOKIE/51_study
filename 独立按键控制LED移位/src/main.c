#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
    while(xms)
    {
        unsigned char i, j;
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
    unsigned int LEDNumb = 0;
    P2=~0x01;
    while(1)
    {
        if(P3_1 == 0)
        {
            Delay(20);
            while(P3_1 == 0);
            Delay(20);
            // LEDNumb<<1;//11111110
            // P2=LEDNumb;
            LEDNumb++;
            if(LEDNumb>=8)
            {
                LEDNumb=0;
            }
            P2=~(0X01<<LEDNumb);
        }
        else if(P3_0 == 0)
        {
            Delay(20);
            while(P3_0 == 0);
            Delay(20);
            // LEDNumb<<1;//11111110
            // P2=LEDNumb;
            if(LEDNumb == 0)
            {
                LEDNumb=7;
            }
            else
            {
                LEDNumb--;
            }
            P2=~(0X01<<LEDNumb);
        }
    }
}
