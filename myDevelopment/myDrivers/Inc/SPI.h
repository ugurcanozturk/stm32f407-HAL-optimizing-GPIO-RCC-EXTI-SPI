/*
 * SPI.h
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f407xx.h"


typedef enum
{
	SPI_FLAG_RESET = 0x0U,
	SPI_FLAG_SET = !SPI_FLAG_RESET
}SPI_FlagStatus_t;

                                  /* SPI BaudRate Macro*/
/* DataSheet'te BaudRate config yapabilmek için CR1 registerın 3,4,5. bitlerine veri yazdırmamız gerekiyor. */
/* Hangi bitte 1 olduğuna göre binary olan sayımızın Hex karşılığını Macromuza veririz ve 32 bit int ile type-cast ederiz.*/

#define SPI_BAUDRATE_DIV2   ((uint32_t)(0x00000000))  // 000: fPCLK/2
#define SPI_BAUDRATE_DIV4   ((uint32_t)(0x00000008))  // 001: fPCLK/4
#define SPI_BAUDRATE_DIV8   ((uint32_t)(0x00000010))  // 010: fPCLK/8
#define SPI_BAUDRATE_DIV16  ((uint32_t)(0x00000018))  // 011: fPCLK/16
#define SPI_BAUDRATE_DIV32  ((uint32_t)(0x00000020))  // 100: fPCLK/32
#define SPI_BAUDRATE_DIV64  ((uint32_t)(0x00000028))  // 101: fPCLK/64
#define SPI_BAUDRATE_DIV128 ((uint32_t)(0x00000030))  // 110: fPCLK/128
#define SPI_BAUDRATE_DIV256 ((uint32_t)(0x00000038))  // 111: fPCLK/256

     /* CPHA Configurasyonu ile datanın hangi Edge'de yani köşede yakalanacağını seçeriz*/
                                  /* SPI CPHA Macro Bit 0 CPHA: Clock phase */

#define SPI_CPHA_FİRST      ((uint32_t)(0x00000000))  // 0: The first clock transition is the first data capture edge
#define SPI_CPHA_SECOND     ((uint32_t)(0x00000001))  // 1: The second clock transition is the first data capture edge

                            /* SPI CPOL Macro Bit1 CPOL: Clock polarity */

#define SPI_CPOL_LOW        ((uint32_t)(0x00000000))  // 0: CK to 0 when idle
#define SPI_CPOL_HIGH       ((uint32_t)(0x00000002))  // 1: CK to 1 when idle

                           /* SPI Mode Selection Macro  Bit 2 MSTR: Master selection*/

#define SPI_SLAVE_SELECTİON  ((uint32_t)(0x00000000)) // 0: Slave configuration
#define SPI_MASTER_SELECTİON ((uint32_t)(0x00000004)) // 1: Master configuration

                          /* SPI DFF Macro  Bit 11 DFF: Data frame format */

#define SPI_DFF_8  ((uint32_t)(0x00000000)) // 0: 8-bit data frame format is selected for transmission/reception
#define SPI_DFF_16 ((uint32_t)(0x00000800)) // 1: 16-bit data frame format is selected for transmission/reception

                         /* SPI Frame Format Macro  Bit 7 LSBFIRST: Frame format */

#define SPI_FRAMEFORMAT_MSB  ((uint32_t)(0x00000000)) // 0: MSB transmitted first
#define SPI_FRAMEFORMAT_LSB  ((uint32_t)(0x00000080)) // 1: LSB transmitted first


                         /* SPI BusConfig Macro */

#define SPI_BUS_FullDuplex   ((uint32_t)(0x00000000)) // Bit 15 BIDIMODE: Bidirectional data mode enable
#define SPI_BUS_ReceiveOnly  ((uint32_t)(0x00000400)) // Bit 10 RXONLY: Receive only
#define SPI_BUS_HalfDuplex_T ((uint32_t)(0x0000C000)) // (Bit 15=1) | (Bit 14=1) 1: Output enabled (transmit-only mode)
#define SPI_BUS_HalfDuplex_R ((uint32_t)(0x00008000)) // (Bit 15=1) | (Bit 14=0) 0: Output disabled (receive-only mode)

                         /* SPI SSM Macro Software slave management */

#define SPI_SSM_DISABLE     ((uint32_t)(0x00000000)) // 0: Software slave management disabled
#define SPI_SSM_ENABLE      ((uint32_t)(0x00000300)) // When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.


typedef struct
{
	uint32_t Mode;
	uint32_t CPHA;
	uint32_t CPOL;
	uint32_t BaudRate;
	uint32_t SSM_Cmd;
	uint32_t DFF_Format;
	uint32_t BusConfig;
	uint32_t FrameFormat;

}SPI_InitTypedef_t;

typedef struct
{
	SPI_Typedef_t  *Instance;
	SPI_InitTypedef_t Init;


}SPI_HandleTypedef_t;  // Bu oluşturduğumz Handle yapısı ile tek struct yapısıyla SPI'ya dair tüm configürasyonları yapabiliyoruz.
/* Handle yapısı configure etmek için önemli ve kısa bir yöntem.Normalde */

void SPI_Init(SPI_HandleTypedef_t *SPI_Handle);
// SPI_PeriphCmd ile SPI'yı çalıştırabilmek edebilmek için CR1'e bağlı 6. biti enable edebilmeliyiz.Bu sayede güç tüketimini sağlarız haberleşmeyi sağladığımız çevresel birimlerde.
void SPI_PeriphCmd(SPI_HandleTypedef_t *SPI_Handle, FunctionalState_t StatePin);
void SPI_TransmitData(SPI_HandleTypedef_t *SPI_Handle, uint8_t *pData, uint16_t sizeofData);

SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypedef_t *SPI_Handle, uint16_t SPI_Flag); // Flaglerin kontrolünü sağlamak için.

#endif /* INC_SPI_H_ */
