#include "ch32v00x.h"

#define LED_PORT GPIOD
#define LED_PIN 2
#define LED_BUS RCC_IOPDEN

int main()
{
	// Enable GPIOD
	RCC->APB2PCENR |= LED_BUS;
	// GPIO D0 Push-Pull
	LED_PORT->CFGLR &= ~(0xf << (4 * LED_PIN));
	LED_PORT->CFGLR |= GPIO_CFGLR_MODE0_0 << (4 * LED_PIN);

	while (1)
	{
		LED_PORT->BSHR = (1 << LED_PIN); // Turn on PA2
		for (int i = 0; i < 4000000; ++i)
			__asm("nop");

		LED_PORT->BSHR = (1 << (16 + LED_PIN)); // Turn off PA2
		for (int i = 0; i < 4000000; ++i)
			__asm("nop");
	}
}