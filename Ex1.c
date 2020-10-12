/* Example 1: Write an Embedded C code to map NVIC to PORT 1 for utilizing 1.1 as an interrupt to 
provoke RED LED at 1.0 */

#include "msp.h"

#define LED1 BIT0
#define S1 BIT1
#define DELAY 500

int i;

void main (void)
{
		WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

		P1->DIR = LED1;
	
		P1->REN = S1;
		P1->OUT = S1;
	
		P1->IE = S1;
	
		P1->IES = 0x00; // 1b high to low 
		P1->IFG = 0x00;

		NVIC->ISER[1] = 0x00000008;
		__enable_irq();
      
		while(1); 
 }

 
void PORT1_IRQHandler (void)
{
	if(P1->IFG & S1)
    {
       P1->OUT = LED1;
    }
   for( i = 0 ; i < DELAY ; i++);
   
    P1->IFG &= ~S1;
}
