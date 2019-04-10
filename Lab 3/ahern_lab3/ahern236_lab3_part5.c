/* Partner(s) Name & E-mail: Alexander Hernandez, ahern236@ucr.edu; n/a
* Lab Section: 026
* Assignment: Lab #3 Exercise #5
* Exercise Description: Car Passenger Weight Sensor -- Working with I/O on the same port
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>
#include <math.h>

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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x00;
    
	unsigned char tmpD = 0x00;
	unsigned char tmpB = 0x00;
	//unsigned char airbagFlags = 0x00;
	int weight = 0;
		
    while (1) 
    {
		tmpD = PIND;
		tmpB = PINB & 0x01;
		//airbagFlags = 0x00;
		weight = 0;
		
		for(int i = 8; i > 0; i--)
		{
			if(GetBit(tmpD, i-1))
			{
				weight = weight + (2 * pow(2.0, i-1));
			}
		}
		
		if(GetBit(tmpB, 0))
		{
			weight++;
		}
		
		if(weight >= 70)
		{
			//tmpB = 0x02;
			// PORTB = SetBit(PORTB, 1, 1); // airbag enable
			// PORTB = SetBit(PORTB, 2, 0); // airbag disable light
			PORTB |= 0x02;
			PORTB &= 0xFB;
		}
		else if ((weight > 5) && (weight < 70))
		{
			//tmpB = 0x04;
			// PORTB = SetBit(PORTB, 1, 0); // airbag enable
			// PORTB = SetBit(PORTB, 2, 1); // airbag disable light
			PORTB &= 0xFD;
			PORTB |= 0x04;
		} 
		else
		{
			PORTB &= 0xF8;
		}
    }
	return 1;
}

