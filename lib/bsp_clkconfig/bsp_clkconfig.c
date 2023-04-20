#include "bsp_clkconfig.h"

static void Error_Handler();

/*
 * @brief   Set System clock and AHB, APB clock by HSE
 * @param   (in "bsp_clkconfig.h") PLL_P, PLL_Q, PLL_M, PLL_N values
 */
void HSE_SetSysClock(uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq)
{
    /* Enable Power Control clock */
    __HAL_RCC_PWR_CLK_ENABLE();

    /* Optimizing power consumption */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /* -1- Config HSE use OscInitStruct */
    RCC_OscInitTypeDef RCC_OscInitStruct =
    {
        .OscillatorType = RCC_OSCILLATORTYPE_HSE,
        .HSEState = RCC_HSE_ON,
        .PLL.PLLSource = RCC_PLLSOURCE_HSE,
        .PLL.PLLState = RCC_PLL_ON,
        .PLL.PLLM = pllm,
        .PLL.PLLN = plln,
        .PLL.PLLP = pllp,
        .PLL.PLLQ = pllq
    };
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        /* Initialization failed */
        Error_Handler();
    }

    /* -2- Select PLL as system clock source and configure the HCLK, PCLK1, PCLK2 clocks dividers */
    RCC_ClkInitTypeDef RCC_ClkInitStruct = 
    {
        .ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2),
        .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK,
        .AHBCLKDivider = RCC_SYSCLK_DIV1,
        .APB1CLKDivider = RCC_HCLK_DIV4,
        .APB2CLKDivider = RCC_HCLK_DIV2
    };
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
        /* Initialization failed */
        Error_Handler();
    }
}

/*
 * @brief   This function is called in case of error occurence
 */
static void Error_Handler()
{
    LED2_ON;
    while (1)
    {
    }
}