/*
 * adc_read.c
 *
 * Created: 6.04.2022 22:15:27
 *  Author: SOFTWARE
 */ 


#include <atmel_start.h>
#include "adc_read.h"

void adc_enable()
{
	
	adc_sync_enable_channel(&ADC_0,0);
	adc_sync_enable_channel(&ADC_0,1);
}

int ADC_Read(ADC_ReadTypeDef_t * ADC_ReadTypeDef)
{
	int ret=adc_sync_read_channel(&ADC_0,0,ADC_ReadTypeDef->buffer,2);
	int ret1=adc_sync_read_channel(&ADC_0,1,ADC_ReadTypeDef->buffer2,2);
	if(ret<=0&&ret1<=0)
	{
		
		return -1;
	}
	 ADC_ReadTypeDef->PA06_ADC_value = (ADC_ReadTypeDef->buffer[1]  + ADC_ReadTypeDef->buffer[0]);
	ADC_ReadTypeDef->PA07_ADC_value = (ADC_ReadTypeDef->buffer2[1]  + ADC_ReadTypeDef->buffer2[0]);
	//ADC_ReadTypeDef->sum = ADC_ReadTypeDef->PA06_ADC_value;
	return 0;
}