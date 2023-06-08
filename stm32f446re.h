#ifndef STM32F446RE_H_
#define STM32F446RE_H_

#include <stdint.h>

// Macros
#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET

// Base Addresses of Flash and SRAM Memories
#define FLASH_BASEADDR (uint32_t)0x08000000
#define SRAM1_BASEADDR (uint32_t)0x20000000 // 112KB
#define SRAM2_BASEADDR (uint32_t)0x2001C000 // 16KB
#define ROM_BASEADDR (uint32_t)0x1FFF0000   // System memory
#define SRAM_BASEADDR SRAM1_BASEADDR

// AHBx and APBx Bus Peripheral Base Addresses
#define APB1_PERIPH_BASEADDR (uint32_t)0x40000000
#define APB2_PERIPH_BASEADDR (uint32_t)0x40010000
#define AHB1_PERIPH_BASEADDR (uint32_t)0x40020000
#define AHB2_PERIPH_BASEADDR (uint32_t)0x50000000

// RCC Base Addresses
#define RCC_BASEADDR (AHB1_PERIPH_BASEADDR + 0x3800)

// GPIOx Base Addresses
#define GPIOA_BASEADDR (AHB1_PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1_PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1_PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1_PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1_PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR (AHB1_PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR (AHB1_PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR (AHB1_PERIPH_BASEADDR + 0x1C00)

// I2Cx Base Addresses
#define I2C1_BASEADDR (APB1_PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR (APB1_PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR (APB1_PERIPH_BASEADDR + 0x5C00)

// TIMx Base Addresses
#define TIM1_BASEADDR (APB2_PERIPH_BASEADDR + 0x0000)
#define TIM2_BASEADDR (APB1_PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR (APB1_PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR (APB1_PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR (APB1_PERIPH_BASEADDR + 0x0C00)
#define TIM6_BASEADDR (APB1_PERIPH_BASEADDR + 0x1000)
#define TIM7_BASEADDR (APB1_PERIPH_BASEADDR + 0x1400)
#define TIM8_BASEADDR (APB2_PERIPH_BASEADDR + 0x0400)
#define TIM9_BASEADDR (APB2_PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR (APB2_PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR (APB2_PERIPH_BASEADDR + 0x4800)
#define TIM12_BASEADDR (APB1_PERIPH_BASEADDR + 0x1800)
#define TIM13_BASEADDR (APB1_PERIPH_BASEADDR + 0x1C00)
#define TIM14_BASEADDR (APB1_PERIPH_BASEADDR + 0x2000)

// SPIx Base Addresses
#define SPI1_BASEADDR (APB2_PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR (APB1_PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR (APB1_PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR (APB2_PERIPH_BASEADDR + 0x3400)

// USARTx and UARTx Base Addresses
#define USART1_BASEADDR (APB2_PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR (APB1_PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR (APB1_PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR (APB1_PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR (APB1_PERIPH_BASEADDR + 0x5000)
#define USART6_BASEADDR (APB2_PERIPH_BASEADDR + 0x1400)

// EXTI Base Addresses
#define EXTI_BASEADDR (APB2_PERIPH_BASEADDR + 0x3C00)

// SYSCFG Base Addresses
#define SYSCFG_BASEADDR (APB2_PERIPH_BASEADDR + 0x3800)

// Peripheral Register Definition Structures
// GPIOx Register Definition Structure
typedef struct {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDER;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2]; // AFR[0]: AFRL and AFR[1]: AFRH
} GPIOx_t;

// GPIOx Peripheral Definitions
#define GPIOA ((GPIOx_t *)GPIOA_BASEADDR)
#define GPIOB ((GPIOx_t *)GPIOB_BASEADDR)
#define GPIOC ((GPIOx_t *)GPIOC_BASEADDR)
#define GPIOD ((GPIOx_t *)GPIOD_BASEADDR)
#define GPIOE ((GPIOx_t *)GPIOE_BASEADDR)
#define GPIOF ((GPIOx_t *)GPIOF_BASEADDR)
#define GPIOG ((GPIOx_t *)GPIOG_BASEADDR)
#define GPIOH ((GPIOx_t *)GPIOH_BASEADDR)

// RCC Register Definition Structure
typedef struct {
  volatile uint32_t CR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  volatile uint32_t AHB3RSTR;
  volatile uint32_t RESERVED_0;
  volatile uint32_t APB1RSTR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t RESERVED_1[2];
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  volatile uint32_t AHB3ENR;
  volatile uint32_t RESERVED_2;
  volatile uint32_t APB1ENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t RESERVED_3[2];
  volatile uint32_t AHB1LPENR;
  volatile uint32_t AHB2LPENR;
  volatile uint32_t AHB3LPENR;
  volatile uint32_t RESERVED_4;
  volatile uint32_t APB1LPENR;
  volatile uint32_t APB2LPENR;
  volatile uint32_t RESERVED_5[2];
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
  volatile uint32_t RESERVED_6[2];
  volatile uint32_t SSCGR;
  volatile uint32_t PLLI2SCFGR;
  volatile uint32_t PLLSAICFGR;
  volatile uint32_t DCKCFGR;
  volatile uint32_t CKGATENR;
  volatile uint32_t DCKCFGR2;
} RCC_t;

// RCC Peripheral Definition
#define RCC ((RCC_t *)RCC_BASEADDR)

// Clock Enable Macros for GPIOx peripherals
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7))

// Clock Disable Macros for GPIOx peripherals
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 7))

// Clock Enable Macros for I2Cx peripherals
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

// Clock Disable Macros for I2Cx peripherals
#define I2C1_PCLK_DI() (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 23))

// Clock Enable Macros for SPIx peripherals
#define SPI1_PCLK_EN (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN (RCC->APB2ENR |= (1 << 13))

// Clock Disable Macros for SPIx peripherals
#define SPI1_PCLK_DI (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI (RCC->APB2ENR &= ~(1 << 13))

// Clock Enable Macros for USARTx peripherals
#define USART1_PCLK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN() (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN() (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN() (RCC->APB2ENR |= (1 << 5))

// Clock Disable Macros for USARTx peripherals
#define USART1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI() (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI() (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI() (RCC->APB2ENR &= ~(1 << 5))

// Clock Enable Macros for SYSCFG peripherals
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

// Clock Disable Macros for SYSCFG peripherals
#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1 << 14))

#endif // STM32F446RE_H_
