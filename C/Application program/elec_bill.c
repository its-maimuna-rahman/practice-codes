/*Write a C program to calculate the total electricity bill using
 *  nested if statements based on these rules:
 
 Units (kWh) -	Rate per unit
 0 – 100	5 tk
 101 – 300	8 tk
 301 – 500	10 tk
 Above 500	12 tk + 15% surcharge */

#include <stdio.h>
#include<math.h>

int main(){
  int u,tk;
  
  printf("enter unit, u = ");
  scanf("%d", &u);
  
  if(u>=0 && u<=100) {
    tk=u*5;
    printf("bill= %d", tk);
  }
  else if(u>=101 && u<=300) {
    tk=(100*5)+((u-100)*8);
    printf("bill= %d", tk);
  }
  else if(u>=301 && u<=500) {
    tk=(100*5)+(200*8)+((u-300)*10);
    printf("bill= %d", tk);
  }
  else if(u>500) {
    tk=(100*5)+(200*8)+(200*10)+((u-500)*12);
    tk=tk+(tk*0.15);
    printf("bill= %d", tk);
  }
  else {
    printf("invalid input");
  }
  
  
  return 0;
}