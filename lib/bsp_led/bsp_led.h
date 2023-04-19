#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f4xx_hal.h"

/*
 * @brief   User LED port definition groups
 */
#define LED_GPIO_PORT               GPIOG
#define LED_PIN_1                   GPIO_PIN_13
#define LED_PIN_2                   GPIO_PIN_14
#define LED_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOG_CLK_ENABLE()

/*
 * @brief   Utilities
 */
#define LED1_ON                     HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN_1, GPIO_PIN_RESET)
#define LED1_OFF                    HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN_1, GPIO_PIN_SET)
#define LED1_TOGGLE                 HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN_1)

#define LED2_ON                     HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN_2, GPIO_PIN_RESET)
#define LED2_OFF                    HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN_2, GPIO_PIN_SET)
#define LED2_TOGGLE                 HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN_2)

void LED_GPIO_Config();








#endif