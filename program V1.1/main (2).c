#include <REGX51.H>
#include <draw.h>
#include <tuxing.h>
#include <LCD1602.h>
#include "MatrixKey.h"
#include "Delay.h"
unsigned char mode_xuanze,mode_f;



void show_tuxing(unsigned char i)
{
	
	switch(i)
	{
		case 1:  LCD_ShowString(2,1,"Line+x ");break;
		case 2:  LCD_ShowString(2,1,"Line+y ");break;
		case 3:  LCD_ShowString(2,1,"SQUARE ");break;
		case 4:  LCD_ShowString(2,1,"APPLE     "); break;
	}
}



//void bezr()
//{
//	unsigned int i;
//	for(i=0;i<500;i++)
//	{
//		P1_5=~P1_5;
//		delay(10);
//	}
//}


void main(void)
{
	unsigned char n,draw,finshed=0,count=0,start=0,i=0,bian=0,ok,pre=20,speed=5,mode,m_s=1;
	
	
	LCD_Init();
	Int1Init();
	Int0Init();

	LCD_ShowString(1,1,"    Welcome!    ");
	
	while(1)
	{
		if(mode_xuanze==0)//界面一：欢迎界面
		{
			LCD_ShowString(1,1,"    Welcome!    ");
			LCD_ShowString(2,1,"                ");
		}
		if(mode_xuanze==1)//界面二：设置模式
		{
			mode_f=0;
			LCD_ShowString(1,1,"SET_MODE:       ");
			
			mode=keypros();
			if(mode==1)
			{
				LCD_ShowString(2,1,"Drawing      OK?");
				n=1;
			}
			else if(mode==2)
			{
				LCD_ShowString(2,1,"Manual       OK?");
				n=2;
			}
			ok=getnumber();
			if(ok==5)
			{
				mode_f=1;
				mode_xuanze=3;
			}
		}
		else if(mode_xuanze==2)//界面三：设置参数
		{
			mode_f=0;
			LCD_ShowString(1,1,"SET_PARA:       ");
			
			mode=keypros();
			if(mode==1)
			{
				LCD_ShowString(2,1,"Speed:          ");
				n=1;
			}
			else if(mode==2)
			{
				LCD_ShowString(2,1,"Presision:      ");
				n=2;
			}
			ok=getnumber();
			if(ok==5)
			{
				mode_xuanze=3;
				mode_f=2;
			}
		}
		else if(mode_f==1)//模式下级界面
		{

			if(n==1)//绘制图形选择
			{
				draw=getnumber();
				if(i==0)
				{
					LCD_ShowString(1,1,"Draw_mode       ");
				}
				
				if(draw==2)//图形上翻：S2
				{
					count++;
				}
				else if(draw==8)//图形下翻：S10
				{
					count--;
				}
				else if(draw==5)//确认绘制：S6
				{
					start=1;
				}
				else if(draw==4)//绘制长度减小：S5，步长-1
				{
					bian--;
					if(bian<0)bian=0;
					LCD_ShowNum(2,8,bian,1);
				}
				else if(draw==6)//绘制长度增加：S7，步长1
				{
					bian++;
					if(bian>5)bian=5;
					LCD_ShowNum(2,8,bian,1);
				}
				else if(draw==3)//退出：S3
				{
					stop=0;
					i-=1;
				}
				if(count>9)count=1;
				if(count<1)count=1;
				if(i==0)
				{
					show_tuxing(count);
				}
				if(start==1)//开始判断
				{
					
					switch(count)//选择要绘制的图形
					{
						case 1: Line_x(bian,pre,speed);start=0;finshed=1;break;
						case 2: Line_y(bian,pre,speed);start=0;finshed=1;break;
						case 3: zhengfangxing(3,pre,speed);start=0;finshed=1;break;
						case 4: pingguo();start=0;finshed=1;break;
					}
					if(finshed==1)//绘制完成，显示
					{
						LCD_ShowString(1,1,"    Finshed!    ");
						LCD_ShowString(2,1,"                ");
						i+=1;
						finshed=0;
						//bezr();
					}
				}
//				if(stop==1)
//				{
////					ok=getnumber();
////					if(ok==5)
////					{	
////						mode_xuanze=1;
////						stop=0;
////						mode_f=0;
////					}
//					LCD_ShowString(2,1,"     STOP!!     ");
//					//LCD_ShowString(2,1,"                ");
//				}	
			}
			else if(n==2)//手动模式:x轴正负方向移动，y轴正负方向移动
			{
				LCD_ShowString(1,1,"Manual_mode");
				LCD_ShowString(1,15,"^");
				LCD_ShowString(2,15,"V");
				LCD_ShowString(2,14,"<");
				LCD_ShowString(2,16,">");
				LCD_ShowNum(2,11,m_s,1);
				LCD_ShowString(2,1,"          ");
				gongneng(m_s);
				draw=getnumber();
//				if(draw==12)
//				{
//					m_s+=1;
//					if(m_s>9)speed=0;
//					//LCD_ShowNum(2,11,m_s,3);
//				}
				if(draw==11)//手动绘制下的速度调节
				{
					m_s+=1;
					if(m_s>9)m_s=0;
					//LCD_ShowNum(2,11,m_s,3);
				}
				if(draw==3)
				{
					mode_f=0;
					mode_xuanze=0;
				}
			}
		}
		else if(mode_f==2)//参数下级界面
		{
			if(n==2)//精度设置
			{
				LCD_ShowNum(2,13,pre,3);
				draw=getnumber();
				if(draw==2)//精度增加
				{
					pre+=5;
					if(pre>100)pre=100;
					LCD_ShowNum(2,13,pre,3);
				}
				else if(draw==4)//精度减少
				{
					pre-=5;
					if(pre<0)pre=0;
					LCD_ShowNum(2,13,pre,3);
				}
				else if(draw==5)//确认
				{
					start=1;
				}
			}
			else if(n==1)//速度设置
			{
				LCD_ShowNum(2,13,speed,3);
				draw=getnumber();
				if(draw==2)//速度增加
				{
					speed+=1;
					if(speed>9)speed=0;
					LCD_ShowNum(2,13,speed,3);
				}
				else if(draw==8)//速度减少
				{
					speed-=1;
					if(speed<0)speed=0;
					LCD_ShowNum(2,13,speed,3);
				}
				else if(draw==5)//确认
				{
					start=1;
				}
			}
			if(start==1)
			{
				LCD_ShowString(2,1,"                ");
				start=0;
				mode_f=0;
				mode_xuanze=2;
			}
		}
		
	}
}



void Int1()	interrupt 2		//外部中断1的中断函数
{
	Delayxm(10);	 //延时消抖
	if(k4==0)
	{
		stop=1;
		mode_xuanze=3;
	}
}

void Int0()	interrupt 0		//外部中断0的中断函数
{
	Delayxm(10);	 //延时消抖
	if(k3==0)
	{
		LCD_ShowString(2,1,"                ");
		mode_f=0;
		mode_xuanze+=1;
		if(mode_xuanze>2)mode_xuanze=0;
	}
}