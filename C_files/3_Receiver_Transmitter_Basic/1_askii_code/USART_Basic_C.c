

int main (void)               	//Example 6
  { setup_HW;					//Exploring program memory
  char *mem_add;
 wdt_enable(WDTO_120MS);
  while(switch_1_down)wdr();
  
  String_to_PC_Local("\0\r\nDefining and using text strings\r\n");
  const char *message_1 = "Hello world\r\n";
  const char *message_2 = "Sending text to a PC\r\n";
  const char message_3[] = "Writing C programs and\r\n";
  const char message_4[] = "Uploading them to a device\r\n";
  String_to_PC_Local(message_1);
  String_to_PC_Local(message_2);
  String_to_PC_Local(message_3);
  String_to_PC_Local(message_4);
  while(switch_1_up)wdr();

 String_to_PC_Local("\r\nPrint out of program memory\r\n");

mem_add = (char*)0x100;
for(int m = 0; m <=200; m++){
  if ((*(mem_add + m))== '\0')Hex_and_Int_to_PC_Basic (0x10,0x100+m );
 else Char_to_PC_Basic(*(mem_add + m));}
  while(switch_1_down);
  return 1;}