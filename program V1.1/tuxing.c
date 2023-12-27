#include <draw.h>
#include <REGX51.H>

/**
  * @brief  绘制线段
  * @param  长度，精度，速度
  * @retval 无
  */
void Line_x(double l,unsigned char pre,unsigned char speed)
{
	draw_zhixian(0,0,l,0,pre,speed);
}
void Line_y(double l,unsigned char pre,unsigned char speed)
{
	draw_zhixian(0,0,0,l,pre,speed);
}
/**
  * @brief  绘制正方形
  * @param  绘制边长，绘制精度，绘制速度
  * @retval 无
  */
void zhengfangxing(double bianchang,unsigned char pre,unsigned char speed)
{
	draw_zhixian(0,0,-bianchang,0,pre,speed);
	draw_zhixian(-bianchang,0,-bianchang,-bianchang,pre,speed);
	draw_zhixian(-bianchang,-bianchang,0,-bianchang,pre,speed);
	draw_zhixian(0,-bianchang,0,0,pre,speed);
}
/**
  * @brief  绘制苹果
  * @param  无
  * @retval 无
  */

void pingguo(void)
{
	draw_shun_yuanhu(0,0.5,0.865,0,120,10,6);	
	draw_shun_yuanhu(1.73,0.5,0,-0.5,90,10,6);
	draw_shun_yuanhu(1,-2.23,0.5,-1.365,60,10,6);
	draw_shun_yuanhu(0,-2.23,-0.5,-1.365,60,10,6);
	draw_shun_yuanhu(-1,-2.23,0,-0.5,90,10,6);
	draw_shun_yuanhu(-1.73,0.5,-0.865,0,120,10,6);
	draw_zhixian(0,0.5,-0.866,2,50,7);
	draw_zhixian(-0.866,2,-1.73,2,50,7);
	draw_zhixian(-1.73,2,0,0.5,50,7);
	draw_zhixian(0,0.5,0.433,1.25,50,7);
	draw_zhixian(0.433,1.25,0.865,1.25,50,7);
	draw_zhixian(0.865,1.25,0,0.5,50,7);
	draw_shun_yuanhu(0,0.5,1.73,0.5,90,10,6);
			
}