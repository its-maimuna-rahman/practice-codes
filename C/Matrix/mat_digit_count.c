#include <stdio.h>

int main() {
  int row, col;
  
  printf("Enter number of rows: ");
  scanf("%d", &row);
  printf("Enter number of columns: ");
  scanf("%d", &col);
  
  int mat[row][col];
  
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      printf("Enter element %d, %d (0-9): ", i, j);
      scanf("%d", &mat[i][j]);
      if(mat[i][j] < 0 || mat[i][j] > 9) {
        printf("Invalid input.");
        printf("Enter element %d, %d (0-9): ", i, j);
        scanf("%d", &mat[i][j]);
      }
    }
  }
  
  printf("\nMatrix : \n\n");
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      printf("%d  ", mat[i][j]);
    }
    printf("\n");
  }
  
  int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0,
      c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
  
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      switch(mat[i][j]) {
      case 0 : c0++;
               break;
      case 1 : c1++;
               break;
      case 2 : c2++;
               break;
      case 3 : c3++;
               break;
      case 4 : c4++;
               break;
      case 5 : c5++;
               break;
      case 6 : c6++;
               break;
      case 7 : c7++;
               break;
      case 8 : c8++;
               break;
      case 9 : c9++;
               break;
        
      }
    }
  }
  
  printf("\ncount of 0 = %d\n", c0);
  printf("count of 1 = %d\n", c1);
  printf("count of 2 = %d\n", c2);
  printf("count of 3 = %d\n", c3);
  printf("count of 4 = %d\n", c4);
  printf("count of 5 = %d\n", c5);
  printf("count of 6 = %d\n", c6);
  printf("count of 7 = %d\n", c7);
  printf("count of 8 = %d\n", c8);
  printf("count of 9 = %d\n", c9);
  
  return 0;
}  