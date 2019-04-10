/*
 * ahern236_lab3_part4.c
 *
 * Created: 4/9/2019 6:10:26 PM
 * Author : alex.espino
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x0F; PORTB = 0xF0;
	DDRC = 0xF0; PORTC = 0x0F;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
    while (1) 
    {
		tmpA = PINA;
		tmpB = 0x00;
		tmpC = 0x00;
		
		for(int i = 7; i > 3; i--)
		{
			tmpB = SetBit(tmpB, i-4, GetBit(tmpA, i));
		}
		
		for(int j = 3; j > -1; j--)
		{
			tmpC = SetBit(tmpC, j+4, GetBit(tmpA, j));
		}
		
		PORTB = tmpB;
		PORTC = tmpC;
    }
	return 1;
}

