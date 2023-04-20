#include "main.h"

static void SysHalInit_Config();
static void Delay(uint32_t);

int main()
{
    SysHalInit_Config();
    HSE_SetSysClock(25, 336, 2, 7);

    while (1)
    {
        LED1_ON;
        Delay(0x0FFFFF);
        LED1_OFF;
        Delay(0x0FFFFF);
    }
}

/*
 * @brief   Initialize hal drivers and bsp drivers
 */
static void SysHalInit_Config()
{
    HAL_Init();
    LED_GPIO_Config();
}

/*
 * @brief Customized delay function
 */
static void Delay(__IO uint32_t nCount)
{
    for (; nCount != 0; nCount--)
    {
    }
}