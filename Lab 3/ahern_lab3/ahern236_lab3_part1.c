/* Partner(s) Name & E-mail: Alexander Hernandez, ahern236@ucr.edu; n/a
* Lab Section: 026
* Assignment: Lab #3 Exercise #1
* Exercise Description: Counting 1s on a port
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

unsigned char GetBit(unsigned char bits, unsigned char pos)
{
	return ((bits & (0x01 << pos)) != 0);
}

unsigned char SetBit(unsigned char bits, unsigned char pos, unsigned char val)
{
	return (val ? bits | (0x01 << pos) : bits & ~(0x01 << pos));
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;

	
    while (1) 
    {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = 0x00;
		
		for(int i = 0; i < 8; i++)
		{
			if(GetBit(tmpA, 7))
				tmpC++;
			if(GetBit(tmpB, 7))
				tmpC++;
			
			tmpA = tmpA * 2;
			tmpB = tmpB * 2;
		}
		
		PORTC = tmpC;
    }
	return 1;
}

