#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

void main()
{
    Timer0Init();
    while ()
    {
    }
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x18; //设置定时初值
    TH0 = 0xFC; //设置定时初值
    T0Count++;
    if (T0Count >= 1000)
    {
        T0Count = 0;
    }
}