
/*Proj_7B_Demo_Clock_B
*************************************************************************************************************************/



/*INTRODUCES

Simple clock in which the display is kept up to date by incrementing a counter every second
The counter is converted to Hours, Minutes, Seconds each of which is then converted to askii 
characters and sent to the display.

As for Project 7A accurracy is not good

USER INSTRUCTIONS

Respond to the user prompt by pressing "R" and entering the time when requested or by pressing "r" and letting 
the clock start at time zero.


Like 7A suffers from I2C bus crashes.  Therefore 7B1 has also beew written based on 7A1
*/



#include "Proj_7B_header_file_1.h"



int main (void){
char User_response;

setup_HW_Arduino_IO_Extra;

Serial.write("Press 'R' to enter time or 'r' to start at time zero  ");
User_prompt_A;

if(User_response == 'R')set_time();
else {reset_clock_1; deci_SecsH = '0'; deci_SecsL = '0'; deci_sec_counter = 0; }
I2C_Tx_8_byte_array(digits);

Serial.write("AK to start\r\n");
waitforkeypress_A();

while(1){Timer_T0_10mS_delay_x_m(20); deci_sec_counter += 2;
if(deci_sec_counter == 864000)deci_sec_counter = 0;
Format_time_for_display();I2C_Tx_8_byte_array(digits);}}



/**********************************************************************************************************************/
void Format_time_for_display(void){
Hours =     deci_sec_counter/36000;
Minutes =   (deci_sec_counter%36000)/600;
Seconds =   ((deci_sec_counter%36000)%600)/10;
deci_Secs = ((deci_sec_counter%36000)%600)%10;

timer_utoa(Hours); HoursH = charH; HoursL = charL; 
timer_utoa(Minutes); MinsH = charH; MinsL = charL; 
timer_utoa(Seconds); SecsH = charH; SecsL = charL; 
timer_utoa(deci_Secs * 10); deci_SecsH = charH; deci_SecsL = charL; }



/***********************************************************************************************************************/
void set_time(void){

for(int m = 0; m <= 7; m++)digits[m] = 0;
Serial.write("Enter start time Hours, Minutes and Seconds\
\r\n(24 hour clock with no spaces). Terminate with cr\r\n");

while(isCharavailable_A(50) == 0){Serial.write("T?  ");}

digits[7] = Serial.read();I2C_Tx_8_byte_array(digits);
for (int m = 0; m<=4; m++){while(isCharavailable_A(5) == 0);
if(m == 4){digits[2] = Serial.read();deci_SecsH = '0'; deci_SecsL = '0';}
else digits[6 - m] = Serial.read(); 
I2C_Tx_8_byte_array(digits);}

waitforkeypress_A();

deci_sec_counter = 10*(long)((((long)((HoursH -'0') * 10) + HoursL-'0') * 3600) +
((((MinsH-'0') * 10) + MinsL-'0') * 60) +(SecsH-'0') * 10 + SecsL - '0');

I2C_Tx_any_segment_clear_all();
_delay_ms(50);}



/**********************************************************************************************************************/
void timer_utoa(char n){                //converts an unsigned number to a string of digits
if (n>=10)
{charL = n%10;
charH = (n-charL)/10;
charL = charL + '0';
charH = charH + '0';}
else
{charH = '0'; charL = n + '0';}}



/**********************************************************************************/
