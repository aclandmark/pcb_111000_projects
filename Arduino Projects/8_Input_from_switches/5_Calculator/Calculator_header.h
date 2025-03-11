


#include <avr/wdt.h>


char watch_dog_reset = 0;
char MCUSR_copy;
char User_response;

volatile char Data_Entry_complete, digit_entry;
volatile char scroll_control;
char digits[8];


#define switch_1_down ((PIND & 0x04)^0x04)
#define switch_1_up   (PIND & 0x04)
#define switch_2_down ((PINB & 0x40)^0x40)
#define switch_2_up   (PINB & 0x40)
#define switch_3_down  ((PIND & 0x80)^0x80)
#define switch_3_up   (PIND & 0x80)



/*****************************************************************************/
#define set_up_pci \
PCICR |= ((1 << PCIE0) | (1 << PCIE2));

#define enable_pci  PCMSK0 |= (1 << PCINT6);\
PCMSK2 |= (1 << PCINT18) | (1 << PCINT23);

#define clear_PCI_on_sw1_and_sw3    PCIFR |= (1<< PCIF2);


#define disable_pci_on_sw2   PCMSK0 &= (~(1 << PCINT6)); 

#define Init_display_for_pci_data_entry \
clear_digits;\
digits[0] = '0';\
I2C_Tx_8_byte_array(digits);

#define clear_digits {for(int m = 0; m<=7; m++)digits[m]=0;}
#define shift_digits_left {for (int n = 0; n < 7; n++){digits[7-n] = digits[6-n];}}



/*****************************************************************************/
#define setup_HW_Arduino_IO \
setup_watchdog;\
set_up_I2C;\
ADMUX |= (1 << REFS0);\
set_up_switched_inputs;\
Set_LED_ports;\
Unused_I_O;\
eeprom_write_byte((uint8_t*)(0x1FD),OSCCAL);\
while (!(PIND & (1 << PD1)));\
Timer_T0_10mS_delay_x_m(5);\
OSC_CAL;\
Serial.begin(115200);\
while (!Serial);\
sei();\
I2C_Tx_LED_dimmer();




/*****************************************************************************/
#define setup_watchdog \
if (MCUSR & (1 << WDRF))watch_dog_reset = 1;\
wdr();\
MCUSR &= ~(1<<WDRF);\
WDTCSR |= (1 <<WDCE) | (1<< WDE);\
WDTCSR = 0;


#define wdr()  __asm__ __volatile__("wdr")


#define SW_reset {wdt_enable(WDTO_30MS);while(1);}



/*****************************************************************************/
#define set_up_I2C \
TWAR = 0x02;                                     /*Address of slave I2C*/



/*****************************************************************************/
#define set_up_switched_inputs \
MCUCR &= (~(1 << PUD));\
DDRD &= (~((1 << PD2)|(1 << PD7)));\
PORTD |= ((1 << PD2) | (1 << PD7));\
DDRB &= (~(1 << PB6));\
PORTB |= (1 << PB6);


/*****************************************************************************/
#define Set_LED_ports   DDRB = (1 << DDB0) | (1 << DDB1);
#define LEDs_on       PORTB |= (1 << PB0)|(1 << PB1);
#define LEDs_off      PORTB &= (~((1 << PB0)|(1 << PB1)));
#define LED_1_on      PORTB |= (1 << PB1);
#define LED_1_off     PORTB &= (~( 1<< PB1)); 
#define LED_2_off     PORTB &= (~(1 << PB0));
#define LED_2_on      PORTB |= (1 << PB0);

#define Toggle_LED_1 \
if (PORTB & (1 << PB1)){LED_1_off;}\
else {PORTB |= (1 << PB1);}


/*****************************************************************************/
#define Unused_I_O \
MCUCR &= (~(1 << PUD));\
DDRB &= (~((1 << PB2)|(1 << PB7)));\
DDRC &= (~((1 << PC0)|(1 << PC1)|(1 << PC2)));\
DDRD &= (~((1 << PD3)|(1 << PD4)|(1 << PD5)|(1 << PD6)));\
PORTB |= ((1 << PB2)|(1 << PB7));\
PORTC |= ((1 << PC0)|(1 << PC1)|(1 << PC2));\
PORTD |= ((1 << PD3)|(1 << PD4)|(1 << PD5)|(1 << PD6));


/*
Note: The hex_text_bootloader reads PD6 to control the reset operation.
It should really be weak pull up but has been left in its default condition (tri-state) 
This is OK because it is always connected to a defined logic level
*/



/*****************************************************************************/
#define User_prompt_A \
while(1){\
do{Serial.write("R?    ");}  while((isCharavailable_A (50) == 0));\
User_response = Serial.read();\
if((User_response == 'R') || (User_response == 'r'))break;} Serial.write("\r\n");

#define OSC_CAL \
if ((eeprom_read_byte((uint8_t*)0x1FE) > 0x0F)\
&&  (eeprom_read_byte((uint8_t*)0x1FE) < 0xF0) && (eeprom_read_byte((uint8_t*)0x1FE)\
== eeprom_read_byte((uint8_t*)0x1FF))) {OSCCAL = eeprom_read_byte((uint8_t*)0x1FE);}



/*****************************************************************************/
#define waiting_for_I2C_master \
TWCR = (1 << TWEA) | (1 << TWEN);\
while (!(TWCR & (1 << TWINT)));\
TWDR;

#define clear_I2C_interrupt \
TWCR = (1 << TWINT);



/*****************************************************************************/
#define User_app_commentary_mode \
\
if(eeprom_read_byte((uint8_t*)0x3F6) == 0xFF)\
eeprom_write_byte((uint8_t*)0x3F6,0);\
\
if(eeprom_read_byte((uint8_t*)0x3F6) == 0x40){\
for(int m = 0; m < 10; m++)Serial.write("\r\n");\
Serial.write\
("Project commentary: Press 'X' to escape or AOK\r\n");\
waitforkeypress_A();\
\
eeprom_write_byte((uint8_t*)0x3F6,0x41);}\
\
if ((eeprom_read_byte((uint8_t*)0x3F6) & 0x40)){\
eeprom_write_byte((uint8_t*)0x3F6,\
(eeprom_read_byte((uint8_t*)0x3F6) | 0x80));\
\
for(int m = 0; m < 8; m++)Serial.write("\r\n");\
_delay_ms(10);\
asm("jmp 0x6C00");}                                     /*Go to Text_Verification.hex to print the next string*/ 



/**********************************************************************************/
#include "Resources_nano_projects\Subroutines\HW_timers.c"
#include "Resources_nano_projects\PC_comms\Basic_Rx_Tx_Arduino.c"
#include "Resources_nano_projects\PC_comms\Arduino_Rx_Tx_UNO_pcb.c"
#include "Resources_nano_projects\Chip2chip_comms\I2C_slave_Rx_Tx.c"
#include "Resources_nano_projects\Chip2chip_comms\I2C_subroutines_1.c"
//#include "Resources_nano_projects\Chip2chip_comms\I2C_subroutines_2.c"
#include "Resources_nano_projects\Subroutines\Random_and_prime_nos.c"


//#include "Resources_nano_projects\FPN_DIY_IO.c"

/**********************************************************************************/
