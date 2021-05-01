#include "activity1.h"

void DelayMilliSecond(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}

void ChangeLEDState(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

void SetButtonSensorPin(void)
{
	BUTTON_SENSOR_PORT |= (1 << BUTTON_SENSOR_PIN);
}

void SetHeaterSensorPin(void)
{
	HEATER_SENSOR_PORT |= (1 << HEATER_SENSOR_PIN);
}

void InitializePeripherals(void)
{
	/* Configure LED Pin */
	SET_PORTB0_AS_OUTPUT;//Makes first pin of PORTB as Output
    SET_PORTD_AS_INPUT; //Makes all pins of PORTD input
	SET_PD0_AND_PD1_AS_PULLUP; //Pull Up
    SetButtonSensorPin();
    SetHeaterSensorPin();
}

uint8_t StatusOfLedActuator(void)
{
    uint8_t FLAG=0;
    InitializePeripherals();/* Initialize Peripherals */
    ChangeLEDState(LED_OFF);
    /*checks whether button sensor is ON or OFF */
    if(BUTTON_SENSOR_ON){
        /*checks whether heater button is ON or OFF */
        if(HEATER_SENSOR_ON){
            ChangeLEDState(LED_ON);
            FLAG=1;
        }
        else{
            ChangeLEDState(LED_OFF);
            FLAG=0;
        }
    }
    else {
        ChangeLEDState(LED_OFF);
        FLAG=0;
    }
    return FLAG;
}