


int main (void)                          //Example 5 
  { unsigned int random_num; 
    unsigned char PRN_counter;
    unsigned int Short_random_number; 
  char num_string[12];
 int str_len;
 int num_counter =0;

  setup_HW; 
  PRN_counter = 0;
  random_num = PRN_16bit_GEN (0, &PRN_counter);
  Short_random_number = PRN_8bit_GEN();
  
  while(1){
switch(Short_random_number%4)
 {case 0:str_len = Bin_to_string_Local(random_num%10,     num_string);break;
  case 1:str_len = Bin_to_string_Local(random_num%100,    num_string);break;
  case 2:str_len = Bin_to_string_Local(random_num%1000,    num_string);break;
  case 3:str_len = Bin_to_string_Local(random_num%10000,  num_string);break;}

 Num_string_to_PC_Local(num_string, str_len);
waitforkeypress_Basic(); num_counter += 1; 
if(!(num_counter%15))newline_Basic();else Char_to_PC_Basic(' ');

random_num = PRN_16bit_GEN (random_num, &PRN_counter);
 Short_random_number = PRN_8bit_GEN();}
return 1;}