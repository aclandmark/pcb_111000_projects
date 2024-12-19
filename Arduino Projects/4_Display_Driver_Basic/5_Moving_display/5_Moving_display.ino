



#include "Moving_display_header.h"
#include "Local_subroutines.c"




int main (void){
char counter=0;         
char digit_array[17];                     //Large array used to hold digits as they are rotated
                                //(ie the addresses defined by "zero", "one", "two" etc....) 
setup_HW;

for(int m = 0; m < 17; m++)digit_array[m] = 0;          //Clear the array
String_to_PC_Basic("Send digits? -x- when complete, AK to rotate"); //User instructions
if (digit_array_to_display(digit_array,  1 ))         //mode is 1: acquire keypresses: returns 1 for 8 digits or 0 for <8 digits
waitforkeypress_Basic();                        //Only wait if 8 digits were entered


while(1){                           
if (counter++ == 8)break;                   //Repeat these steps 8 times to clear the display
rotate_display_left;                      //Shifts data in "digit_array" one places left
Timer_T0_10mS_delay_x_m(10);                  //delay
I2C_Tx_any_segment_clear_all();                 //Clear display and then update it from the array "digit_array": 
digit_array_to_display(digit_array,  0 );           //Note: mode is zero (i.e. data is taken from array rather than the keyboard
}waitforkeypress_Basic();                       //pauses when all digits have shifted off the end of the display

counter=0;

do{
while(1){                           //As above but repeat steps 16 times making the number scan across the display
if (counter++ == 16)break;                    //Continue shifting digits but rotate display
rotate_display_left;                      //so that number re-enters from RH end of display
digit_array_to_display(digit_array,  0 );           //keep rotating digits until user enters 'x'
Timer_T0_10mS_delay_x_m(10);
I2C_Tx_any_segment_clear_all();}counter = 0;}
while(waitforkeypress_Basic() !='x');

counter = 0;
while(counter++ <= 8){                      //Shift digits back into display
digit_array_to_display(digit_array,  0 );
rotate_display_left;
Timer_T0_10mS_delay_x_m(10);
if(counter != 9)I2C_Tx_any_segment_clear_all();}        //Finnish with number visible on display

waitforkeypress_Basic();I2C_Tx_any_segment_clear_all();       //Clear display
newline_Basic();SW_reset;}




/************************************************************************************************/
