#include "activity1.h"
#include "activity3.h"

#define DUTY_CYCLE(Percent) (1024*Percent/100)
#define WRITE_PWM OCR1A


void InitializePWM(void){
    TCCR1A=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B=(1<<CS11)|(1<<WGM12)|(1<<CS10);
    DDRB|=(1<<PB1);
}

char GeneratePWM(uint16_t Temperature){
    InitializePWM();/* Initialize Peripherals for PWM */
    if(Temperature<=200){
        WRITE_PWM=DUTY_CYCLE(20.0);//PWM of Duty cycle 20%
        DelayMilliSecond(200);
        return 'a';
    }
    else if(Temperature>200 && Temperature<=500){
        WRITE_PWM=DUTY_CYCLE(40.0);//PWM of Duty cycle 40%
        DelayMilliSecond(200);
        return 'b';
    }
    else if(Temperature>500 && Temperature<=700){
        WRITE_PWM=DUTY_CYCLE(70.0);//PWM of Duty cycle 70%
        DelayMilliSecond(200);
        return 'c';
    }
    else{
        WRITE_PWM=DUTY_CYCLE(95.0);//PWM of Duty cycle 95%
        DelayMilliSecond(200);
        return 'd';
    }
}