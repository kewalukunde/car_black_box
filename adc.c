#include "main.h"

unsigned short adc(void)
{
	unsigned short data_adc;

	// Start ADC conversion
	ADCON0bits.GO = 1;

	// Wait till conversion is complete
	while(ADCON0bits.GO);

	// Store the result
	data_adc = ADRESH;
	data_adc = (data_adc << 8) | ADRESL;

	return data_adc;
}
