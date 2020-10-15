#include "msp.h"

char a=0b00001111;//0x0F
char b=0b11110000;//0xF0
char c,e,f,g;//one byte for each variable

int main()


{
WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

c=a|b; //ORR operation
e=a&b; //AND operation
f=a^b; //XOR operation
g=~a;  // NOT operation
while(1);
	
}