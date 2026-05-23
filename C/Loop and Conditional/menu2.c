// gives factorial of an integer
// gives value of e by Taylor Series expansion
// gives value of e^x by Taylor Series expansion


#include <stdio.h>
#include <math.h>

long long factorial(int n) {
  long long factorial = 1;
  for(int i = 1; i <= n; i++) {
    factorial *= i;  
  }
  return factorial;
}

int main() {
  int choice, n, m, x, y;
  long long fact;
  
  while(1) {
    printf("\n");
    printf("====== Factorial menu ======\n");
    printf("1. factorial of an integer\n");
    printf("2. value of e\n");
    printf("3. value of e^x\n");
    printf("0. exit\n");
    printf("Enter choice : \n");
    scanf("%d", &choice);
    
    if(choice == 1) {
      
      printf("--- factorial of an integer ---\n");
      printf("Enter an integer: ");
      scanf("%d", &n);
      
      fact = factorial(n);
      printf("\nfactorial = %lld\n", fact); 
    }
    else if(choice == 2) {
      
      printf("--- value of e ---\n");
      printf("How many terms of Taylor Series expansion you want? =  ");
      scanf("%d", &m);    // m = 15 has good accuracy
      
      double e = 1.0;
      for(int i = 1; i <= m; i++) {
        e += (1.0 / factorial(i));
      }
      printf("\ne = %.10lf\n", e);
    }
    else if(choice == 3) {
      
      printf("--- value of e^x ---\n");
      printf("Enter e's power (e^x) : ");
      scanf("%d", &x);
      printf("How many terms of Taylor Series expansion you want? =  ");
      scanf("%d", &y);
      
      double ex = 1.0;
      for(int i = 1; i <= y; i++) {
        ex += (pow(x,i)/ factorial(i));
      }
      printf("\ne^x = %.10lf\n", ex);
      
    }
    else if(choice == 0) {
      printf("\nEXIT\n");
      break;
    }
    else {
      printf("Invalid choice, please choose 1/2/3/0\n");
    }
  }
  return 0;
}
