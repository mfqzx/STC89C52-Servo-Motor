#include <REGX52.H>
#include "Delay.h"
#include "draw.h"
#include "MatrixKey.h"
#include "tuxing.h"

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval KeyNumber 按下按键的键码值
			如果按键按下不放，程序会停留在此函数，松手的一瞬间，返回按键键码，没有按键按下时，返回0
  */
unsigned char getnumber()
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;
	P1_3=0;
	
	if(P1_7==0){Delayxm(20);while(P1_7==0);Delayxm(20);KeyNumber=1;}
	if(P1_6==0){Delayxm(20);while(P1_6==0);Delayxm(20);KeyNumber=4;}
	if(P1_5==0){Delayxm(20);while(P1_5==0);Delayxm(20);KeyNumber=7;}
	if(P1_4==0){Delayxm(20);while(P1_4==0);Delayxm(20);KeyNumber=0;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delayxm(20);while(P1_7==0);Delayxm(20);KeyNumber=2;}
	if(P1_6==0){Delayxm(20);while(P1_6==0);Delayxm(20);KeyNumber=5;}
	if(P1_5==0){Delayxm(20);while(P1_5==0);Delayxm(20);KeyNumber=8;}
	
	
	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delayxm(20);while(P1_7==0);Delayxm(20);KeyNumber=3;}
	if(P1_6==0){Delayxm(20);while(P1_6==0);Delayxm(20);KeyNumber=6;}
	if(P1_5==0){Delayxm(20);while(P1_5==0);Delayxm(20);KeyNumber=9;}
	
	
	return KeyNumber;
}


/**
  * @brief  各个轴的移动函数
  * @param  速度
  * @retval 无
		支持点按和长按两种形式
  */
void gongneng(unsigned char speed)
{
	
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0)
	{Delayxm(10);while(P1_7==0){show_fx(1);go_onestep('x',0,100,speed);};}
	if(P1_5==0)
	{Delayxm(10);while(P1_5==0){show_fx(2);go_onestep('x',1,100,speed);};}
	
	P1=0xFF;
	P1_3=0;
	if(P1_6==0)
	{Delayxm(10);while(P1_6==0){show_fx(3);go_onestep('y',0,100,speed);};}
	
	P1=0xFF;
	P1_1=0;
	if(P1_6==0)
	{Delayxm(10);while(P1_6==0){show_fx(4);go_onestep('y',1,100,speed);};}

}

void Int1Init()
{
	//设置INT1
	IT1=1;//跳变沿出发方式（下降沿）
	EX1=1;//打开INT1的中断允许。	
	EA=1;//打开总中断	
}
void Int0Init()
{
	//设置INT0
	IT0=1;//跳变沿出发方式（下降沿）
	EX0=1;//打开INT0的中断允许。	
	EA=1;//打开总中断	
}
/**
  * @brief  独立键盘键码获取函数
  * @param  无
  * @retval 按下的键码，无按键按下时返回0
  */
unsigned char keypros()
{
	unsigned char r=0;
	if(k1==0)		  //检测按键K1是否按下
	{	
		 Delay10ms();  //消除抖动 一般大约10ms
		if(k1==0)	 //再次判断按键是否按下
		{
			r=1;
		}
		while(!k1);	 //检测按键是否松开
	}		
	if(k2==0)		  //检测按键K1是否按下
	{	
		 Delay10ms();  //消除抖动 一般大约10ms
		if(k2==0)	 //再次判断按键是否按下
		{ 
			r=2;
		}
		while(!k2);	 //检测按键是否松开,我是金刚腿
	}
	return r;
}
