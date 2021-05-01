#define BAUD 9600 // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1) // set baud rate value for UBRR
#include "activity4.h"
#include "activity1.h"
#include <avr/interrupt.h>
#define DATA_IS_TRANSMITTING !(UCSR0A & (1<<UDRE0))
#define DATA_IS_RECEIVING !(UCSR0A & (1<<RXC0))
#define DATA UDR0

void USARTInit(void){
    UBRR0H = (BAUDRATE>>8); //Set Baud rate
    UBRR0L = BAUDRATE;
    sei();
    UCSR0C=(1<<UCSZ01)|(1<<UCSZ00); //Enable The receiver and transmitter
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}
/*
char USARTReadChar(){
    USARTInit(); // Initialize Peripherals for UART
    while(DATA_IS_RECEIVING) //Wait untill a data is available
    {
    //Do nothing
    }
    return DATA;
}
void USARTWriteChar(char letter){
    while(DATA_IS_TRANSMITTING) //Wait untill the transmitter is ready
    {
    //Do nothing
    }
    DATA = letter; //write the data to USART buffer
}
*/

void USARTWriteString(char letter){
    if(letter=='a'){
        while(DATA_IS_TRANSMITTING){};
            DATA = '2';
            DATA = '0';
            DATA = 'C';
    }
    if(letter=='b'){
        while(DATA_IS_TRANSMITTING){};
            DATA = '2';
            DATA = '5';
            DATA = 'C';
    }
    if(letter=='c'){
        while(DATA_IS_TRANSMITTING){};
            DATA = '2';
            DATA = '9';
            DATA = 'C';
    }
    if(letter=='d'){
        while(DATA_IS_TRANSMITTING){};
            DATA = '3';
            DATA = '3';
            DATA = 'C';
    }
}