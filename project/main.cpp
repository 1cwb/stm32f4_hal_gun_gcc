#include "stm32f4xx_hal.h"
#include "sys.h"
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "usart.h"
#include "led.h"
using namespace  std;


void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
    while(nCount--){}
}

int main(void)
{
    
    HAL_Init(); //初始化 HAL 库
    Stm32_Clock_Init(25,384,4,8); //设置时钟,96Mhz
    delay_init(HAL_RCC_GetHCLKFreq()/1000000);//1US跑的tick数
    uart_init(115200);
    led_init();

    printf("==========================================================\n");
    while(1)
    {
        led_off();
        delay_ms(1000);
        led_on();
        delay_ms(1000);
    }
    return 0;
}