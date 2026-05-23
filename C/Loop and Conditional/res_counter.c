#include <stdio.h>
int main() {
  int res, n, pass = 0, fail = 0;
  
  printf("pass = 1, fail = 0\n");
  printf("enter number of result = ");
  scanf("%d", &n);
  
  for(int i = 1; i <= n; i++) {
    scanf("%d", &res);
    if(res == 1) {
      pass += 1;
    }
    else if(res == 0) {
      fail += 1;
    }
    else{
      printf("invalid input\n");
    }
  }
  printf("pass = %d\n", pass);
  printf("fail = %d\n", fail);
  
  if(pass >= 0.8*n) {
    printf("yayyyyy\n");
  }
  return 0;
} 