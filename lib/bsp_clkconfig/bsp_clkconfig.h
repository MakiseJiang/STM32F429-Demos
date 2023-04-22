#ifndef __BSP_CLKCONFIG_H
#define __BSP_CLKCONFIG_H

#include "stm32f4xx_hal.h"
#include "bsp_led.h"

/*
 * @brief   Set Clock source, divide and multiplication factor of PLLCFGR
 */

void HSE_SetSysClock(uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq);

#endif