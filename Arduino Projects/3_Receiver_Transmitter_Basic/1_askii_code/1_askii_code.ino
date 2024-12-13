

//Use cntrl z
//put numbers in order


#include "Receiver_Transmitter_header.h"
#include "Local_subroutines.c"

int main (void)                          //Example 6
  { setup_HW;
  char *mem_add;
 wdt_enable(WDTO_120MS);
  while(switch_1_down)wdr();
  
  String_to_PC_Local("\r\nDefining and using text strings\r\n");
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
  if ((*(mem_add + m))== '\0')Hex_and_Int_to_PC_Basic (0x10,100+m );
 else Char_to_PC_Basic(*(mem_add + m));}
  while(switch_1_down);
  return 1;}  

/*
    
int main (void)                          //Example 10
  { 
    char char_counter = 0;
    char *mem_add;
    char array[25];
    
    setup_HW;
    for (int m = 0; m <25; m++)array[m] = m;
    String_to_PC_Basic("ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n\
    Read out of program memory\r\n\r\n");
mem_add = (char*)0x100;
for(int m = 0; m <=75; m++)Char_to_PC_Basic(*(mem_add + m));
while(1);
  return 1;} 

*/




  

/************************************************************************************************************

  Use this area for saving the examples when they have been got working and finished with
  Use the space above for the active program (the one being worked on)



********Example 1: Echoes keypresses*************************************************************************
  int main (void)                          //Example 1
  { setup_HW;
  User_prompt;
  String_to_PC_Local("\r\nExploring the operation of the USART\r\n");
  Char_to_PC_Local('?');
  newline_Basic();
  while (1)
  { Char_to_PC_Local
    (waitforkeypress_Local());
  }
  return 1;
  }


int main (void)                          //Example 2
  { setup_HW;
  char keypress;
 
  if (watch_dog_reset == 1) String_to_PC_Local("\r\n?  ");
  else {User_prompt;String_to_PC_Local("\r\nWe often send\
  detailed text the first time our program runs\r\n\
  and a simple prompt on subsequent ocaissions\r\n\
  Enter number -cr- when done\r\n    ");}
  
  while (1)
  { keypress = waitforkeypress_Local();
    if  ((keypress =='\r') ||  (keypress =='\n'))break; 
    else Char_to_PC_Local(keypress); }
 SW_reset; }


**********Example 3: Prints out ASKII characters**************************************************************
  int main (void)                          //Example 3
  { char symbol;
  setup_HW;
  newline_Basic();
  symbol = '!';
  while (symbol <= '~')
  { Char_to_PC_Local(symbol);
    _delay_ms(10);
    symbol++;
    wdr();
  }
  waitforkeypress_Local();
  SW_reset;
  return 1;
  }




********Example 4: Echo character string or prints file*******************************************************
int main (void)                          //Example 4
  { setup_HW;
  while (!(isCharavailable_Local(65)))    //Use local version
    Char_to_PC_Local('?');                //Use local version
  newline_Basic();
  Char_to_PC_Local(Char_from_PC_Local());
  while (1)
  { if (isCharavailable_Local(10))
      Char_to_PC_Local(Char_from_PC_Local());
    else break;
  }
  String_to_PC_Local("Done\r\n");
  SW_reset;
  return 1;}
 


//Look for text strings
int main (void)                          //Example 5
  { setup_HW;
  char keypress;
 
  String_to_PC_Basic("abcdefghijklmnopqrstuvwxyz");
 String_to_PC_Basic("\r\nSend_the_hex_file\r\n");

 while (!(isCharavailable_Local(65)))    //Use local version
    Char_to_PC_Local('?');                //Use local version
  newline_Basic();
  Char_to_PC_Local(Char_from_PC_Local());
  while (1)
  { if (isCharavailable_Local(10))
      Char_to_PC_Local(Char_from_PC_Local());
    else break;
  }
 String_to_PC_Local("Done\r\n");
 
 
 while(1); }

 

********Example 6: Send strings to the PC********************************************************************

int main (void)                          //Example 6
  { setup_HW;
  char *mem_add;
 wdt_enable(WDTO_120MS);
  while(switch_1_down)wdr();
  
  String_to_PC_Local("\r\nDefining and using text strings\r\n");
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
  if ((*(mem_add + m))== '\0')Hex_and_Int_to_PC_Basic (0x10,100+m );
 else Char_to_PC_Basic(*(mem_add + m));}
  while(switch_1_down);
  return 1;}  




************Example 7: Generate an ASKII table****************************************************************
int main (void)                          //Example 7
  { char symbol = '!';
  setup_HW;
  wdt_enable(WDTO_120MS);
  while(switch_1_down)wdr();
  
  newline_Basic();
  while (symbol <= '~')
  { Int_to_PC_Basic(symbol);
    Char_to_PC_Local(symbol++);
    wdr();_delay_ms(50);
    if (!((symbol - '!') % 8))newline_Basic();
    else Char_to_PC_Local('\t');
  }
  while(switch_1_up)wdr();
  while(switch_1_down);
  }
  
  //Lower case to upper case
int main (void)                          //Example 8
  { setup_HW;
  char keypress;
 char text[25];
 int m=0;
 
  if (watch_dog_reset == 1) String_to_PC_Local("\r\n?  ");
  else {User_prompt;String_to_PC_Local("\r\nEnter some text\
  maybe the name of a song then -cr-\r\n");}
  
  while (1)
  { keypress = waitforkeypress_Local();
    if  ((keypress =='\r') ||  (keypress =='\n'))break;
    else {Char_to_PC_Local(keypress); text[m++] = keypress; }}
text [m] = '\0';
m=0;
while(text[m]){if((text[m]>='a') && (text[m]<= 'z'))
text[m] -= 32; m+=1;}
newline_Basic(); String_to_PC_Local(text);
SW_reset; }


int main (void)                          //Example 9
  { 
    char char_counter = 0;
    char keypress;
    char line_len;
    char High_byte=0;
    char askii_char;
   
    setup_HW;
    String_to_PC_Basic("ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n\
Send hex file\r\n");
          
  while (!(isCharavailable_Local(65)))    //Use local version
    Char_to_PC_Local('?');                //Use local version
  newline_Basic();
  Char_from_PC_Local();

  while (1)
  { if (isCharavailable_Local(10))
        {keypress =  Char_from_PC_Local();
      if(keypress ==':')char_counter = 0;
      if (char_counter == 1)line_len = (keypress - '0')*0x10;
      if (char_counter == 2)line_len += keypress - '0';
      char_counter += 1;
     if((char_counter >=10) && (char_counter < ((line_len*2) + 10)))
            
      {if (!(char_counter%2))
      {if ((keypress >= '2') &&  (keypress <= '7'))High_byte = keypress; 
            else {Char_to_PC_Local(keypress);}}
      if (char_counter%2)
      {if (!(High_byte))Char_to_PC_Local(keypress);  
            else{
              
              if (keypress >='A')keypress -= 7;
              askii_char = ((High_byte-'0') * 0x10)+ keypress - '0';
            Char_to_PC_Basic(askii_char);High_byte=0;}}
      
        }else {Char_to_PC_Local(keypress);}}
       else break;
       }
  String_to_PC_Local("Done\r\n");
  SW_reset;
  return 1;}

**************************************************************************************************************************************/
