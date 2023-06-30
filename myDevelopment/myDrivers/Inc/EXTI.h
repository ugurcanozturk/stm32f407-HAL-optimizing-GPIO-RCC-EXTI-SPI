/*
 * EXTI.h
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f407xx.h"




              /* Interrupt'un port seçimini configure ettiğimiz macrolar.Bu bilgiyi SCSCFG registerı ile alırız.*/

#define EXTI_PortSource_GPIOA  ((uint8_t)(0x0))
#define EXTI_PortSource_GPIOB  ((uint8_t)(0x1))
#define EXTI_PortSource_GPIOC  ((uint8_t)(0x2))
#define EXTI_PortSource_GPIOD  ((uint8_t)(0x3))
#define EXTI_PortSource_GPIOE  ((uint8_t)(0x4))
#define EXTI_PortSource_GPIOF  ((uint8_t)(0x5))
#define EXTI_PortSource_GPIOG  ((uint8_t)(0x6))
#define EXTI_PortSource_GPIOH  ((uint8_t)(0x7))

             /* Interrupt'ın pin bilgisini configure ettiğimiz macrolar*/

#define EXTI_LineSource_0       ((uint8_t)(0x0))
#define EXTI_LineSource_1       ((uint8_t)(0x1))
#define EXTI_LineSource_2       ((uint8_t)(0x2))
#define EXTI_LineSource_3       ((uint8_t)(0x3))
#define EXTI_LineSource_4       ((uint8_t)(0x4))
#define EXTI_LineSource_5       ((uint8_t)(0x5))
#define EXTI_LineSource_6       ((uint8_t)(0x6))
#define EXTI_LineSource_7       ((uint8_t)(0x7))
#define EXTI_LineSource_8       ((uint8_t)(0x8))
#define EXTI_LineSource_9       ((uint8_t)(0x9))
#define EXTI_LineSource_10      ((uint8_t)(0xA))
#define EXTI_LineSource_11      ((uint8_t)(0xB))
#define EXTI_LineSource_12      ((uint8_t)(0xC))
#define EXTI_LineSource_13      ((uint8_t)(0xD))
#define EXTI_LineSource_14      ((uint8_t)(0xE))
#define EXTI_LineSource_15      ((uint8_t)(0xF))

       /* Mode bilgisini bu şekilde macro olarak tutarız        */
#define EXTI_MODE_Interrupt   (0x00U)  // Interrupt mask register Address offset : 0x00
#define EXTI_MODE_Event       (0x04U)  // Event mask register Address offset : 0x04

      /* Trigger mod bilgisini bu şekilde macro olarak tutarız. */

#define EXTI_Trigger_Rising   (0x08U)  // Rising trigger selection register  Address offset : 0x08
#define EXTI_Trigger_Falling  (0x0CU)  // Falling trigger selection register Address offset : 0x0C
#define EXTI_Trigger_RF       (0X10U)  // Software interrupt event register  Address offset : 0x10 Hem Rising HEM Falling mode.


typedef struct
{
	FunctionalState_t EXTI_LineCmd;    // Hattı aktif mi etmek istiyor kullanıcı yok deaktif mi onun bilgisini tutarız.
	uint8_t LineNumber;                // EXTI Line numberi tutarız bu yapı ile.
	uint8_t  TriggerSelection;
	uint8_t EXTI_Mode;                 // Event or Interrupt

}EXTI_InitTypedef_t;

void EXTI_Init(EXTI_InitTypedef_t *EXTI_InitStruct);   // GPIO GİBİ FARKLI PORTLAR VS OLMADIĞI İÇİN PARAMETRE OLARAK SADECE INIT STRUCT'I ALMAK YETERLİ OLACAKTIR.
void EXTI_LineConfig(uint8_t PortSource ,uint8_t LineSource);
void NVIC_EnableInterrupt(IRQNumber_Typedef_t IRQNumber);          // IRQNumber kullanıcıdan aldığımız position ile hangi birimden Interrupt geldiğini anlarız.

#endif /* INC_EXTI_H_ */
