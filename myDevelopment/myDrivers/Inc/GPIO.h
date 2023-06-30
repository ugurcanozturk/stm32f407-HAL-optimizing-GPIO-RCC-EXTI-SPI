/*
 * GPIO.h
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f407xx.h"

                 /* Binary to Hex./ / GPIO PİNS*/

#define GPIO_PIN_0 (uint16_t)(0x0001)     /* PİN 0 SELECTED*/
#define GPIO_PIN_1 (uint16_t)(0x0002)     /* PİN 1 SELECTED*/
#define GPIO_PIN_2 (uint16_t)(0x0004)     /* PİN 2 SELECTED*/
#define GPIO_PIN_3 (uint16_t)(0x0008)     /* PİN 3 SELECTED*/
#define GPIO_PIN_4 (uint16_t)(0x0010)     /* PİN 4 SELECTED*/
#define GPIO_PIN_5 (uint16_t)(0x0020)     /* PİN 5 SELECTED*/
#define GPIO_PIN_6 (uint16_t)(0x0040)     /* PİN 6 SELECTED*/
#define GPIO_PIN_7 (uint16_t)(0x0080)     /* PİN 7 SELECTED*/
#define GPIO_PIN_8 (uint16_t)(0x0100)     /* PİN 8 SELECTED*/
#define GPIO_PIN_9 (uint16_t)(0x0200)     /* PİN 9 SELECTED*/
#define GPIO_PIN_10 (uint16_t)(0x0400)    /* PİN 10 SELECTED*/
#define GPIO_PIN_11 (uint16_t)(0x0800)    /* PİN 11 SELECTED*/
#define GPIO_PIN_12 (uint16_t)(0x1000)    /* PİN 12 SELECTED*/
#define GPIO_PIN_13 (uint16_t)(0x2000)    /* PİN 13 SELECTED*/
#define GPIO_PIN_14 (uint16_t)(0x4000)    /* PİN 14 SELECTED*/
#define GPIO_PIN_15 (uint16_t)(0x8000)    /* PİN 15 SELECTED*/
#define GPIO_PIN_ALL (uint16_t)(0xFFFF)   /* PİN ALL SELECTED*/


                               /* GPIO MODES*/

#define GPIO_MODE_INPUT   (0X0U) // 00: Input (reset state)
#define GPIO_MODE_OUTPUT  (0X1U) // 01: General purpose output mode
#define GPIO_MODE_AF      (0X2U) // 10: Alternate function mode
#define GPIO_MODE_ANALOG  (0X3U) // 11: Analog mode

                              /* GPIO OTYPE MODE*/
#define GPIO_OTYPE_PP     (0X0U)  // 0: Output push-pull (reset state)
#define GPIO_OTYPE_OD     (0X1U)  // 1: Output open-drain

                              /* GPIO SPEED MODE*/
#define GPIO_OSPEEDR_LOW      (0X0U)    // 00: Low speed
#define GPIO_OSPEEDR_MEDIUM   (0X1U)    // 01: Medium speed
#define GPIO_OSPEEDR_HİGH     (0X2U)    // 10: High speed
#define GPIO_OSPEEDR_VERYHIGH (0X3U)    // 11: Very high speed

                             /* GPIO PORT PULL-UP PULL-DOWN MODE*/
#define GPIO_PUPDR_NOPULL   (0X0U)  // 00: No pull-up, pull-down
#define GPIO_PUPDR_PULLUP   (0X1U)  // 01: Pull-up
#define GPIO_PUPDR_PULLDOWN (0X2U)  // 10: Pull-down

             /* Alternate function selection for port x bit */
#define GPIO_AF0     (0x0U)
#define GPIO_AF1     (0x1U)
#define GPIO_AF2     (0x2U)
#define GPIO_AF3     (0x3U)
#define GPIO_AF4     (0x4U)
#define GPIO_AF5     (0x5U)
#define GPIO_AF6     (0x6U)
#define GPIO_AF7     (0x7U)
#define GPIO_AF8     (0x8U)
#define GPIO_AF9     (0x9U)
#define GPIO_AF10    (0xAU)
#define GPIO_AF11    (0xBU)
#define GPIO_AF12    (0xCU)
#define GPIO_AF13    (0xDU)
#define GPIO_AF14    (0xEU)
#define GPIO_AF15    (0xFU)

typedef enum
{
	GPIO_Pin_Reset = 0x0U,
	GPIO_Pin_Set   = !GPIO_Pin_Reset
}GPIO_PinState_t;


typedef struct
{
	uint32_t pinNumber;
	uint32_t Mode;
	uint32_t Otype;
	uint32_t Speed;
	uint32_t Pupd;
	uint32_t Lock;
    uint32_t Alternate;


}GPIO_InitTypedef_t;

        /* GPIO Fonksiyonlarımızın DECLARATİON'U */

void GPIO_Init(GPIO_Typedef_t *GPIOx, GPIO_InitTypedef_t *GPIO_ConfigStuct);
void GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState);
GPIO_PinState_t GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber);
void GPIO_LockPin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber);
void GPIO_TogglePin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber);

#endif /* INC_GPIO_H_ */
