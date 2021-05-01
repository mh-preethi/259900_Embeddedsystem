#include "activity1.h"
#include "activity2.h"

#define CONVERSION_IS_INCOMPLETE  ADCSRA & (1<<ADSC)
//#define (1<<REFS0)

void InitializeADC()
{
    // Select Vref=AVcc
    ADMUX |= (1<<REFS0);
    //set prescaller to 128 and enable ADC
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}
uint16_t ReadADC(uint8_t channel)
{
    InitializeADC();/* Initialize Peripherals for ADC */
    //select ADC channel with safety mask
    ADMUX &= 0xF8;
    //single conversion mode
    channel &= 0x07;
    ADMUX &= channel;
    ADCSRA |= (1<<ADSC);
    // wait until ADC conversion is complete
    while(CONVERSION_IS_INCOMPLETE);
    ADCSRA|=(1<<ADIF);
    return ADC;
}