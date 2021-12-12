/******************************************************************************
 * The following code generates PWM Dead band and complementary outputs, using
 * the Timer 1 (Advanced Timer).
 *
 * TIM1_CH1 - PA8
 * TIM1_CH1N - PB13
 *
 * Note: The Dead Time is inserted at both the sides of the Pulse, which
 * affects the Pulse Width or the Duty Cycle. So, as per the configurations
 * below, the pulse width reduces to 20us from 25us, since a 5us dead time
 * is inserted at both the sides of the pulse. Hence, the value in the
 * TIM1->CCR1 register for the Pulse On time should be set accordingly
 * by taking into account the amount of dead time inserted.
 *
 * @file    main.c
 * @Date    12 December, 2021
 * @Author  Ruturaj A. Nanoti
 *****************************************************************************/

// Including the necessary header files
#include "stm32f4xx.h"
#define ARM_MATH_CM4

// Declaration for User-Defined Functions
void GPIO_Init(void);
void TIM1_Init(void);

void GPIO_Init(){
	// Enable GPIOA and GPIOB clock
	RCC->AHB1ENR |= ( RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN );

	// Set PA8 in alternate function mode and configure alternate function
	// AF1 - TIM1
	GPIOA->MODER |=  GPIO_MODER_MODER8_1;
	GPIOA->AFR[1] |=  GPIO_AFRH_AFSEL8_0;

	// Set PB13 in alternate function mode and configure alternate function
	// AF1 - TIM1
	GPIOB->MODER |=  GPIO_MODER_MODER13_1;
	GPIOB->AFR[1] |=  GPIO_AFRH_AFSEL13_0;

}

void TIM1_Init(){
	// Enable clock for Timer 1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	//Setting the clock frequency to 2MHz.
	TIM1->PSC = 8-1;

	// Total period of the timer, which is (1/20KHz) = 50us
	TIM1->ARR = 100-1;

	// Setting Initial count to 0.
	TIM1->CNT = 0;

	// Enabling complementary polarity outputs on Channel 1
	TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC1NE);

	//Configure PWM mode 1
	TIM1->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2);

	// Enabling OC and OCN complementary Outputs
	TIM1->BDTR |= TIM_BDTR_MOE;

	// Configuring OC and OCN as active high
	TIM1->CCER &= ~TIM_CCER_CC1P;
	TIM1->CCER &= ~TIM_CCER_CC1NP;

	// Setting the Duty Cycle (50% = 25us)
	TIM1->CCR1 |= 50;

	// Setting the Dead-Time to 1us, with a clock frequency of 16MHz
	// DTG[7:0] = 80 => 80*(1/16MHz) = 80*62.5ns = 5us
	TIM1->BDTR |= (80UL<<0);
}

int main(void){
	// Call to the Configuration Functions
	GPIO_Init();
	TIM1_Init();

	// Start the Timer to generate the PWM Signals
	TIM1->CR1 |= TIM_CR1_CEN;

	// Dead Loop
	while(1){};
}
