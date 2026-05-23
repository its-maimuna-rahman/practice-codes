/*A palindrome is a number or a text phrase that reads the same backward as
 forward. For example : 12321, 55555, 45554 11611. This program shows 
 whether an integer a palindrome or not
 */

#include <stdio.h>

int main() {
  int n, rev = 0, digit;
  
  printf("Enter an integer: ");
  scanf("%d", &n);
  
  int temp1 = n, temp2, s = 0;
  
  while(temp1 != 0) {
    temp1 = temp1 / 10;
    s++;
  }
  
  while(1) {
    if(s % 2 == 1) {
      break;
    }
    else {
      printf("Invalid input. enter odd digit integer.\n");
      printf("Enter an integer: ");
      scanf("%d", &n);
    
  
      temp1 = n;
      
      s = 0;
      
      while(temp1 != 0) {         // digit count recalculated after invalid input
        temp1 = temp1 / 10;
        s++;
        
      }
    }  
  }
  
  temp2 = n;
  while (temp2 != 0) {
    digit = temp2 % 10;
    rev = rev * 10 + digit;
    temp2 = temp2 / 10;
  }
  
  printf("Reversed number = %d\n", rev);
  
  if(rev == n) {
    printf("palindrome\n");
  }
  else {
    printf("not a palindrome\n");
  }
  
  return 0;
}