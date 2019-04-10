/*
 * ahern236_lab3_part2.c
 *
 * Created: 4/9/2019 4:20:39 PM
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
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char fuelLevel = 0x00;
	
    while (1) 
    {
		tmpA = PINA & 0x0F;
		fuelLevel = 0x00;
		tmpC = 0x00;
		
		for(int i = 4; i > 0; i--)
		{
			if(GetBit(tmpA, i-1))
			{
				fuelLevel = fuelLevel + pow(2, i-1);
			}
		}
		
		switch(fuelLevel){
			case 1:
			case 2:
				tmpC = SetBit(tmpC, 5, 1);
				tmpC = SetBit(tmpC, 6, 1);
				break;
			case 3:
			case 4:
				tmpC = SetBit(tmpC, 5, 1);
				tmpC = SetBit(tmpC, 4, 1);
				tmpC = SetBit(tmpC, 6, 1);
				break;
			case 5:
			case 6:
				tmpC = SetBit(tmpC, 6, 0);
				tmpC = SetBit(tmpC, 5, 1);
				tmpC = SetBit(tmpC, 4, 1);
				tmpC = SetBit(tmpC, 3, 1);
				break;
			case 7:
			case 8:
			case 9:
				tmpC = SetBit(tmpC, 6, 0);
				tmpC = SetBit(tmpC, 5, 1);
				tmpC = SetBit(tmpC, 4, 1);
				tmpC = SetBit(tmpC, 3, 1);
				tmpC = SetBit(tmpC, 2, 1);
				break;
			case 10:
			case 11:
			case 12:
				tmpC = SetBit(tmpC, 6, 0);
				tmpC = SetBit(tmpC, 5, 1);
				tmpC = SetBit(tmpC, 4, 1);
				tmpC = SetBit(tmpC, 3, 1);
				tmpC = SetBit(tmpC, 2, 1);
				tmpC = SetBit(tmpC, 1, 1);
				break;
			case 13:
			case 14:
			case 15:
				tmpC = SetBit(tmpC, 6, 0);
				tmpC = SetBit(tmpC, 5, 1);
				tmpC = SetBit(tmpC, 4, 1);
				tmpC = SetBit(tmpC, 3, 1);
				tmpC = SetBit(tmpC, 2, 1);
				tmpC = SetBit(tmpC, 1, 1);
				tmpC = SetBit(tmpC, 0, 1);
				break;
			default:
				tmpC = 0x00;
				break;
		}
		
		PORTC = tmpC;
    }
	return 1;
}

