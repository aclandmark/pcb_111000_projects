

int main (void){
int Num;
int Inc;
unsigned char digit_array[4], radix = 16;

setup_HW;

  String_to_PC_Basic("Enter positive number and increment then x or y or AK\r\n");  
    Num = Int_from_PC_Basic(digits);
    Hex_and_Int_to_PC_Basic(10, Num);
    Inc = Int_from_PC_Basic(digits);
  
  Hex_and_Int_to_PC_Basic(10, Inc);
  newline_Basic();
    
while(1){ 
   Hex_and_Int_to_PC_Basic(10, Num);
  Char_to_PC_Basic('\t');
 Hex_and_Int_to_PC_Basic(radix, Num);Char_to_PC_Basic('\t');     //Send the number to the pc with a radix of 16.
  Binary_to_PC_local(Num);              						//Send the number to the pc in binary form
  String_to_PC_Basic("\r\n");
  
  switch(waitforkeypress_Basic()){
   case 'x': Num= Num + Inc;break;
   case 'y': Num= Num - Inc;break;
   case 'z': Num = Num * -1; break;
   default:SW_reset;break;    
  }}
  }
  