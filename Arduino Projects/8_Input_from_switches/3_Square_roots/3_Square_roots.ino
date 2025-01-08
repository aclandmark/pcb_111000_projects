
/**************Proj_6G_Acquire_and process_Integer_Data_from_the user switches********************/

/*
 * Prints colum of numbers each 1.5 times the previous until 99999999 or -9999999 is reached
 * then returns by dividing by 1.5
 * 
*/

/*
EEPROM usage
0x1FF, 0x1FE and 0x1FD     OSCCAL
0x1FC and 0x1FB            PRN generator
0x1FA                      Reset source
*/

#include "Square_roots_header.h"
#include "square_root_subroutines.c"


#define message_1 "\r\nDATA FROM I/O\r\n\
Press sw1 to populate digits[0]\r\nsw3 to shift display left\r\n\
sw2 to enter the number\r\nsw1 to pause the program and restart the program.\r\n"

#define message_2 "\r\nEnter new number\r\n"


int main (void){
long Num_1;

char digits[8];
char result[8];
int counter = 0;

setup_HW;

switch(reset_status){
  case POR_reset:             break; 
  case WDT_reset:             String_to_PC_Basic(message_2);break;
   case External_reset:       String_to_PC_Basic(message_1);break;}

sei();
while((switch_1_down) || (switch_2_down) ||(switch_3_down));        //wait for switch release

Num_1 = number_from_IO();
I2C_Tx_long(Num_1);                                           //Sends number to the display
Timer_T0_10mS_delay_x_m(15);

root_computation(Num_1, digits);
    Num_string_to_PC_Basic(digits); 
    for(int m = 0; m < 8; m++)result[m] = digits[7-m];
    I2C_Tx_8_byte_array(result);          

while(switch_3_up);
SW_reset;}



/******************************************************************************************/
long number_from_IO(void){

set_up_PCI;
enable_PCI;

Init_display_for_pci_data_entry;                                    //Set digit[0] to zero and display it.
while(!(Data_Entry_complete))wdr();                                      //Line A. wait here for pci interrupts used to enter data
Data_Entry_complete = 0;
disable_PCI;
return I2C_displayToNum();}                                         //Acquire binary value of the display and return it.



/********************************************************************************************************************/
ISR(PCINT2_vect) {                                                //input number: store keypresses in array -digits
if(switch_1_down)enable_PCI_on_sw3;
while(switch_1_down){                                             //Use switch 1 to select keypress 0...9
    switch(digits[0]){                                            //Test digits[0]
      case '9': if(!(digits[1]))                                  //If its 9 scroll onto "-"
      digits[0] = '-';                                            //but only if this is the first entry (i.e. digits[1] is 0.
      else digits[0] = '0';break;                                 //otherwise scroll from zero to 9
      case '-': digits[0] = '0';break;                             //If digits[0] is "-" scroll onto '0'.
      default: digits[0]++; break;}                                //Otherwise increment it
    I2C_Tx_8_byte_array(digits);                                  //Send value to the display
    Timer_T0_10mS_delay_x_m(25);}                                 //return to Line A when sw1 is released

if(switch_3_down) {disable_PCI_on_sw3;                           //Use switch 3 to shift display left
    shift_digits_left; digits[0] = '0';                             //shift the display and initialise digit[0] (make it display '0')
  I2C_Tx_8_byte_array(digits);}}                                  //update the display and return to Line A



/********************************************************************************************************************/
ISR(PCINT0_vect){
if(switch_2_up)return;                                           //Ignore switch release
I2C_Tx_any_segment_clear_all();
Timer_T0_10mS_delay_x_m(25);                                      //Flash display
I2C_Tx_8_byte_array(digits);
Data_Entry_complete=1;}                                           //Return to Line A



/****************************************************************************************************************/



/************************************************************************************************************************/
