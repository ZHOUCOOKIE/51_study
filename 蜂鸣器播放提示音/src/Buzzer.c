#include <REGX52.H>
#include <INTRINS.H>

//�������˿ڣ�
sbit Buzzer=P1^5;

/**
  * @brief  ������˽����ʱ��������ʱ500us
  * @param  ��
  * @retval ��
  */
void Buzzer_Delay500us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 247;
	while (--i);
}

/**
  * @brief  ����������
  * @param  ms ������ʱ������Χ��0~32767
  * @retval ��
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
