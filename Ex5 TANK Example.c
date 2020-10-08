/*Example 4.1 : Write an Embedded C code to perform automation using GPIO for a water Tank filling*/

#include "msp.h"
int x;
int main ()
{
	P1->DIR = BIT0;
	P1->REN = BIT1|BIT4;
	P1->OUT = BIT1|BIT4;
	
while(1)
{
	P1->REN = BIT1|BIT4;
	P1->OUT = BIT1|BIT4;
	if (((P1IN & BIT1) == 1) && ((P1IN & BIT4) == 0) && (x=0))
	{
		P1->OUT = BIT0;
		P2->DIR = 0x00;
	}
	
	if (((P1IN & BIT1) == 0) && ((P1IN & BIT4) == 0))
	{
		x = 1;		
		P2->OUT = BIT2;
	}
	if ((x=1) && ((P1IN & BIT1) ==0))
		{
			P2->OUT = BIT2;
			P1->OUT = BIT0;
			if (((P1IN & BIT4) == 0) && (x=1) && ((P1IN & BIT1) ==0))
			{
				x=0;
				P1->OUT = BIT0;
				P2->OUT = BIT1;				
			}
			P1->OUT = BIT0;
		}
}
}