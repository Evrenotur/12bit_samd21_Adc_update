#include <atmel_start.h>
#include "adc_read.h"
#include <math.h>

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



/*
The method by which the read analog value and voltage value are printed
read_value_1 -> Variable that holds the average of the voltage read from the GPIO PA06 pin
read_value_2 -> Variable that holds the average of the voltage read from the GPIO PA07 pin
*/
	while (1) {
			
		ADC_ReadTypeDef_t  adc_read;
	
		ret = ADC_Read(&adc_read);
		if (ret == 0) {


			//printf("PA06 raw     = %03d\r\n",adc_read.PA07_ADC_value);
			//printf("PA07 raw     = %03d\r\n",adc_read.PA07_ADC_value);
			//printf("PA06 DB = %d\r\n",(int)adc_read.PA06_voltage/10);
			//printf("PA07 voltage = %03d\r\n",(int)adc_read.PA07_voltage);
			printf("%f,%d\r\n",adc_read.db,(int)adc_read.PA06_voltage/10);
		//	printf("sn1c=%d\r\n",adc_read.ort_1);
			//printf("----- ------------- -----\r\n");
			
		/*The process of summing and averaging the voltage value read*/
				
		
		 
			

                

			delay_ms(1000);
		}
		else {
			printf("Reading Failed!");
		}
		delay_ms(500);
	}
}