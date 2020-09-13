#include <16F88.h>
#FUSES NOBROWNOUT, NOMCLR
#use delay(internal=8MHz)

#define PIN_OUTPUT    PIN_A0
#define BUTTON1       PIN_B4
#define BUTTON2       PIN_B5

#define NMAX 250
#define NMIN 1

