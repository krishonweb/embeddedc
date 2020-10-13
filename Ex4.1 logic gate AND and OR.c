/*Example 4.1 : Write an Embedded C code to perform logical operation on RED LED*/

#include "msp.h"
int main ()
{
	P1->DIR = BIT0; // 0x01
	P1->REN = BIT1|BIT4; // enabling pullup and pull down configuration
	P1->OUT = BIT1|BIT4; // 1.1 and 1.4 to pullup configuration - high value
	
while(1)
{
	P1->REN = BIT1|BIT4;
	P1->OUT = BIT1|BIT4;
	
	if (((P1IN & BIT1) == 0) || ((P1IN & BIT4) == 0))
	{
		P1->OUT = BIT0;
	}
	else
	{
		P1->OUT = ~BIT0;
	}
}
}