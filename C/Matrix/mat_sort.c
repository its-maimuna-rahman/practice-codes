#include <stdio.h>

int main() {
  int r, c;
  printf("Enter number of rows = ");
  scanf("%d", &r);
  printf("Enter number of columns = ");
  scanf("%d", &c);
  
  int a[r][c];
  int x[r][c];
  int y[r][c];
  
  // Input
  printf("Enter elements (row by row):\n");
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");               // A matrix print
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf(" %5.d  ", a[i][j]);
      x[i][j] = a[i][j];
      y[i][j] = a[i][j];
    }
    printf("\n");
  }
  
  // row wise sort
  for(int i = 0; i < r; i++) {              
    for(int j = 0; j < c-1; j++) {        // bubble sort
      for(int k = 0; k < c-j-1; k++) {
        if(x[i][k] > x[i][k+1]) {
          int temp = x[i][k];
          x[i][k] = x[i][k+1];
          x[i][k+1] = temp;
        }
      }
    }
  }
  
  // Print row wise sorted matrix
  printf("\nSorted rows:\n");
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf("%5.d ", x[i][j]);
    }
    printf("\n");
  }
  
  // column wise sort
  for(int j = 0; j < c; j++) {              
    for(int i = 0; i < r-1; i++) {        // bubble sort
      for(int k = 0; k < r-i-1; k++) {
        if(y[k][j] > y[k+1][j]) {
          int temp = y[k][j];
          y[k][j] = y[k+1][j];
          y[k+1][j] = temp;
        }
      }
    }
  }
  
  // Print column wise sorted matrix
  printf("\nSorted columns:\n");
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf("%5.d ", y[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}