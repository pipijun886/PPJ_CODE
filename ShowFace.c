#include <REGX52.H>
#include "LCD1602.h"

#include <REGX52.H>
#include "LCD1602.h"

//==================== 表情1：睁眼笑脸 + 挥手身体 ====================
void ShowFace_1(void)
{
    //第一行 脸
    LCD_ShowChar(1,5,'(');
    LCD_ShowChar(1,6,'^');
    LCD_ShowChar(1,7,'_');
    LCD_ShowChar(1,8,'^');
    LCD_ShowChar(1,9,')');

    //第二行 身体
    LCD_ShowChar(2,4,'<');
    LCD_ShowChar(2,6,'(');
    LCD_ShowChar(2,7,'_');
    LCD_ShowChar(2,8,'_');
    LCD_ShowChar(2,9,')');
}

//==================== 表情2：闭眼嘟嘴 + 叉腰身体 ====================
void ShowFace_2(void)
{
    //第一行 脸
    LCD_ShowChar(1,5,'(');
    LCD_ShowChar(1,6,'-');
    LCD_ShowChar(1,7,'_');
    LCD_ShowChar(1,8,'-');
    LCD_ShowChar(1,9,')');

    //第二行 身体
    LCD_ShowChar(2,4,'>');
    LCD_ShowChar(2,6,'(');
    LCD_ShowChar(2,7,'_');
    LCD_ShowChar(2,8,'_');
    LCD_ShowChar(2,9,')');
}

//==================== 表情3：眨眼wink + 抬手身体 ====================
void ShowFace_3(void)
{
    //第一行 脸
    LCD_ShowChar(1,5,'(');
    LCD_ShowChar(1,6,'^');
    LCD_ShowChar(1,7,'_');
    LCD_ShowChar(1,8,'-');
    LCD_ShowChar(1,9,')');

    //第二行 身体
    LCD_ShowChar(2,4,'<');
    LCD_ShowChar(2,6,'(');
    LCD_ShowChar(2,8,')');
    LCD_ShowChar(2,10,'>');
}

//==================== 表情4：歪嘴笑 + 摆手身体 ====================
void ShowFace_4(void)
{
    //第一行 脸
    LCD_ShowChar(1,5,'(');
    LCD_ShowChar(1,6,'^');
    LCD_ShowChar(1,7,'_');
    LCD_ShowChar(1,8,'w');
    LCD_ShowChar(1,9,')');

    //第二行 身体
    LCD_ShowChar(2,4,'>');
    LCD_ShowChar(2,6,'(');
    LCD_ShowChar(2,8,')');
    LCD_ShowChar(2,10,'<');
}

//==================== 表情5：惊讶脸 + 举手身体 ====================
void ShowFace_5(void)
{
    //第一行 脸
    LCD_ShowChar(1,5,'(');
    LCD_ShowChar(1,6,'o');
    LCD_ShowChar(1,7,'_');
    LCD_ShowChar(1,8,'o');
    LCD_ShowChar(1,9,')');

    //第二行 身体
    LCD_ShowChar(2,4,'<');
    LCD_ShowChar(2,6,'(');
    LCD_ShowChar(2,8,')');
    LCD_ShowChar(2,9,'<');
    LCD_ShowChar(2,10,'>');
}