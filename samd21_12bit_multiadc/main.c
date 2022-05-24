#include <atmel_start.h>
#include "adc_read.h"
int main(void)
{
	int ret=0;
		int read_value_1=0;
	int read_value_2=0;
	int snc_1=0;
	int snc_2=0;
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
<<<<<<< HEAD
			printf("PA06=%03d\r\n",adc_read.PA06_ADC_value);
			printf("PA07=%03d\r\n",adc_read.PA07_ADC_value);
			delay_ms(250);
				
			for(int i=0;i<1023;i++)
			{
				read_value_1 += adc_read.PA06_ADC_value;
					read_value_2 += adc_read.PA07_ADC_value;
			}
             snc_1 = read_value_1 /1023;
			 snc_2 = read_value_2 /1023;
			 printf("snc_1 = %03d\r\n",(int)snc_1);
			 printf("snc_2 = %03d\r\n",(int)snc_2);
=======
			printf("PA06 raw     = %03d\r\n",adc_read.PA06_ADC_value);
			printf("PA07 raw     = %03d\r\n",adc_read.PA07_ADC_value);
			printf("PA06 voltage = %03d\r\n",(int)adc_read.PA06_voltage);
			printf("PA07 voltage = %03d\r\n",(int)adc_read.PA07_voltage);
			printf("----- ------------- -----\r\n");

>>>>>>> eaa01aa81dabcc2ce3fb016e0960e42d4e6ce14f
			delay_ms(1000);
		}
		else {
			printf("Reading Failed!");
		}
		delay_ms(500);
	}
}