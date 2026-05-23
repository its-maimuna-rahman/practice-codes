// Recurrence practice

#include <stdio.h>
#include <math.h>

// factorial
int factorial(int n) {
  
  if(n == 1) {                          // Base case (the stop sign)
    return 1;
  }
  else {
    return (n * factorial(n - 1));      //The Recursive Step (The reduction)
  }
  
}

// sum of integer series
int sum_series(int n) {
  
  if(n == 1) {
    return 1;
  }
  else {
    return (n + sum_series(n - 1));
  }
  
}

// countdown
void countdown(int n) {
  
  if(n == 0) {
    printf("blast off\n");
    
  }
  else {
    printf("%d ", n);
    return countdown(n - 1);
  }
}

// digit count
int digit_count(int n) {
  
  if(n == 0) {
    return 0;
  }
  else {
    return (1 + digit_count(n / 10));
  }
  
}

int main() {
  int n, x;
  printf("enter n = ");
  scanf("%d", &n);
  printf("enter x = ");
  scanf("%d", &x);
  
  printf("factorial of n = %d\n", factorial(n));
  printf("sum series of n = %d\n", sum_series(n));
  printf("countdown from n to 0 : \n");
  countdown(n);
  printf("total number of digits of x integer : %d\n", digit_count(x));
  
  return 0;
}