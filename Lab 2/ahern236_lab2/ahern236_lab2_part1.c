/* Partner(s) Name & E-mail: Alexander Hernandez, ahern236@ucr.edu; n/a
* Lab Section: 026
* Assignment: Lab #2 Exercise #1
* Exercise Description: Garage & Light Sensor
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
	unsigned char tmpA1 = 0x00; // Temporary variable to hold the value of A1 (Light Sensor Input)
	unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A0 (Garage Door Sensor Input)
	
	//Output temp vars
    unsigned char tmpB0 = 0x00; // Temporary variable to hold the value of B0 (LED Output)
	
    while(1)
    {
	    // Read input
	    tmpA1 = PINA & 0x02; // reads from PINA: 000000b0
		tmpA0 = PINA & 0x01; // reads from PINA: 0000000b
		
	    // if PA1 is 0 and PA0 is 1, set PB0 = 1, else = 0
	    if ((tmpA1 == 0x00) && (tmpA0 == 0x01)) { // True if PA0 is 1
		    tmpB0 = (tmpB0 & 0xFE) | 0x01; // Sets tmpB to bbbbbbb1
		    // (clear rightmost bit, then set to 1)
	    }
	    else {
		    tmpB0 = (tmpB0 & 0xFE); // Sets tmpB to bbbbbbb0
	    }
		
	    // Write output
	    PORTB = tmpB0;
    }
    return 0;

}