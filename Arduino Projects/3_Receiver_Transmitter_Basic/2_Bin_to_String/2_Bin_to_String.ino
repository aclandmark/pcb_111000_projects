
/*Sending numbers to the PC*/


#include "Receiver_Transmitter_header.h"



  
  int main (void)                    //Example 3
  { int i = 0;             //Print out a column of numbers
  long number = 123456789;
  long number_old = 123456789;
  char s[12];
  setup_HW;
   wdt_enable(WDTO_120MS);
  while(switch_1_down)wdr();
  
  for(int m = 2; m < 11; m++){
Int_to_PC_Basic(number);
 newline_Basic();

number = number_old / 10;  
number_old = number;}

while(switch_1_up)wdr();
  while(switch_1_down);
  return 1;}
