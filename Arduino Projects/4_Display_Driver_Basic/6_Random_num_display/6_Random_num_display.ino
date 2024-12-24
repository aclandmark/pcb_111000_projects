
#include "Random_num_header.h"
#include "Local_subroutines.c"


  
  int main (void)   //Example 12
  { unsigned int random_num[2];
  unsigned char PRN_counter;
  char display_string[8], num_string[8];
  char num_length;
    int num_counter=0;

  setup_HW;
  //wdt_enable(WDTO_30MS);
  PRN_counter = 0;
  random_num[0] = PRN_16bit_GEN (0, &PRN_counter);
   random_num[1] = PRN_16bit_GEN 
  (random_num[0], &PRN_counter);


  
  while (1)       
  {
    
    while(switch_3_down)wdr();
    num_length = Bin_to_string_Local(random_num[num_counter%2], num_string);
    //num_length -= 1;
    Num_string_to_PC_Local(num_string,num_length);newline_Basic();

    
    for(int n = 0; n <= num_length; n++){
    display_string[0] = num_string[num_length - n];
    I2C_Tx_8_byte_array(display_string);_delay_ms(100);
    
for(int m = 0; m < 7; m++){
display_string[7-m] = display_string[7-m-1];}

 
Timer_T0_10mS_delay_x_m(10);
}
  random_num[(num_counter+1)%2] = PRN_16bit_GEN 
  (random_num[num_counter%2], &PRN_counter);

num_counter += 1;
  
  
  }



   /* Char_to_PC_Basic('\t');
    Int_to_PC_Basic(num_length);
    newline_Basic();
    
    Timer_T0_10mS_delay_x_m(25);while(switch_3_down)wdr();
    random_num = PRN_16bit_GEN 
  (random_num, &PRN_counter);*/
  
  
  
  
  }  
