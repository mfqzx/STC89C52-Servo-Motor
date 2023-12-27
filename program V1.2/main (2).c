#include <REGX51.H>
#include <draw.h>
#include <tuxing.h>
#include "MatrixKey.h"
#include "Delay.h"
#include "shuma.h"
#include "Buzzer.h"
unsigned char mode_xuanze;

void main(void)
{
	unsigned char speed=5,mode=0,draw=0,n=0,a=0,f=0;
	
	
	Int1Init();
	Int0Init();
	
	while(1)
	{
		if(mode_xuanze==0)//һ�����棬��ӭ
		{
			show_fx(5);
		}
		if(mode_xuanze==1)//һ�����棬�ٶ�����
		{
			Nixie(7,speed);//�������ʾ�ٶ�
			mode=getnumber();//��ȡ����
			if(mode==2)
			{
				Buzzer_Time(50);//������������ʾ��
				speed++;
				if(speed>9)speed=0;
				//Nixie(7,speed);
			}
			else if(mode==8)//ͬ��
			{
				Buzzer_Time(50);
				speed--;
				if(speed<0)speed=0;
				//Nixie(7,speed);
			}
		}
		else if(mode_xuanze==2)//һ�����棬�ֶ�����
		{
			show_fx(6);
			gongneng(speed);
		}
		else if(mode_xuanze==3)//һ���������ͼ��
		{
			if(f==0)
			{
				show_fx(8);
			}
			n=getnumber();//�ӽ���
			if(n==2)
			{
				f=1;
				a+=1;
				if(a>5)a=1;
			}
			else if(n==8)
			{
				f=1;
				a-=1;
				if(a<1)a=1;
			}
			show_tx(a);
			if(n==5)
			{
				f=0;
				switch(a)//ʹ�ñ���a�ж�Ҫ���Ƶ�ͼ��
				{
					case 1:	sanjiao(speed);break;
					case 2: yuan();break;
					case 3: zhengfangxing(speed);break;
					case 4: break;
					case 5: break;
				}
			}
		}
		else if(stop==1)//��ͣ�жϣ�����س���
		{
			show_fx(7);
			mode=getnumber();
			Buzzer_Time(150);
			if(mode==5)
			{
				stop=0;
				mode_xuanze=0;
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
		mode_xuanze=4;
	}
}

void Int0()	interrupt 0		//�ⲿ�ж�0���жϺ���
{
	Delayxm(10);	 //��ʱ����
	if(k3==0)
	{
		//f=0;
		mode_xuanze+=1;
		if(mode_xuanze>3)mode_xuanze=0;
	}
}