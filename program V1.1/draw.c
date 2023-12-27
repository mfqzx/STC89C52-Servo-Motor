#include <REGX51.H>
#include <LCD1602.h>
#include <math.h>
#include "Delay.h"
#define one_s	0.0002

sbit x_maichong=P2^0;
sbit x_fangxiang=P2^1;
sbit y_maichong=P2^2;
sbit y_fangxiang=P2^3;
unsigned char stop;
/**
  * @brief  绝对值求取函数
  * @param  待取绝对值的数
  * @retval 绝对值
  */
double myabs(double a)
{
	if(a<0)
		return -a;
	else
		return a;
}

/**
  * @brief  前进一步函数
  * @param  移动的轴；移动方向；移动精度即一步走多少；移动的速度
  * @retval 无
  */
void go_onestep(unsigned char zhou,unsigned int fangxiang,unsigned int step,unsigned int speed)
{
	unsigned int i;
	
	speed=(-5*speed+50);
	
	if (zhou=='x')
	{
		if (fangxiang==1)
		{
			x_fangxiang=0;
		}
		else
			x_fangxiang=1;
		for(i=0;i<step;i++)
		{
			x_maichong=0;           
			delay(speed);     
			x_maichong=1;            
		}
	}
	if (zhou=='y')
	{
		if (fangxiang==1)
		{
			y_fangxiang=1;
		}
		else
			y_fangxiang=0;
		for(i=0;i<step;i++)
		{
			y_maichong=0;           
			delay(speed);     
			y_maichong=1;            
		}
	}
}
/**
  * @brief  直线插补函数
  * @param  要绘制直线的起点坐标，终点坐标；step：绘制精度；speed：绘制速度
  * @retval 无
  */
void draw_zhixian(double x_qi,double y_qi,double x_end,double y_end,unsigned int step,unsigned int speed)
{
	unsigned int zong_step;
	double x_now;
	double y_now;
	double juli=0;
	unsigned char n=0;
	int x_dir,y_dir,x_data,y_data;
	/******************************/
	x_now=x_qi;
	y_now=y_qi;
	
	zong_step=(myabs(x_qi-x_end)+myabs(y_qi-y_end))/(one_s*step);
	
	if((x_end-x_qi)>0)
		x_dir=1;
	else
		x_dir=0;
	if((y_end-y_qi)>0)
		y_dir=1;
	else
		y_dir=0;
	while(zong_step)
	{
		if(juli>=0)
		{
			go_onestep('x',x_dir,step,speed);
			if(x_dir==0)
			{
				x_now=x_now-one_s*step;
			}
			else
			{
				x_now=x_now+one_s*step;
			}
			juli = juli - myabs(y_end - y_qi);
		}
		
		else if(juli<0)
		{
			go_onestep('y',y_dir,step,speed);
			if(y_dir==0)
			{
				y_now=y_now-one_s*step;
			}
			else
			{	
				y_now=y_now+one_s*step;
			}
			juli = juli + myabs(x_end - x_qi);
		}
		n++;
		if(n%100==0)
		{
			x_data=x_now*100;
			y_data=y_now*100;
			show_x_y(x_data,y_data);
		}
		zong_step--;
		if(stop==1)
		{
			break;
		}
	}
}

/**
  * @brief  顺圆绘制函数，使用圆弧插补
  * @param  要绘制圆的起点坐标，圆心坐标；jiaodu：绘制的角度；step：绘制的精度（步长）；speed：绘制的速度
  * @retval 无
  */

void draw_shun_yuanhu(double x_qi,double y_qi,double xin_x,double xin_y,double jiaodu,unsigned int step,unsigned int speed)
{
	double juli;
	double x_now,y_now;
	double zong;
	double r;
	unsigned char n=0;
	int x_data,y_data;
	x_now=x_qi-xin_x;
	y_now=y_qi-xin_y;
	
	r=sqrt((xin_x-x_qi)*(xin_x-x_qi)+(xin_y-y_qi)*(xin_y-y_qi));
	
	zong=r*jiaodu*0.02222;
	
	while(zong>0)
	{
		juli=x_now*x_now+y_now*y_now-r*r;
		if(x_now>=0&&y_now>0)
		{
			if(juli>=0)
			{
				go_onestep('y',0,step,speed);
				y_now-=one_s*step;
			}
			else
			{
				go_onestep('x',1,step,speed);
				x_now+=one_s*step;
			}
		}
		else if(x_now<0&&y_now>=0)
		{
			if(juli>=0)
			{
				go_onestep('x',1,step,speed);
				x_now+=one_s*step;
			}
			else
			{
				go_onestep('y',1,step,speed);
				y_now+=one_s*step;
			}
		}
		else if(x_now<=0&&y_now<0)
		{
			if(juli>=0)
			{
				go_onestep('y',1,step,speed);
				y_now+=one_s*step;
			}
			else
			{
				go_onestep('x',0,step,speed);
				x_now-=one_s*step;
			}
		}
		else if(x_now>0&&y_now<=0)
		{
			if(juli>=0)
			{
				go_onestep('x',0,step,speed);
				x_now-=one_s*step;
			}
			else 
			{
				go_onestep('y',0,step,speed);
				y_now-=one_s*step;
			}
		}
		n++;
		if(n%100==0)
		{
			x_data=x_now*100;
			y_data=y_now*100;
			show_x_y(x_data,y_data);
		}
		zong-=one_s*step;
		if(stop==1)
		{
			break;
		}
	}
}

