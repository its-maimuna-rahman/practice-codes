// prime number, GCD, LCM for 2 integers.

#include <stdio.h>
#include <math.h>

int prime(int n) {
  for(int i = 1; i < n; i++) {
    if(n <= 1) {
      return 0;
    }
    else if(n % i == 0) {
      return 0;
    }
    else {
      return 1;
    }
  }
}  

int gcd(int a, int b) {
    int t;
  while(b != 0) {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int lcm(int a, int b) {
  int temp;
  temp = gcd(a, b);
  return ((a * b) / temp);
}

int main() {
  int a, b, GCD, LCM;
  
  printf("a, b = \n");
  scanf("%d%d", &a, &b);
  
  if(prime(a)) {
    printf("%d is a prime number\n", a);
  }
  else {
    printf("%d is not a prime number\n", a);
  }
  
  if(prime(a)) {
    printf("%d is a prime number\n", b);
  }
  else {
    printf("%d is not a prime number\n", b);
  }
  
  GCD = gcd(a, b);
  LCM = lcm(a, b);
  
  printf("GCD = %d\n", GCD);
  printf("LCM = %d\n", LCM);
  
  return 0;
}