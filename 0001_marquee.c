/**
 * @file 0000_light.c
 * @author your name (you@domain.com)
 * @brief turn on a light
 * @version 0.1
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <lint.h>
#include <8051.h>

int main() {
    while (1)
    {
        P1=0x01;
        for (int i = 0; i < 8; i++)
        {
            for (int i=0; i<1000; i++) {
                for (int j=0; j<110; j++);
            }
            P1 = P1 << 1;
        }
    }
    return 0;
}