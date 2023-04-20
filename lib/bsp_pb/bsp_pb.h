#include "stm32f4xx_hal.h"

#define PB_ON      1
#define PB_OFF     0

/*
 * @brief   User button port definition group
 */
#define PB_GPIO_PORT               GPIOA
#define PB_PIN                     GPIO_PIN_0
#define PB_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()



/*
 * @brief   Utilities
 */
void PB_GPIO_Config();
uint8_t PB_Pushed(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);