
/*Proj_2C_2_Hex_numbers
***********************************************************/

/*QUICK INTRODUCTION TO HEX NUMBERS


IT INTRODUCES


1.  Hex number format.

2.  Project subroutine  "Binary_to_PC_local()".*/



#include "Num_types_header_file.h"

char digits [12];

//Type main routine here


  
/**************************************************************************************************/
void Binary_to_PC_local(int x){             //check with paper and pencil
for (int m = 0; m<16; m++){
  if(x & (1 << (15-m))) Char_to_PC_Basic('1');        //test each bit in turn starting with the most significant
  else Char_to_PC_Basic('0');   
  if(m%4==3)String_to_PC_Basic("  ");}}



/*******************************************************************************************************/
