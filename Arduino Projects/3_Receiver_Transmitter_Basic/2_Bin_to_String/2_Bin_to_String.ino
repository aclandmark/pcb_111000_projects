
/*Sending numbers to the PC*/


#include "Receiver_Transmitter_header.h"
#include "Local_subroutines.c"

int Bin_to_string_Local(long, char *);



int main (void)                          //Example 1B 
  { unsigned int random_num; 
    unsigned char PRN_counter;
  char num_string[12];
 int str_len;
 int num_counter =0;

  setup_HW; 
  PRN_counter = 0;
  random_num = PRN_16bit_GEN (0, &PRN_counter);

  while(1){
 str_len = Bin_to_string_Local(random_num%100, num_string);
 Num_string_to_PC_Local(num_string, str_len);
waitforkeypress_Basic(); num_counter += 1; 
if(!(num_counter%15))newline_Basic();else Char_to_PC_Basic(' ');
random_num = PRN_16bit_GEN (random_num, &PRN_counter);}
return 1;}



/*
int main (void)                          //Example 1 
  { int i = 0;              //Convert number to string
  int number = 12345;
  char s[12];
  setup_HW;
  //Set up watchdog timer to generate a reset
  wdt_enable(WDTO_120MS);
 while(switch_1_down)wdr();

  //Convert number to string
  while(1) {
    s[i++] = number % 10 + '0';
    number = number/10;
    if (!(number))break;
  }s[i] = '\0';

  //Print string out in reverse order
    for (int m = i; m > 0; m--)
    Char_to_PC_Basic(s[m - 1]);
  newline_Basic();
 //Generate a reset
 while(switch_1_up)wdr();
  while(switch_1_down);
  return 1;}
*/

/*int main (void)                          //Example 1A
  {                                      //Convert number to string
  long number = 2;
 char num_string[12];
 char direction = 0;
 int str_len;
  
  setup_HW;
 
while(number) {
str_len = Bin_to_string_Local(number, num_string);
 Num_string_to_PC_Local(num_string, str_len);
 if (!(direction))number = number *3/2;
else number = number *2/3;
  
  newline_Basic();
 waitforkeypress_Basic();
if (number >= 18000){direction ^= 1;
number = number *2/3;newline_Basic();}}
newline_Basic();SW_reset;
  return 1;}*/


/*************************************************************************************************************************/
