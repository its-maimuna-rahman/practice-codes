#include <stdio.h>

int main() {
    int row, col;

    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    float mat[row][col];
    float tp[col][row];
    float rotate1[col][row];      // col x row because they interchange
    float rotate2[row][col];
    float rotate3[col][row];
    float rotate4[col][row];
    float rotate5[row][col];
    float rotate6[col][row];
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("Enter element %d, %d: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    
    printf("\nOriginal Matrix : \n\n");
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        printf("%.3f  ", mat[i][j]);
      }
      printf("\n");
    }
    
    
    // transpose
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        tp[j][i] = mat[i][j]; 
      }
    }

    printf("\nTranspose Matrix : \n\n");
    for(int i = 0; i < col; i++) {
      for(int j = 0; j < row; j++) {
        printf("%.3f  ", tp[i][j]);
      }
      printf("\n");
    }

    // 90 degree rotation anti-clockwise
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          rotate1[col-1-j][i] = mat[i][j];
      }
    }
    
    printf("\n90 degree rotation ANTI-CLOCKWISE : \n\n");
    for(int i = 0; i < col; i++) {
      for(int j = 0; j < row; j++) {
        printf("%.3f  ", rotate1[i][j]);
      }
      printf("\n");
    }
    
    // 180 degree rotation anti-clockwise
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {              // row-1-i for reversing rows
        rotate2[row-1-i][col-1-j] = mat[i][j];    // col-1-j for reversing cols 
      }
    }
    
    printf("\n180 degree rotation ANTI-CLOCKWISE : \n\n");
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        printf("%.3f  ", rotate2[i][j]);
      }
      printf("\n");
    }
    
    // 270 degree rotation anti-clockwise
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {              // transpose
        rotate3[j][col-1-i] = mat[i][j];          // row-1-i for reversing rows
      }
    }
    
    printf("\n270 degree rotation ANTI-CLOCKWISE : \n\n");
    for(int i = 0; i < col; i++) {
      for(int j = 0; j < row; j++) {
        printf("%.3f  ", rotate3[i][j]);
      }
      printf("\n");
    }
    
    // 90 degree rotation clockwise
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        rotate4[j][col-1-i] = mat[i][j];
      }
    }
    
    printf("\n90 degree rotation CLOCKWISE : \n\n");
    for(int i = 0; i < col; i++) {
      for(int j = 0; j < row; j++) {
        printf("%.3f  ", rotate4[i][j]);
      }
      printf("\n");
    }
    
    // 180 degree rotation clockwise
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        rotate5[row-1-i][col-1-j] = mat[i][j];
      }
    }
    
    printf("\n180 degree rotation CLOCKWISE : \n\n");
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        printf("%.3f  ", rotate5[i][j]);
      }
      printf("\n");
    }
    
    // 270 degree rotation clockwise
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        rotate6[row-1-j][i] = mat[i][j];
      }
    }
    
    printf("\n270 degree rotation CLOCKWISE : \n\n");
    for(int i = 0; i < col; i++) {
      for(int j = 0; j < row; j++) {
        printf("%.3f  ", rotate6[i][j]);
      }
      printf("\n");
    }
    
    return 0;
}