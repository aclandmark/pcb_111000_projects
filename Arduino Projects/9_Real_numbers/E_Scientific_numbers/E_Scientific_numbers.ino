
/*
EEPROM usage
0x1FF, 0x1FE and 0x1FD     OSCCAL
0x1FC and 0x1FB            PRN generator
0x1FA                      Reset source
*/


long Real_num_to_string_with_rounding(char *, long, int, char, char *);

#define message_1 "\r\n\r\nUsing Arduino functions to receive and print scientific numbers.\r\n\
\r\nEnter scientific number\r\nthen the number of digits before and after the decimal point.\r\n\
Then press AK to generate a series of numbers.\t"
#define message_2 "\r\nEnter new data?\t"


#include "Scientific_numbers_header.h"
#include "SC_Num_to_string.c"


void real_divide(long, long, long *, long *) ;

char digits[8];


int main (void)  
  { 
    char num_string[12];
    float  num_1;
    float index;
    char pre_dp;
    char post_dp;
    char mode = '0';
 
 setup_HW_Arduino;

 switch(reset_status){
  case POR_reset:                 User_prompt_A;    Serial.write(message_1);break;
  case WDT_reset:                 
  case WDT_reset_with_flag:       for(int m = 0; m <= 7; m++)digits[m] = '.'; I2C_Tx_8_byte_array(digits);Serial.write ("Press 'x' to continue"); 
                                  while(waitforkeypress_A() != 'x'); Serial.write(message_2);break;
 case External_reset:            Serial.write(message_1);break;}

for(int m = 0; m <= 7; m++)digits[m] = '0'; I2C_Tx_8_byte_array(digits);

newline_A();
num_1 = Sc_Num_from_PC_A_Local(num_string);
 Print_and_display_FPN_Local(num_1,1,6,'\t', mode); Serial.write("\tpre/post dp digits?\t");

pre_dp = waitforkeypress_A() - '0'; Serial.write(pre_dp + '0');
post_dp = waitforkeypress_A() - '0';Serial.write(post_dp + '0');

while(1){
newline_A();
    I2C_Tx_any_segment_clear_all();
   Print_and_display_FPN_Local(num_1,pre_dp,post_dp,'\t', mode);

switch(waitforkeypress_A()){
  case '1': num_1 = pow(num_1,1.25);  mode = '0'; break;
  case '2': num_1 = 1.0/num_1;        mode = '0'; break;
  case '3': num_1 = pow(num_1,0.5);   mode = '0'; break;
  case 'x':   if(mode == 'x')mode = 'y'; else mode = 'x'; break;
  case 'y': SW_reset; break;}}

  return 1;}




/*****************************************************************************************/
void Print_and_display_FPN_Local(float num, char pre_dp, char post_dp, char next_char, char mode)
{long A = 1;
char sign = '+';
int Exp = 0;
char FP_location;

FP_location = pre_dp;

Check_num_for_to_big_or_small(num);                       //SW_reset required to escape from infinity and zero      
if (num < 0){sign = '-'; num = num * (-1);}
if(pre_dp){
while(pre_dp--)A = A*10;}

if (num >= A)while (num >= A){num = num/10.0; Exp += 1;}

else {while (num*10.0 < A){num = num*10.0; Exp -= 1;}}

Serial.write("\tA");
if(sign == '-')num = num * (-1);
Serial.print(num, post_dp+2);
if(Exp) {Serial.write ('E'); Serial.print(Exp);}
Serial.write(next_char);
Display_FPN(num, FP_location, post_dp, sign, Exp, mode);}



void Display_FPN(float num, char pre_dp, char post_dp, char sign, int Exp, char mode){
int twos_expnt;
long FPN_digits;
char num_string[12];
//long Test;
char string_offset;
//char digits[8];


FPN_digits = unpack_FPN(num, &twos_expnt, &sign);  twos_expnt -= 31;
Int_Num_to_PC_A(FPN_digits, num_string, ' ');Int_Num_to_PC_A(twos_expnt, num_string, ' ');Serial.write('\t');
Real_num_to_string_with_rounding_Local(num_string, FPN_digits, twos_expnt, post_dp, &string_offset);

//for(int m = 0; m < (string_offset - post_dp); m++)                     //Print out the digits to the left of the decimal point
//Serial.write (num_string[m]);
//Serial.write('.');

//for(int m = (string_offset - post_dp); m < string_offset; m++) 
//Serial.write (num_string[m]); 

//newline_A();
Format_num_string(num_string, digits, pre_dp, Exp, mode );
I2C_Tx_8_byte_array(digits);

}



/******************************************************************************************/
float Sc_Num_from_PC_A_Local(char * num_as_string)                    //Nano resources version supports backspace key
{char strln;                                                          //Length of a string of characters

Serial.flush();                                                       //Clear the Arduino serial buffer   
strln = Serial.readBytesUntil('\r',num_as_string, 12);                //Read upto 20 characters or until a -cr- is received 
num_as_string[strln] = 0;                                             //Terminate the string with the null character

return atof(num_as_string);}                                           //"askii to float" -C- library function                                       



/******************************************************************************************/

void Format_num_string(char* num_string, char * digits, char pre_dp, int Exp, char mode ){

for(int m = 0; m <=7; m++)digits[m] = num_string[7-m];

  for (int m = 0; m < (7-pre_dp); m++) digits[m] = digits[m + 1];
  digits[7 - pre_dp] = '.'; 

if((mode == '0') || (mode == 'y')){
if (Exp > 0){
if (Exp < 10) {digits [1] = 'E'; digits[0] = Exp + '0';}
if (Exp >=10) {digits [2] = 'E'; digits[0] = (Exp%10) + '0'; digits[1]= (Exp/10) + '0';}}

if (Exp < 0){Exp *= (-1);
if (Exp < 10) {digits [2] = 'E'; digits[1] = '-'; digits[0] = Exp + '0';}
if (Exp >=10) {digits [3] = 'E'; digits[2] = '-'; digits[0] = (Exp%10) + '0'; digits[1]= (Exp/10) + '0';}}}

}




/***********************************************************************************************/
