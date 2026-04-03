#include <REGX52.H>
#include "LCD1602.h"
 #include "Delay.h"
 #include "ShowFace.h"
void main()
{
	LCD_Init();
  ShowFace_1();
	while(1)
	{
		ShowFace_1();
		Delay(300);
		ShowFace_2();
		Delay(300);
		ShowFace_3();
		Delay(300);
		ShowFace_4();
		Delay(300);
		ShowFace_5();
		Delay(300);
  }
}