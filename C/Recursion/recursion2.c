// Recurrence practice 2

#include <stdio.h>
#include <math.h>


// sum of digits of a integer
int digit_sum(int n) {
  
  if(n == 0) {
    return 0;
  }
  else {
   return ((n % 10) + digit_sum(n / 10)); 
  }
  
}

// gcd of 2 integer
int gcd(int x, int y) {
  
  if(y == 0) {
    return x;
  }
  else  {
    return gcd(y, (x % y));
  }
}

// string reverse
void reverse(char *x) {
  
      if(*x == '\0') {
          return;
      }
        reverse(x + 1); 
        printf("%c", *x);
}

// fibonacci series
void fibonacci(int n, int a, int b, int count) {
  if(count >= n) {
    return;
  }
  
  if(count == 0) {
    printf("0\n");
    fibonacci(n, 0, 1, count + 1);
  }
  else if(count == 1) {
    printf("1\n");
    fibonacci(n, 0, 1, count + 1);
  }
  else {
    int c = a + b;
    printf("%d\n", c);
    fibonacci(n, b, c, count+1);
  }
}

      
int main() {
  int x, y, m, n;
  char str[20];
  
  printf("enter x for digit sum = ");
  scanf("%d", &x);
  printf("enter m and n for gcd = ");
  scanf("%d%d", &m, &n);
  printf("enter word for string reverse = ");
  scanf("%19s", str);
  printf("enter y for fibonacci series = ");
  scanf("%d", &y);
  
  printf("digit sum of x = %d\n", digit_sum(x));
  printf("gcd of %d and %d = %d\n", m, n, gcd(m, n));
  printf("reversed string : ");
  reverse(str);
  printf("\n");
  printf("fibonacci series : \n");
  fibonacci(y, 0, 1, 0);
  
  return 0;
}