

volatile char sym_counter;
volatile int p=0;

#include "UART_interrupts_header.h"

#define double_space        String_to_PC_Basic("  ");
#define double_space_back   String_to_PC_Basic("\b\b");
#define newline_plus        String_to_PC_Basic("\r\n    ");

int main (void){
char symbol;
char q = 0;
char start, finnish;


setup_HW;
newline_plus;

start = '~';
do{
symbol = '!';
  while (symbol <= '~')
  { if (symbol >= start)Char_to_PC_Basic(symbol);
  else double_space;
  symbol += 1;}
_delay_ms(25);
 start -= 1;
newline_plus;
  }while(start >= '!');
    
 finnish = '~' - 1; 
 do
{symbol = '!';
  while (symbol <= finnish)Char_to_PC_Basic(symbol++);
  finnish -= 1;newline_plus;
  _delay_ms(25);
  } while (finnish >= '!');

SW_reset;  }
