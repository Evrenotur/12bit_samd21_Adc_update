#include <atmel_start.h>
#include "adc_read.h"
int main(void)
{
	int ret=0;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	

	/* Replace with your application code */
	adc_enable();

	while (1) {
		
		ADC_ReadTypeDef_t  adc_read;
		ret = ADC_Read(&adc_read);
		if (ret == 0) {
			//float PA06_ADC_volts = (adc_read.PA06_ADC_value * 5.0) / 4.095;
			//float PA07_ADC_volts = (adc_read.PA07_ADC_value * 5.0) / 4.095;
			//printf("PA06volts=%0.2f\r\n",PA06_ADC_volts);
			//printf("PA07volst=%0.2f\r\n",PA07_ADC_volts);
			printf("PA06 raw     = %03d\r\n",adc_read.PA06_ADC_value);
			printf("PA07 raw     = %03d\r\n",adc_read.PA07_ADC_value);
			printf("PA06 voltage = %03d\r\n",(int)adc_read.PA06_voltage);
			printf("PA07 voltage = %03d\r\n",(int)adc_read.PA07_voltage);
			printf("----- ------------- -----\r\n");

			delay_ms(1000);
		}
		else {
			printf("Reading Failed!");
		}
		delay_ms(500);
	}
}