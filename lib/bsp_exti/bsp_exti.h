#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "stm32f4xx_hal.h"
#include "stm32f429xx.h"
#include "bsp_key.h"
#include "bsp_led.h"

#define KEY_IRQHandler          EXTI0_IRQHandler
#define KEY_EXTI_IRQ            EXTI0_IRQn

void EXTI_KEY_Config();
#endif