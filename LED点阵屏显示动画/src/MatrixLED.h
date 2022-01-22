#ifndef __MATRIX_LED_H__
#define __MATRIX_LRD_H__

void MatrixLED_Init();
void MatrixLED_showCoulumn(unsigned char Column,unsigned char Data);
void _74HC595_WriteByte(unsigned char Byte);

#endif // !__MATRIX_LED_H__