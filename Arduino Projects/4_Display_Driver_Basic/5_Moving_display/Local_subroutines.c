
char waitforkeypress_Basic (void);
char decimal_digit_Basic (char );

void display_num_string (const char*, int);
void I2C_Tx_any_segment_clear_all(void);
void I2C_Tx_any_segment(char, char);


#define zero "abcdef"          //chars a,b,c,d,e,f stored in array named "zero"
#define one "bc"
#define two "abged"
#define three "abcdg"
#define four "fgbc"
#define five "afgcd"
#define six "fegdc"
#define seven "abc"
#define eight "abcdefg"
#define nine "abcfg"
#define null "\0"

extern const char* string_ptr;



char digit_array_to_display(char digit_array[], char mode)    //"digit_array" is a pointer to a block of memory defined by "main"
{char keypress;
int array_offset = 0;                     //takes on values between 0 and 16                      

do{
if(mode == 1)                         //mode = 1: First of all enter keypresses into "digit_array"
{keypress = waitforkeypress_Basic();                  //Only keypresses 0 to 9 or x allowed. Otherwise use "continue" to skip input 
if((decimal_digit_Basic (keypress)) || (keypress == 'x'))     //mode = 0: Skip keypress entry stage
digit_array[array_offset] = keypress;         
else continue;}

switch(digit_array[array_offset]){                //Read entries stored in "digit_array" and send them to the display.
case '0': string_ptr = zero; break;               //next keypress in "digit_array" is '0': "string_ptr" addresses string "zero" 
case '1': string_ptr = one; break;
case '2': string_ptr = two; break;
case '3': string_ptr = three; break;
case '4': string_ptr = four; break;
case '5': string_ptr = five; break;
case '6': string_ptr = six; break;
case '7': string_ptr = seven; break;
case '8': string_ptr = eight; break;
case '9': string_ptr = nine; break;
case 'x': digit_array[array_offset] = 0; return 0; break;   //Inform "main" that user wants to enter < 8 digits
case 0: string_ptr = null; break;}                //All unused bytes in "digit_array" contain zero: Null generates a space.

{display_num_string(string_ptr, array_offset++);}}        //Increment "array_offset" before executing next line of code
while (array_offset < 8);                   //Exit "do" loop when "array_offset" gets to 8

return 1;}                            //Inform "main" that user has entered 8 digits



/************************************************************************************************/
void display_num_string (const char* s, int digit_num){       //Subroutine requires a pointer to the string   
int char_ptr=0;                         //containing segments used to define a digit
char letter;

while(1){
letter = *(s + char_ptr);                   //Address of first segment of next digit
switch(letter){
case 'a':
case 'b': 
case 'c': 
case 'd': 
case 'e': 
case 'f': 
case 'g': I2C_Tx_any_segment(letter, digit_num);break;      //update display
case 0:  return; break;
default: break;}char_ptr++;}}                 //incrementing "char_ptr" steps through the string
                                //Selecting segment letters in turn until the null character:0 is encountered
                                
