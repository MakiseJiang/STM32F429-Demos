#include "stm32f4xx_hal.h"
#include "bsp_key.h"
#include "bsp_led.h"

void SysHalInit_Config();

int main()
{
    SysHalInit();

    while (1)
    {
        if (Key_Pushed(KEY_GPIO_PORT, KEY_PIN) == KEY_ON)
        {
            LED1_TOGGLE;
        }
    }
    
}

void SysHalInit_Config()
{
    HAL_Init();
    LED_GPIO_Config();
    Key_GPIO_Config();
}

void SysTick_Handler()
{
    HAL_IncTick();
}