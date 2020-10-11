/*Example 3: Write an Embedded C language program to switch RGB LED individually for one cycle and after RGB switch RED LED at P1.0. 
  Repeat this cycle for 5 times and stop. */

#include "msp.h"
int i, j;

void main ()
{
	P2->DIR = BIT0|BIT1|BIT2;
	P1->DIR = BIT0;
	for(j=5; j>0; j--)
	{
		P1->OUT = ~BIT0;
		
		P2->OUT = BIT0;
		for (i=100000; i>0; i--);
		P2->OUT = BIT1;
		for (i=100000; i>0; i--);
		P2->OUT = BIT2;
		for (i=100000; i>0; i--);
		P2->OUT = 0x00;
		P1->OUT = BIT0;
		for (i=100000; i>0; i--);
	}
}