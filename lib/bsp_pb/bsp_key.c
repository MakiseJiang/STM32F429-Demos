#include "bsp_key.h"

/*
 * @brief   Initialize User button
 */
void KEY_GPIO_Config()
{
    KEY_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = 
    {
        .Pin = KEY_PIN,
        .Mode = GPIO_MODE_INPUT
    };

    HAL_GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

/*
 * @brief   Scan for button push
 * @retval  Button(Key) status
 *    @arg  KEY_ON      Pushed
 *    @arg  KEY_OFF     Released
 */
uint8_t KEY_Pushed(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
    if (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN) == KEY_ON)
    {
        /* Wait for the button to be released */
        while (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN) == KEY_ON);
        return KEY_ON;
    }
    else
    {
        return KEY_OFF;
    }
}