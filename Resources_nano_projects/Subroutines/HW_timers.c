void USART_init (unsigned char, unsigned char);
void nop_delay(int);
void Timer_T0_10mS_delay_x_m(int);
void Timer_T0_sub(char, unsigned char);
void Timer_T0_sub_with_interrupt(char, unsigned char);
void T1_65ms_clock_tick(void);
void Timer_T1_sub_with_interrupt(char, unsigned int);
void Timer_T1_sub(char, unsigned int);
void Timer_T2_sub(char, char);
void sendChar(char);
void sendString(char*);

/*********************************************************************/

#define T0_delay_10ms 	5,178
#define T1_delay_100ms 	3, 0x9E62
#define T1_delay_50ms 	5,0xFE78
#define T2_delay_10ms 	7,178

#define T2_delay_2ms  5, 131
#define T0_delay_5ms  5,217


/*********************************************************************/
void nop_delay(int nop_counter){for(int q = 0; q<= nop_counter; q++) {asm("nop");}}

/*********************************************************************/
void Timer_T0_10mS_delay_x_m(int m)
{for (int n = 0; n < m; n++){Timer_T0_sub(T0_delay_10ms);wdr();}}

/*********************************************************************/
void Timer_T0_sub(char Counter_speed, unsigned char Start_point){ 
TCNT0 = Start_point;
TCCR0B = Counter_speed;
while(!(TIFR0 & (1<<TOV0)));
TIFR0 |= (1<<TOV0); TCCR0B = 0;}


/*********************************************************************/
void Timer_T0_sub_with_interrupt(char Counter_speed, unsigned char Start_point){ 
TIMSK0 |= (1 << TOIE0);
TCNT0 = Start_point;
TCCR0B = Counter_speed;}


/*********************************************************************/
void T1_65ms_clock_tick(void){ 
TIMSK1 |= (1 << TOIE1);TCCR1B = 0x02;}

/*********************************************************************/
void Timer_T1_sub(char Counter_speed, unsigned int Start_point){ 
TCNT1H = (Start_point >> 8);
TCNT1L = Start_point & 0x00FF;
TIFR1 = 0xFF;
TCCR1B = Counter_speed;
while(!(TIFR1 & (1<<TOV1)))wdr();
TIFR1 |= (1<<TOV1); 
TCCR1B = 0;}

/*********************************************************************/
void Timer_T1_sub_with_interrupt(char Counter_speed, unsigned int Start_point){ 
TIMSK1 |= (1 << TOIE1);
TCNT1H = (Start_point >> 8);
TCNT1L = Start_point & 0x00FF;
TCCR1B = Counter_speed;}


/*********************************************************************/
void Timer_T2_sub(char Counter_speed, char Start_point){ 
TCNT2 = (Start_point );

TCCR2B = Counter_speed;
while(!(TIFR2 & (1<<TOV2)));
TIFR2 |= (1<<TOV2); 
TCCR2B = 0;}



/*********************************************************************/
void Timer_T2_10mS_delay_x_m(int m)
{for (int n = 0; n < m; n++){Timer_T2_sub(T2_delay_10ms);wdr();}}



/*********************************************************************/






