#ifndef __MATRIXKEY_H__
#define __MATRIXKEY_H__

sbit k1=P3^1;	
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

unsigned char getnumber();
void gongneng(unsigned char speed);
unsigned char keypros();
void Int1Init();
void Int0Init();
#endif
