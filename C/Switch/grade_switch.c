/*
 Input a grade (A, B, C, D, F) and use a switch to print:
 “Excellent” for A
 “Good” for B
 “Average” for C
 “Poor” for D
 “Fail” for F
 If the input is not one of these letters, print “Invalid grade.”
 */

#include <stdio.h>
int main() {
  char gd;
  printf("enter grade (A,B,C,D,F) = ");
  scanf(" %c", &gd);
  
  switch(gd) {
  case 'A' :
    printf("excellent");
    break;
  case 'B' :
    printf("good");
    break;
  case 'C' :
    printf("average");
    break;
  case 'D' :
    printf("poor");
    break;
  case 'F' :
    printf("fail");
    break;
  default :
    printf("invalid input");
  break;
  }
  
  return 0;
}