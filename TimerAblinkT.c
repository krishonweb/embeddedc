
//            |             P1.0|--> LED
//
#include "msp.h"

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW |    WDT_A_CTL_HOLD;          // Stop WDT
            
    // Configure GPIO
    P1->DIR |= BIT0;
    P1->OUT |= BIT0;

    // Configure Timer_A
    TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 |  // SMCLK
            TIMER_A_CTL_MC_2 |              // Continuous mode
            TIMER_A_CTL_CLR |               // Clear TAR
            TIMER_A_CTL_IE  |								// Enable overflow interrupt

						TIMER_A_CTL_ID_3;                // /8
	
		 TIMER_A0->EX0 |=TIMER_A_EX0_TAIDEX_7 ;   // /8

      NVIC->ISER[0] = 1 << ((TA0_N_IRQn) & 31);

    // Enable global interrupt
    __enable_irq();

		while(1);                    // For debugger
}

// Timer A0 interrupt service routine
void TA0_N_IRQHandler(void)
{
    TIMER_A0->CTL &= ~TIMER_A_CTL_IFG;      // Clear timer overflow interrupt flag
    P1->OUT ^= BIT0;                        // Toggle P1.0 LED
}
