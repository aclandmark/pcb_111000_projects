

void Char_to_PC_Basic(char);



int Bin_to_string_Local(long number, char *s){
  int i = 0; 
 while(1) {
    s[i++] = number % 10 + '0';
    number = number/10;
    if (!(number))break;
  }s[i] = '\0';
   return i;}




void Num_string_to_PC_Local(char *s, int str_len){
 for (int m = str_len; m > 0; m--)
 Char_to_PC_Basic(s[m - 1]);}
