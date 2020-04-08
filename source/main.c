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
    DDRD = 0x00; PORTD = 0xFF;
    DDRB = 0xFE; PORTB = 0x01;
    /* Insert your solution below */
    unsigned short weight = 0x00;
    while (1) {
        weight = (PIND<<1) + (PINB&0x01);
        PORTB = ((weight>5&&weight<70)<<2) + ((weight>=70)<<1);
    }
    return 1;
}
