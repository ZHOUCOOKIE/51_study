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
    while(1)
    {
        if(P3_1 == 0)
        {
            Delay(20);
            while(P3_1 == 0);
            Delay(20);
            LEDNumb++;
            P2=~LEDNumb;
        }
    }
}
