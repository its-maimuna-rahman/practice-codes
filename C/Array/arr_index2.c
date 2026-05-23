// index searching : shows first and last index of a searched element.

#include <stdio.h>

int main() {
  int n, search;
  
  printf("Enter number of elements = ");
  scanf("%d", &n);
  
  int x[n];
  
  printf("Enter elements = \n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  
  printf("The array = \n");
  for(int i = 0; i < n; i++) {
    printf("%d  ", x[i]);
  }
  
  printf("\n");
  printf("Enter a element to search = ");
  scanf(" %d", &search);
  
  printf("\n");
  for(int i = 0; i < n; i++) {
    if(x[i] == search) {
      printf("first appreared at index = %d\n", i);
      break;
    } 
  }
  
  int y[n];     // for reversed array, bec y first pos = x first pos of a number
  
  for(int i = n - 1; i >= 0; i--) {
    y[i] = x[n-1-i];  
  }
  
  for(int i = 0; i < n; i++) {
    if(y[i] == search) {
      printf("last appreared at index = %d\n", n-1-i);
      break;
    } 
  }
  
  return 0;
}