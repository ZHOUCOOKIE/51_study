CFLAGS := PRINT(".\build\Target 1\obj\${c}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\Keil_v5\C51\INC\Atmel;.\..\..\..\..\..\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(".\build\Target 1\obj\${cpp}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\Keil_v5\C51\INC\Atmel;.\..\..\..\..\..\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Target 1\obj\${asm}.lst) SET(SMALL) INCDIR(.\..\..\..\..\..\Keil_v5\C51\INC\Atmel;.\..\..\..\..\..\Keil_v5\C51\INC)
LDFLAGS :=  PRINT(".\build\Target 1\点亮一个LED.map") REMOVEUNUSED
LDLIBS := 
