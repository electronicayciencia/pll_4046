/* 
Frequency divider to test PLL.
Electronicayciencia 2020/08/18 

I use asyncronous counter so we only count counter's overflows.
Just set-up counter trigger L-TO-H load TMR0 with 256-n and the 
interrupt will fire after n pulses.

*/
#include "main.h"

int a = 0;
int n1;
int n2;

#INT_TIMER0
void timer0() {
	a ^= 1;
	output_bit(PIN_OUTPUT,a);
	if (a) {
		int t = get_timer0();
		set_timer0(256-n1+t);
	}
	else {
		int t = get_timer0();
		set_timer0(256-n2+t);
	}
}

void increase_div() {
	if (n1 >= NMAX && n2 >= NMAX)
		return;
	
	if (n2 < n1) {
		n2++;
	}
	else {
		n1++;
	}
}


void decrease_div() {
	if (n1 <= NMIN && n2 <= NMIN)
		return;
	
	if (n2 > n1) {
		n2--;
	}
	else {
		n1--;
	}
}


void main() {
	n1 = 1;
	n2 = 1;
	
	port_b_pullups(TRUE);

	// 1 ms overflow @8MHz (1kHz)
	setup_oscillator(OSC_8MHZ, OSC_FINETUNE);
	setup_ccp1(CCP_PWM);
	setup_timer_2(T2_DIV_BY_16,124,1);		
	set_pwm1_duty((int16)248);
	
	// Async counter
	setup_timer_0(T0_EXT_L_TO_H|T0_DIV_1);	
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);


	while (true) {
		if (!input(BUTTON1) || !input(BUTTON2))
			delay_ms(20); // lazy debouncer
		
		if (!input(BUTTON1)) {
			decrease_div();
			delay_ms(500);
			
			while(!input(BUTTON1)) {
				decrease_div();
				delay_ms(50);
			}
		}
		
		else if (!input(BUTTON2)) {
			increase_div();
			delay_ms(500);
			
			while(!input(BUTTON2)) {
				increase_div();
				delay_ms(50);
			}
		}
		
		delay_ms(10);
	}
}

