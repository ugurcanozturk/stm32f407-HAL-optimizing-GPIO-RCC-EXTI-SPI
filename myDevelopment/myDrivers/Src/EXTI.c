/*
 * EXTI.c
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */


#include "EXTI.h"

        /* Kullanıcının EXTI İÇİN GİRMESİ GEREKEN INİT PARAMETRELERİNİ ALAN INİT FONKSİYONUMUZ */

void EXTI_Init(EXTI_InitTypedef_t *EXTI_InitStruct)
{
          uint32_t tempValue = 0;
          tempValue = (uint32_t)EXTI_BASE_ADDR;  // Değişkenimizde base adresimizi integer değişken olarak tutuyoruz.

          EXTI->IMR &= ~(0X1U << EXTI_InitStruct->LineNumber); // Interrupt Mask registerı kullanıcının girdiği line numarasına uygun şekilde clearlarız.
          EXTI->EMR &= ~(0X1U << EXTI_InitStruct->LineNumber); // Event Mask registerı kullanıcının girdiği line numarasına uygun şekilde clearlarız.

          if(EXTI_InitStruct->EXTI_LineCmd != DISABLE)
            {
          tempValue += EXTI_InitStruct->EXTI_Mode; /* LineCmd ile tuttuğumuz hattın aktif edilme durumuna göre eğer Enable ise ; */
            	                                   /* tempValue'de integer olarak tuttuğumuz adres bilgisine Mode'da Interrupt veya Event offset değerlerini ekleyerek doğru adrese oluşuruz.*/

          *( (__IO uint32_t *)tempValue) = (0x1U << EXTI_InitStruct->LineNumber); /* Integer olarak tuttuğumuz adres değerini tekrar adrese dönüştürüp */
               tempValue = (uint32_t)EXTI_BASE_ADDR;                         /* Parantezin dışındaki yıldız ile o adresteki değere ulaşıyoruz.    */
               EXTI->RTSR &= ~(0X1U << EXTI_InitStruct->LineNumber);
               EXTI->FTSR  &= ~(0X1U << EXTI_InitStruct->LineNumber);   /* Clearlama işlemini yapıp bir alt satır kod bloğuna geçeriz*/

           if(EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF)  /* Burada ise RSTR ve FSTR registerlarını configure ederiz.*/
           {                                                         /* Hem Rising hem Falling olma durumunu if bloğu içinde kontrol ederiz ilk önce */
        	   EXTI->RTSR |= (0X1U << EXTI_InitStruct->LineNumber);  /* Clearlama işlemi yapmadan burada direkt lineNumber kadar kaydırıp veriyi yazdırırz. */
        	   EXTI->FTSR |= (0X1U << EXTI_InitStruct->LineNumber);  /* Hem Rising hem falling durumu aktif ise veriyi direkt içine yazarız*/

           }
           else
           {
        	   tempValue += EXTI_InitStruct->TriggerSelection;       /* Yalnızca birisinin olma durumuna göre adrese gidip lineNumber kadar kaydırıp gerekli değeri yazarız.*/
        	   *((__IO uint32_t *)tempValue) = (0x1U << EXTI_InitStruct->LineNumber);
               /* Buradaki tempValue'yı += şeklinde yazmadığım ve sadece eşittir dediğim için */
               /* IMR ve RTSR Registerlarının gerekli bitlerini enable edemedim. += olarak güüncelleyince sorun düzeldi.*/
           }


            }
          else  /* LineCmd yani hattın aktif edilme durumu DISABLE ise*/
          {
        	  tempValue = (uint32_t)EXTI_BASE_ADDR;

        	  tempValue += EXTI_InitStruct->EXTI_Mode;
        	  *((__IO uint32_t *)tempValue) &= ~(0x1U << EXTI_InitStruct->LineNumber); // Eğer kullanıcı bize DISABLE OLARAK girdiyse zaten orayı Clearlarız direkt olarak.
          }

}

            /* Port ve pin bilgisini SYSCFG için kullanıcıdan alan fonksiyon*/

void EXTI_LineConfig(uint8_t PortSource ,uint8_t LineSource)
{
      uint32_t tempValue;

      tempValue = SYSCFG->EXTI_CR[LineSource >> 2U];  // Burada registerımızın 1-2-3-4 hangisi olduğunu buluyoruz.
      tempValue &= ~(0xFU << (LineSource & 0x3U)*4);  // Burada registerın 4 bitine clear işlemi uygulandı.0xF=1111 ile AND işlemine sokarak tersledik ve bitleri temizledik.Daha sonra bit numarasını buluruz.
      tempValue = (PortSource << (LineSource & 0x3U)*4);
      SYSCFG->EXTI_CR[LineSource >> 2U]= tempValue;

}

            /* Mikroişlemci ile alakalı Interrupt işlemleri için oluşturduğumuz fonksiyon */
            /* Cortex™ M4 Devices*/
void NVIC_EnableInterrupt(IRQNumber_Typedef_t IRQNumber)
{
	 uint32_t tempValue = 0;

	 tempValue =  *((IRQNumber >> 5U) + NVIC_ISER0);  // Register 32 bit olduğu için 32'ye bölerek doğru registerı buluruz ilk önce

	 tempValue &= ~(0x1U << (IRQNumber & 0x1FU));    // 5 biti 1 olan sayı ile yani 1F ile and işlemine sokarak doğru biti buluruz ve clearlama işlemine sokarız
	 tempValue |= (0x1U << (IRQNumber & 0x1FU));     // 5 biti 1 olan sayı ile yani 1F ile and işlemine sokarak doğru biti buluruz ve enable ederiz

	 *((IRQNumber >> 5U) + NVIC_ISER0) = tempValue;
}
