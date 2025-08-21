/*
 Binary multiplication is simply a process of shift and add
 For details see
https://www.geeksforgeeks.org/maths/binary-multiplication/


Multiplication can also be achieved by adding the multiplicand to
itself as many times as the multiplier, but this process is relatively slow.

For example 2 x 3 is 2 + 2 + 2 = 6

*/




#include "SW_multiplication_header.h"
#include "Local_subroutines.c"
#include "KBD_to_display.c"


//Type main rotine here
int main (void) {
long Num_A, Num_B, Num_C;
char digits[8]; 

setup_HW;
for(int m = 0; m <= 7; m++)digits[m] = 0;
I2C_Tx_any_segment_clear_all();

if(watch_dog_reset != 1)String_to_PC_Basic
("\r\nEnter 2 positive numbers to be multiplied\r\n\
Then press sw1\r\n");
else String_to_PC_Basic("\r\n");

while(switch_1_down);

Num_A = Int_KBD_to_display_Local(digits);
String_to_PC_Basic(" times ");
Num_B = Int_KBD_to_display_Local(digits);
String_to_PC_Basic("  =  ");

Num_C = 0;
for (int m = 0; m <=15; m++)
{
  if (Num_B & (1 << m))Num_C = Logic_Add(Num_C, (Num_A << m));
}

for(int m = 0; m <= 7; m++)digits[m] = 0;
 I2C_Tx_any_segment_clear_all();

digits[0] = Num_A;
digits[1] = Num_B;
digits[2] = Num_C;
I2C_Tx_BWops(digits);
Long_Hex_and_Int_to_PC_Basic (10, Num_C);

while(switch_1_up);
SW_reset;}











/*****************************************************************************************************************************************/
