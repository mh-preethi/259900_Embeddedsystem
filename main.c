/*
 */

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"
#define ON 1
/**
 * @brief Main function where the code execution starts
 *
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
	uint16_t Temperature, ADCchannel=0;
	char TempType;
	USARTInit(); /* Initialize Peripherals for UART */
	while(1){
		uint8_t Status;
		/* Turns LED ON if and only if both switches ButtonSensor and Heater are closed */
		Status=StatusOfLedActuator();
		if(Status==ON){
			Temperature=ReadADC(ADCchannel); /*reads sensor data from ADCChannel*/
    	    TempType=GeneratePWM(Temperature);/*Generates PWM according to data received from sensor*/
			USARTWriteString(TempType);/*Sends data to serial monitor*/
		}
	}
	return 0;
}