/*
 * adc_read.h
 *
 * Created: 6.04.2022 22:15:42
 *  Author: SOFTWARE
 */ 

typedef struct {
	int16_t PA06_ADC_value;
	int16_t PA07_ADC_value;
	float PA06_voltage;
	float PA07_voltage;
}ADC_ReadTypeDef_t;

int  ADC_Read(ADC_ReadTypeDef_t * ADC_ReadTypeDef);

void adc_enable();