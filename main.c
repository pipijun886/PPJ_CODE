#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Nixie.h"
#include "Timer1.h"

//蜂鸣器端口定义
	 sbit Buzzer = P2^5;
	 
	 //播放速度为500ms，即一个四分音符
	 #define SPEED  500
	 
	 //音符与索引对应表，P：休止符，L：低音，M：中音，H：高音，下划线：升半音符号#
	 #define P   0
	 #define L1  1
	 #define L1_ 2
	 #define L2  3
	 #define L2_ 4
	 #define L3  5
	 #define L4  6
	 #define L4_ 7
	 #define L5  8 
	 #define L5_ 9
	 #define L6  10
	 #define L6_ 11
	 #define L7  12
	 #define M1  13
	 #define M1_ 14
	 #define M2  15
	 #define M2_ 16
	 #define M3  17
	 #define M4  18
	 #define M4_ 19
	 #define M5  20 
	 #define M5_ 21
	 #define M6  22
	 #define M6_ 23
	 #define M7  24
	 #define H1  25
	 #define H1_ 26
	 #define H2  27
	 #define H2_ 28
	 #define H3  29
	 #define H4  30
	 #define H4_ 31
	 #define H5  32
	 #define H5_ 33
	 #define H6  34
	 #define H6_ 35
	 #define H7  36
	 
	 //晶振频率11.0592的索引表
	 unsigned int  code FreqTable[] = 
	 {0,63777,63872,63968,64054,64139,64215,64290,64360,64425,64488,64547,64606,
64654,64704,64750,64795,64836,64875,64913,64948,64981,65012,65041,65069,
65095,65120,65143,65165,65186,65205,65222,65239,65254,65269,65282,65294};
	 
   //谱子，音符，时值
		 unsigned char code Music[]=
		 {
			 //前奏
			 P ,4,
			 L6,2,
			 M3,2,
			 M3,2,
			 M3,2,
			 M3,6,
			 M2,2,
			 
			 M1,4,
			 M2,1,
			 M1,2,
			 L7,2,
			 L6,4,
			 P ,4,
			 
			 // 我从山中来，带着兰花草
			 L6,2,
			 M3,2,
			 M3,2,
			 M3,2,
			 M3,6,
			 M2,2,
			 
			 M1,4,
			 M2,1,
			 M1,2,
			 L7,2,
			 L6,8,
			 
			 // 种在小园里，希望花开早
			 M6,2,
			 M6,2,
			 M6,2,
			 M6,2,
			 M6,6,
			 M5,2,
			 
			 M3,2,
			 M5,2,
			 M5,2,
			 M4,2,
			 M3,8,
			 
			 // 一日看三回，看得花时过
			 M3,2,
			 M6,2,
			 M6,2,
			 M5,2,
			 M3,6,
			 M2,2,
			 
			 M1,6,
			 M2,1,
			 M1,2,
			 L7,2,
			 L6,4,
			 L3,4,
			 
			 // 兰花却依旧，苞也无一个
			 L3,2,
			 M1,2,
			 M1,2,
			 L7,2,
			 L6,6,
			 M3,2,
			 
			 M2,4,
			 M1,1,
			 L7,2,
			 L5,2,
			 L6,8,
			 
			 // 转眼秋天到，移兰入暖房
			 L6,2,
			 M3,2,
			 M3,2,
			 M3,2,
			 M3,6,
			 M2,2,
			 
			 M1,4,
			 M2,1,
			 M1,2,
			 L7,2,
			 L6,8,
			 
			 // 朝朝频顾惜，夜夜不相忘
			 M6,2,
			 M6,2,
			 M6,2,
			 M6,2,
			 M6,6,
			 M5,2,
			 
			 M3,2,
			 M5,2,
			 M5,2,
			 M4_,2,
			 M3,8,
			 
			 // 期待春花开，能将夙愿偿
			 M3,2,
			 M6,2,
			 M6,2,
			 M5,2,
			 M3,6,
			 M2,2,
			 
			 M1,6,
			 M2,1,
			 M1,2,
			 L7,2,
			 L6,4,
			 L3,4,
			 
			 // 满庭花簇簇，添得许多香
			 L3,2,
			 M1,2,
			 M1,2,
			 L7,2,
			 L6,6,
			 M3,2,
			 
			 M2,4,
			 M1,1,
			 L7,2,
			 L5,2,
			 L6,8,
			 
			 
			 // 尾奏
			 M2,4,
			 M1,1,
			 L7,2,
			 L5,2,
			 L6,8,
			 
			 M3,4,
			 M2,2,
			 M3,2,
			 P ,2,
			 M2,2,
			 M3,2,
			 M5,2,
			 
			 M6,2,
			 M6,2,
			 P ,4,
			 P ,4,
			 M7,2,
			 M6,2,
			 
			 M5_,8,
			 P ,2,
			 M2,2,
			 M3,2,
			 M4,2,
			 
			 M3,2,
			 H3,2,
			 H3,1,
			 H3,1,
			 H3,2,
			 H2_,1,
			 H2,1,
			 H2,2,
			 H1,1,
			 
			 H3,16,
			 M6,12,
			 H3,2,
			 H2,2,
			 M7,8,
			 P ,2,
			 M2,2,
			 M3,2,
			 M4,2,
			 
			 M3,2,
			 M3,2,
			 M3,4,
			 H3,2,
			 H2,2,
			 H1,2,
			 M7,2,
			 
			 M2,4,
			 M1,2,
			 M7,2,
			 M5,2,
			 L6,8,
			 M3,2,
			 M1,2,
			 M1,2,
			 M7,2,
			 L6,6,
			 M3,2,
			 
			 M2,4,
			 M1,2,
			 M7,2,
			 M5,2,
			 L6,8,
			 P ,4,
			 
			 //终止标志
			 0xFF	
		 };

		 
int Music_Len = sizeof (Music)/sizeof(Music[0]);		 
		 

unsigned char FreqSelect, MusicSelect;
unsigned long PlayStart_ms = 0;    // 当前音符开始播放的时刻（毫秒）
extern unsigned long SysTick_ms;
float TotalTime = 0;
float NowTime = 0;
int Count = 0;	
		 
void main()
{
	
	
	

  unsigned char duration = 0;
  unsigned int duration_ms = 0;
	unsigned long target = 0;
	
    // 计算乐曲总时长（秒）
   unsigned int i = 0; 
    unsigned long total_duration = 0;   // 时值总和（整数）
    
    // 计算总时长（遍历 Music 数组，直到遇到 0xFF）
    while(1)
    {
        unsigned char note = Music[i];     // 音符（跳过，不使用）
        unsigned char duration = Music[i+1]; // 时值
        
        if(note == 0xFF)   // 遇到终止标志，停止累加
            break;
        
        total_duration += duration;   // 累加时值
        i += 2;            // 移动到下一组（音符+时值）
    }
    
    // 总时长（秒）= 时值总和 × (SPEED/4) ÷ 1000
    // SPEED=500 → SPEED/4=125 → 125/1000=0.125
    TotalTime = total_duration * 0.125f;
    
		
    Timer0Init();      // 初始化蜂鸣器定时器
    Timer1_Init();     // 初始化进度计时器
    
    MusicSelect = 0;   // 从第一个音符开始
    PlayStart_ms = SysTick_ms;   // 记录起始时刻
    
    while(1)
    {
    if(Music[MusicSelect] == 0xFF)  // 播放结束
    {
     TR0 = 0;
     while(1);
        }
        
// 取出音符和时值
    FreqSelect = Music[MusicSelect];      // 音符索引
    MusicSelect++;
    duration = Music[MusicSelect];  // 时值
    MusicSelect++;
        
// 计算当前音符应持续的时间（毫秒）
    duration_ms = (SPEED / 4) * duration;
        
 // 开始播放该音符
    if(FreqTable[FreqSelect] != 0)
            TR0 = 1;      // 有音高则开启蜂鸣器定时器
    else
            TR0 = 0;      // 休止符关闭蜂鸣器
        
//等待当前音符播放完毕，同时不断刷新数码管
   target = SysTick_ms + duration_ms;
   while(SysTick_ms < target)
        {
            //计算当前已播放时长
            NowTime = (float)(SysTick_ms - PlayStart_ms) / 1000.0f;
            //刷新数码管显示进度和总时长
            Display_Progress(1, NowTime);
            Display_Progress(4, TotalTime);
        }
        
        // 音符结束后停顿5ms
        TR0 = 0;
        Delay(5);
        
        // 继续下一个音符
    }
}

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])
	{
		//取对应频率值的重装载值到定时器
		TL0 = FreqTable[FreqSelect]%256;
		TH0 = FreqTable[FreqSelect]/256;
		//翻转蜂鸣器io口
		Buzzer=!Buzzer;
		Count++;
	}
}

			 
	 
		 
