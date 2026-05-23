#include <stdio.h>

int main() {
  int n;
  printf("n = ");
  scanf("%d", &n);
  
  printf("\n");
  // Increasing right triangle
  printf("Increasing right triangle\n\n");
  for(int row = 1; row <= n; row++) {
    for(int col = 1; col <= row; col++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n");
  // Decreasing right triangle
  printf("Decreasing right triangle\n\n");
  for(int row = 1; row <= n; row++) {
    for(int col = 1; col <= (n - row + 1); col++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n");
  // Left-padded right triangle
  printf("Left-padded right triangle\n\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 1; space <= (n - row); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= row; col++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n");
  // Reverse left-padded right triangle
  printf("Reverse left-padded right triangle\n\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 0; space <= (row-1); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= (n - row + 1); col++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n");
  // Pyramid (centered)
  printf("Pyramid (centered)\n\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 1; space <= (n - row); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= (2 * row) - 1; col++) {
      printf("*");
    } 
    printf("\n");
  }
  
  printf("\n");
  // Pyramid (centered - 2)
  printf("Pyramid (centered - 2)\n\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 1; space <= (n - row); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= row; col++) {
      printf("* ");
    }
    printf("\n");
  }
  
  printf("\n");
  // Pyramid (Inverted)
  printf("Pyramid (Inverted)\n\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 1; space <= (row-1); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= 2 * (n-row) + 1; col++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n");
  // Pyramid (Inverted - 2)
  printf("Pyramid (Inverted - 2)\n\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 0; space <= (row-1); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= (n - row + 1); col++) {
      printf("* ");
    }
    printf("\n");
  }
  
  printf("\n");
  // diamond
  printf("Diamond\n\n");
  for(int row = 1; row <= n; row++) {                   //first half including mid
    
    for(int space = 1; space <= (n - row); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= (2 * row) - 1; col++) {
      printf("*");
    } 
    printf("\n");
  }
  
  for(int row = 2; row <= n; row++) {                 // 2nd half
    
    for(int space = 1; space <= (row-1); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= 2 * (n-row) + 1; col++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n");
  //hollow pyramid
  printf("Hollow pyramid\n");
  for(int row = 1; row <= n; row++) {
    
    for(int space = 1; space <= (n - row); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= (2 * row) - 1; col++) {
      if(col == 1 || col == (2 * row) - 1 || row == n) {
        printf("*");
      }
      else {
        printf(" ");
      }
      
    } 
    printf("\n");
  }
  
  printf("\n");
  // hollow diamond
  printf("Diamond\n\n");
  for(int row = 1; row <= n; row++) {                   //first half including mid
    
    for(int space = 1; space <= (n - row); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= (2 * row) - 1; col++) {
      if(col == 1 || col == (2 * row) - 1) {
        printf("*");
      }
      else {
        printf(" ");
      }
      
    }
    printf("\n");
  }
  
  for(int row = 2; row <= n; row++) {                 // 2nd half
    
    for(int space = 1; space <= (row-1); space++) {
      printf(" ");
    }
    
    for(int col = 1; col <= 2 * (n-row) + 1; col++) {
      if(col == 1 || col == 2 * (n-row) + 1) {
        printf("*");
      }
      else {
        printf(" ");
      }
      
    }
    printf("\n");
  }
  
  return 0;
}


