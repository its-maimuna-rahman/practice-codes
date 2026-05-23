// counting digits of an integer
// separating digits of an integer
// reversing it
// 0 in the first does not count

#include <stdio.h>
#include <math.h>

int main() {
  int n, count = 0;
  
  printf("Enter an integer: ");
  scanf("%d", &n);
  
  int temp = n;
  
  if (temp == 0) {
    count = 1;                            // 0 has 1 digit
  } 
  else {
    if (temp < 0) temp = -temp;           // handle negative numbers
    
    while (temp > 0) {
      temp = temp / 10;
      count++;
    }
  }
  
  printf("Number of digits = %d\n", count);
  
  int x = (n < 0) ? -n : n;               // make positive for separating
  int y = (n < 0) ? -n : n;               // make positive for reversing
  
  int divisor, p;                        // divisor for separating
  p = count - 1;
  divisor = pow(10, p);
  
  printf("\nseparating digits : ");       // separating digits
  while(divisor > 0) {
    int digit = x / divisor;
    printf("%d ", digit);
    x = x % divisor;
    divisor /= 10;
  }
  
  int rev = 0;             // reversing integer
  while(y > 0) {
    int digit = y % 10;
    rev = rev * 10 + digit;
    y /= 10;
  }
  printf("\nReversing the integer : %d\n", rev);
  
  return 0;
}
