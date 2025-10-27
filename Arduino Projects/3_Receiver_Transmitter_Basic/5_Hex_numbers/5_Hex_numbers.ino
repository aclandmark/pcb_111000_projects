
//Introducing hex numbers

/*
Humans feel at home with decimal numbers like 1250 for example
But microchips can only process binary numbers 
Using the PC calculator we find that 1250 is 0100 1110 0010
Notice that it places the bits in groups of 4
We can recognise 0100 and 0010 as 4 and 2 
1110 is 14 but rather than writing 14 we write E.

We can now write 1250 and 4E2 in hexadecimal
It is not obvious the 1250 decimal is 010011100010
But if we know that 1250 decimal is 4E2 in hex 
we can write the binary equivalent quite easily.

  Hex is a useful half way house between binary and decimal
  Like decimal it is compact and it also gives the 
  more cumbersome binary equivalent.
  In addition to E we use the letters A,B,C,D and F for 10,11,12,13 and 15. 
  Hex numbers are numbers to the base of 16.
  At first glance they may not look particularly intuitive 
  but many do find them useful.   
*/



#include "Num_types_header_file.h"
#include "Local_subroutines.c"


char digits [12];

//Type main routine here



  

  
/**************************************************************************************************/
void Binary_to_PC_local(long x){ 
for (int m = 0; m<16; m++){
  if(x & (1 << (15-m))) Char_to_PC_Basic('1');  
  else Char_to_PC_Basic('0');   
  if(m%4==3)String_to_PC_Basic("  ");}}




/***************************************************************************************************/
void Long_Binary_to_PC_local(long x){ 
long x_high, x_low;
x_high = x >> 16;
x_low = x & 0xFFFF ;
 Binary_to_PC_local(x_high);
 String_to_PC_Basic("  ");
 Binary_to_PC_local(x_low);}



/*******************************************************************************************************/
