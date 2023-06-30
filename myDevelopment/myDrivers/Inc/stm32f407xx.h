/*
 * stm32f407xx.h
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>

   /* Mikroişlemci define yapıları*/

#define NVIC_ISER0  ((uint32_t *)(0xE000E100UL))  // Type-cast ettik ve böylece 1 eklediğimizde 4 byte ilerleme sağlayabileceğiz.

typedef enum
{
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	EXTI4_IRQNumber = 10

}IRQNumber_Typedef_t;

typedef enum
{                        // 0 VEYA 1 YAZDIRMAK YERİNE ENABLE VE DISABLE OLARAK TANIMLADIK ENUM YAPISI İLE.
	DISABLE = 0X0U,
	ENABLE = !DISABLE
}FunctionalState_t;


#define __IO volatile


       /* RCC için kullandığımız macrolar.Enable ve disable için kullanıyoruz*/
#define SET_BIT(REG, BIT)    ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)  ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)   ((REG) & (BIT))
#define UNUSED(x) (void)x

                    /* IRQ Numbers of MCU == Vector Table*/




                       /*       Memory Base Adress */

#define              FLASH_BASE_ADDR            (0X08000000UL)
#define              SRAM1_BASE_ADDR            (0X20000000UL)
#define              SRAM2_BASE_ADDR            (0X2001C000UL)

                      /*      Peripheral Base Adress  */

#define              PERİPH_BASE_ADDR           (0x40000000UL)
#define              APB1_BASE_ADDR             (PERİPH_BASE_ADDR)
#define              APB2_BASE_ADDR             (PERİPH_BASE_ADDR + 0x10000UL)
#define              AHB1_BASE_ADDR             (PERİPH_BASE_ADDR + 0x20000UL)
#define              AHB2_BASE_ADDR             (PERİPH_BASE_ADDR + 0x10000000UL)

                    /*   APB1 Peripheral Base Adress  */

#define              TIM2_BASE_ADDR             (APB1_BASE_ADDR)
#define              TIM3_BASE_ADDR             (APB1_BASE_ADDR + 0x0400UL)
#define              TIM4_BASE_ADDR             (APB1_BASE_ADDR + 0x0800UL)
#define              TIM5_BASE_ADDR             (APB1_BASE_ADDR + 0x0C00UL)
#define              TIM6_BASE_ADDR             (APB1_BASE_ADDR + 0x1000UL)
#define              TIM7_BASE_ADDR             (APB1_BASE_ADDR + 0x1400UL)
#define              TIM12_BASE_ADDR            (APB1_BASE_ADDR + 0x1800UL)
#define              TIM13_BASE_ADDR            (APB1_BASE_ADDR + 0x1C00UL)
#define              TIM14_BASE_ADDR            (APB1_BASE_ADDR + 0x2000UL)
#define              WWDG_BASE_ADDR             (APB1_BASE_ADDR + 0x2C00UL)
#define              SPI2_BASE_ADDR             (APB1_BASE_ADDR + 0x3800UL)
#define              SPI3_BASE_ADDR             (APB1_BASE_ADDR + 0x3C00UL)
#define              USART2_BASE_ADDR           (APB1_BASE_ADDR + 0x4400UL)
#define              USART3_BASE_ADDR           (APB1_BASE_ADDR + 0x4800UL)
#define              UART4_BASE_ADDR            (APB1_BASE_ADDR + 0x4C00UL)
#define              UART5_BASE_ADDR            (APB1_BASE_ADDR + 0x5000UL)
#define              I2C1_BASE_ADDR             (APB1_BASE_ADDR + 0x5400UL)
#define              I2C2_BASE_ADDR             (APB1_BASE_ADDR + 0x5800UL)
#define              CAN1_BASE_ADDR             (APB1_BASE_ADDR + 0x6400UL)
#define              CAN2_BASE_ADDR             (APB1_BASE_ADDR + 0x6800UL)
#define              PWR_BASE_ADDR              (APB1_BASE_ADDR + 0x7000UL)
#define              DAC_BASE_ADDR              (APB1_BASE_ADDR + 0x7400UL)

                            /*  APB2 Peripheral Base Address  */

#define              TIM1_BASE_ADDR             (APB2_BASE_ADDR)
#define              TIM8_BASE_ADDR             (APB2_BASE_ADDR + 0x0400UL)
#define              USART1_BASE_ADDR           (APB2_BASE_ADDR + 0x1000UL)
#define              USART6_BASE_ADDR           (APB2_BASE_ADDR + 0x1400UL)
#define              ADC1_BASE_ADDR             (APB2_BASE_ADDR + 0x2000UL)
#define              ADC2_BASE_ADDR             (APB2_BASE_ADDR + 0x2100UL)
#define              ADC3_BASE_ADDR             (APB2_BASE_ADDR + 0x2200UL)
#define              SPI1_BASE_ADDR             (APB2_BASE_ADDR + 0x3000UL)
#define              SPI4_BASE_ADDR             (APB2_BASE_ADDR + 0x3400UL)
#define              SYSFGC_BASE_ADDR           (APB2_BASE_ADDR + 0x3800UL)
#define              EXTI_BASE_ADDR             (APB2_BASE_ADDR + 0x3C00UL)
#define              SPI5_BASE_ADDR             (APB2_BASE_ADDR + 0x5000UL)
#define              SPI6_BASE_ADDR             (APB2_BASE_ADDR + 0x5400UL)
#define              LTDC_BASE_ADDR             (APB2_BASE_ADDR + 0x6800UL)         /* LCD-TFT DİSPLAY CONTROLLER*/

                           /*  AHB1 Peripheral Base Address   */

#define              GPIOA_BASE_ADDR            (AHB1_BASE_ADDR)
#define              GPIOB_BASE_ADDR            (AHB1_BASE_ADDR + 0x0400UL)
#define              GPIOC_BASE_ADDR            (AHB1_BASE_ADDR + 0x0800UL)
#define              GPIOD_BASE_ADDR            (AHB1_BASE_ADDR + 0x0C00UL)
#define              GPIOE_BASE_ADDR            (AHB1_BASE_ADDR + 0x1000UL)
#define              GPIOF_BASE_ADDR            (AHB1_BASE_ADDR + 0x1400UL)
#define              GPIOG_BASE_ADDR            (AHB1_BASE_ADDR + 0x1800UL)
#define              GPIOH_BASE_ADDR            (AHB1_BASE_ADDR + 0x1C00UL)
#define              GPIOI_BASE_ADDR            (AHB1_BASE_ADDR + 0x2000UL)
#define              GPIOJ_BASE_ADDR            (AHB1_BASE_ADDR + 0x2400UL)
#define              GPIOK_BASE_ADDR            (AHB1_BASE_ADDR + 0x2800UL)
#define              CRC_BASE_ADDR              (AHB1_BASE_ADDR + 0x3000UL)
#define              RCC_BASE_ADDR              (AHB1_BASE_ADDR + 0x3800UL)
#define              DMA1_BASE_ADDR             (AHB1_BASE_ADDR + 0x6000UL)
#define              DMA2_BASE_ADDR             (AHB1_BASE_ADDR + 0x6400UL)
#define              ETHERNET_BASE_ADDR         (AHB1_BASE_ADDR + 0x8000UL)
#define              OTG_HS_BASE_ADDR           (AHB1_BASE_ADDR + 0x20000UL)

                        /*  AHB2 Peripheral Base Address       */

#define             OTG_FS_BASE_ADDR            (AHB2_BASE_ADDR)
#define             DCMI_BASE_ADDR              (AHB2_BASE_ADDR + 0x50000UL)
#define             CRYP_BASE_ADDR              (AHB2_BASE_ADDR + 0x60000UL)
#define             RNG_BASE_ADDR               (AHB2_BASE_ADDR + 0x60800UL)


 /* GPIO registerlarımızı struct yapısı içinde oluşturarak ulaşabiliyoruz.*/

typedef struct
{
	__IO uint32_t MODER;                   /* GPIO port mode register               Address offset : 0x00  */
	__IO uint32_t OTYPER;                  /* GPIO port output type register        Address offset : 0x04  */
	__IO uint32_t OSPEEDR;                 /* GPIO port output speed register       Address offset : 0x08  */
	__IO uint32_t PUPDR;                   /* GPIO port pull-up/pull-down register  Address offset : 0x0C  */
	__IO uint32_t IDR;                     /* GPIO port input data register         Address offset : 0x10  */
	__IO uint32_t ODR;                     /* GPIO port output data register        Address offset : 0x14  */
	__IO uint32_t BSRR;                    /* GPIO port bit set/reset register      Address offset : 0x18  */
	__IO uint32_t LCKR;                    /* GPIO port configuration lock register Address offset : 0x1C  */
	__IO uint32_t AFR[2];                  /* GPIO alternate function LOW/HİGH                             */




}GPIO_Typedef_t;

                    /* RCC Register Struct yapısı*/

typedef struct
{
	__IO uint32_t CR;                     /* RCC clock control register                                    Address offset: 0x00 */
	__IO uint32_t PLLCFGR;                /* RCC PLL configuration register                                Address offset: 0x04 */
	__IO uint32_t CFGR;                   /* RCC clock configuration register                              Address offset: 0x08 */
	__IO uint32_t CIR;                    /* RCC clock interrupt register                                  Address offset: 0x0C */
	__IO uint32_t AHB1RSTR;               /* RCC AHB1 peripheral reset register                            Address offset: 0x10 */
	__IO uint32_t AHB2RSTR;               /* RCC AHB2 peripheral reset register                            Address offset: 0x14 */
	__IO uint32_t AHB3RSTR;               /* RCC AHB3 peripheral reset register                            Address offset: 0x18 */
	__IO uint32_t RESERVED0;              /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t APB1RSTR;               /* RCC APB1 peripheral reset register                            Address offset: 0x20 */
	__IO uint32_t APB2RSTR;               /* RCC APB2 peripheral reset register                            Address offset: 0x24 */
	__IO uint32_t RESERVED1[2];           /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t AHB1ENR;                /* RCC AHB1 peripheral clock enable register                     Address offset: 0x30 */
	__IO uint32_t AHB2ENR;                /* RCC AHB2 peripheral clock enable register                     Address offset: 0x34 */
	__IO uint32_t AHB3ENR;                /* RCC AHB3 peripheral clock enable register                     Address offset: 0x38 */
	__IO uint32_t RESERVED2;              /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t APB1ENR;                /* RCC APB1 peripheral clock enable register                     Address offset: 0x40 */
	__IO uint32_t APB2ENR;                /* RCC APB2 peripheral clock enable register                     Address offset: 0x44 */
	__IO uint32_t RESERVED3[2];           /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t AHB1LPENR;              /* RCC AHB1 peripheral clock enable in low power mode register   Address offset: 0x50 */
	__IO uint32_t AHB2LPENR;              /* RCC AHB2 peripheral clock enable in low power mode register   Address offset: 0x54 */
	__IO uint32_t AHB3LPENR;              /* RCC AHB3 peripheral clock enable in low power mode register   Address offset: 0x58 */
	__IO uint32_t RESERVED4;              /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t APB1LPENR;              /* RCC APB1 peripheral clock enable in low power mode register   Address offset: 0x60 */
	__IO uint32_t APB2LPENR;              /* RCC APB2 peripheral clock enable in low power mode register   Address offset: 0x64 */
	__IO uint32_t RESERVED5[2];           /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t BDCR;                   /* RCC Backup domain control register                            Address offset: 0x70 */
	__IO uint32_t CSR;                    /* RCC clock control & status register                           Address offset: 0x74 */
	__IO uint32_t RESERVED6[2];           /* RESERVED                                                      Address offset: 0x00 */
	__IO uint32_t SSCGR;                  /* RCC spread spectrum clock generation register                 Address offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;             /* RCC PLLI2S configuration register                             Address offset: 0x84 */

}RCC_Typedef_t;

typedef struct
{
	__IO uint32_t MEMRMP;                 /* SYSCFG memory remap register                     Address offset: 0x00   */
	__IO uint32_t PMC;                    /* SYSCFG peripheral mode configuration register    Address offset: 0x04   */
	__IO uint32_t EXTI_CR[4];             /* SYSCFG external interrupt configuration register Address offset: 0x08   */
	__IO uint32_t CMPCR;                  /* Compensation cell control register               Address offset: 0x20*/

}SYSCFG_Typedef_t;

typedef struct
{
	__IO uint32_t IMR;                    /* Interrupt mask register               Address offset: 0x00 */
	__IO uint32_t EMR;                    /* Event mask register                   Address offset: 0x04 */
	__IO uint32_t RTSR;                   /* Rising trigger selection register     Address offset: 0x08 */
	__IO uint32_t FTSR;                   /* Falling trigger selection register    Address offset: 0x0C */
	__IO uint32_t SWIER;                  /* Software interrupt event register     Address offset: 0x10 */
	__IO uint32_t PR;                     /* Pending register                      Address offset: 0x14 */

}EXTI_Typedef_t;

typedef struct
{
	__IO uint32_t SR;          /* ADC status register                                                Address offset: 0x00      */
	__IO uint32_t CR[2];       /* ADC control register                                               Address offset: 0x04      */
	__IO uint32_t SMPR[2];     /* ADC sample time register                                           Address offset: 0x0C      */
	__IO uint32_t JOFR[4];     /* ADC injected channel data offset register                          Address offset: 0x14-0x20 */
	__IO uint32_t HTR;         /* ADC watchdog higher threshold register                             Address offset: 0x24      */
	__IO uint32_t LTR;         /* ADC watchdog lower threshold register                              Address offset: 0x28      */
	__IO uint32_t SQR[3];      /* ADC regular sequence register                                      Address offset: 0x2C      */
	__IO uint32_t JSQR;        /* ADC injected sequence register                                     Address offset: 0x38      */
	__IO uint32_t JDR[4];      /* ADC injected data register                                         Address offset: 0x3C-0x48 */
	__IO uint32_t DR;          /* ADC regular data register                                          Address offset: 0x4C      */

}ADC_Typedef_t;

typedef struct
{
	__IO uint32_t CSR;
	__IO uint32_t CCR;
	__IO uint32_t CDR;
}ADC_Common_Typedef_t;

typedef struct
{
	__IO uint32_t CR1;           /* SPI control register 1         Address offset: 0x00*/
	__IO uint32_t CR2;           /* SPI control register 2         Address offset: 0x04*/
	__IO uint32_t SR;            /* SPI status register            Address offset: 0x08*/
	__IO uint32_t DR;            /* SPI data register              Address offset: 0x0C*/
	__IO uint32_t CRCPR;         /* SPI CRC polynomial register    Address offset: 0x10*/
	__IO uint32_t RXCRCR;        /* SPI RX CRC register            Address offset: 0x14*/
	__IO uint32_t TXCRCR;        /* SPI TX CRC register            Address offset: 0x18*/
	__IO uint32_t I2SCFGR;       /* SPI_I2S configuration register Address offset: 0x1C*/
	__IO uint32_t I2SPR;         /* SPI_I2S prescaler register     Address offset: 0x20*/

}SPI_Typedef_t;

/* STRUCT YAPISI İÇİNDEKİ REGİSTERLARIMIZIN ADRESLERİNİ GPIO PORTLARIMIZIN BASE ADRESLERİ İLE TYPE-CASTİNG YAPARAK
    PORTLARIMIZIN REGİSTER YAPISINI OLUŞTURDUK      */

#define GPIOA  ((GPIO_Typedef_t *)(GPIOA_BASE_ADDR))
#define GPIOB  ((GPIO_Typedef_t *)(GPIOB_BASE_ADDR))
#define GPIOC  ((GPIO_Typedef_t *)(GPIOC_BASE_ADDR))
#define GPIOD  ((GPIO_Typedef_t *)(GPIOD_BASE_ADDR))
#define GPIOE  ((GPIO_Typedef_t *)(GPIOE_BASE_ADDR))
#define GPIOF  ((GPIO_Typedef_t *)(GPIOF_BASE_ADDR))
#define GPIOG  ((GPIO_Typedef_t *)(GPIOG_BASE_ADDR))
#define GPIOH  ((GPIO_Typedef_t *)(GPIOH_BASE_ADDR))
#define GPIOI  ((GPIO_Typedef_t *)(GPIOI_BASE_ADDR))
#define GPIOJ  ((GPIO_Typedef_t *)(GPIOJ_BASE_ADDR))
#define GPIOK  ((GPIO_Typedef_t *)(GPIOK_BASE_ADDR))

#define RCC    ((RCC_Typedef_t *)(RCC_BASE_ADDR  ))

#define SYSCFG ((SYSCFG_Typedef_t *)( SYSFGC_BASE_ADDR))
#define EXTI   ((EXTI_Typedef_t   *)( EXTI_BASE_ADDR  ))

#define SPI1   ((SPI_Typedef_t *)(SPI1_BASE_ADDR ))
#define SPI2   ((SPI_Typedef_t *)(SPI2_BASE_ADDR ))
#define SPI3   ((SPI_Typedef_t *)(SPI3_BASE_ADDR ))
#define SPI4   ((SPI_Typedef_t *)(SPI4_BASE_ADDR ))


                           /* Bit Definitions */

/* Maskeleme işlemini bu yapı ile yaparız,bit definition işlemini yaparız.
    Böylece hangi bitteyse orayı enable ederiz.Ayrıca elle manuel tek tek yapmak yerine daha profesyonelce bir yazım şeklidir.*/

#define RCC_AHB1ENR_GPIOAEN_Pos    (0U)                                    // RCC AHB1ENR register GPIOAEN Bit position
#define RCC_AHB1ENR_GPIOAEN_Msk    (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)      // RCC AHB1ENR register GPIOAEN Msk position
#define RCC_AHB1ENR_GPIOAEN        RCC_AHB1ENR_GPIOAEN_Msk                 // RCC AHB1ENR register GPIOAEN Macro

#define RCC_AHB1ENR_GPIOBEN_Pos    (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk    (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)
#define RCC_AHB1ENR_GPIOBEN        RCC_AHB1ENR_GPIOBEN_Msk

#define RCC_AHB1ENR_GPIOC_Pos      (2U)
#define RCC_AHB1ENR_GPIOC_Msk      (0x1UL << RCC_AHB1ENR_GPIOC_Pos)
#define RCC_AHB1ENR_GPIOCEN        RCC_AHB1ENR_GPIOC_Msk

#define RCC_AHB1ENR_GPIOD_Pos      (3U)
#define RCC_AHB1ENR_GPIOD_Msk      (0X1UL << RCC_AHB1ENR_GPIOD_Pos)
#define RCC_AHB1ENR_GPIODEN        RCC_AHB1ENR_GPIOD_Msk

#define RCC_AHB1ENR_GPIOE_Pos      (4U)
#define RCC_AHB1ENR_GPIOE_Msk      (0x1UL << RCC_AHB1ENR_GPIOE_Pos)
#define RCC_AHB1ENR_GPIOEEN        RCC_AHB1ENR_GPIOE_Msk
                  /* SYSCFG Bit Definition */
#define RCC_APB2ENR_SYSCFGEN_Pos    (14U)                                 // RCC APB2 register SYSCFGEN Bit position
#define RCC_APB2ENR_SYSCFGEN_Msk    (0x1U << RCC_APB2ENR_SYSCFGEN_Pos)    // RCC APB2 register SYSCFGEN Maskelemesi.
#define RCC_APB2ENR_SYSCFGEN        RCC_APB2ENR_SYSCFGEN_Msk              // RCC APB2 register SYSCFGEN Macro.
                  /* SPI1 Bit Definition */
#define RCC_APB2ENR_SPI1EN_Pos      (12U)                                // RCC APB2 register SPI1EN Bit position.
#define RCC_APB2ENR_SPI1EN_Msk      (0x1U << RCC_APB2ENR_SPI1EN_Pos)     // RCC APB2 register SPI1EN Maskelemesi
#define RCC_APB2ENR_SPI1EN          RCC_APB2ENR_SPI1EN_Msk               // RCC APB2 register SPI1EN Macro.

                   /* SPI2 Bit Definition */
#define RCC_APB1ENR_SPI2EN_Pos      (14U)
#define RCC_APB1ENR_SPI2EN_Msk      (0x1U << RCC_APB1ENR_SPI2EN_Pos)
#define RCC_APB1ENR_SPI2EN          RCC_APB1ENR_SPI2EN_Msk

                   /* SPI3 Bit Definition */
#define RCC_APB1ENR_SPI3EN_Pos      (15U)
#define RCC_APB1ENR_SPI3EN_Msk      (0x1U << RCC_APB1ENR_SPI3EN_Pos )
#define RCC_APB1ENR_SPI3EN          RCC_APB1ENR_SPI3EN_Msk

                   /* SPI Flag Definition */

#define SPI_RXNE_Flag              (0U)            // Receive buffer not empty 0:Rx buffer empty
#define SPI_TXE_Flag               (0x1U << 1U)    // Transmit buffer empty    1:Tx buffer empty
#define SPI_BSY_Flag               (0x1U << 7U)    // Busy flag                1:SPI (or I2S) is busy in communication or Tx buffer is not empty


#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"

#include "SPI.h"
#endif /* INC_STM32F407XX_H_ */
