#ifndef __LCD1602_H__
#define __LCD1602_H__

//用户调用函数：
void LCD_Init();
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void show_x_y(int x,int y);
#endif
