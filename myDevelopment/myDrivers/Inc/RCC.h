/*
 * RCC.h
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"



/* GPIOA HATTININ CLOCK HATTINI ENABLE ETTİĞİMİZ FUNCTİON MACRO. */
/* VALUE DEĞİŞKENİNE OKUMA READ_BIT İLE OKUMA YAPARAK İŞLEMCİYE VAKİT KAZANDIRDIK RCC HATTINI AKTİFLEŞTİRMESİ İÇİN*/
/* VALUE'YI KULLANMADIĞIMIZ İÇİN WARNİNG VERMESİN DİYE UNUSED DİYE BOŞ BİR FONKSİYON TANIMLAYARAK ONUN İÇİNE ATTIK DEĞERİ*/

#define RCC_GPIOA_CLK_ENABLE()    do{     __IO uint32_t value = 0;                                 \
                                           SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);             \
                                           value = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);    \
                                           UNUSED(value);                                          \
	                                 }while(0);

#define RCC_GPIOB_CLK_ENABLE()  do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);              \
                                           tempValue = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN); \
                                           UNUSED(tempValue);                                       \
	                                 }while(0);

#define RCC_GPIOC_CLK_ENABLE()  do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);              \
                                           tempValue = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN); \
                                           UNUSED(tempValue);                                       \
	                                 }while(0);

#define RCC_GPIOD_CLK_ENABLE()  do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);              \
                                           tempValue = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN); \
                                           UNUSED(tempValue);                                       \
	                                 }while(0);

#define RCC_GPIOE_CLK_ENABLE()  do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN);              \
                                           tempValue = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN); \
                                           UNUSED(tempValue);                                       \
	                                 }while(0);

                   /* SPI Function Enable macroların tanımlanması */
#define RCC_SPI1_CLK_ENABLE()    do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);                \
                                           tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);   \
                                           UNUSED(tempValue);                                        \
	                                 }while(0);

#define RCC_SPI1_CLK_DISABLE()      CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN)


#define RCC_SPI2_CLK_ENABLE()    do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);                \
                                           tempValue = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);   \
                                           UNUSED(tempValue);                                        \
	                                 }while(0);

#define RCC_SPI2_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN)

#define RCC_SPI3_CLK_ENABLE()    do{        __IO uint32_t tempValue = 0;                             \
                                           SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);                \
                                           tempValue = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);   \
                                           UNUSED(tempValue);                                        \
	                                 }while(0);

#define RCC_SPI3_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN)



#define RCC_GPIOA_CLK_DİSABLE()       CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
#define RCC_GPIOB_CLK_DİSABLE()       CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
#define RCC_GPIOC_CLK_DİSABLE()       CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
#define RCC_GPIOD_CLK_DİSABLE()       CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);
#define RCC_GPIOE_CLK_DİSABLE()       CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN);

             /* SYSCFG Registerının Clock hattının enable edilmesi için Function Macro.*/

#define RCC_SYSCFG_CLK_ENABLE() do{           __IO uint32_t tempValue = 0;                                          \
                                               SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);                         \
											   tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);			\
												UNUSED(tempValue);					                                \
                                 }while(0);

#endif /* INC_RCC_H_ */
