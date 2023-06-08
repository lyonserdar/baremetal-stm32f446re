#ifndef STM32F446RE_GPIO_H_
#define STM32F446RE_GPIO_H_

#include "stm32f446re.h"
#include <stdint.h>

// Configuration structure for a GPIO pin
typedef struct {
  uint8_t GPIO_PinNumber;
  uint8_t GPIO_PinMode;
  uint8_t GPIO_PinSpeed;
  uint8_t GPIO_PinPuPdControl;
  uint8_t GPIO_PinOPType;
  uint8_t GPIO_PinAltFunMode;
} GPIOx_PinConfig_t;

// Handle structure for GPIOx
typedef struct {
  GPIOx_t *pGPIOx;
  GPIOx_PinConfig_t GPIO_PinConfig;
} GPIOx_Handle_t;

// GPIO Pin Modes
#define GPIO_Mode_IN 0
#define GPIO_Mode_OUT 1
#define GPIO_Mode_ALTFN 2
#define GPIO_Mode_ANALOG 3

// API
// Clock Setup
void GPIO_PeriClkControl(GPIOx_t *pGPIOx, uint8_t ENorDI);

// Initialize/Deinitialize
void GPIO_Init(GPIOx_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIOx_t *pGPIOx);

// Read/Write
uint8_t GPIO_ReadFromInputPin(GPIOx_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIOx_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIOx_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIOx_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIOx_t *pGPIOx, uint8_t pinNumber);

// Interrupt
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI);
void GPIO_IRQHandle(uint8_t pinNumber);

#endif /* STM32F446RE_GPIO_H_ */
