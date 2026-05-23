// matrix's diagonal elements and trace

#include <stdio.h>

int main() {
  int n;
  
  printf("\nenter matrix size (n x n), n = ");
  scanf("%d", &n);
  
  double a[n][n];
  printf("\nenter matrix A row by row = \n");
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf(" %5.3lf  ", a[i][j]);
    }
    printf("\n");
  }
  
  double trace = 0;
  printf("\nThe diagonal elements of the martix :\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        printf("%5.3lf \n", a[i][j]);
        trace += a[i][j];
      }
    }
  }
  
  printf("\nTrace of the matrix = %.3lf\n", trace);
  
  return 0;
} 