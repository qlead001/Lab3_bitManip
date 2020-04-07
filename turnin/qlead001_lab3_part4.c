/*	Author: Quinn Leader qlead001@ucr.edu
 *  	Partner(s) Name: NA
 *	Lab Section: 026
 *	Assignment: Lab 3  Exercise 2
 *	Exercise Description: Fuel level indicator
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    while (1) {
        tempA = PINA&0xF0; tempB = PINA&0x0F;
        PORTB = tempA>>4; PORTC = tempB<<4;
    }
    return 1;
}
