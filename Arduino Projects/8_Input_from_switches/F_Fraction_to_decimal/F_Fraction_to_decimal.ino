
#include "decimal_fraction_header.h"
#include "Local_subroutines.c"


void fraction_to_decimal_string_Local(long, long, char *);


int main (void){
long Num_1, Num_2;
char digits[8];

setup_HW;
while(1){
String_to_PC_Basic("Num_1?  ");
Num_1 = Int_from_PC_Basic(digits); Int_to_PC_Basic(Num_1); newline_Basic();      

String_to_PC_Basic("Num_2?  ");
Num_2 = Int_from_PC_Basic(digits);Int_to_PC_Basic(Num_2);newline_Basic();

String_to_PC_Basic("Answer =   ");

if (Num_1 > Num_2)fraction_to_decimal_string_Local(Num_2, Num_1, digits); 
else fraction_to_decimal_string_Local(Num_1, Num_2, digits); 
newline_Basic();}SW_reset;}
