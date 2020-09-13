#include <12F683.h>
#FUSES NOBROWNOUT, NOMCLR
#DEVICE ADC=8
#use delay(internal=8MHz)



#define PIN_INPUT     PIN_A2
#define PIN_OUTPUT    PIN_A5
#define PIN_UART_RX   PIN_A1
#define PIN_UART_TX   PIN_A0
//PIN_A4 reserved for analog input.


/*
#use rs232(baud=9600, \
	parity=N,         \
	RCV=PIN_UART_RX,  \
	XMIT=PIN_UART_TX, \
	bits=8,           \
	stream=SERIAL)    \
*/