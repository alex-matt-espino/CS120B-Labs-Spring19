/*
 * ahern236_lab2_part4.c
 *
 * Created: 4/7/2019 9:41:37 PM
 * Author : alex.espino
 */ 

#include <avr/io.h>


int main(void)
{
    // Initialize I/O Ports
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	
	// Input temp vars
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	
	//Output temp vars
	unsigned char tmpD = 0x00;
	
	// Other vars
	unsigned char totWeight = 0x00;
	unsigned char totWeightShift = 0x00;
	
    while (1) 
    {
		// Read input
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		
		totWeight = tmpA + tmpB + tmpC;
		totWeightShift = totWeight * 4;
		
		if(totWeight > 0x8C) // If totWeight > 140
			totWeightShift++; // Set PD7 to 1
			
		if((tmpA - tmpC > 0x50) || (tmpC - tmpA > 0x50))
		{
			totWeightShift = totWeightShift + 2;
		}
		
		tmpD = totWeightShift;
		
		// Write output
		PORTD = tmpD;
		
    }
	
	return 0;
}

