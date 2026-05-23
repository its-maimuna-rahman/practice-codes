#include <stdio.h>
int main() {
  int n;
  char c;
  
  printf("c = ");
  scanf(" %c", &c);
  printf("n = ");
  scanf("%d", &n);
  
  for(int i=1; i<=n; i++) {
    for(int j=n; j>=1; j--) {
      if(i>=j) {
        printf("%c ", c);
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}