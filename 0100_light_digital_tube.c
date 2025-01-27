/**
 * @file 0100_light_digital_tube.c
 * @author Ming Li (fox20431@gmail.com)
 * @brief light "0123" on the digital tube
 * @version 0.1
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <lint.h>
#include <8051.h>

#define uchar unsigned char

unsigned char table[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void delay(uchar n) // 使用for循环达到阻塞效果 n的单位近似ms
{
  for(int i=0;i<n;i++) {
    for(int j=0;j<440;j++); // 循环数经验所得，可根据具体情况调整
  }
}

void display()
{

    // set 0 disable those digital tubes
    P2_0 = 0;
    P2_1 = 0;
    P2_2 = 0;
    P2_3 = 0;

    // pass P0 the sign on how to light up the digital tube
    P0 = table[7];
    P2_0 = 1;
    delay(1000);

    P0 = table[8];
    P2_1 = 1;
    delay(1000);


    P0 = table[7];
    P2_2 = 1;
    delay(1000);

    P0 = table[8];
    P2_3 = 1;
    delay(1000);
}

int main()
{
    unsigned int a;

    while (1)
    {
        for (a = 100; a > 0; a--)
        {
            display();
        }
    }
}
