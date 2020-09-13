/* 
Frequency divider to test PLL.
Electronicayciencia 2020/08/18 

*/
#include "main.h"

int a = 0;

/* For exact division */
#INT_TIMER0
void timer0() {
	a ^= 1;
	output_bit(PIN_OUTPUT,a);
	// 255 -> divide by 2
	// 254 ->   "    by 4
	// 253 ->   "    by 6
	set_timer0(254);
}

/* For non-exact division */
/*
#INT_TIMER0
void timer0() {
	a ^= 1;
	output_bit(PIN_OUTPUT,a);
	// To divide by 5 set 254 and 253
	if (a)
		set_timer0(254);
	else
		set_timer0(253);	
}
*/

void main() {
	setup_timer_0(T0_EXT_L_TO_H|T0_DIV_1);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);

	set_timer0(255); //easier debug

	while (true) {}
}

