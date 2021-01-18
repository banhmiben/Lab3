/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
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
	
	DDRB = 0x01; PORTB = 0xFF;
	DDRD = 0x00; PORTD = 0xFF;

	unsigned tmpB = 0x00;
	unsigned tmpD = 0x00;
	unsigned short totWeight = 0x00;

    /* Insert your solution below */
    while (1) {
	
	tmpB = PINB;
	tmpD = PIND;
	totWeight = (tmpD << 1) | (tmpB & 0x01);

	if (totWeight >= 0x0046) {
		tmpB = 0x02;
	} else if ((totWeight > 0x0005) && (totWeight < 70)) {
		tmpB = 0x04;
	} else {
		tmpB = 0x00;
	}

	PORTB = tmpB;
	

    }
    return 1;
}
