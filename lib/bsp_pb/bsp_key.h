#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f4xx_hal.h"
#include "stm32f429xx.h"

#define KEY_ON      1
#define KEY_OFF     0

/*
 * @brief   User button port definition group
 */
#define KEY_GPIO_PORT               GPIOA
#define KEY_PIN                     GPIO_PIN_0
#define KEY_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()



/*
 * @brief   Utilities
 */
void KEY_GPIO_Config();
uint8_t KEY_Pushed(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);

#endif