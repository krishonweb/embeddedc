// Example 1: Write an Embedded C code to toggle LED at P1.0

#include "msp.h"

int i;
int main()
{
	P1->DIR= BIT0; // output 1.0
	
	while(1)
	{
		P1->OUT ^= BIT0; // xor operation
		for(i=100000; i>0; i--);
		
		//P1->OUT = BIT0; 
		//for(i=100000; i>0; i--);
		//P1->OUT = ~BIT0;
		//for(i=100000; i>0; i--);

	}
}