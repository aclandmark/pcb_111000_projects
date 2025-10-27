


//Introducing the divide and modulo operations 
//A/B and A%B which is the remainder

/*This is a reminder about how division works
Suppose we want to divide 63 by 8
63/8 is 7 remainder remainder 7
70 divided by 8 is 8 remainder 6
60 divided by 8 is 7 remainder 4
40 divided by 8 is 5 remainder zero.
We write 63/8 is 7.875

 Some divisions will have many more decimal places 
 63/17 is 3.705882353
 Obviously we can continue the process described above for as long as we wish.
 Of course the result can only be printed out digit by digit.
 It is not suitable for further arithmetic. */


#include "Simple_division_header.h"


//Type main routine here




/***********************************************************************************************/
  long divide(long A, long B, long *Div, long *mod, int no_decimal_places)
  {*Div = A/B;
  *mod = A%B;
  no_decimal_places -= 1;
  return no_decimal_places; } 



  /****************************************************************************************************/
