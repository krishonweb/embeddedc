/*Example 2: Write an Embedded C language program to toggle RGB LED’s individually. 
Set a visible frequency. 
RGB LED is at 2.0, 2.1, 2.2. */

#include "msp.h"
int i;

void main ()
{
	P2->DIR = BIT0|BIT1|BIT2; //0x07  - 00000111b
	
	while(1)
	{
		P2->OUT = BIT0; //RED LED of RGB LED
		for (i=100000; i>0; i--);
		P2->OUT = BIT1; // GREEN LED of RGB LED 
		for (i=100000; i>0; i--);
		P2->OUT = BIT2; // BLUE LED of RGB LED 
		for (i=100000; i>0; i--);
	}
}