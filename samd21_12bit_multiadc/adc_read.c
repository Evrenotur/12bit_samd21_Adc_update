/*
 * adc_read.c
 *
 * Created: 6.04.2022 22:15:27
 *  Author: SOFTWARE
 */ 

#include <string.h>

#define ADC_VREF 3300 //mV
#define ADC_MAX_BIT 4095 //12bit ADC
#define ADC_BUFFER_SIZE 2 //ADC read buffer size

#include <atmel_start.h>
#include "adc_read.h"
        
		
		 /* adc_sync_enable_channel (struct adc_sync_descriptor *const descr, const uint8_t
             channel)
             */

void adc_enable() {
	
	adc_sync_enable_channel(&ADC_0,0);
	adc_sync_enable_channel(&ADC_0,1);
	
	return;
}
/* Adc Read Pin Number PA06-PA07

int32_t adc_sync_read_channel(struct adc_sync_descriptor *const descr, const uint8_t
channel, uint8_t *const buffer,const uint16_t length)

If the read is successful, the ADC_Read function returns 0, if it fails, it returns -1.
*/
int ADC_Read(ADC_ReadTypeDef_t * ADC_ReadTypeDef) {
	
	uint8_t buffer[ADC_BUFFER_SIZE] = {0};
	/* Read Channel Number 0 */
	
	int read_size = adc_sync_read_channel(&ADC_0, 0, buffer, ADC_BUFFER_SIZE); 
	if(read_size != 2) {
		return -1;
	}
	/* Converting the value read from the GPIO PA06 pin to voltage */
	memcpy(&ADC_ReadTypeDef->PA06_ADC_value, &buffer[0], ADC_BUFFER_SIZE);
	ADC_ReadTypeDef->PA06_voltage = ADC_ReadTypeDef->PA06_ADC_value*ADC_VREF/ADC_MAX_BIT;

	////
      /* Read Channel Number 1 */
	read_size = adc_sync_read_channel(&ADC_0, 1, buffer, ADC_BUFFER_SIZE); 
	if(read_size != 2) {
		return -1;
	}
	/* Converting the value read from the GPIO PA07 pin to voltage */
	memcpy(&ADC_ReadTypeDef->PA07_ADC_value, &buffer[0], ADC_BUFFER_SIZE);
	ADC_ReadTypeDef->PA07_voltage = ADC_ReadTypeDef->PA07_ADC_value*ADC_VREF/ADC_MAX_BIT;
	

	return 0;
}