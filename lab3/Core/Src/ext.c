/*
 * ext.c
 *
 *  Created on: Oct 12, 2021
 *      Author: dang khoa
 */


#include <input_reading.h>
#include "main.h"
#include "timer.h"


void EXTI15_10_IRQHandler(void)
{


	if(EXTI->PR & (1<<13))
	{
		EXTI->PR |= (1<<13); //Clear the Interrupt Pending bit


		//masking line 0
		EXTI->IMR &=~(1<<13);

		//disables NIVIC IRQ
		//NVIC_DisableIRQ(EXTI2_IRQn);

		process[0]=1;
		button= Button1;
		TIM1->CNT=0;
		TIM1->CR1 |= (1<<0);

	}



	if(EXTI->PR & (1<<14))
		{
			EXTI->PR |= (1<<14); //Clear the Interrupt Pending bit


			//masking line 0
			EXTI->IMR &=~(1<<14);

			//disables NIVIC IRQ
			//NVIC_DisableIRQ(EXTI2_IRQn);

			process[1]=1;
			button= Button2;
			TIM1->CNT=0;
			TIM1->CR1 |= (1<<0);


		}


	if(EXTI->PR & (1<<15))
	{
		EXTI->PR |= (1<<15); //Clear the Interrupt Pending bit


		//masking line 0
		EXTI->IMR &=~(1<<15);

		//disables NIVIC IRQ
	//	NVIC_DisableIRQ(EXTI2_IRQn);

		process[2]=1;
		button =Button3;
		TIM1->CNT=0;
		TIM1->CR1 |= (1<<0);

	}




}

