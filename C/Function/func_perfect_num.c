#include <stdio.h>
#include <math.h>


int prime(int n) {
  if (n <= 1) return 0;  // not prime
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;  // prime
}


int perfect_num(long long int n) {
  long long int x;
  
  for (int i = 2; i <= 30; i++) {                 // loop over small primes
    if (prime(i)) {
      x = (pow(2, i-1) * (pow(2, i) - 1));        // compute perfect number
      if (x == n) return 1;
    }
  }
  return 0;                                       // not perfect
}


int main() {
  long long int n;
  
  printf("Enter integer = ");
  scanf("%lld", &n);
  
  if (perfect_num(n))
    printf("%lld is a Perfect number.\n", n);
  else
    printf("%lld is NOT a Perfect number.\n", n);
  
  return 0;
}
