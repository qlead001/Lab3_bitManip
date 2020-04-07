/*	Author: Quinn Leader qlead001@ucr.edu
 *  	Partner(s) Name: NA
 *	Lab Section: 026
 *	Assignment: Lab 3  Exercise 1
 *	Exercise Description: Count 1s on A and B
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char count1s(unsigned char num) {
    unsigned char count = 0;
    while (num > 0) {
        count += num&0x01;
        num >>= 1;
    }
    return count;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    while (1) {
        tempA = PINA; tempB = PINB;
        PORTC = count1s(tempA) + count1s(tempB);
    }
    return 1;
}
