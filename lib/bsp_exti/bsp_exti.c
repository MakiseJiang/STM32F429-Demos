#include "bsp_exti.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == KEY_PIN)
    {
        LED1_TOGGLE;
    }
}

void EXTI_KEY_Config()
{
    /* Enable key button clock */
    KEY_GPIO_CLK_ENABLE();

    /* Configure key button to float input mode */
    GPIO_InitTypeDef GPIO_InitStruct = 
    {
        .Mode = GPIO_MODE_IT_RISING,
        .Pin = KEY_PIN,
        .Pull = GPIO_NOPULL
    };
    HAL_GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);

    /* Set key as NVIC source, and set priority */
    HAL_NVIC_SetPriority(KEY_EXTI_IRQ, 0, 0);
    HAL_NVIC_EnableIRQ(KEY_EXTI_IRQ);
}