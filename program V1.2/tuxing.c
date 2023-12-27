#include <draw.h>
#include <REGX51.H>
#include "LED.h"
/**
  * @brief  LED点阵屏显示菜单功能函数
  * @param  要显示的图形号
  * @retval 无
  */
void show_fx(unsigned char n)
{
	unsigned char up[8]={0x00,0x10,0x20,0x7E,0x7E,0x20,0x10,0x00};
	unsigned char down[8]={0x00,0x08,0x04,0x7E,0x7E,0x04,0x08,0x00};
	unsigned char left[8]={0x00,0x18,0x3C,0x5A,0x18,0x18,0x18,0x00};
	unsigned char right[8]={0x00,0x18,0x18,0x18,0x5A,0x3C,0x18,0x00};
	unsigned char xiaolian[8]={0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C};
	unsigned char ok[8]={0x3E,0x22,0x3E,0x00,0x3E,0x18,0x24,0x02};
	unsigned char stop[8]={0x00,0x00,0x00,0xFB,0xFB,0x00,0x00,0x00};
	unsigned char huitu[8]={0x3E,0x08,0x08,0x3E,0x00,0x20,0x3E,0x20};
	unsigned char i;
	if(n==1)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,up[i]);
		}
	}
	else if(n==2)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,down[i]);
		}
	}
	else if(n==3)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,left[i]);
		}
	}
	else if(n==4)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,right[i]);
		}
	}
	else if(n==5)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,xiaolian[i]);
		}
	}
	else if(n==6)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,ok[i]);
		}
	}
	else if(n==7)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,stop[i]);
		}
	}
	else if(n==8)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,huitu[i]);
		}
	}
}

/**
  * @brief  LED点阵屏显示绘制图形函数
  * @param  要显示的绘制图形，详细见函数本身
  * @retval 无
  */
void show_tx(unsigned char a)
{
	unsigned char sanjiao[8]={0x20,0x30,0x28,0x24,0x28,0x30,0x20,0x00};
	unsigned char yuan[8]={0x18,0x24,0x42,0x81,0x81,0x42,0x24,0x18};
	unsigned char zhengfangx[8]={0x00,0x7E,0x42,0x42,0x42,0x42,0x7E,0x00};
	unsigned char fz[8]={0x7E,0xC3,0xBD,0xA5,0xA5,0xBD,0xC3,0x7E};
	unsigned char xin[8]={0x30,0x78,0x7C,0x3E,0x3E,0x7C,0x78,0x30};
	unsigned char i;
	if(a==1)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,sanjiao[i]);
		}
	}
	else if(a==2)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,yuan[i]);
		}
	}
	else if(a==3)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,zhengfangx[i]);
		}
	}
	else if(a==4)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,fz[i]);
		}
	}
	else if(a==5)
	{
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,xin[i]);
		}
	}
}
/**
  * @brief  三角图形绘制函数
  * @param  速度
  * @retval 无
  */
void sanjiao(unsigned char speed)
{
	draw_zhixian(0,0,2,2,50,speed);
	draw_zhixian(2,2,-2,2,50,speed);
	draw_zhixian(-2,2,0,0,50,speed);
}
/**
  * @brief  正方形绘制函数
  * @param  速度
  * @retval 无
  */
void zhengfangxing(unsigned char speed)
{
	draw_zhixian(0,0,-2,0,50,speed);
	draw_zhixian(-2,0,-2,-2,50,speed);
	draw_zhixian(-2,-2,0,-2,50,speed);
	draw_zhixian(0,-2,0,0,50,speed);
}
/**
  * @brief  顺圆绘制函数
  * @param  无
  * @retval 无
  */
void yuan(void)
{
	draw_shun_yuanhu(0,2,0,0,360,10,7);
}
