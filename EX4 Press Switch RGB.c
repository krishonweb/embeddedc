/*Example 4: Write an Embedded C code to toggle RGB LED’s individually (pin P2.0, P2.1, P2.2) after pressing input switch S1 at P1.1.*/

#include "msp.h"
int i, j;

void main ()
{
	P2->DIR = BIT0|BIT1|BIT2;
	P1->DIR = 0x00;
	P1->REN = BIT1;
	P1->OUT = BIT1;
	
while(1)
{
	if((P1IN & BIT1) == 0)
	{		
		P2->OUT = BIT0;
		for (i=100000; i>0; i--);
		P2->OUT = BIT1;
		for (i=100000; i>0; i--);
		P2->OUT = BIT2;
		for (i=100000; i>0; i--);
		P2->OUT = 0x00;
		
		P1->OUT = BIT0;
		for (i=100000; i>0; i--);
		P1->OUT = BIT1;
	}
	else
	{
		P2->OUT = 0x00;
	}
}
}