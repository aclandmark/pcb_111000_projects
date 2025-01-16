

      //Four examples using a timer interrupt to drive the display


#include "Interrupt_basic_header.h"

volatile long PORT_1 = 1, PORT_2 = 0x8000;                            //For example 1, 2 and 3
volatile int m = 0, n = 0;                                            //Extras for example 3
volatile unsigned int clock_rate = 150;                                //Extra for examples 2 and 3
volatile unsigned int PRN;                                            //For example 4
unsigned char PRN_counter = 0;                                        //For example 4
volatile unsigned char counter = 0;                                   //For example 4



 int main (void)   
  {
  setup_HW;
set_up_PCI_on_sw1_and_sw3;                                             //Eamples 2 and 3 only
enable_pci_on_sw1_and_sw3;                                              //Eamples 2 and 3 only
    sei();
   T1_clock_tick(clock_rate);
while(1);
   SW_reset;
    }


void T1_clock_tick(unsigned int T1_period_in_ms)                                 //Start the T1 clock
{ TCNT1 = 0;
OCR1A = T1_period_in_ms * 125;
  TIMSK1 |= (1 <<  OCIE1A);
  TCCR1B = 0x03;}


ISR(PCINT2_vect) {                                                      //Use with examples 2 & 3 only
  if ((switch_2_down)|| (clock_rate <= 10))clock_rate = 150;
  else
  {if (switch_1_down)clock_rate += 20;
  if (switch_3_down)clock_rate -= clock_rate/7;}}








    
