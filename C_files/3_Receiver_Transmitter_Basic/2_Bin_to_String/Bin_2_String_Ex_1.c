




int main (void)                          //Example 1 
  { int i = 0;              //Convert number to string
  int number = 12345;
  char s[12];
  setup_HW;
  //Set up watchdog timer to generate a reset
  wdt_enable(WDTO_120MS);
 while(switch_1_down)wdr();

  //Convert number to string
  while(1) {
    s[i++] = number % 10 + '0';
    number = number/10;
    if (!(number))break;
  }s[i] = '\0';

  //Print string out in reverse order
    for (int m = i; m > 0; m--)
    Char_to_PC_Basic(s[m - 1]);
  newline_Basic();
 //Generate a reset
 while(switch_1_up)wdr();
  while(switch_1_down);
  return 1;}