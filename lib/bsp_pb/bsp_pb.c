#include "bsp_pb.h"

/*
 * @brief   Initialize User button
 */
void PB_GPIO_Config()
{
    KEY_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = 
    {
        .Pin = PB_PIN,
        .Mode = GPIO_MODE_INPUT
    };

    HAL_GPIO_Init(PB_GPIO_PORT, &GPIO_InitStruct);
}

/*
 * @brief   Scan for button push
 * @retval  Button(Key) status
 *    @arg  KEY_ON      Pushed
 *    @arg  KEY_OFF     Released
 */
uint8_t Key_Pushed(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
    if (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN) == PB_ON)
    {
        /* Wait for the button to be released */
        while (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN) == PB_ON);
        return PB_ON;
    }
    else
    {
        return PB_OFF;
    }
}