
//Introducing hex numbers


#include "Num_types_header_file.h"
#include "Local_subroutines.c"


char digits [12];

int main (void){
long Num;


char strlength;

setup_HW;

  String_to_PC_Basic("Enter hex number then x, X or y, Y or AK\r\n");  
   Num = Int_from_PC_local(0x10, digits);
           
   newline_Basic();
    
while(1){ 
  strlength = Long_Hex_and_Int_to_PC_Basic_local(0x10, Num);
for(int m = strlength; m < (30 - strlength); m++)Char_to_PC_Basic(' ');
strlength =  Long_Hex_and_Int_to_PC_Basic_local(10, Num);
for(int m = strlength; m < (30 - strlength); m++)Char_to_PC_Basic(' ');
  Long_Binary_to_PC_local(Num);    
  String_to_PC_Basic("\r\n");
  
  switch(waitforkeypress_Basic()){
   case 'x': Num= Num * 0x10;break;
   case 'y': Num= Num / 0x10;break;
    case 'X': Num= Num * 10;break;
   case 'Y': Num= Num / 10;break;
   case 'z': Num = Num * -1; break;
   default:SW_reset;break;    
  }}}

  

  
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
