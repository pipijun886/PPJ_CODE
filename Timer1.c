#include <REGX52.H>
unsigned long SysTick_ms = 0;     
//Timer1 初始化：1ms中断
void Timer1_Init(void)
{
    TMOD &= 0x0F;      // 清零T1模式位
    TMOD |= 0x10;      // T1模式1（16位定时器）
    TL1 = 0x66;        // 11.0592MHz下1ms初值
    TH1 = 0xFC;
    ET1 = 1;           // 使能T1中断
    EA  = 1;           // 总中断
    TR1 = 1;           // 启动T1
}

// Timer1中断程序
void Timer1_Routine(void) interrupt 3
{
    TL1 = 0x66;
    TH1 = 0xFC;
    SysTick_ms++;
}