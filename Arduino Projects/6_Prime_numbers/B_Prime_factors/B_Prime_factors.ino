
#include "Prime_factors_header.h"

/************************************************************************************************************/
//Type main routine here



/***************************************************************************************************************************/
unsigned long next_prime_number(unsigned long num){
 
 while (!(prime_num_check(++num)));
 return num;}


/***************************************************************************************************************************/
char prime_num_check(unsigned int Num)                        
{   
int i = 2;   
int m;  
 while(1){  
if (i*i > Num)break;  
m=0;
while(1){
if(i*(i+m) == Num)return 0;
if(i*(i+m) > Num)break;
m += 1;}  
i += 1;}
return 1;}


/*************************************************************************************/
