// even and odd element count, row and column wise sum
// as it will count even/odd, so all elements need to be integer

#include <stdio.h>

int main() {
  int n,m;
  
  printf("\nn (row) = ");
  scanf("%d", &n);
  printf("m (column) = ");
  scanf("%d", &m);
  
  int a[n][m];
  
  printf("\nenter matrix A row by row = \n");
  
  for(int i = 0; i < n; i++) {            // A matrix input 
    for(int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");               // A matrix print
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf(" %8.d  ", a[i][j]);
    }
    printf("\n");
  }
  
  int even_count = 0, odd_count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] % 2 == 0) {
        even_count++;
      }
      else {
        odd_count++;
      }
    }
  }
  
  printf("\nNumber of even elements = %d\n", even_count);
  printf("Number of odd elements = %d\n", odd_count);
  
  printf("\n");
  
  for(int i = 0; i < n; i++) {         // row sum
    int row_sum = 0;
    for(int j = 0; j < m; j++) {
      row_sum += a[i][j];
    }
    printf("Sum of row %d = %d\n", i+1, row_sum);
  }
  
  printf("\n");
  
  for(int j = 0; j < m; j++) {         // column sum
    int col_sum = 0;
    for(int i = 0; i < n; i++) {
      col_sum += a[i][j];
    }
    printf("Sum of column %d = %d\n", j+1, col_sum);
  }
  
  return 0;
}  