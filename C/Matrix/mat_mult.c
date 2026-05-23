// matrix multiplication

#include <stdio.h>

int main() {
  int r1, c1, r2, c2;
  
  printf("\nr1 (row of A matrix) = ");
  scanf("%d", &r1);
  printf("c1 (column of A matrix) = ");
  scanf("%d", &c1);
  
  double a[r1][c1];
  printf("\nenter matrix A row by row = \n");
  
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c1; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c1; j++) {
      printf(" %8.3lf  ", a[i][j]);
    }
    printf("\n");
  }
  
  printf("\nr2 (row of B matrix) = ");
  scanf("%d", &r2);
  printf("c2 (column of B matrix) = ");
  scanf("%d", &c2);
  
  double b[r2][c2];
  printf("\nenter matrix B row by row = \n");
  
  for(int i = 0; i < r2; i++) {
    for(int j = 0; j < c2; j++) {
      scanf("%lf", &b[i][j]);
    }
  }
  
  printf("\nMatrix B :\n");
  for(int i = 0; i < r2; i++) {
    for(int j = 0; j < c2; j++) {
      printf(" %8.3lf  ", b[i][j]);
    }
    printf("\n");
  }
  
  double c[r1][c2];
  
  if(c1 != r2) {
    printf("\nA and B matrix cannot be multiplied\n");
  }
  else {
    for(int i = 0; i < r1; i++) {
      for(int j = 0; j < c2; j++) {
        c[i][j] = 0;
        for(int k = 0; k < c1; k++) {
          c[i][j] += a[i][k] * b[k][j]; 
        }
      }
    }
  }
  
  printf("\nMatrix C (multiplication) :\n");
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c2; j++) {
      printf(" %8.3lf  ", c[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
