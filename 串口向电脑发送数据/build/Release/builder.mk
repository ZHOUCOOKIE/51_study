CFLAGS := PRINT(.\build\Release\${c}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\..\..\Keil\C51\INC;.\src) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(.\build\Release\${cpp}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\..\..\Keil\C51\INC;.\src) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Release\${asm}.lst) SET(SMALL) INCDIR(.\..\..\..\..\..\..\..\Keil\C51\INC;.\src)
LDFLAGS :=  PRINT(.\build\Release\串口向电脑发送数据.map) REMOVEUNUSED
LDLIBS := 
