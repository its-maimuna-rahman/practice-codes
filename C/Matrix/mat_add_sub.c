// matrix addition and subtraction

#include <stdio.h>

int main() {
  int n,m;
  
  printf("\nn (row) = ");
  scanf("%d", &n);
  printf("m (column) = ");
  scanf("%d", &m);
  
  double a[n][m], b[n][m];
  
  printf("\nenter matrix A row by row = \n");
  
  for(int i = 0; i < n; i++) {            // A matrix input 
    for(int j = 0; j < m; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");               // A matrix print
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf(" %8.3lf  ", a[i][j]);
    }
    printf("\n");
  }
  
  printf("\nenter matrix B row by row = \n");
  
  for(int i = 0; i < n; i++) {            // B matrix input
    for(int j = 0; j < m; j++) {
      scanf("%lf", &b[i][j]);
    }
  }
  
  printf("\nMatrix B :\n");               // B matrix print
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf(" %8.3lf  ", b[i][j]);
    }
    printf("\n");
  }
  
  double c[n][m]; 
  printf("\nMatrix C (addition) :\n");
  for(int i = 0; i < n; i++) {            // addition plus print
    for(int j = 0; j < m; j++) {
      c[i][j] = a[i][j] + b[i][j];
      printf(" %8.3lf  ", c[i][j]);
    }
    printf("\n");
  }
  
  double d[n][m]; 
  printf("\nMatrix D (subtraction) [A - B] :\n");
  for(int i = 0; i < n; i++) {            
    for(int j = 0; j < m; j++) {          // subtraction plus print
      d[i][j] = a[i][j] - b[i][j];
      printf(" %8.3lf  ", d[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
