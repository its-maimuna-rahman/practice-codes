//row wise and column wise minimum and maximum value

#include <stdio.h>

int main() {
  int r,c;
  
  printf("\nr (row) = ");
  scanf("%d", &r);
  printf("c (column) = ");
  scanf("%d", &c);
  
  float a[r][c];
  
  printf("\nenter matrix A row by row = \n");
  
  for(int i = 0; i < r; i++) {            // A matrix input 
    for(int j = 0; j < c; j++) {
      scanf("%f", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");               // A matrix print
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf(" %8.3f  ", a[i][j]);
    }
    printf("\n");
  }
  
  printf("\n");
  for(int i = 0; i < r; i++) {
    int max_r_index = 0;
    for(int j = 0; j < c; j++) {
      if(a[i][j] > a[i][max_r_index]) {
        max_r_index = j;
      }
    }
    printf("Maximum value in row %d = %.3f\n", i+1, a[i][max_r_index]);
  }
  
  printf("\n");
  for(int j = 0; j < c; j++) {
    int max_c_index = 0;
    for(int i = 0; i < r; i++) {
      if(a[i][j] > a[max_c_index][j]) {
        max_c_index = i;
      }
    }
    printf("Maximum value in column %d = %.3f\n", j+1, a[max_c_index][j]);
  }
  
  printf("\n");
  for(int i = 0; i < r; i++) {
    int min_r_index = 0;
    for(int j = 0; j < c; j++) {
      if(a[i][j] < a[i][min_r_index]) {
        min_r_index = j;
      }
    }
    printf("Minimum value in row %d = %.3f\n", i+1, a[i][min_r_index]);
  }
  
  printf("\n");
  for(int j = 0; j < c; j++) {
    int min_c_index = 0;
    for(int i = 0; i < r; i++) {
      if(a[i][j] < a[min_c_index][j]) {
        min_c_index = i;
      }
    }
    printf("Minimum value in column %d = %.3f\n", j+1, a[min_c_index][j]);
  }
  
  return 0;
} 