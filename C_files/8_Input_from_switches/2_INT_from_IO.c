int main (void){
long Num_1;
char digits[8];
int counter = 0;

setup_HW;

switch(reset_status){
  case POR_reset:             User_prompt_A;    String_to_PC_Basic(message_1);break;
  case WDT_reset:             String_to_PC_Basic(message_2);break;
   case External_reset:       String_to_PC_Basic(message_1);break;}

sei();
while((switch_1_down) || (switch_2_down) ||(switch_3_down));        //wait for switch release

Num_1 = number_from_IO();

do{
Int_to_PC_Basic(++counter); Char_to_PC_Basic('\t');
Int_to_PC_Basic(Num_1); String_to_PC_Basic("\r\n");

I2C_Tx_long(Num_1);                                           //Sends number to the display
Timer_T0_10mS_delay_x_m(15);
while(switch_1_down)wdr();

Num_1 = (Num_1 / 2) *3;} 
while ((Num_1 < 99999999) && (Num_1 > -9999999));                   //Do some arithmetic

String_to_PC_Basic("Press sw1 to continue\r\n");

while(switch_1_up)wdr();
Num_1 = (Num_1 / 3) *2; 

do{Num_1 = (Num_1 / 3) *2;                                           //Do the arithmetic in reverse
Int_to_PC_Basic(--counter); Char_to_PC_Basic('\t');
Int_to_PC_Basic(Num_1); 
String_to_PC_Basic("\r\n");                                             
I2C_Tx_long(Num_1);
Timer_T0_10mS_delay_x_m(15);
while(switch_1_down)wdr();}while (counter-1);

String_to_PC_Basic("sw1 !\r\n");
while(switch_1_up)wdr();
while(switch_1_down)wdr();
setup_watchdog_A;
SW_reset;}