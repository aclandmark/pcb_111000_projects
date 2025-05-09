

/*
Uses the display to illustrate conversion between 8 bit binary and decimal numbers
*/



#include "Char_to_binary_header.h"

//Type main routine here


/**************************************************************************************************/
ISR(PCINT0_vect){                                          //sw3 interrupt service routine
if(switch_2_up)return;                                     //Ignore sw3 key release
if((switch_1_down) || (switch_3_down))return;              //Ignore if sw1 or 2 are still down
if (mode == 's')  
{mode = 'u'; I2C_Tx_display_char(digit,mode);return;}      //toggle display from signed to unsigned
if (mode == 'u')
{mode = 's'; I2C_Tx_display_char(digit,mode);return;}}     //and visa-versa



ISR(PCINT2_vect) {                                        //sw1 and sw3 interrupt
if(switch_2_down)return;                                  //Ignore if sw3 is still down
if((switch_1_up) && (switch_3_up)){op = 0; return;}       //Both switches up

if(switch_1_down) {op = 1; return;}                       //Digits increment
if(switch_3_down) {op = 2; return;}}                      //Digits decrement






/*****************************************************************************************************/
