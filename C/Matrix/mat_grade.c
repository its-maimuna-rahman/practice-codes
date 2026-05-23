// r students × c subjects
/* Input all marks
 Print marksheet
 Calculate each student’s total
 Calculate each subject’s average
 Find topper
 Sort rows by total marks */

#include <stdio.h>

int main() {
  int r,c;
  
  printf("\nr (row) = ");
  scanf("%d", &r);
  printf("c (column) = ");
  scanf("%d", &c);
  
  int a[r][c];
  
  printf("\nenter matrix A row by row = \n");
  
  for(int i = 0; i < r; i++) {            // A matrix input 
    for(int j = 0; j < c; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  printf("\nMatrix A :\n");               // A matrix print
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf(" %8.d  ", a[i][j]);
    }
    printf("\n");
  }
  
  // each students total = row wise sum
  // finding topper = max among row wise sum
  // row_sum is array to use in sorting in the next step
  printf("\n");
  int max = 0;
  int row_sum[r];
  for(int i = 0 ; i < r; i++) {
    row_sum[i] = 0;
    for(int j = 0; j < c; j++) {
      row_sum[i] += a[i][j];
    }
    printf("The total number of student %d is = %d\n", i+1, row_sum[i]);
    if(row_sum[i] > max) {
      max = row_sum[i];
    }
  }
  printf("\ntopper is the student with total mark = %d\n", max);
  
  // each subjects average =  column wise average
  printf("\n");
  float col_avg;
  for(int j = 0 ; j < c; j++) {
    int col_sum = 0;
    for(int i = 0; i < r; i++) {
      col_sum += a[i][j];
    }
    col_avg = (float)col_sum / r;
    printf("The average number of subject %d is = %.2f\n", j+1, col_avg);
  }
  
  // Sort rows by total marks
  for(int i = 0; i < r; i++) {
    for(int k = 0; k < r-i-1; k++) {
      if(row_sum[k] < row_sum[k+1]) {
        
        // swap sums
        int tempS = row_sum[k];
        row_sum[k] = row_sum[k+1];
        row_sum[k+1] = tempS;
        
        // swap entire rows
        for(int j = 0; j < c; j++) {
          int temp = a[k][j];
          a[k][j] = a[k+1][j];
          a[k+1][j] = temp;
        }
      }
    }
  }
  
  
  printf("\nMatrix A (merit wise sort):\n\n");        //sorted A matrix print
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf(" %8.d  ", a[i][j]);
    }
    printf("    | total = %d\n", row_sum[i]);
  }
  
  return 0;
}