/*
 * adc_read.h
 *
 * Created: 6.04.2022 22:15:42
 *  Author: SOFTWARE
 */ 
/* Variable declaration
PA06_ADC_value-> GPIO PA06 pin read value variable
PA07_ADC_value-> GPIO PA07 pin read value variable
PA06_voltage-> GPIO PA06 pin voltage variable
PA07_voltage->GPIO PA07 pin voltage variable 
 
*/
typedef struct {
	int16_t PA06_ADC_value;
	int16_t PA07_ADC_value;
	float PA06_voltage;
	float PA07_voltage;
	int ort_1;
	int ort_2;
	int read_value_1;
	int read_value_2;
}ADC_ReadTypeDef_t;

/* int type Adc Read function*/
int  ADC_Read(ADC_ReadTypeDef_t * ADC_ReadTypeDef);

/* Adc channel (0-1 )active function */
void adc_enable();