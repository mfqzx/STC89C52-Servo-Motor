#ifndef __DRAW__H__
#define __DRAW__H__



void go_onestep(unsigned char zhou,unsigned int fangxiang,unsigned int step,unsigned int speed);
void draw_zhixian(double x_qi,double y_qi,double x_end,double y_end,unsigned int step,unsigned int speed);
void draw_shun_yuanhu(double x_qi,double y_qi,double xin_x,double xin_y,double jiaodu,unsigned int step,unsigned int speed);
extern unsigned char stop;
#endif