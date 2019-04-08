/* Partner(s) Name & E-mail: Alexander Hernandez, ahern236@ucr.edu; n/a
* Lab Section: 026
* Assignment: Lab #2 Exercise #2
* Exercise Description: Parking Space Sensor
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>


int main(void)
{
    // Initialize I/O Ports
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	
	// Input temp vars
	unsigned char pSensor3 = 0x00;
	unsigned char pSensor2 = 0x00;
	unsigned char pSensor1 = 0x00;
	unsigned char pSensor0 = 0x00;
	
	// Output temp vars
	unsigned char cntavail = 0x00; // The number of available spots
	
    while (1) 
    {
		// Read input
		pSensor3 = PINA & 0x08; // sets pSensor3 to 0000b000
		pSensor2 = PINA & 0x04; // sets pSensor2 to 00000b00
		pSensor1 = PINA & 0x02; // sets pSensor1 to 000000b0
		pSensor0 = PINA & 0x01; // sets pSensor0 to 0000000b
		
		cntavail = 0x04; // Initialize avail spots to 4
		
		if(pSensor3 == 0x08)
			cntavail--;
		if(pSensor2 == 0x04)
			cntavail--;
		if(pSensor1 == 0x02)
			cntavail--;
		if(pSensor0 == 0x01)
			cntavail--;
		
		// Write output
		PORTB = cntavail;
    }
	return 0;
}

