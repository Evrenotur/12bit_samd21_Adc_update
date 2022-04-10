/*
 * adc_read.h
 *
 * Created: 6.04.2022 22:15:42
 *  Author: SOFTWARE
 */ 

typedef struct
{
	uint8_t buffer[2];
	uint8_t buffer2[2];
	int16_t PA06_ADC_value;
	int16_t PA07_ADC_value;
	uint8_t a;
	uint8_t b;
	uint32_t sum;
	
}ADC_ReadTypeDef_t;

int  ADC_Read(ADC_ReadTypeDef_t * ADC_ReadTypeDef);

void adc_enable();