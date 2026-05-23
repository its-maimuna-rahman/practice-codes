#include <stdio.h>

int main(void) {
  int choice, n, s = 0, m;
  
  while(1) {
    printf("\n=== MENU ===\n");
    printf("1. Sum of first n integers\n");
    printf("2. Print odd integers up to limit\n");
    printf("3. Print first 50 fibonacci numbers\n");
    printf("4. Exit\n");
    
    printf("enter your choice = ");
    scanf("%d", &choice);
    
    if(choice == 1) {
      
      printf("n = ");
      scanf("%d", &n);
      
      for(int i = 1; i <=n; i++) {
        s += i;
      }
      printf("Sum of first n integers = %d\n", s);
    }
    else if(choice == 2) {
      
      printf("m = ");
      scanf("%d", &m);
      
      for(int i=1; i <= m; i+=2) {
        printf("%d\n", i);
      }
    }
    else if(choice == 3) {
      
      long long a = 0;
      long long b = 1;
      long long next;
      
      printf("%lld\n", a);
      printf("%lld\n", b);
      
      for(int i = 0; i < 50; i++) {
        next = a + b;
        a = b;
        b = next;
        printf("%lld\n", next);
      }
    }
    else if(choice == 4) {
      printf("exit\n");
      break;
    }
    else {
      printf("invalid number, try again.\n");
    }
    
  }
 
 return 0; 
}