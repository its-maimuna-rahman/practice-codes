#include <stdio.h>

int main() {
  int n;
  printf("enter n = ");
  scanf("%d", &n);
  
  long long a = 0;
  long long b = 1;
  long long next;
  
  printf("%lld\n", a);
  printf("%lld\n", b);
  
  for(int i = 0; i < n; i++) {
    next = a + b;
    a = b;
    b = next;
    printf("%lld\n", next);
  }
  
  return 0;
}