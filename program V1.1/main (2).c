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
		if(mode_xuanze==0)//����һ����ӭ����
		{
			LCD_ShowString(1,1,"    Welcome!    ");
			LCD_ShowString(2,1,"                ");
		}
		if(mode_xuanze==1)//�����������ģʽ
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
		else if(mode_xuanze==2)//�����������ò���
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
		else if(mode_f==1)//ģʽ�¼�����
		{

			if(n==1)//����ͼ��ѡ��
			{
				draw=getnumber();
				if(i==0)
				{
					LCD_ShowString(1,1,"Draw_mode       ");
				}
				
				if(draw==2)//ͼ���Ϸ���S2
				{
					count++;
				}
				else if(draw==8)//ͼ���·���S10
				{
					count--;
				}
				else if(draw==5)//ȷ�ϻ��ƣ�S6
				{
					start=1;
				}
				else if(draw==4)//���Ƴ��ȼ�С��S5������-1
				{
					bian--;
					if(bian<0)bian=0;
					LCD_ShowNum(2,8,bian,1);
				}
				else if(draw==6)//���Ƴ������ӣ�S7������1
				{
					bian++;
					if(bian>5)bian=5;
					LCD_ShowNum(2,8,bian,1);
				}
				else if(draw==3)//�˳���S3
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
				if(start==1)//��ʼ�ж�
				{
					
					switch(count)//ѡ��Ҫ���Ƶ�ͼ��
					{
						case 1: Line_x(bian,pre,speed);start=0;finshed=1;break;
						case 2: Line_y(bian,pre,speed);start=0;finshed=1;break;
						case 3: zhengfangxing(3,pre,speed);start=0;finshed=1;break;
						case 4: pingguo();start=0;finshed=1;break;
					}
					if(finshed==1)//������ɣ���ʾ
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
			else if(n==2)//�ֶ�ģʽ:x�����������ƶ���y�����������ƶ�
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
				if(draw==11)//�ֶ������µ��ٶȵ���
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
		else if(mode_f==2)//�����¼�����
		{
			if(n==2)//��������
			{
				LCD_ShowNum(2,13,pre,3);
				draw=getnumber();
				if(draw==2)//��������
				{
					pre+=5;
					if(pre>100)pre=100;
					LCD_ShowNum(2,13,pre,3);
				}
				else if(draw==4)//���ȼ���
				{
					pre-=5;
					if(pre<0)pre=0;
					LCD_ShowNum(2,13,pre,3);
				}
				else if(draw==5)//ȷ��
				{
					start=1;
				}
			}
			else if(n==1)//�ٶ�����
			{
				LCD_ShowNum(2,13,speed,3);
				draw=getnumber();
				if(draw==2)//�ٶ�����
				{
					speed+=1;
					if(speed>9)speed=0;
					LCD_ShowNum(2,13,speed,3);
				}
				else if(draw==8)//�ٶȼ���
				{
					speed-=1;
					if(speed<0)speed=0;
					LCD_ShowNum(2,13,speed,3);
				}
				else if(draw==5)//ȷ��
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



void Int1()	interrupt 2		//�ⲿ�ж�1���жϺ���
{
	Delayxm(10);	 //��ʱ����
	if(k4==0)
	{
		stop=1;
		mode_xuanze=3;
	}
}

void Int0()	interrupt 0		//�ⲿ�ж�0���жϺ���
{
	Delayxm(10);	 //��ʱ����
	if(k3==0)
	{
		LCD_ShowString(2,1,"                ");
		mode_f=0;
		mode_xuanze+=1;
		if(mode_xuanze>2)mode_xuanze=0;
	}
}