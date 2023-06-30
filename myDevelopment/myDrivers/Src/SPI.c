/*
 * SPI.c
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */


#include "SPI.h"


void SPI_Init(SPI_HandleTypedef_t *SPI_Handle)
{
       uint32_t tempValue = 0;
       tempValue = SPI_Handle->Instance->CR1;  // Ulaşmak istediğimiz configurasyon yapacağımız registerı burada ilk önce seçiyoruz.

       /* Burada ise o registerın bitleriyle kullanıcının isteğine göre yapabileceğimiz configurasyonları yapıyoruz.*/
       tempValue |= (SPI_Handle->Init.BaudRate) | (SPI_Handle->Init.CPHA) | (SPI_Handle->Init.CPOL) | \
    		   (SPI_Handle->Init.Mode) | (SPI_Handle->Init.DFF_Format) | (SPI_Handle->Init.FrameFormat) | \
			   (SPI_Handle->Init.BusConfig) | (SPI_Handle->Init.SSM_Cmd);

       SPI_Handle->Instance->CR1 = tempValue;

}

void SPI_PeriphCmd(SPI_HandleTypedef_t *SPI_Handle, FunctionalState_t StatePin)
{
          if(StatePin == ENABLE)
          {
        	  SPI_Handle->Instance->CR1 |= (0x1U << 6U);  // Enable durumda ise SPI ENABLE eden CR1'deki 6. biti high konuma çekiyoruz.
          }
          else
          {
        	  SPI_Handle->Instance->CR1 &= ~(0x1U << 6U);
          }
}

void SPI_TransmitData(SPI_HandleTypedef_t *SPI_Handle, uint8_t *pData, uint16_t sizeofData)
{
	  if(SPI_Handle->Init.DFF_Format == SPI_DFF_16) // Burada DFF formatına göre veri gönderimi yapacağız.Ya 16 bit yada 8 bit gönderim yapabiliriz.
	  {
		  while(sizeofData > 0)  // Datayı byte byte gönderdiğimiz için gönderme işlemi Datanın size'ı kadar devam etmeli.
		  {
		if((SPI_Handle->Instance->SR >> 1U) & 0x1U) /* if(SPI_GetFlagStatus(SPI_Handle, SPI_TXE_Flag) olarak kullanırsak da aynı anlama gelmektedir.Daha profesyonel seviye bir flag kontrolüdür. */ // TX flag kontrolünü burada sağlarız.Eğer flag empty ise bir sonraki byte'ın gönderimine geçilir.
			  {
				  SPI_Handle->Instance->DR = *((uint16_t *)pData); // Empty koşulu sağlanıyorsa 2byte yani 16 bit şeklinde Data Register'a yazılır
				  pData += sizeof(uint16_t);   // 2 byte şeklinde gönderdiğimiz için ilk 2byte'ı gönderdikten sonra size'ı 2 byte ile typecast ederek arttırız ve bir sonraki 2.bytlera geçer göndermek adına.
				  sizeofData -= 2; // Datanın ilk 2 byte'nı gönderdikten sonra 2byte kadar azalttık kalan size'ı.
			  } // Aslında sizeof(uint16_t) = ( +=2) fakat daha profesyonel gözükmesi için typecast ederek yazarız.
		  }

	  }
	  else                          // Burada ise DFF formatın 8 bit yani 1byte'lık durumu için veri gönderimi yapıyoruz.
	  {
		  while(sizeofData > 0)
		  {
			  if((SPI_Handle->Instance->SR >> 1U) & 0x1U)  // TX Flag kontrolü yaptık empty olup olmadığını buna göre bir sonraki byte'a geçeceğiz.
			  {
				  SPI_Handle->Instance->DR = *pData;   // Adresine gittiğimize dikkat et direkt kullanıcıdan aldığımız dataya değil onu tuttuğumuz adrese eşitleriz.
			      pData += sizeof(uint8_t);   // Burada ise DFF format 8 bit yani 1 byte olduğu için kullanıcıdan gelen datayı ilk gönderimden sonra 1byte arttırdık.
			      sizeofData--; // Size'ı 1 byte azalttık ilk gönderimden sonra.
			  }
		  }
	  }
          while((SPI_Handle->Instance->SR >> 7U) & 0x1U); /* while(SPI_GetFlagStatus(SPI_Handle, SPI_BSY_Flag )*/ // Son datanın da güvenli bir şekilde gönderilmesi için en Busy Flag kontrolünü sağlarız.
}

SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypedef_t *SPI_Handle, uint16_t SPI_Flag)
{
	return (SPI_Handle->Instance->SR & SPI_Flag) ? SPI_FLAG_SET : SPI_FLAG_RESET;
}
