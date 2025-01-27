#include <8052.h>

// 定时器由High和Low两个寄存器组成，预存入数据使得50um寄存器溢出
// 晶振11.0592MHz，一个机器周期为12个时钟频率
// 所以定时器的寄存器+1所需要时间为12*(1/11059200)=1.09us
// 所以预存入的数为 5000/1.09=45872
// 寄存器应该写入的数：
#define d_time (65536 - 45872)
const unsigned char tl = d_time & 0xFF;
const unsigned char th = (d_time >> 8) & 0xFF;
 
volatile unsigned char i = 0;
 
void main(void) {
  TMOD= 0x01; //工作方式为16位定时器
  TH0 = th;   //计数寄存器高8位
  TL0 = tl;   //计数寄存器低8位
  EA  = 1;    //允许中断
  ET0 = 0x01; //允许T0中断
  TR0 = 1;    //启动T0
  while(1);
}
 
void Timer0IRQ(void) __interrupt (1) // 中断处理函数 T0 -> 中断1
{
  i++;
  if(i > 20) {
    P1_0 = (P1_0 == 1)? 0 : 1; //触发P0.7 LED闪烁
    i = 1; // 注意这边不能初始化为0, 否则每次会多跑一个中断
  }
  TH0 = th; //计数寄存器高8 位重新载入
  TL0 = tl; //计数寄存器低8 位重新载入
}