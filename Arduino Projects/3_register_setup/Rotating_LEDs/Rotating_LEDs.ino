



#include "Rotating_LEDs_header.h"

int main (void)
  { char digit[] =  "01234567777654321000";
    
    char letter = 'a';
    char counter=0;
    int top = 1000;
    
  setup_HW;
  while(1){
   
  I2C_Tx_any_segment(letter,digit[counter]-'0');

for(int m = 0; m < top; m++)_delay_us(100);
if (counter < 7)letter = 'a';
if (counter == 7) letter = 'f';
if (counter == 8) letter = 'e';
if ((counter >= 9) && (counter <= 16)) letter = 'd';
if (counter == 17) letter = 'c';
if (counter == 18) letter = 'b';
if (counter == 19) letter = 'a';
counter = (counter + 1)%20;

if (switch_2_down) I2C_Tx_any_segment_clear_all();

if(counter == 19){if((switch_1_down)|| (top <= 50))break;
if(switch_3_down)top = top*2/3;}
}SW_reset;}

  
