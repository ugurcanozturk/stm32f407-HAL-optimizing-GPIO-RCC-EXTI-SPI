/*
 * GPIO.c
 *
 *  Created on: 1 Tem 2023
 *      Author: Ugur
 */


#include "GPIO.h"

void GPIO_Init(GPIO_Typedef_t *GPIOx, GPIO_InitTypedef_t *GPIO_ConfigStuct)
{
	uint32_t pos;
	uint32_t fakePos = 0;
	uint32_t lastPos = 0;

	for(pos = 0; pos<16; pos++) // Bitleri tek tek gezmek için indirgeme işlemi bit kaydırma yapabilmek adına.
	{
		fakePos = (0x1 << pos);
		lastPos = (uint32_t)(GPIO_ConfigStuct->pinNumber)& fakePos; // Pin number dolasıyla 32 bit ile type-casting yaptık.

		if(fakePos == lastPos)  // Eğer oluşturduğumuz fakePos ile kullanıcının girdiği pin numarası olan lastPos eşitse configurasyon işlemi başlar.
		{
			       /* MODE CONFİG*/
			uint32_t tempValue = GPIOx->MODER;  // Direkt register üzerinden işlem yapmayız önce local bir değişkene atarız.
			tempValue &= ~(0x3U << (pos * 2));  //Önce gerekli bitlere clearlama işlemi yaparız.
			tempValue |= (GPIO_ConfigStuct->Mode << (pos * 2)); // MODER registerı her pin 2 bit olduğu için o pine 2 katıyla çarptığımızda ulaşırız
			GPIOx->MODER = tempValue;  // Yani 7.pin 14.bitten başlıyor örneğin. // En son burada registerı değişkene eşitleyip okuma işlemini yaparız

			if(GPIO_ConfigStuct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStuct->Mode == GPIO_MODE_AF)
			{
				 /* OUTPUT TYPE CONFİG*/   // OTYPER İLE OSPEEDR output registerları olduğu için ınput ve analog modda iken çalışması gereksizdir çalışmaz.
			    tempValue = GPIOx->OTYPER; // İf bloğuyla bunu kontrol ederiz INPUT VE ANALOG ise configure etmeyiz.
				tempValue &= (0x1U << pos);
				tempValue |= (GPIO_ConfigStuct->Otype << pos);
				GPIOx->OTYPER = tempValue;

				/* OUTPUT SPEED CONFİG*/
				tempValue = GPIOx->OSPEEDR;
				tempValue &= (0x3U << (pos * 2));
				tempValue |= (GPIO_ConfigStuct->Speed << (pos * 2));
				GPIOx->OSPEEDR = tempValue;

              }
			  /* PULL UP PULL DOWN CONFİG*/
			    tempValue = GPIOx->PUPDR;
			    tempValue &= (0x3U << (pos * 2));
			    tempValue |= (GPIO_ConfigStuct->Pupd << (pos * 2));
			    GPIOx->PUPDR = tempValue;


		      if(GPIO_ConfigStuct->Mode == GPIO_MODE_AF)
		      {
		    	  tempValue = GPIOx->AFR[pos >> 3U];  // Girilen pin numarasına göre 8 ile bölüyoruz ve doğru AFR Registera ulaşıyoruz.Sağa doğru 3 bit kaydırmak 8'e bölmek demektir.
		    	  tempValue &= ~(0xFU << ((pos & 0x7U) *4)); // Daha sonra 8 ile modunu alarak ve sonucu 4 ile çarparak doğru bit sayısına ulaşarak orayı clearlama işlemi yapıyoruz.
		    	  tempValue |= (GPIO_ConfigStuct->Alternate << ((pos & 0x7U) *4)); // Doğru register ve bite ulaştıktan sonra verimi oraya yazdırıyoruz.
		    	  GPIOx->AFR[pos >> 3U] = tempValue;

/* 2^3=8 yani 3 bit sağa kaydırmak 8'e bölmek demektir/ 8 ile mod almak ise 2^3=8 yani 3 biti 1 olan sayı ile AND'leme yapmak demektir.İlk 3 biti 1 olan sayı ise 7'dir.*/
		/* AFR her bir pine bakan registerı 4 bit ve toplam 16 adet pin var bu yüzden 8 ile bölme ve mod alarak doğru register ve bite ulaşıyoruz.*/
		      }
		}
	}


}


      /* Herhangi bir değer okuması yapmayacağımız için void fonksiyon oluşturduk.Yalnızca değer ataması yapacağız */

void GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState)
{
	if(pinState==GPIO_Pin_Set)  //pinState 1 ise direkt registerde istenilen pine yazdrılır.
	{
		GPIOx->BSRR = pinNumber;
	}
	else
	{
		GPIOx->BSRR = (pinNumber << 16U); //değilse BSSR registerına uygun şekilde 16 bit kaydırarak 1 yazılır ve reset konumda olduğu anlaşılır.
	}
}

        /* Bir değer okuyacağımız için PinState türünden onun türünden bir fonksiyon oluşturduk.*/
        /* PinState bizim struct yapımız reset ve set değerimizi tutuyoruz içinde*/
GPIO_PinState_t GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitStart = GPIO_Pin_Reset;      // Local bir değişken oluşturarak reset yani '0' durumunda başlatırız.
	if((GPIOx->IDR & pinNumber) != GPIO_Pin_Reset)  // IDR registerımızın ilgili pininde veri olup olmadığı kontrol ediliyor pin ile and işlemine sokuyoruz.
	{                                               // VE REGİSTERIN İLGİLİ PİNİNDE DEĞER VAR MI AND İLE KONTROL EDİYORUZ.
		bitStart = GPIO_Pin_Set;                    // Veri varsa yani '1' konunmunda ise direkt set ediliyor.
	}
	return bitStart;             // Herhangi bir veri yoksa direkt olarak local değişkenimiz return olarak döndürelecek.
}

/* LockPin algoritması ve yazım şekli referance manuelde belirtilmiştir.Ona uygun local değişken ve algoritma yazımı */

void GPIO_LockPin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber)
{

	uint32_t localValue = (0x1U << 16U) | pinNumber; // 16.biti 1 olan bir sayı oluşturduk lock registerı için ve pinlerimiz ile and işlemine soktuk.

	GPIOx->LCKR = localValue;  // 16.bit 1 ve istenilen pinlerin değeri 1'lendi.
	GPIOx->LCKR = pinNumber;   // 16.bit 0 oldu ve yalnızca pin değerlerimiz kaldı.
	GPIOx->LCKR = localValue;  // 16.bit 1 ve istenilen pin değerleri registera atandı.
	localValue = GPIOx->LCKR;  // Değer okuması yapılıyor.


}

void GPIO_TogglePin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber){

	uint32_t tempODRReg = GPIOx->ODR;
	GPIOx->BSRR = ((tempODRReg & pinNumber) <<16U) | (~tempODRReg & pinNumber);

// Set konumunda olup resete dönüşenleri 16 bit kaydırarak yazarız BSSR Registerından dolayı.
}
