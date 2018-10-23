#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define ziwei P1
#define ziduan P2
uchar  Led[] = { 0xc0,0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
uchar  hang[] = { 0x01,0x02,0x04,0x08 };
uchar buffer[4];
uint count;
void delay(uint i) {
	unsigned char j,k;
	for (j = 0; j < i; j++) {
		for (k = 0; k < 124; k++);
	}
}
void num() {
	buffer[0] = count / 1000;//千位
	buffer[1] = count / 100 % 10;//百位
	buffer[2] = count / 10 % 10;//十位
	buffer[3] = count % 10;//个位
}
void xianshi() {
	uchar i;
	for (i = 0; i < 4; i++)
	{
		ziwei = hang[i];
		ziduan = Led[buffer[i]];
		delay(4);
		ziwei = 0x00;
	}
}
void main() {
	count = 0;
	IT0 = 1;
	EA = 1;
	EX0 = 1;
	while (1) {
		num();
		xianshi();
	}
}
void INT_0()interrupt 0{
	count++;
}