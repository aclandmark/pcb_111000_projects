

ISR(TIMER1_COMPA_vect)                                              //Example 1
{ TCNT1 = 0; 
 if(PORT_1 < 0x10000)I2C_Tx_2_integers(PORT_1, PORT_1);
PORT_1 = PORT_1 << 1;
if (PORT_1 == 0x10000)PORT_1 = 1;}


//*********************************************************************************
ISR(TIMER1_COMPA_vect)                                             //Example 2 
{OCR1A = clock_rate * 125;
 TCNT1 = 0; 
     I2C_Tx_2_integers(PORT_1, PORT_2);
      PORT_1 = PORT_1 << 1;
      PORT_2 = PORT_2 >> 1;
   if (PORT_1 == 0x10000){PORT_1 = 1; PORT_2 = 0x8000;}}
 


//*********************************************************************************
ISR(TIMER1_COMPA_vect)                                             //Example 3
  {OCR1A = clock_rate * 125;
 TCNT1 = 0; 
  I2C_Tx_2_integers(PORT_1 << m, PORT_2 >> m);
  
    if (!(n)) m += 1;
    if (m == 16)n = 1;
    if (n == 1)m -= 1;
    if (m == 0)n = 0;}


 
//*********************************************************************************
ISR(TIMER1_COMPA_vect)                                            //Example 4 
  { TCNT1 = 0; 
   PRN_counter = counter;
  PRN = PRN_16bit_GEN (PRN, &PRN_counter);
  I2C_Tx_2_integers(PRN, (PRN << ((PRN % 2) + 1)));
    counter = PRN_counter;
    Int_to_PC_Basic(counter);
   while(switch_2_down); }
   
  


//*********************************************************************************
 ISR(TIMER1_COMPA_vect)												//Example_5
{
  { OCR1A = 150 * 125;
    TCNT1 = 0;

 if (n < 8)
  { PORT_1 |= (1 << (2 * n));
    PORT_2 |= (0x8000 >> (2 * n)); }
  else
  { PORT_1 = PORT_1 << 2;
    PORT_2 = PORT_2 >> 2; }

  I2C_Tx_2_integers(PORT_1, PORT_2);

  n += 1;
  if (n == n_max)
  { n = 0;
    m += 1;
    m = m % 8;
    initialise_display();}}}
	
	
	
//*********************************************************************************
	ISR(TIMER1_COMPA_vect)												//Example_6
{
  { OCR1A = 150 * 125;
    TCNT1 = 0;

 if (n < 5)
      { PORT_1 |= PORT_1 << 1;
        PORT_2 |= PORT_2 >> 1; }
      else
      { PORT_1 = PORT_1 << 1;
        PORT_2 = PORT_2 >> 1; }

  I2C_Tx_2_integers(PORT_1, PORT_2);
  
  n += 1;
  if (n == n_max)
  {  n = 0;
    m += 1;
    m = m % 8;
    initialise_display();}}}
	
	
	
	
	
	

//*********************************************************************************	
	
	
	
	
	
	
	
	
	
	
	
	