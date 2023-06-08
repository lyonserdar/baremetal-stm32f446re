#include "stm32f446re_gpio.h"
#include "stm32f446re.h"

// API
void GPIO_PeriClkControl(GPIOx_t *pGPIOx, uint8_t ENorDI) {
  if (ENorDI == ENABLE) {
    switch ((unsigned long int)pGPIOx) {
    case (unsigned long int)GPIOA:
      GPIOA_PCLK_EN();
      break;
    case (unsigned long int)GPIOB:
      GPIOB_PCLK_EN();
      break;
    case (unsigned long int)GPIOC:
      GPIOC_PCLK_EN();
      break;
    case (unsigned long int)GPIOD:
      GPIOD_PCLK_EN();
      break;
    case (unsigned long int)GPIOE:
      GPIOE_PCLK_EN();
      break;
    case (unsigned long int)GPIOF:
      GPIOF_PCLK_EN();
      break;
    case (unsigned long int)GPIOG:
      GPIOG_PCLK_EN();
      break;
    case (unsigned long int)GPIOH:
      GPIOH_PCLK_EN();
      break;
    default:
      return;
    }
  } else {
    switch ((unsigned long int)pGPIOx) {
    case (unsigned long int)GPIOA:
      GPIOA_PCLK_EN();
      break;
    case (unsigned long int)GPIOB:
      GPIOB_PCLK_EN();
      break;
    case (unsigned long int)GPIOC:
      GPIOC_PCLK_EN();
      break;
    case (unsigned long int)GPIOD:
      GPIOD_PCLK_EN();
      break;
    case (unsigned long int)GPIOE:
      GPIOE_PCLK_EN();
      break;
    case (unsigned long int)GPIOF:
      GPIOF_PCLK_EN();
      break;
    case (unsigned long int)GPIOG:
      GPIOG_PCLK_EN();
      break;
    case (unsigned long int)GPIOH:
      GPIOH_PCLK_EN();
      break;
    default:
      return;
    }
  }
}

// Initialize/Deinitialize
void GPIO_Init(GPIOx_Handle_t *pGPIOHandle) {}
void GPIO_DeInit(GPIOx_t *pGPIOx) {}

// Read/Write
uint8_t GPIO_ReadFromInputPin(GPIOx_t *pGPIOx, uint8_t pinNumber) { return 0; }
uint16_t GPIO_ReadFromInputPort(GPIOx_t *pGPIOx) { return 0; }
void GPIO_WriteToOutputPin(GPIOx_t *pGPIOx, uint8_t pinNumber, uint8_t value) {}
void GPIO_WriteToOutputPort(GPIOx_t *pGPIOx, uint16_t value) {}
void GPIO_ToggleOutputPin(GPIOx_t *pGPIOx, uint8_t pinNumber) {}

// Interrupt
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI) {}
void GPIO_IRQHandle(uint8_t pinNumber) {}
